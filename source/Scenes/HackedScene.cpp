/*
 * Dokkaebi Hack
 * Copyright (c) 2019 Steven Mattera
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <math.h>
#include <SDL2/SDL_image.h>

#include "Application.hpp"
#include "HackedScene.hpp"

using namespace DokkaebiHack;
using namespace DokkaebiHack::Views;

namespace DokkaebiHack::Scenes {
    HackedScene::HackedScene() {
        background = { 0, 0, 0, 255 };

        _backgroundView = new BackgroundView();
        _backgroundView->frame = { 0, 0, 1280, 720 };
        _backgroundView->generate();
        addSubView(_backgroundView);

        _dokkaebiView = new DokkaebiView();
        _dokkaebiView->frame = { 466, 37, 348, 249 };
        _dokkaebiView->setState(0);
        addSubView(_dokkaebiView);

        auto surface = IMG_Load("romfs:/club_2.png");
        _leftClub = SDL_CreateTextureFromSurface(Application::renderer, surface);
        SDL_FreeSurface(surface);

        _leftClubView = new ImageView(_leftClub);
        _leftClubView->frame = { 509, 463, 261, 189 };
        addSubView(_leftClubView);

        surface = IMG_Load("romfs:/club_1.png");
        _rightClub = SDL_CreateTextureFromSurface(Application::renderer, surface);
        SDL_FreeSurface(surface);

        _rightClubView = new ImageView(_rightClub);
        _rightClubView->frame = { 509, 463, 255, 189 };
        addSubView(_rightClubView);

        surface = IMG_Load("romfs:/text.png");
        _text = SDL_CreateTextureFromSurface(Application::renderer, surface);
        SDL_FreeSurface(surface);

        _textView = new ImageView(_text);
        _textView->frame = { 502, 323, 276, 73 };
        addSubView(_textView);
    }

    HackedScene::~HackedScene() {
        if (_dokkaebiView != NULL)
            delete _dokkaebiView;
    }

    void HackedScene::buttonsDown(u32 buttons, double dTime) {
        if (buttons & KEY_A) {
            Application::switchScene(NULL);
        }
    }

    void HackedScene::render(SDL_Rect rect, double dTime) {
        Scene::render(rect, dTime);

        _backgroundStateChangeCounter += dTime;
        if (_backgroundStateChangeCounter >= 500) {
            _backgroundStateChangeCounter = 0;
            _backgroundView->generate();
        }

        _dokkaebiStateChangeCounter += dTime;
        if (_dokkaebiStateChangeCounter >= 350) {
            _dokkaebiStateChangeCounter = 0;
            _dokkaebiState++;
            if (_dokkaebiState > 2) {
                _dokkaebiState = 0;
            }
            _dokkaebiView->setState(_dokkaebiState);
        }

        _timeSpent += dTime / 100;
        if (_timeSpent > M_PI * 300) {
            _timeSpent = 0;
        }

        _leftClubView->frame.y = 463 + sin(_timeSpent) * 10 + 10;
        _rightClubView->frame.y = 463 + sin(_timeSpent + M_PI) * 10 + 10;
    }
}
