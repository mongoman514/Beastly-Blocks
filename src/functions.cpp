#include "resource.h"

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool check_collision( SDL_Rect A, SDL_Rect B )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;
        
    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;
    
    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }
    
    if( topA >= bottomB )
    {
        return false;
    }
    
    if( rightA <= leftB )
    {
        return false;
    }
    
    if( leftA >= rightB )
    {
        return false;
    }
    
    //If none of the sides from A are outside B
    return true;
}

bool check_tet_collision(Tetramino A, Tetramino B)
{
    if(check_collision(A.blocks[0].offsets, B.blocks[0].offsets) == true)
    {
	return true;
    }
    if(check_collision(A.blocks[1].offsets, B.blocks[1].offsets) == true)
    {
	return true;
    }
    if(check_collision(A.blocks[2].offsets, B.blocks[2].offsets) == true)
    {
	return true;
    }
    if(check_collision(A.blocks[3].offsets, B.blocks[3].offsets) == true)
    {
	return true;
    }
    return false;
}

void clean_up()
{
    SDL_Quit();
}

SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0xFF, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

bool load_files()
{
    //Load the dot image
    background = load_image("background.png");

    //If there was a problem in loading the background
    if( background == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

bool init()
{
    //initialize all sdl subsystems
    SDL_Init(SDL_INIT_EVERYTHING);

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if(screen == NULL)
    {
        return false;
    }
    SDL_WM_SetCaption("Beastly Blocks", NULL);
}

