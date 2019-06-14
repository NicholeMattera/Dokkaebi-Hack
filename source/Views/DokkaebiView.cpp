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

#include "Application.hpp"
#include "DokkaebiView.hpp"

using namespace std;

namespace DokkaebiHack::Views {
    DokkaebiView::DokkaebiView() {
        clipsToBounds = false;
        
        SDL_Surface * surface;

        for (int i = 0; i < 3; i++) {
            string path = "romfs:/dokkaebi_" + to_string(i + 1) + ".png";
            surface = IMG_Load(path.c_str());
            _dokkaebi[i] = SDL_CreateTextureFromSurface(Application::renderer, surface);
            SDL_FreeSurface(surface);
        }
    }

    DokkaebiView::~DokkaebiView() {
        for (int i = 0; i < 3; i++) {
            if (_dokkaebi[i] != NULL)
                SDL_DestroyTexture(_dokkaebi[i]);
        }
    }

    void DokkaebiView::onRender(SDL_Rect rect, double dTime) {
        switch(_state) {
            case 0:
                rect.w = 348;
                rect.h = 240;
                break;

            case 1:
                rect.x += 6;
                rect.y += 10;
                rect.w = 335;
                rect.h = 240;
                break;

            case 2:
                rect.x += 6;
                rect.y += 20;
                rect.w = 335;
                rect.h = 249;
                break;
        }
        SDL_RenderCopy(Application::renderer, _dokkaebi[_state], NULL, &rect);
    }

    void DokkaebiView::setState(int state) {
        if (state != _state) {
            _state = state;
            requiresRendering = true;
        }
    }
}