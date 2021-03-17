#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,s1,s2,s3,s4,c,c1,c2,rest;
    int n,i,j,k1,k2,flag;
    char ch;
    cout<<"Enter the number of Production: ";
    char ch1;
    cin>>n;
    while(n--)
    {
        flag=0;
        cout<<"Enter the production: ";
        cin>>s;
        ch=s[0];
        int len=s.size();
        i=3;
        while (s[i])
        {
            ch1=s[i];
            if (isupper(ch1))
            {
                flag=1;//non-terminal check
                break;
            }
            else
                i++;
        }
        if(flag)
        {
            for(i=3; s[i]!='|'; i++)
            {
                s1+=s[i]; //vaag kore nisi part 1
            }
            i++;
            for(j=i++; s[j]!='|'; j++)
            {
                s2+=s[j]; //vaag kore nisi part 2
            }
            k1=j;
            int len1=s1.size();
            int len2=s2.size();
            if(len2>len1)
            {
                swap(len2,len1);
                swap(s2,s1);
            }
            j=0;
            for(i=0; i<len1; i++)
            {
                if(s1[j]==s2[i])
                {
                    c+=s2[i]; // common string
                    j++;
                }
            }
            k2=j;
            for(i=k2; i<len1; i++)
                c1+=s1[i]; //s1 er rest
            for(i=k2; i<len2; i++)
                c2+=s2[i]; //s2 er rest
            for(i=k1+1; i<s.size(); i++)
                rest+=s[i]; // uncommon
            // cout<<k2<<endl;
            //  cout<<len2<<endl;

            cout<<ch<<"->"<<c<<ch<<"' | "<<rest<<endl;
            if(k2==len2)
                cout<<ch<<"'-> E |"<<c1<<endl;
            else
                cout<<ch<<"'->"<<c1<<" |"<<c2<<endl;
        }
        else
            cout<<s<<endl;
        s.clear();
        s1.clear();
        s2.clear();
        c1.clear();
        c.clear();
        c2.clear();
        rest.clear();

    }
    return 0;
}
