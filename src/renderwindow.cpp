#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

#include"renderwindow.hpp"

renderwindow::renderwindow(const char* p_title, int p_w, int p_h)
    :window(NULL), renderer(NULL)
{
    window=SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,p_w,p_h,
    SDL_WINDOW_SHOWN);
    if(window==NULL){
        std::cout<<"Window failed to init. Error: "<<SDL_GetError()<<std::endl;
    }
    renderer= SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}
SDL_Texture* renderwindow::loadTexture(const char* p_filePath){
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer,p_filePath);
    
    if(texture==NULL){
        std::cout<<"Failed to load texture, Error:"<<SDL_GetError()<<std::endl;
    }
    return texture;
}
void renderwindow::cleanup(){
    SDL_DestroyWindow(window);
}
void renderwindow::clear(){
    SDL_RenderClear(renderer);
}
void renderwindow::render(Entity& p_entity){
    SDL_Rect src;
    src.x=0;
    src.y=0;
    src.h=32;
    src.w=32;

    SDL_Rect dst;
    dst.x=p_entity.x;
    dst.y=00;
    dst.h=280;
    dst.w=720;      
    SDL_RenderCopy(renderer,p_tex,&src,&dst);
}
void renderwindow::display(){
    SDL_RenderPresent(renderer);
}