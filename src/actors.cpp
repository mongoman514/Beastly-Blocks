#include "resource.h"


//block functions
Block::Block()
{
    offsets.x = 0;
    offsets.y = 0;
    offsets.w = 25;
    offsets.h = 25;
}

void Block::show()
{
            SDL_FillRect( screen, &offsets, SDL_MapRGB( screen->format, 0x77, 0x77, 0x77 ) );
}


//tetramino functions
Tetramino::Tetramino()
{
    //initialize everything to 0
    xVel = 0;
    yVel = 0;
    currForm = 1;
    prevForm = 0;

    //init block stuff
    blocks[0].offsets.x = 175;    
    blocks[0].offsets.y = -20;
    blocks[1].offsets.x = 200;
    blocks[1].offsets.y = -20;
    blocks[2].offsets.x = 225;
    blocks[2].offsets.y = -20;
    blocks[3].offsets.x = 250;
    blocks[3].offsets.y = -20;
}

void Tetramino::handle_input()
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //
        if (event.key.keysym.sym == SDLK_LEFT)
	{
	    currForm++;
	}
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
	if (event.key.keysym.sym == SDLK_LEFT)
	{
	    
	}
    }
}

//determines the current form
void Tetramino::determine_form()
{
    if(currForm == 0)
    {
	blocks[0].offsets.x = 175;    
	blocks[0].offsets.y = -20;
	blocks[1].offsets.x = 200;
	blocks[1].offsets.y = -20;
	blocks[2].offsets.x = 225;
	blocks[2].offsets.y = -20;
	blocks[3].offsets.x = 250;
	blocks[3].offsets.y = -20;
    }
    if(currForm == 1)
    {
	blocks[0].offsets.x = 175;
	blocks[0].offsets.y = 0;
	blocks[1].offsets.x = 200;
	blocks[1].offsets.y = 0;
	blocks[2].offsets.x = 225;
	blocks[2].offsets.y = 0;
	blocks[3].offsets.x = 225;
	blocks[3].offsets.y = 25;
    }

    std::cout << "Form has been determined" << std::endl;
}

void Tetramino::gravity()
{
    yVel = GRAV_SPEED;

    std::cout << "Gravity has been controlled" << std::endl;
}

void Tetramino::move()
{
    blocks[0].offsets.y += yVel;
    blocks[1].offsets.y += yVel;
    blocks[2].offsets.y += yVel;
    blocks[3].offsets.y += yVel;

    std::cout << "Tetramino has been moved" << std::endl;
}

void Tetramino::show()
{
    blocks[0].show();
    blocks[1].show();
    blocks[2].show();
    blocks[3].show();

    std::cout << "Tetramino has been shown" << std::endl;
}
