#include "resource.h"

//screen attributes
const int SCREEN_HEIGHT = 500;
const int SCREEN_WIDTH = 400;
const int SCREEN_BPP = 32;

//the frame rate
const int FRAMES_PER_SECOND = 20;

//the surfaces
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;

//the gravity speed
const int GRAV_SPEED = 2;

//integer
int form = 0;

Tetramino myMino[50];
int counter = 0;

//the event structure
SDL_Event event;

