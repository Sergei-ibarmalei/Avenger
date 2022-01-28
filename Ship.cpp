#include "Ship.hpp"

Ship::Ship(SDL_Renderer* r, const string& file_name, const plot_type& c , bool media) : 
    Drawable_ABC(r, file_name, c, media)
    {
        if(media) loadMedia();
    }

Ship::~Ship()
{
    delete lt;
    lt = nullptr;
}

void Ship::loadMedia()
{
    gSprites[UPSHIP].x = 0;
    gSprites[UPSHIP].y = 0;
    gSprites[UPSHIP].w = lt->get_mTexture_w();
    gSprites[UPSHIP].h = 24;

    gSprites_half[UPSHIP].x = gSprites[UPSHIP].w / 2;
    gSprites_half[UPSHIP].y = gSprites[UPSHIP].h / 2;

    gSprites[CENTERSHIP].x = 0;
    gSprites[CENTERSHIP].y = 26;
    gSprites[CENTERSHIP].w = lt->get_mTexture_w();
    gSprites[CENTERSHIP].h = 28;

    gSprites_half[CENTERSHIP].x = gSprites[CENTERSHIP].w / 2;
    gSprites_half[CENTERSHIP].y = gSprites[CENTERSHIP].h / 2;

    gSprites[DOWNSHIP].x = 0;
    gSprites[DOWNSHIP].y = 57;
    gSprites[DOWNSHIP].w = lt->get_mTexture_w();
    gSprites[DOWNSHIP].h = 24;

    gSprites_half[DOWNSHIP].x = gSprites[DOWNSHIP].w / 2;
    gSprites_half[DOWNSHIP].y = gSprites[DOWNSHIP].h / 2;
}

void Ship::draw_(int x, int y, object_position position)
{
     switch (position)
    {
        case object_position::UP:
        {
            lt->render(x - gSprites_half[UPSHIP].x, y - gSprites_half[UPSHIP].y, &gSprites[UPSHIP]); break;
        }
        case object_position::CENTER:
        {
            lt->render(x - gSprites_half[CENTERSHIP].x, y - gSprites_half[CENTERSHIP].y, &gSprites[CENTERSHIP]); break;
        }
        case object_position::DOWN:
        {
            lt->render(x - gSprites_half[DOWNSHIP].x, y - gSprites_half[DOWNSHIP].y, &gSprites[DOWNSHIP]); break;
        }
        default: {}
    }   
}

void Ship::move(plot_type& ship_center, Move_direction direction)
{
    switch(direction)
    {
        case Move_direction::UP:
            if(check_ship_and_mainborder(*this, direction)) return;
            ship_center.y -= SHIP_SPEED; break;
        case Move_direction::DOWN:
            if(check_ship_and_mainborder(*this, direction)) return;
            ship_center.y += SHIP_SPEED; break;
        case Move_direction::LEFT:
            if(check_ship_and_mainborder(*this, direction)) return;
            ship_center.x -= SHIP_SPEED; break;
        case Move_direction::RIGHT:
            if(check_ship_and_mainborder(*this, direction)) return;
            ship_center.x += SHIP_SPEED; break;
        default: {}
    }
}

bool check_ship_and_mainborder(const Ship& hero, Move_direction direction)
{
    switch(direction)
    {
        case Move_direction::UP:
            if( (hero.center.y - hero.gSprites_half[UPSHIP].y - SHIP_SPEED) < UP_BORDER ) return true; break;
        case Move_direction::DOWN:
            if( (hero.center.y + hero.gSprites_half[DOWNSHIP].y +  SHIP_SPEED) > DOWN_BORDER ) return  true; break;
        case Move_direction::LEFT:
            if( (hero.center.x - hero.gSprites_half[CENTERSHIP].x -  SHIP_SPEED) < LEFT_BORDER) return true; break;
        case Move_direction::RIGHT:
            if( (hero.center.x + hero.gSprites_half[CENTERSHIP].x +  SHIP_SPEED) > RIGHT_BORDER) return true; break;
        default: {}
    }
    return false;
}