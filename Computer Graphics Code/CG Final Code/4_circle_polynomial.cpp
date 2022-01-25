#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;
#define ll long long int
void drawcircle(ll x1,ll y1,ll x,ll y)
{
    putpixel(x1+x,y1+y,RED);
    putpixel(x1-x,y1+y,RED);
    putpixel(x1+x,y1-y,RED);
    putpixel(x1+y,y1+x,RED);
    putpixel(x1-y,y1-x,RED);
    putpixel(x1-y,y1+x,RED);
    putpixel(x1+y,y1-x,RED);
    putpixel(x1-x,y1-y,RED);
}
int main()
{

    initwindow(800,900, "Scan Convert Circle Using Polynomial Equation");
    setbkcolor(15);
    cleardevice();
    ll x1,y1,x2,x,y,r,i;
    cin>>x1>>y1>>r;
    x=0,y=0;
    x2= r/sqrt(2);
    drawcircle(x1,y1,x,y);
    for(i=x; i<x2; i++)
    {
        x=x+1;
        y=sqrt((r*r)-(x*x));
        drawcircle(x1,y1,x,y);
    }
    getch();
    closegraph();
    return 0;
}

