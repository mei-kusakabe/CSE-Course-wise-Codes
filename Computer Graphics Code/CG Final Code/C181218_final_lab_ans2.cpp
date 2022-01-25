#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;
#define ll long long int
ll x1_p,x2_p,y1_p,y2_p,x,y,dx,dy,dt,ds,d;
void draw_quadrant()
{
    int i,m,n;
    for(i=0; i<=600; i++)
    {
        m=300;
        putpixel(m,i,RED); // y axis
    }
    for(i=0; i<=600; i++)
    {
        n=300;
        putpixel(i,n,RED); // x axis
    }
}
void apply_bresenham(int x1,int y1,int x2,int y2)
{
    x1_p = floor(x1);
    y1_p = floor(y1);
    x2_p = floor(x2);
    y2_p = floor(y2);

    x= x1_p,y=y1_p;
    dx = x2_p - x1_p;
   // dy= y2_p - y1_p;
    dy= 0;
    dt = 2*(dy-dx);
    ds = 2*dy;
    d= 2*dy - dx;

    putpixel (x, y, CYAN);

    for(ll i=x; i<x2_p ; i++)
    {
        x++;
        if(d<0)
        {
            putpixel(x,y,CYAN);
            putpixel(x+275,y,CYAN);
             putpixel(x,y+275,CYAN);
             putpixel(x+275,y+275,CYAN);
            d+=ds;

        }
        else
        {
            putpixel(x,y,CYAN);
            putpixel(x+275,y,CYAN);
            putpixel(x,y+275,CYAN);
            putpixel(x+275,y+275,CYAN);
            y++;
            d+=dt;
        }
        // putpixel (x,y, RED);
    }

}

int main()
{
    int x1,y1,x2,y2;
    initwindow(920,880, "Bresenham Line Algorithm implementation");
    setbkcolor(15);
    cleardevice();
    draw_quadrant();
    cout<<"\nGenerating lines using Bresenham's Algorithm\n";
    cout<<"\nEnter co-ordinates of first point: ";
    cin>>x1>>y1;
    cout<<"\nEnter co-ordinates of second point: ";
    cin>>x2>>y2;
    apply_bresenham(x1,y1,x2,y2);
    getch();
    closegraph();

    return 0;
}
