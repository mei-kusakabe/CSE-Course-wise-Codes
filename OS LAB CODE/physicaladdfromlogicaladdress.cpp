#include<bits/stdc++.h>
using namespace std;
int main()
{
    int seg[100],base[100],limit[100],la[100],i,j,len,n,pa,index;
    string l,s;
    cout<<"Enter the number of segment : \n";
    cin>>n;
    cout<<"Enter segment number, base & limit : \n";
    for(i=0; i<n; i++)
    {
        cin>>seg[i]>>base[i]>>limit[i];
    }
    for(i=0; i<n; i++)
    {
        cout<<"Enter segment number with logical address: \n";
        cin>>l;
        len=l.size();
        s=l.substr(1,len);
        index=l[0]-'0';
        la[index]=stoi(s);
        if(la[index]<=limit[index])
        {
            printf("\nPhysical address of segment[%d] is: ",index);
            pa=la[index]+base[index];
            printf("%d\n\n",pa);
        }
        else
        {
            printf("\nPhysical address is not found for segment[%d] as the length is not legal.\n\n",index);
        }
        s.clear();
        l.clear();

    }
    return 0;
}
/*
5
0 219 600
1 2300 14
2 90 100
3 1327 590
4 1952 96

0430
2500
3400
110
4112
*/
