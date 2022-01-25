#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;
#define ll long longint
int main()
{
    initwindow(1920,1080, "DDA Algorithm implementation");
    setbkcolor(15);
    cleardevice();
    double x1,x2,y1,y2,m,b,x,y;
    ll x1_p,x2_p,y1_p,y2_p;
    cin>>x1>>y1>>x2>>y2;
    x1_p = floor(x1);
    y1_p = floor(y1);
    x2_p = floor(x2);
    y2_p = floor(y2);
    m= (y2_p -y1_p)/(x2_p-x1_p);
    if(abs(m)<=1)
    {
        y=y1_p;
        for(lli = x1_p; i<=x2_p ; i++)
        {
            y+=m; ;
            putpixel (i, y, RED);
        }
    }
    else
    {
        x= x1_p;
        for(lli = y1_p; i<=y2_p ; i++)
        {
            x +=(1/m);
            putpixel (x, i, RED);
        }
    }
    getch();
    closegraph();
    return 0;
}

