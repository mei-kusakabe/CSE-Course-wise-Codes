#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    cout<<"Enter total number of processes : ";
    cin>>n;
    cout<<"\nEnter processes burst time : \n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"] :";
        cin>>bt[i];
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        wt[i]+=bt[j];
    }
    cout<<"\nProcess\t\tBurst time\tWaiting time\tTurnaround time";

    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }
    avwt/=i;
    avtat/=i;
    cout<<"\n\nAverage Waiting Time:"<<avwt;
    cout<<"\nAverage Turnaround Time:"<<avtat;

    return 0;
}
/*
3
24
3
3
*/




