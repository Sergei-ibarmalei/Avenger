#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "Ltexture.hpp"
#include "consts.hpp"

class Drawable_ABC
{
    protected:
    Ltexture* lt;
    plot_type center;
    bool init = true;
    //virtual void loadMedia();

    public:
    Drawable_ABC(SDL_Renderer* r, const string& file_name, const plot_type& c, bool media = true);
    virtual ~Drawable_ABC();
    plot_type& Center() {return center;}
    virtual void move(plot_type& center, Move_direction direction) = 0;
    virtual void draw_(int x, int y, object_position position) = 0;
    bool Status() {return init;}
    virtual void loadMedia() = 0;


};







#endif