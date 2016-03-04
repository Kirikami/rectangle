//
//  cube.cpp
//  rectangle
//
//  Created by Ruslan Naumenko on 3/1/16.
//  Copyright © 2016 Ruslan Naumenko. All rights reserved.
//

#include <SDL2/SDl.h>
#include <SDL2/SDL_opengl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    
    SDL_Window* window = SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
    
    SDL_GLContext context = SDL_GL_CreateContext(window);
    
    float ratio = 800 / 600;
    
    float rotation = 0.f;
    
    int rotate_count = 0;
    
    SDL_Event windowEvent;
    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT) break;
        }
        
        // drar here
        
        glClear(GL_COLOR_BUFFER_BIT);
        
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        rotation += 1.f;
        if (rotation >= 360.0f) {
            rotation = 0.f;
            rotate_count++;
            printf("rotate_count: %d\n", rotate_count);
              int a = rand()%5;
            if (a == 3)
            {
                int b = a / 0;
                printf("Process finished with %d", b);
            }

        }

        glRotatef((float) rotation, 0.f, 0.f, 1.f);
        
        /* Calculate rataion count here */
        
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.f);
        glColor3f(0.f, 1.0f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.0f);
        glColor3f(0.f, 0.0f, 1.0f);
        glVertex3f(0.5f, 0.5f, 0.f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-0.5f, 0.5f, 0.f);
        glEnd();
        
        SDL_GL_SwapWindow(window);
    }
    
    SDL_GL_DeleteContext(context);
    
    SDL_Quit();
    
    return 0;
}

