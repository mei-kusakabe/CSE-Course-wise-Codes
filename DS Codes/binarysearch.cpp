#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    ll a[n+5],low,high,mid,i,m;
    for(i=0; i<n; i++)
        cin>>a[i];
    cin>>m;
    low=0;
    high=n;
    while(low<=high)
    {
        mid = low+(high-low)/2;
        if(m>a[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    if(a[mid]==m)
        cout<<"Found at position "<<mid<<endl;
    else
        cout<<"Not Found"<<endl;
    return 0;
}
