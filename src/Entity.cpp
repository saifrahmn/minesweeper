#include"Entity.hpp"
Entity::Entity(float p_x,float p_y,SDL_Texture* p_tex):x(p_x),y(p_y), tex(p_tex){
    currentframe.x=0;
    currentframe.y=0;
    currentframe.w=32;
    currentframe.h=32;
}
float Entity::getX(){
    return x;
}
float Entity::getY(){
    return y;
}