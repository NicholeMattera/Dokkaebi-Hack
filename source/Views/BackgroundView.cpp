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

#include <SDL2/SDL_image.h>
#include <string>
#include <time.h>

#include "Application.hpp"
#include "BackgroundView.hpp"

using namespace std;

namespace DokkaebiHack::Views {
    BackgroundView::BackgroundView() {
        srand(time(NULL));
        
        SDL_Surface * surface;

        for (int i = 0; i < 5; i++) {
            string path = "romfs:/snow_" + to_string(i + 1) + ".png";
            surface = IMG_Load(path.c_str());
            _snow[i] = SDL_CreateTextureFromSurface(Application::renderer, surface);
            SDL_FreeSurface(surface);
        }

        surface = IMG_Load("romfs:/background.png");
        _cover = SDL_CreateTextureFromSurface(Application::renderer, surface);
        SDL_FreeSurface(surface);
    }

    BackgroundView::~BackgroundView() {
        for (int i = 0; i < 5; i++) {
            if (_snow[i] != NULL)
                SDL_DestroyTexture(_snow[i]);
        }

        if (_cover != NULL)
            SDL_DestroyTexture(_cover);
    }

    void BackgroundView::onRender(SDL_Rect rect, double dTime) {
        for (int x = 0; x <= 26; x++) {
            for (int y = 0; y <= 14; y++) {
                unsigned char snowType = _snowStates[y * 26 + x];
                if (snowType > 4) {
                    SDL_Rect snowRect = { x * 50, y * 50, 50, 50};
                    SDL_RenderCopy(Application::renderer, _snow[snowType - 4], NULL, &snowRect);
                } 
            }
        }

        SDL_RenderCopy(Application::renderer, _cover, NULL, &rect);
    }

    void BackgroundView::generate() {
        for (int i = 0; i < 390; i++) {
            _snowStates[i] = rand() % 10;
        }
        requiresRendering = true;
    }
}
