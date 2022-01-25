#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;

void rotate_triangle(int p1,int q1,int p2,int q2,int p3,int q3)
{
    setcolor(YELLOW);
    line(p1,q1,p2,q2);
    line(p2,q2,p3,q3);
    line(p3,q3,p1,q1);

}
void rotate_triangle_after(int p1,int q1,int p2,int q2,int p3,int q3)
{
   setcolor(CYAN);
    line(p1,q1,p2,q2);
    line(p2,q2,p3,q3);
    line(p3,q3,p1,q1);

}
int main()
{
    initwindow(1920,1080, "2D_Rotation");
    setbkcolor(BLACK);
    cleardevice();
    int x1,y1,x2,y2,x3,y3,theta;
    void rotate_triangle(int,int,int,int,int,int);
    cout<<"Enter points for triangle : ";
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    cout<<"Enter angle of rotation : ";
    cin>>theta;
    // rotation
    int a1,b1,a2,b2,a3,b3;
    a1= x1*cos(theta) - y1*sin(theta);
    b1= x1*sin(theta) + y1*cos(theta);
    a2= x2*cos(theta) - y2*sin(theta);
    b2= x2*sin(theta) + y2*cos(theta);
    a3= x3*cos(theta) - y3*sin(theta);
    b3= x3*sin(theta) + y3*cos(theta);
	rotate_triangle(x1,y1,x2,y2,x3,y3);
    rotate_triangle_after(a1,b1,a2,b2,a3,b3);
	getch();


    return 0;
}

