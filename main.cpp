#include "sdl_init.hpp"
#include "Ship.hpp"

static mySDL mysdl;
static SDL_Event e;
static plot_type sh_center {S_W/2, S_H/2};
static object_position ship_position = object_position::CENTER;

void draw(Drawable_ABC& object, int x, int y, object_position position);


int main(int argc, char* argv[])
{
    if(!init(mysdl, "Test")) return 1;
    bool quit = false;

    Ship hero(mysdl.gRenderer, "ships_2.png", sh_center);
    if(!hero.Status()) return 1;
    while(!quit)
    {
        while (SDL_PollEvent(&e) !=0)
        {
            if(e.type == SDL_QUIT) quit = true;
            else if(e.type == SDL_KEYDOWN)
            {
                switch(e.key.keysym.sym)
                {
                    case SDLK_UP:
                    std::cout << "UP" << '\n';
                    break;

                    case SDLK_DOWN:
                    std::cout << "DOWN" << '\n';
                    break;
                }
            }


        }
        SDL_SetRenderDrawColor(mysdl.gRenderer, 0x0, 0x0, 0x0, 0xFF);
        SDL_RenderClear(mysdl.gRenderer);
        //hero.draw_(hero.Center().x, hero.Center().y, ship_position);
        draw(hero, hero.Center().x, hero.Center().y, ship_position);

        SDL_RenderPresent(mysdl.gRenderer);
    }
    return 0;
}


void draw(Drawable_ABC& object, int x, int y, object_position position)
{
    object.draw_(x, y, position);
}