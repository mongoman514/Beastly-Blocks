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
    currForm = 0;
    rotation = 0;
    done = 4;
}

void Tetramino::handle_input()
{
    //If a key was pressed
    if( event.type == SDL_MOUSEBUTTONDOWN)
    {
	rotate();
	rotation++;
	if(rotation > 3)
	{
	    rotation = 0;
	}
    }
    if(event.type == SDL_KEYDOWN)
    {
	if(event.key.keysym.sym == SDLK_LEFT)
	{
	    xVel = -15;
	}
	if(event.key.keysym.sym == SDLK_RIGHT)
	{
	    xVel = 15;
	}
    }
    if(event.type == SDL_KEYUP)
    {
	if(event.key.keysym.sym == SDLK_LEFT)
	{
	    xVel = 0;
	}
	if(event.key.keysym.sym == SDLK_RIGHT)
	{
	    xVel = 0;
	}
    }
}

//determines the current form
void Tetramino::determine_form()
{

    currForm = 0;

    if(done == 4)
    {
        if(currForm == 0)
        {
	    blocks[0].offsets.x = 175;    
	    blocks[0].offsets.y = 0;
	    blocks[1].offsets.x = 200;
	    blocks[1].offsets.y = 0;
	    blocks[2].offsets.x = 225;
	    blocks[2].offsets.y = 0;
	    blocks[3].offsets.x = 250;
	    blocks[3].offsets.y = 0;
	    done = 1;
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
	    done = 1;
        }
        if(currForm == 2)
        {
	    blocks[0].offsets.x = 175;
	    blocks[0].offsets.y = 0;
	    blocks[1].offsets.x = 200;
	    blocks[1].offsets.y = 0;
	    blocks[2].offsets.x = 175;
	    blocks[2].offsets.y = 25;
	    blocks[3].offsets.x = 200;
	    blocks[3].offsets.y = 25;
	    done = 1;
        }
    }
}

void Tetramino::rotate()
{
    if(currForm == 0)
    {
	if(rotation == 0) 
	{
	    blocks[1].offsets.x = blocks[0].offsets.x + 25;
	    blocks[1].offsets.y = blocks[0].offsets.y;
	    blocks[2].offsets.x = blocks[1].offsets.x + 25;
	    blocks[2].offsets.y = blocks[0].offsets.y;
	    blocks[3].offsets.x = blocks[2].offsets.x + 25;
	    blocks[3].offsets.y = blocks[0].offsets.y;

	    //reset width/height
	    blocks[0].offsets.w = 25;
	    blocks[0].offsets.h = 25;
	    blocks[1].offsets.w = 25;
	    blocks[1].offsets.h = 25;
	    blocks[2].offsets.w = 25;
	    blocks[2].offsets.h = 25;
	    blocks[3].offsets.w = 25;
	    blocks[3].offsets.h = 25;
	}
	if(rotation == 1)
	{
	    blocks[1].offsets.x = blocks[0].offsets.x;
	    blocks[1].offsets.y = blocks[0].offsets.y + 25;
	    blocks[2].offsets.x = blocks[1].offsets.x;
	    blocks[2].offsets.y = blocks[1].offsets.y + 25;
	    blocks[3].offsets.x = blocks[2].offsets.x;
	    blocks[3].offsets.y = blocks[2].offsets.y + 25;

	    //reset width/height
	    blocks[0].offsets.w = 25;
	    blocks[0].offsets.h = 25;
	    blocks[1].offsets.w = 25;
	    blocks[1].offsets.h = 25;
	    blocks[2].offsets.w = 25;
	    blocks[2].offsets.h = 25;
	    blocks[3].offsets.w = 25;
	    blocks[3].offsets.h = 25;
	}
	if(rotation == 2)
	{
	    blocks[1].offsets.x = blocks[0].offsets.x - 25;
	    blocks[1].offsets.y = blocks[0].offsets.y;
	    blocks[2].offsets.x = blocks[1].offsets.x - 25;
	    blocks[2].offsets.y = blocks[0].offsets.y;
	    blocks[3].offsets.x = blocks[2].offsets.x - 25;
	    blocks[3].offsets.y = blocks[0].offsets.y;

	    //reset width/height
	    blocks[0].offsets.w = 25;
	    blocks[0].offsets.h = 25;
	    blocks[1].offsets.w = 25;
	    blocks[1].offsets.h = 25;
	    blocks[2].offsets.w = 25;
	    blocks[2].offsets.h = 25;
	    blocks[3].offsets.w = 25;
	    blocks[3].offsets.h = 25;
	}
	if(rotation == 3)
	{
	    blocks[1].offsets.x = blocks[0].offsets.x;
	    blocks[1].offsets.y = blocks[0].offsets.y - 25;
	    blocks[2].offsets.x = blocks[1].offsets.x;
	    blocks[2].offsets.y = blocks[1].offsets.y - 25;
	    blocks[3].offsets.x = blocks[2].offsets.x;
	    blocks[3].offsets.y = blocks[2].offsets.y - 25;

	    //reset width/height
	    blocks[0].offsets.w = 25;
	    blocks[0].offsets.h = 25;
	    blocks[1].offsets.w = 25;
	    blocks[1].offsets.h = 25;
	    blocks[2].offsets.w = 25;
	    blocks[2].offsets.h = 25;
	    blocks[3].offsets.w = 25;
	    blocks[3].offsets.h = 25;
	}
    }
}

void Tetramino::gravity()
{
    yVel = 1;
}

void Tetramino::move()
{
    //if(rotation == 0)
    //{
        //move block 1
        blocks[0].offsets.y += yVel;
        blocks[0].offsets.x += xVel;
        if(blocks[0].offsets.y < 0 || blocks[0].offsets.y + 25 > SCREEN_HEIGHT)
	{
	    blocks[0].offsets.y -= yVel;
	    blocks[1].offsets.y -= yVel;
	    blocks[2].offsets.y -= yVel;
	    blocks[3].offsets.y -= yVel;
	}
	if(blocks[0].offsets.x < 0 || blocks[0].offsets.x + 25 > SCREEN_WIDTH)
        {
	    blocks[0].offsets.x -= xVel;
	    blocks[1].offsets.x -= xVel;
	    blocks[2].offsets.x -= xVel;
	    blocks[3].offsets.x -= xVel;
	}

        //move block 2
        blocks[1].offsets.y += yVel;
        blocks[1].offsets.x += xVel;
        if(blocks[1].offsets.y < 0 || blocks[1].offsets.y + 25 > SCREEN_HEIGHT)
	{
	    blocks[0].offsets.y -= yVel;
	    blocks[1].offsets.y -= yVel;
	    blocks[2].offsets.y -= yVel;
	    blocks[3].offsets.y -= yVel;
	}
	if(blocks[1].offsets.x < 0 || blocks[1].offsets.x + 25 > SCREEN_WIDTH)
        {
	    blocks[0].offsets.x -= xVel;
	    blocks[1].offsets.x -= xVel;
	    blocks[2].offsets.x -= xVel;
	    blocks[3].offsets.x -= xVel;
	}

        //move block 3
        blocks[2].offsets.y += yVel;
        blocks[2].offsets.x += xVel;
        if(blocks[2].offsets.y < 0 || blocks[2].offsets.y + 25 > SCREEN_HEIGHT)
	{
	    blocks[0].offsets.y -= yVel;
	    blocks[1].offsets.y -= yVel;
	    blocks[2].offsets.y -= yVel;
	    blocks[3].offsets.y -= yVel;
	}
	if(blocks[2].offsets.x < 0 || blocks[2].offsets.x + 25 > SCREEN_WIDTH)
        {
	    blocks[0].offsets.x -= xVel;
	    blocks[1].offsets.x -= xVel;
	    blocks[2].offsets.x -= xVel;
	    blocks[3].offsets.x -= xVel;
	}

        //move block 4
        blocks[3].offsets.y += yVel;
        blocks[3].offsets.x += xVel;
	if(blocks[3].offsets.y < 0 || blocks[3].offsets.y + 25 > SCREEN_HEIGHT)
	{
	    blocks[0].offsets.y -= yVel;
	    blocks[1].offsets.y -= yVel;
	    blocks[2].offsets.y -= yVel;
	    blocks[3].offsets.y -= yVel;
	}
	if(blocks[3].offsets.x < 0 || blocks[3].offsets.x + 25 > SCREEN_WIDTH)
        {
	    blocks[0].offsets.x -= xVel;
	    blocks[1].offsets.x -= xVel;
	    blocks[2].offsets.x -= xVel;
	    blocks[3].offsets.x -= xVel;
	}
	
    //}

    /*the 2nd rotation
    if(rotation == 1)
    {
        //move block 1
        blocks[0].offsets.y += yVel;
        blocks[0].offsets.x += xVel;
        if(blocks[0].offsets.y < 0 || blocks[0].offsets.y + 25 > SCREEN_HEIGHT)
        {
	    blocks[0].offsets.y -= yVel;
        }
        if(blocks[0].offsets.x < 0 || blocks[0].offsets.x + 25 > SCREEN_WIDTH)
        {
	    blocks[0].offsets.x -= xVel;
        }

        //move block 2
        blocks[1].offsets.y += yVel;
        blocks[1].offsets.x += xVel;
        if(blocks[1].offsets.y < 0 || blocks[1].offsets.y + 25 > SCREEN_HEIGHT)
        {
	    blocks[1].offsets.y -= yVel;
        }
        if(blocks[1].offsets.x < 0 || blocks[1].offsets.x + 25 > SCREEN_WIDTH)
        {
	    blocks[1].offsets.x -= xVel;
        }

        //move block 3
        blocks[2].offsets.y += yVel;
        blocks[2].offsets.x += xVel;
        if(blocks[2].offsets.y < 0 || blocks[2].offsets.y + 25 > SCREEN_HEIGHT)
        {
	    blocks[2].offsets.y -= yVel;
        }
        if(blocks[2].offsets.x < 0 || blocks[2].offsets.x + 25 > SCREEN_WIDTH)
        {
	    blocks[2].offsets.x -= xVel;
        }

        //move block 4
        blocks[3].offsets.y += yVel;
        blocks[3].offsets.x += xVel;
        if(blocks[3].offsets.y < 0 || blocks[3].offsets.y + 25 > SCREEN_HEIGHT)
        {
	    blocks[3].offsets.y -= yVel;
        }
        if(blocks[3].offsets.x < 0 || blocks[3].offsets.x + 25 > SCREEN_WIDTH)
        {
	    blocks[3].offsets.x -= xVel;
        }
    }*/
}

void Tetramino::show()
{
    blocks[0].show();
    blocks[1].show();
    blocks[2].show();
    blocks[3].show();
}
