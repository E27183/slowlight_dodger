#include <SDL2/SDL.h> 
#include <iostream>
#include "constants.h"

void handle_event(gameState *state) {
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

struct point {
    float x;
    float y;
    float z;
};

struct object {
    point points[16];
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
        bool accelerating;
        void render(SDL_Renderer* renderer) {
            //Not implemented
        };
        void update(float delay) {
            //Not implemented
        };
        void initialise() {
            this->player_x = 0;
            this->player_y = 0;
            this->player_z = 0;
            this->player_direction_azimuth = 0;
            this->player_direction_inclination = 0;
            this->player_velocity = 0;
            this->object_count = 0;
            this->accelerating = false;
        };
    float player_direction_azimuth;
    float player_direction_inclination;
    float player_velocity;
    object objects[scenario_max_objects];
    int object_count;
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
    gameState state;
    state.initialise();
    while (1) {
        handle_event(&state);
        state.update(millisecond_frame_delay);
        state.render(renderer);
        SDL_Delay(millisecond_frame_delay);
    };

    return 0;  
};