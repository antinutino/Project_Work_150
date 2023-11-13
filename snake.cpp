#include<bits/stdc++.h>
#include<math.h>
#include<SDL2/SDL.h>
using namespace std;
int foodX;
int foodY;
int direction=1;
int score=0;
int rectenglex=100;
int rectengley=100;
SDL_Window* window=SDL_CreateWindow("Snake Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN);
SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
int main(int argc,char* argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        cout<<"SDL_Init Error"<<endl;
        return 1;
    }

while(quit!=true)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)
{
    quit=true;
}
    }
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
     SDL_RenderClear(renderer);
     SDL_SetRenderDrawColor(renderer,10,100,200,255);
     SDL_Rect rect = { rectenglex, rectengley, 10, 10};
    SDL_RenderFillRect(renderer, &rect);
    renderpresent(renderer);

}
 SDL_DestroyRenderer(renderer);
 SDL_DestroyWindow(window);
 SDL_Quit();
 return 0;
 }
