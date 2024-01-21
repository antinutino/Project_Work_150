#include<bits/stdc++.h>
#include<math.h>
#include<SDL2/SDL.h>
//#include "include/SDL_ttf.h"
using namespace std;
int foodX;
int foodY;
int bonusfoodx;
int bonusfoody;
int border=40;
int pathweidth=40;
int screenheight=600;
int screenweidth=800;
int direction=1;
int score=0;
int foodcol1=30;
int foodcol2=10;
int puse=0;
bool quit1=false;
int rectenglex=100;
int rectengley=100;
int foodred=252;
int foodgreen=194;
int foodblue=0;
int snakered=245;
int snakegreen=222;
int snakeblue=180;
vector<pair<int,int>>snakebody;
vector<pair<int,int>>snakebody1;
vector<pair<int,int>>foodposition;
map<pair<int,int>,int>mp;
SDL_Event event;
SDL_Window* window=SDL_CreateWindow("Snake Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN);
SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
bool quit=false;
void snakecordinate()
{
   for(int i=0;i<=600;i+=10)
    {mp[{20,i}]=1;mp[{10,i}]=1;mp[{0,i}]=1;}
     for(int i=0;i<=600;i+=10)
    {mp[{760, i}]=1;mp[{780,i}]=1;mp[{770,i}]=1;}
   for(int i=0;i<=800;i+=10)
   {mp[{i,0}]=1;mp[{i,20}]=1;mp[{i,10}]=1;}
    for(int i=0;i<=800;i+=10)
    {mp[{i, 560}]=1;mp[{i,580}]=1;mp[{i,570}]=1;}
     mp[{30,100}]=1;mp[{30,110}]=1;mp[{30,120}]=1;
     mp[{30,400}]=1;mp[{30,410}]=1;mp[{30,420}]=1;

     mp[{30,100}]=1;mp[{30,110}]=1;mp[{30,120}]=1;
    mp[{300,30}]=1;mp[{310,30}]=1;mp[{320,30}]=1;
    mp[{400,30}]=1;mp[{410,30}]=1;mp[{420,30}]=1;
}
void foodcordinatex(int x,int n,int y)
{
    for(int i=x;i<=n;i++)
    foodposition.push_back( make_pair(i,y) );
    for(int i=x-5;i<=n+5;i+=10)
    {mp[{i, y}]=1;mp[{i, y-10}]=1;mp[{i,y-20}]=1;}

}
void foodcordinatey(int y,int n,int x)
{
    for(int i=y;i<=n;i++)
    foodposition.push_back( make_pair(x,i) );
    for(int i=y-5;i<=n+5;i+=10)
    {mp[{x, i}]=1;mp[{x-10, i}]=1;mp[{x-20,i}]=1;}
}
void pathset()
{ int x=0,y=0;
   SDL_Rect rect = { x, y, border,screenheight};
    SDL_RenderFillRect(renderer, &rect);
     rect = { x, y, screenweidth,border};
    SDL_RenderFillRect(renderer, &rect);
    y=560;
     rect = { x, y,screenweidth,border};
    SDL_RenderFillRect(renderer, &rect);
    x=760;y=0;
     rect = { x, y, border, screenheight};
    SDL_RenderFillRect(renderer, &rect);
    x=0;y=100;
     rect = { x, y,300, pathweidth};
    SDL_RenderFillRect(renderer, &rect);
    x=0;y=400;
     rect = { x, y,600, pathweidth};
    SDL_RenderFillRect(renderer, &rect);
    x=200;y=100;
     rect = { x, y, pathweidth,300};
    SDL_RenderFillRect(renderer, &rect);
    
    x=100;y=300;
     rect = { x, y,100, pathweidth};
    SDL_RenderFillRect(renderer, &rect);
    
    x=100;y=140;
     rect = { x, y, pathweidth,160};
    SDL_RenderFillRect(renderer, &rect);
    
    x=320;y=440;//
     rect = { x, y, pathweidth,40};
    SDL_RenderFillRect(renderer, &rect);
    
    x=200;y=200;
     rect = { x, y,200, pathweidth};
    SDL_RenderFillRect(renderer, &rect);
   
    x=400;y=0;
     rect = { x, y, pathweidth,440};
    SDL_RenderFillRect(renderer, &rect);
    
    x=300;y=0;
     rect = { x, y, pathweidth,140};
    SDL_RenderFillRect(renderer, &rect);
    
    x=140;y=480;
     rect = { x, y,220, pathweidth};
    SDL_RenderFillRect(renderer, &rect);
    
    x=140;y=480;
     rect = { x, y, pathweidth,100};
    SDL_RenderFillRect(renderer, &rect);
     x=600;y=400;
     rect = { x, y, pathweidth,200};
    SDL_RenderFillRect(renderer, &rect);
    x=400;y=100;
     rect = { x, y,150, pathweidth};
    SDL_RenderFillRect(renderer, &rect);
    x=400;y=300;
     rect = { x, y,150, pathweidth};
    SDL_RenderFillRect(renderer, &rect);
    x=550;y=100;
     rect = { x, y, pathweidth,240};
    SDL_RenderFillRect(renderer, &rect);

    x=550;y=200;
     rect = { x, y,150, pathweidth};
    SDL_RenderFillRect(renderer, &rect);

    x=660;y=100;//
     rect = { x, y,pathweidth,240};
    SDL_RenderFillRect(renderer, &rect);

    x=660;y=100;
     rect = { x, y,100, pathweidth};
    SDL_RenderFillRect(renderer, &rect);
    x=660;y=340;
     rect = { x, y,100, pathweidth};
    SDL_RenderFillRect(renderer, &rect);

    x=600;y=450;
     rect = { x, y,200, pathweidth};
    SDL_RenderFillRect(renderer, &rect);

    x=350;y=480;
     rect = { x, y,150,pathweidth};
    SDL_RenderFillRect(renderer, &rect);

    x=500;y=400;
     rect = { x, y, pathweidth,120};
    SDL_RenderFillRect(renderer, &rect);

x=300;y=200;
     rect = { x, y, pathweidth,100};
    SDL_RenderFillRect(renderer, &rect);

    x=200;y=300;
     rect = { x, y,140, pathweidth};
    SDL_RenderFillRect(renderer, &rect);

  x=550;y=300;
     rect = { x, y,150, pathweidth};
    SDL_RenderFillRect(renderer, &rect);

}
/*void bonusfooddraw()
{
    SDL_SetRenderDrawColor(renderer,200,20,20,0);
         while(radius--)
    for(int angle=0;angle<360;angle++)
    {
        int x=bonusfoodx+radius*cos(angle*M_PI/180);
         int y=bonusfoody+radius*sin(angle*M_PI/180);
         SDL_RenderDrawPoint(renderer,x,y);}
         Uint32 start_time = SDL_GetTicks();
    while (SDL_GetTicks() - start_time < 5000) {
        SDL_RenderPresent(renderer);
    }
}
void bonusfood()
{   int x=foodposition.size();
    int randi=(rand() %x);
    bonusfoodx = foodposition[randi].first;
    bonusfoody = foodposition[randi].second;
     bonusfooddraw();
}*/
void foodpos()
{
    cout<<"score:"<<score++<<endl;
    int x=foodposition.size()-1;
    int randi=(rand() %x);
    foodX = foodposition[randi].first;
    foodY = foodposition[randi].second;
    //if(score>0&&(score-1)%7==0)
    //bonusfood();
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
    SDL_Rect rect = { x, y, 20, 20};
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
                        case SDLK_SPACE:
                        { 
                            puse++;
                        }

    } }
    void Drawfood()
    {  int radius=10;
          SDL_SetRenderDrawColor(renderer,foodred,foodgreen,foodblue,0);
         while(radius--)
    for(int angle=0;angle<360;angle++)
    {
        int x=foodX+radius*cos(angle*M_PI/180);
         int y=foodY+radius*sin(angle*M_PI/180);
         SDL_RenderDrawPoint(renderer,x,y);}
    }
    void foodcollision()
    {
         if(((foodX-rectenglex)<foodcol1&&(foodX-rectenglex)>=0)&&((rectengley-foodY)>=0&&(rectengley-foodY)<foodcol2))
         {swap(foodred,snakered);
        swap(foodgreen,snakegreen);
        swap(foodblue,snakeblue);foodpos();}
  else if(((foodX-rectenglex)<foodcol1&&(foodX-rectenglex)>=0)&&((foodY-rectengley)>=0&&(foodY-rectengley)<foodcol1))
         {swap(foodred,snakered);
        swap(foodgreen,snakegreen);
        swap(foodblue,snakeblue);foodpos();}
  else if(((rectenglex-foodX)<foodcol2&&(rectenglex-foodX)>=0)&&((foodY-rectengley)>=0&&(foodY-rectengley)<foodcol1))
        {swap(foodred,snakered);
        swap(foodgreen,snakegreen);
        swap(foodblue,snakeblue);foodpos();}
   else if(((foodX-rectenglex)<foodcol2&&(foodX-rectenglex)>=0)&&((foodY-rectengley)>=0&&(foodY-rectengley)<foodcol1))
        {swap(foodred,snakered);
        swap(foodgreen,snakegreen);
        swap(foodblue,snakeblue);foodpos();}
        
    }
 void snakehead()
    {
       if(direction==1)
   { rectenglex+=10;
   //if(rectenglex==800)
   //rectenglex=10;
   }
   else if(direction==2)
   { rectenglex-=10;
   //if(rectenglex==0)
   //rectenglex=790;
   }
   else if(direction==3)
   { rectengley+=10;
   //if(rectengley==600)
   //rectengley=10;
   }
   else if(direction==4)
   { rectengley-=10;
   //if(rectengley==0)
   //rectengley=590;
   }
    }
  void movebody()
  {    if(puse%2==0)
    {snakehead();
    snakebody1=snakebody;
    snakebody[snakebody.size()-1].first=rectenglex;
    snakebody[snakebody.size()-1].second=rectengley;}
    SDL_SetRenderDrawColor(renderer,snakered,snakegreen,snakeblue,0);
    DrawRect(snakebody[snakebody.size()-1].first,snakebody[snakebody.size()-1].second);
    for(int i=snakebody.size()-1;i>0;i--)
    { snakebody[i-1]=snakebody1[i];
        DrawRect(snakebody[i].first,snakebody[i].second);

    }

  }
  void snakecollision()
     { if(rectenglex>800||rectenglex<0||rectengley>600||rectengley<0)
        {  
                     
                cout<<"GAME IS OVER"<<endl; 
                quit=true;
               }
               if(mp[{rectenglex,rectengley}]!=1)
               {  
                     
                cout<<"GAME IS OVER"<<endl;
                quit=true;
               }
        for(int i=0;i<snakebody.size()-3;i++)
          {
               if(snakebody[i].first==rectenglex&&snakebody[i].second==rectengley)
               { 
                cout<<"GAME IS OVER"<<endl;
                quit=true;
                  break;
               }
          }

     }
      void mainbody()
     { 
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
    SDL_SetRenderDrawColor(renderer,0,200,80,0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,30,30,30,200);
    pathset();
    //SDL_SetRenderDrawColor(renderer,30,30,0,220);
    Drawfood();
    foodcollision();
    movebody();
    snakecollision();
         SDL_RenderPresent(renderer);
          SDL_Delay(80); 
}    
        while(quit1!=true) 
     {  
        SDL_SetRenderDrawColor(renderer,30,30,30,210);
        SDL_Rect rect = { 0,0 ,800, 600};
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer,255,220,180,0);
     rect = { 380,280 , 40, 40};
    SDL_RenderFillRect(renderer, &rect);
                 SDL_RenderPresent(renderer);
        int mousex,mousey;
         while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)
{
    quit1=true;
    break;
}
        if(SDL_MOUSEMOTION==event.type)
        {
            SDL_GetMouseState(&mousex,&mousey);}
            if(SDL_MOUSEBUTTONDOWN==event.type)
            {
                if(SDL_BUTTON_LEFT==event.button.button)
                  {  if(mousex>=380&&mousex<=420&&mousey>=280&&mousey<=320)
                      {quit=false;
                      direction=1;
                      score=0;
                    rectenglex=100;
                    rectengley=100;
            snakebody.clear();
            snakebody1.clear();
                 mainbody();
                 quit=true;
                 quit1=true;
                 }

                  }
            }
        }
     }


     }
     
     
    
int main(int argc,char* argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        cout<<"SDL_Init Error"<<endl;
        return 1;
    }
   snakecordinate();
 foodcordinatex(45,295,120);
 foodcordinatex(45,595,420);
 foodcordinatey(105,395,220);
 foodcordinatex(105,195,320);
 foodcordinatey(135,295,120);
 foodcordinatey(405,475,340);//
 foodcordinatex(205,395,220);
 foodcordinatey(45,435,420);
 foodcordinatey(45,135,320);//
 foodcordinatex(145,355,500);
 foodcordinatey(485,575,160);
 foodcordinatey(405,595,620);
 foodcordinatex(405,545,120);
 foodcordinatex(405,545,320);
 foodcordinatey(105,335,570);
 foodcordinatex(555,695,220);
 foodcordinatey(105,335,680);//
 foodcordinatex(665,755,120);//
 foodcordinatex(665,755,360);
 foodcordinatex(605,755,470);
 foodcordinatex(355,495,500);
 foodcordinatey(405,515,520);
 foodcordinatey(205,295,320);
 foodcordinatex(205,335,320);
 foodcordinatex(555,695,320);
  mainbody();

 SDL_DestroyRenderer(renderer);
 SDL_DestroyWindow(window);
 SDL_Quit();
 return 0;
 }