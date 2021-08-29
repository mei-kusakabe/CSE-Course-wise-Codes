#include<bits/stdc++.h>
#include<graphics.h>
#include<dos.h>
using namespace std;
void printMsg()
{
    initwindow(1920,1080);
    setbkcolor(9);
    cleardevice();

    settextstyle(10,0,5);
    setcolor(WHITE);
    outtextxy(390, 230, "Assalamu  alaikum Ma'am ");
    delay(350);

    setcolor(11);
    circle(610, 420, 50);
    setfillstyle(SOLID_FILL, 11);
    floodfill(610, 420, 11);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);

    fillellipse(620, 416, 3, 8);
    fillellipse(600, 416, 3, 8);

    ellipse(610, 430, 205, 335, 20, 9);
    ellipse(610, 430, 205, 335, 20, 10);
    ellipse(610, 430, 205, 335, 20, 11);
    delay(4000);
    cleardevice();
    string str0[10]= {"Here, ", "from", "7AF, "," We","are", "dropping", "you","a","few","lines..."};
    string str1[20]= {"You", "might", "be","away","from", "us..", "but","your", "teachings", "&", "   memories", "with", "us", "will", "never", "be."};
    string str2[19]= {"May", "Allah", "bless ", "you", " and", " showers", " His", "  countless", "  blessings", " on", "  you,", "keep", " you", " safe", " and", " sound", " in", " all ", "respects."};
    string str3[9]= {"We, ", "will", "always","miss","you","and","remember","you..."};
    setcolor(WHITE);
    int x=100,y=160;
    for (int i=0; i<10; i++)
    {
        // setbkcolor(9);
        //setcolor(BLACK);
        settextstyle(8,0,5);
        outtextxy(x,y,(char*)str0[i].c_str());
        if(i==2)
            y=250,x=100;
        else
            x+=str0[i].size()*40;
        delay(700);
    }
    // setbkcolor(15);
    cleardevice();
    x=100,y=160;
    for (int i=0; i<20; i++)
    {
        //setbkcolor(9);
        //  setcolor(BLACK);
        settextstyle(8,0,5);
        outtextxy(x,y,(char*)str1[i].c_str());
        if(i==5)
            y=250,x=100;
        else if(i==10)
            y=340,x=100;
        else
            x+=str1[i].size()*40;
        delay(700);
    }
    //setbkcolor(15);
    cleardevice();
    x=100,y=160;
    for (int i=0; i<19; i++)
    {
        // setbkcolor(9);
        //setcolor(BLACK);
        settextstyle(8,0,4);
        outtextxy(x,y,(char*)str2[i].c_str());
        if(i==4)
            y=250,x=100;
        else  if(i==10)
            y=340,x=100;
        else  if(i==15)
            y=430,x=100;
        else if(i>4 and i<10)
            x+=str2[i].size()*25;
        else
            x+=str2[i].size()*40;
        delay(700);
    }
    //setbkcolor(15);
    cleardevice();
    x=100,y=160;
    for (int i=0; i<9; i++)
    {
        //setbkcolor(9);
        //setcolor(WHITE);
        settextstyle(8,0,5);
        outtextxy(x,y,(char*)str3[i].c_str());
        if(i==2)
            y=250,x=100;
        else
            x+=str3[i].size()*40;
        delay(700);
    }
    // setbkcolor(15);
    cleardevice();
}
int main()
{
    printMsg();
    return 0;
}
