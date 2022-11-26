#pragma once
#include<SDL.h>
#include<SDL_image.h>

#include"Entity.hpp"

class renderwindow{
    public:
        renderwindow(const char* p_title, int p_w,int p_h);
        SDL_Texture* loadTexture(const char* p_filePath);
        void cleanup();
        void clear();
        void render(Entity& p_entity);
        void display();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};