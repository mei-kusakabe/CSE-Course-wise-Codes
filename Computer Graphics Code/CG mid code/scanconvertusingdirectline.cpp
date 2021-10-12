#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;
#define ll long long int
int main()
{

    initwindow(1920,1080, "Scan Convert Using direct line equation");
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
    b= y1_p - m*(x1_p);

    if(abs(m)<=1)
    {
        for(ll i = x1_p+1; i< x2_p ; i++)
        {
            y= m*i+b;
            putpixel (i, y, RED);
        }
    }
    else
    {
        for(ll i = y1_p+1; i< y2_p ; i++)
        {
            x = (i-b)/m;
            putpixel (x, i, RED);
        }
    }
    getch();
    closegraph();

    return 0;

}

