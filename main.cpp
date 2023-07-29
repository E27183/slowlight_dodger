#include <SDL2/SDL.h> 
#include <iostream>
#include "constants.h"

void handle_event() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
                break;

            default:
                break;
        };
    };
};

struct object {
    float x;
    float y;
    float z;
    float azimuth;
    float inclination;
    float velocity;
};

struct movement_charcteristics {
    float azimuth;
    float inclination;
    float velocity;
};

class gameState {
    public:
        float player_x;
        float player_y;
        float player_z;
        void render(SDL_Renderer* renderer) {
            //Not implemented
        };
    float player_direction_azimuth;
    float player_direction_inclination;
    float player_velocity;
    object objects[256];
};

int main(int argc, char *argv[]) {  
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {  
                printf("error initializing SDL: %s\n", SDL_GetError());  
    };
    SDL_DisplayMode DisplayMode;
    SDL_GetCurrentDisplayMode(0, &DisplayMode);
    SDL_Window* window = SDL_CreateWindow("Slowlight",  
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        DisplayMode.w, DisplayMode.h, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); 

    while (1) {
        SDL_Delay(100);
    };

    return 0;  
};