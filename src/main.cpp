#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

#include"renderwindow.hpp"
#include"Entity.hpp"

int main(int argc,char** argv){
    if(SDL_Init(SDL_INIT_VIDEO)>0){
        std::cout<<"Hey.. SDL_Init HAS FAILED. SDL_ERROR: "<<SDL_GetError()<<std::endl;
    }
    if(!(IMG_Init(IMG_INIT_PNG))){
        std::cout<<"IMG_init has failed. Errors:"<<SDL_GetError()<<std::endl;
    }
    renderwindow window("Minesweeper",1280,720);

    SDL_Texture * grid=window.loadTexture("./res/gfs/gif.gif");

    Entity platform(100,100,grid);
    bool gameRunning = true;
    SDL_Event event;
    while(gameRunning){
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT)
                gameRunning= false;
        }

        window.clear();
        window.render(grid);
        window.display();

    }
    window.cleanup();
    SDL_Quit();
    return 0;
}
