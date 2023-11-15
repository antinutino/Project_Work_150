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
void snakefood()
{
    cout<<"score:"<<score++<<endl;
    foodX = rand() % (780 /10 ) * 10;
    foodY = rand() % (580 / 10) * 10;
    if(dir==1)
    {
         v.push_back( make_pair(recx+10,recy) );
    }
    else if(dir==2)
    {
         v.push_back( make_pair(recx-10,recy) );
    }
    else if(dir==3)
    {
         v.push_back( make_pair(recx,recy+10) );
    }
    else if(dir==4)
    {
         v.push_back( make_pair(recx,recy-10) );
    }
}
void DrawRect(int x, int y) {
    SDL_Rect rect = { x, y, 10, 10};
    SDL_RenderFillRect(renderer, &rect);
}
void direction()
{
    if (event.type == SDL_KEYDOWN) 
                {switch (event.key.keysym.sym) 
                    {case SDLK_UP:
                          { if(dir==3)
                          continue;
                          else
                            {dir=4;
                          break;}}
                    case SDLK_DOWN:
                        { if(dir==4)
                        continue;
                        else
                        {dir=3;
                      
                        break;}
                        }
                    case SDLK_LEFT:
                     { if(dir==1)
                     continue;
                     else
                        {dir=2;
                    
                     break;}}
                    case SDLK_RIGHT:
                    { if(dir==2)
                    continue;
                    else
                        {dir=1;
                        break;}}

    } }
    }
    void Drawfood()
    {  
        int rad=10;
         while(rad--)
    for(int angle=0;angle<360;angle++)
    {
        int x=foodX+rad*cos(angle*M_PI/180);
         int y=foodY+rad*sin(angle*M_PI/180);
         SDL_RenderDrawPoint(renderer,x,y);}
    }

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
     else 
     direction();
    }
    snakefood();
     Drawfood();

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
