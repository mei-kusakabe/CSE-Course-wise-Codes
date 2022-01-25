#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;
#define ll long long int
#define pi acos(-1.0)
void drawcircle(ll x,ll y,ll h,ll k)
{
    putpixel(x+h,y+k,RED);
    putpixel(x+h,-y+k,RED);
    putpixel(-x+h,y+k,RED);
    putpixel(-x+h,-y+k,RED);
    putpixel(y+h,x+k,RED);
    putpixel(y+h,-x+k,RED);
    putpixel(-y+h,x+k,RED);
    putpixel(-y+h,-x+k,RED);
}
int main()
{
    initwindow(800,900, "Scan Convert Circle Using Trigonometric Function");
    setbkcolor(15);
    cleardevice();
    ll x,y,x1,y1,r,h,k,theta;
    double n=pi/180.0;
    cin>>h>>k>>r;
    for(theta=0; theta<=45; theta++)
    {
        x1=r*cos(theta*n);
        y1=r*sin(theta*n);
        x=floor(x1+0.5);
        y=floor(y1+0.5);
        drawcircle(x,y,h,k);
    }
    getch();
    closegraph();
    return 0;

}

