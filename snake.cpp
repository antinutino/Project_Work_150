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
vector<pair<int,int>>snakebody;
vector<pair<int,int>>snakebody1;
SDL_Event event;
SDL_Window* window=SDL_CreateWindow("Snake Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN);
SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
bool quit=false;
void foodpos()
{
    cout<<"score:"<<score++<<endl;
    foodX = rand() % (780 /10 ) * 10;
    foodY = rand() % (580 / 10) * 10;
    if(direction==1)
    {
         snakebody.push_back( make_pair(rectenglex+10,rectengley) );
    }
    else if(direction==2)
    {
         snakebody.push_back( make_pair(rectenglex-10,rectengley) );
    }
    else if(direction==3)
    {
         snakebody.push_back( make_pair(rectenglex,rectengley+10) );
    }
    else if(direction==4)
    {
         snakebody.push_back( make_pair(rectenglex,rectengley-10) );
    }
}
void DrawRect(int x, int y) {
    SDL_Rect rect = { x, y, 10, 10};
    SDL_RenderFillRect(renderer, &rect);
}
void nextdirection()
{ 
        switch (event.key.keysym.sym) 
                    {
                        case SDLK_LEFT:
                     { if(direction!=1)
                       direction=2;
                     break;}
                    case SDLK_RIGHT:
                    { if(direction!=2)
                      direction=1;
                        break;}
                        case SDLK_UP:
                          { if(direction!=3)
                          direction=4;
                          break;}
                    case SDLK_DOWN:
                        { if(direction!=4)
                        direction=3;
                        break;}

    } }
    void Drawfood()
    {  
        int radius=10;
         while(radius--)
    for(int angle=0;angle<360;angle++)
    {
        int x=foodX+radius*cos(angle*M_PI/180);
         int y=foodY+radius*sin(angle*M_PI/180);
         SDL_RenderDrawPoint(renderer,x,y);}
    }
    void foodcollision()
    {
         if(((foodX-rectenglex)<=20&&(foodX-rectenglex)>=0)&&((rectengley-foodY)>=0&&(rectengley-foodY)<=10))
         foodpos();
  else if(((foodX-rectenglex)<=20&&(foodX-rectenglex)>=0)&&((foodY-rectengley)>=0&&(foodY-rectengley)<=20))
         foodpos();
  else if(((rectenglex-foodX)<=10&&(rectenglex-foodX)>=0)&&((foodY-rectengley)>=0&&(foodY-rectengley)<=20))
        foodpos();
   else if(((foodX-rectenglex)<=10&&(foodX-rectenglex)>=0)&&((foodY-rectengley)>=0&&(foodY-rectengley)<=20))
        foodpos();
    }
 void snakehead()
    {
       if(direction==1)
   { rectenglex+=10;
   if(rectenglex==800)
   rectenglex=10;}
   else if(direction==2)
   { rectenglex-=10;
   if(rectenglex==0)
   rectenglex=790;}
   else if(direction==3)
   { rectengley+=10;
   if(rectengley==600)
   rectengley=10;}
   else if(direction==4)
   { rectengley-=10;
   if(rectengley==0)
   rectengley=590;}
    }
  void movebody()
  /*void snakecollision()
     {
        for(int i=0;i<snakebody.size()-2;i++)
          {
               if(snakebody[i].first==rectenglex&&snakebody[i].second==rectengley)
               {  SDL_SetRenderDrawColor(renderer,50,100,50,255);
                        SDL_RenderClear(renderer);
                 SDL_RenderPresent(renderer);
                     SDL_Delay(2000);
                cout<<"GAME IS OVER"<<endl;
                quit=true;
                  break;
               }
          }

     }*/
  {   snakehead();
    snakebody1=snakebody;
    snakebody[snakebody.size()-1].first=rectenglex;
    snakebody[snakebody.size()-1].second=rectengley;
    DrawRect(snakebody[snakebody.size()-1].first,snakebody1[snakebody.size()-1].second);
    for(int i=snakebody.size()-1;i>0;i--)
    { snakebody[i-1]=snakebody1[i];
        DrawRect(snakebody[i].first,snakebody[i].second);
    }

  }
int main(int argc,char* argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        cout<<"SDL_Init Error"<<endl;
        return 1;
    }
 snakebody.push_back( make_pair(rectenglex,rectengley) );
 snakebody.push_back( make_pair(rectenglex+10,rectengley) );
 rectenglex+=10;
 foodpos();
while(quit!=true)
{
    while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)
{
    quit=true;
}
     else if(event.type == SDL_KEYDOWN) 
     nextdirection();
    }
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,10,100,200,255);
    Drawfood();
    foodcollision();
    movebody();
    //snakecollision();
         SDL_RenderPresent(renderer);
          if(score<=10)
          SDL_Delay(5000);
           else if(score>10&&score<=20)
          SDL_Delay(60);
       else if(score>20&&score<=30)
          SDL_Delay(50);
          else if(score>30&&score<=40)
          SDL_Delay(40);
          else
          SDL_Delay(30); 
}
 SDL_DestroyRenderer(renderer);
 SDL_DestroyWindow(window);
 SDL_Quit();
 return 0;
 }
