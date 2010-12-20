#include "resource.h"

int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    //tetramino
    //Tetramino myMino[50];

    //form
    int form = 0;

    //integer
    //int counter = 0;
    counter = 0;

    //The frame rate regulator
    Timer fps;

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
        if( SDL_PollEvent( &event ) )
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
	myMino[counter].determine_form();
	myMino[counter].gravity();
	myMino[counter].handle_input();
	myMino[counter].move();
	myMino[counter].show();

	if(myMino[counter].alive == false)
	{
	   counter++;
	   form++;
	   myMino[counter].currForm = form;
	   if (form >= 4)
	   {
	      form = 0;
	   }
	   myMino[counter].done = false;
	}

	//show all tetraminos
	myMino[0].show();
	myMino[1].show();
	myMino[2].show();
	myMino[3].show();
	myMino[4].show();
	myMino[5].show();
	myMino[6].show();
	myMino[7].show();
	myMino[8].show();
	myMino[9].show();
	myMino[10].show();
	myMino[11].show();
	myMino[12].show();
	myMino[13].show();
	myMino[14].show();
	myMino[15].show();
	myMino[16].show();
	myMino[17].show();
	myMino[18].show();
	myMino[19].show();
	myMino[20].show();
	myMino[21].show();
	myMino[22].show();
	myMino[23].show();
	myMino[24].show();
	myMino[25].show();
	myMino[26].show();
	myMino[27].show();
	myMino[28].show();
	myMino[29].show();
	myMino[30].show();
	myMino[31].show();
	myMino[32].show();
	myMino[33].show();
	myMino[34].show();
	myMino[35].show();
	myMino[36].show();
	myMino[37].show();
	myMino[38].show();
	myMino[39].show();
	myMino[40].show();
	myMino[41].show();
	myMino[42].show();
	myMino[43].show();
	myMino[44].show();
	myMino[45].show();
	myMino[46].show();
	myMino[47].show();
	myMino[48].show();
	myMino[49].show();

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
