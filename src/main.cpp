#include "resource.h"

int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    //The frame rate regulator
    Timer fps;

    Tetramino myMino;

    //Initialize
    if( init() == false )
    {
        return 1;
    }
    if(load_files() == false)
    {
	return 1;
    }

    //While the user hasn't quit
    while( quit == false )
    {
        //Start the frame timer
        fps.start();

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

	//Show background
	apply_surface(0, 0, background, screen);

	//tetramino stuff
	myMino.determine_form();
	myMino.gravity();
	myMino.handle_input();
	myMino.move();
	myMino.show();

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }

    //Clean up
    clean_up();

    return 0;
}
