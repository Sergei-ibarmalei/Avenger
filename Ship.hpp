#ifndef SHIP_HPP
#define SHIP_HPP

#include "drawable.hpp"


class Ship:public Drawable_ABC
{
    protected:
    SDL_Rect gSprites[3];
    plot_type gSprites_half[3];
    //void loadMedia();

    public:
    Ship(SDL_Renderer* r, const string& file_name, const plot_type& c, bool media = true);
    ~Ship();
    void draw_(int x, int y, object_position position);
    void move(plot_type& center, Move_direction direction);
    friend bool check_ship_and_mainborder(const Ship& hero, Move_direction direction);
    void loadMedia();

};

#endif