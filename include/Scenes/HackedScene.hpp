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

#include <SDL2/SDL.h>

#include "BackgroundView.hpp"
#include "DokkaebiView.hpp"
#include "ImageView.hpp"
#include "Scene.hpp"

#pragma once

namespace DokkaebiHack::Scenes {
    class HackedScene : public DokkaebiHack::Scene {
        public:
            HackedScene();
            ~HackedScene();

            void buttonsDown(u32 buttons, double dTime);
            void render(SDL_Rect rect, double dTime);

        private:
            SDL_Texture * _leftClub = NULL;
            SDL_Texture * _rightClub = NULL;
            SDL_Texture * _text = NULL;

            DokkaebiHack::Views::BackgroundView * _backgroundView = NULL;
            DokkaebiHack::Views::DokkaebiView * _dokkaebiView = NULL;
            DokkaebiHack::Views::ImageView * _leftClubView = NULL;
            DokkaebiHack::Views::ImageView * _rightClubView = NULL;
            DokkaebiHack::Views::ImageView * _textView = NULL;

            double _timeSpent = 0;
            double _backgroundStateChangeCounter = 0;
            double _dokkaebiStateChangeCounter = 0;
            int _dokkaebiState = 0;
    };
}
