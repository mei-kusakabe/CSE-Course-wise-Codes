#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void LOWER_BOUND(ll a[],ll n,ll x)
{
    ll low=0;
    ll high=n;
    while(low<high)
    {
        ll mid= low+(high-low)/2;
        if(x<=a[mid]) high = mid;
        else low = mid+1;
    }
    cout<<"Found at position for lower bound : "<<low<<endl;

}
void UPPER_BOUND(ll a[],ll n,ll x)
{
    ll low=0;
    ll high=n;
    while(low<high)
    {
        ll mid= low+(high-low)/2;
        if(x<a[mid]) high = mid;
        else low = mid+1;
    }
    cout<<"Found at position for upper bound : "<<low<<endl;
}
int main()
{
    ll n;
    cin>>n;
    ll a[n+5],low,high,mid,i,m;
    for(i=0; i<n; i++)
        cin>>a[i];
    cin>>m;
    LOWER_BOUND(a,n,m);
    UPPER_BOUND(a,n,m);
    return 0;
}
/*
5
3 3 5 8 9
3
*/
