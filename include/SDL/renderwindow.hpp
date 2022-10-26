#pragma once
#include<SDL.h>
#include<SDL_image.h>
class renderwindow{
    public:
        renderwindow(const char* p_title, int p_w,int p_h);
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};