// on windows compile with: gcc main.c glad/src/glad.c -I./glad/include -o prog -lSDL2

#include <windows.h>
#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {

    SDL_Window *window=NULL;
    SDL_GLContext context;

    SDL_Init(SDL_INIT_VIDEO);

    // specify opengl version

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                           // window title
        100,                                        // where it opens ins the screen
        100,                   
        640,                                        // width, in pixels
        480,                                        // height, in pixels
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL        // flags - open_gl, etc
    );

    context = SDL_GL_CreateContext(window);

    // setup function pointers
    gladLoadGLLoader(SDL_GL_GetProcAddress);

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // Game loop
    bool gameIsRunning = true;
    //glViewport(0,0,640,480);

    while(gameIsRunning){
        //all events get stored here before the loop continues
        SDL_Event sdl_event;
        while(SDL_PollEvent(&sdl_event)){
            
            if (sdl_event.type == SDL_QUIT){
            gameIsRunning = false;
            }

            if (sdl_event.type == SDL_KEYDOWN){
                if (sdl_event.key.keysym.scancode == SDL_SCANCODE_DOWN){
                    printf("down");
                }
                if (sdl_event.key.keysym.scancode == SDL_SCANCODE_UP){
                    printf("up");
                }
                if (sdl_event.key.keysym.scancode == SDL_SCANCODE_LEFT){
                    printf("left");
                }
                if (sdl_event.key.keysym.scancode == SDL_SCANCODE_RIGHT){
                    printf("right");
                }

            }

        }

        glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);


    }
    // The window is open: could enter program loop here (see SDL_PollEvent())

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}