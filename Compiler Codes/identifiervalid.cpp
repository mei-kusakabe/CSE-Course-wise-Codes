#include<bits/stdc++.h>
using namespace std;
int isvalid(string s,int len)
{
    if(!((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z') || s[0]=='_'))
        return 0;
    for(int i=1; i<s.length(); i++)
    {
        if(!((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || s[i]=='_'|| (s[i]>='0'&& s[i]<='9')))
        {
            return 0;
        }

    }
     return 1;
}
int main()
{
    string s;
    int i,l,n;
    cin>>n;
    while(n--)
    {
        getline(cin>>ws,s);
        l=s.length();
        if(isvalid(s,l))
            cout<<"Valid identifier.\n\n";
        else
            cout<<"Invalid identifier.\n\n";
    }
    return 0;
}
