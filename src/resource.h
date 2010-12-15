#ifndef RESOURCE_H_
#define RESOURCE_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "timerclass.h"
#include <iostream>
#include <string>

//screen attributes
extern const int SCREEN_HEIGHT;
extern const int SCREEN_WIDTH;
extern const int SCREEN_BPP;

//the gravity speed (note: not acceleration)
extern const int GRAV_SPEED;

//the frame rate
extern const int FRAMES_PER_SECOND;

//the surfaces
extern SDL_Surface *screen;
extern SDL_Surface *background;


//the global function declarations
extern bool init();
extern bool check_collision(SDL_Rect A, SDL_Rect B);
extern void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL);
extern SDL_Surface *load_image( std::string filename );
extern void clean_up();
extern bool load_files();

//the event structure
extern SDL_Event event;

//the block class that will make up the tetraminos
class Block
{
public:
    //the offsets
    SDL_Rect offsets;

    //the constructor
    Block();

    //the show function
    void show();
};

//the actual tetramino class
class Tetramino
{
public:
    //the constructor
    Tetramino();

    //the offsets
    SDL_Rect offsets;

    //the orientation
    int Orientation;

    //the blocks that will make up the tetramino
    Block blocks[4];

    //the current form
    int currForm;

    //a test
    int done;

    //the current rotation
    int rotation;

    //the velocities of the tetramino
    int xVel, yVel;

    //handles the input
    void handle_input();

    //controls the gravity
    void gravity();

    //moves the tetramino
    void move();

    //determines the tetraminos form
    void determine_form();

    //rotates the tetramino
    void rotate();

    //shows the tetramino
    void show();

    //befriends the block class
    friend class Block;
};

#endif //RESOURCE_H
