#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;

void before_scaling(int p1,int q1,int p2,int q2,int p3,int q3)
{
    setcolor(YELLOW);
    line(p1,q1,p2,q2);
    line(p2,q2,p3,q3);
    line(p3,q3,p1,q1);

}
void after_scaling(int p1,int q1,int p2,int q2,int p3,int q3)
{
    setcolor(CYAN);
    line(p1,q1,p2,q2);
    line(p2,q2,p3,q3);
    line(p3,q3,p1,q1);

}
int main()
{
    initwindow(1920,1080, "2D_Scaling");
    setbkcolor(BLACK);
    cleardevice();
    int x1,y1,x2,y2,x3,y3,sx,sy;
    void rotate_triangle(int,int,int,int,int,int);
    cout<<"Enter points for triangle : ";
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    cout<<"Enter scaling factor : ";
    cin>>sx>>sy;
    // scaling
    int a1,b1,a2,b2,a3,b3;
    a1= x1*sx;
    b1= y1*sy;
    a2= x2*sx;
    b2= y2*sy;
    a3= x3*sx;
    b3= y3*sy;
    before_scaling(x1,y1,x2,y2,x3,y3);
    after_scaling(a1,b1,a2,b2,a3,b3);
    getch();


    return 0;
}



