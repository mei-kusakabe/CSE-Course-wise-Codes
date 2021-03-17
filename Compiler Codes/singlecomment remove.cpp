#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int len;
    ifstream myfile ("sm.txt");
    if (myfile.is_open())
    {
        while(getline(myfile,s))
        {
            len=s.size();
            for(int i=0; i<len; i++)
            {
                if(s[i]=='/'&& s[i+1]=='/')
                {
                    break;
                }
                else
                    cout<<s[i];
            }
            cout<<endl;
        }
        myfile.close();
    }
    else
        cout<<"Unable to open file";

    return 0;
}
