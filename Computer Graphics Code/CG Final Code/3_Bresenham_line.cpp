#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;
#define ll long long int
int main()
{
    initwindow(1920,1080, "Bresenham Line Algorithm implementation");
    setbkcolor(15);
    cleardevice();
    double x1,x2,y1,y2;
    ll x1_p,x2_p,y1_p,y2_p,x,y,dx,dy,dt,ds,d;
    cin>>x1>>y1>>x2>>y2;
    x1_p = floor(x1);
    y1_p = floor(y1);
    x2_p = floor(x2);
    y2_p = floor(y2);

    x= x1_p,y=y1_p;
    dx = x2_p - x1_p,dy= y2_p - y1_p;
    dt = 2*(dy-dx);
    ds = 2*dy;
    d= 2*dy - dx;

    putpixel (x, y, RED);

    for(ll i=x; i<x2_p ; i++)
    {
        x++;
        if(d<0)d+=ds;
        else
        {
            y++;
            d+=dt;
        }
        putpixel (x,y, RED);
    }


    getch();
    closegraph();
    return 0;
}

