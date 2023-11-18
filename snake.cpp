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
    if(direction==1)
    {
         v.push_back( make_pair(rectenglex+10,rectengley) );
    }
    else if(direction==2)
    {
         v.push_back( make_pair(rectenglex-10,rectengley) );
    }
    else if(direction==3)
    {
         v.push_back( make_pair(rectenglex,rectengley+10) );
    }
    else if(direction==4)
    {
         v.push_back( make_pair(rectenglex,rectengley-10) );
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
                    {
                        case SDLK_LEFT:
                     { if(direction==1)
                     continue;
                     else
                        {direction=2;
                    
                     break;}}
                    case SDLK_RIGHT:
                    { if(direction==2)
                    continue;
                    else
                        {direction=1;
                        break;}}
                        case SDLK_UP:
                          { if(direction==3)
                          continue;
                          else
                            {direction=4;
                          break;}}
                    case SDLK_DOWN:
                        { if(direction==4)
                        continue;
                        else
                        {direction=3;
                        break;}
                        }

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
    void foodcollision()
    {
         if(((foodX-rectenglex)<=20&&(foodX-rectenglex)>=0)&&((rectengley-foodY)>=0&&(rectengley-foodY)<=10))
   { snakefood();

   }
  else if(((foodX-rectenglex)<=20&&(foodX-rectenglex)>=0)&&((foodY-rectengley)>=0&&(foodY-rectengley)<=20))
   { snakefood();
   }
  else if(((rectenglex-foodX)<=10&&(rectenglex-foodX)>=0)&&((foodY-rectengley)>=0&&(foodY-rectengley)<=20))
   { snakefood();
   }
   else if(((foodX-rectenglex)<=10&&(foodX-rectenglex)>=0)&&((foodY-rectengley)>=0&&(foodY-rectengley)<=20))
   { snakefood();
   }
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
