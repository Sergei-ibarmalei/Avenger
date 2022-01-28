#include "drawable.hpp"

Drawable_ABC::Drawable_ABC(SDL_Renderer* r, const string& file_name, const plot_type& c, bool media)
{
    lt = new Ltexture(r, file_name);
    if(!lt->get_Ltexture_status())
    {
        init = false;
        return;
    }
    //if(media) loadMedia();
    center = c;
}

Drawable_ABC::~Drawable_ABC()
{
    //delete lt;
    //lt = nullptr;
}