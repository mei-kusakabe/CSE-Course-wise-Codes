#include<bits/stdc++.h>
using namespace std;
int n,m;
char flw[100];
void First_normal(char c);
void follow(char c);
void first(char c);
void addrslt(char c);
struct
{
    string non_terminal,production;
} FF[10];
void First_normal(char c)
{
    int i,l,j;
    for(i=0; i<n; i++)
    {
        if(FF[i].non_terminal[0]==c)
        {
            l=FF[i].production.length();
            for(j=0; j<l; j++)
            {
                if(j==0)
                {
                    if(FF[i].production[j]>='A' && FF[i].production[j]<='Z')
                        First_normal(FF[i].production[j]);
                    else
                        printf("%c, ",FF[i].production[j]);
                }
                else if(FF[i].production[j-1]=='|')
                {
                    if(FF[i].production[j]>='A'&& FF[i].production[j]<='Z')
                        First_normal(FF[i].production[j]);
                    else
                        printf("%c, ",FF[i].production[j]);
                }
            }
        }
    }

}
void addrslt(char c)
{
    int i;
    for(i=0; i<m; i++)
        if(flw[i]==c)
            return;
    if(c!='&'&&c!='|')
        flw[m++]=c;
}
void follow(char c)
{
    int j,i,l;
//   printf("%c ",c);
    if(c==FF[0].non_terminal[0])
        addrslt('$');
    for(i=0; i<n; i++)
    {
        l=FF[i].production.length();
        for(j=0; j<l; j++)
            if(FF[i].production[j]==c) // char ta production e khujbo
            {
                if(((j+1)==l||FF[i].production[j+1]=='|')&& c!=FF[i].non_terminal[0])//last element hole write follow of l.h.s
                {
                    //   printf("%c",g[i].nt[0]);
                    follow(FF[i].non_terminal[0]);
                }
                else
                {
                    first(FF[i].production[j+1]);//non_t hole write follow's first element
                }
            }
    }
}
void first(char c)
{
    if(!isupper(c)&& c!='|'&& c!='&')//if terminal
        addrslt(c);// add terminal
    int i,l,j;
    for(i=0; i<n; i++)
    {
        l=FF[i].production.length();
        if(FF[i].non_terminal[0]==c)
        {
            for(j=0; j<l; j++)
            {
                if(j==0)
                {
                    if(isupper(FF[i].production[j])) // if non_terminal
                        first(FF[i].production[j]);
                    else
                        addrslt(FF[i].production[j]); //else write as it is
                }
                else if(FF[i].production[j-1]=='|')
                {
                    if(FF[i].production[j]=='&') //if epsilon , then write follow of l.h.s
                        follow(FF[i].non_terminal[0]);
                    if(isupper(FF[i].production[j]))// if non_terminal, write its first
                        first(FF[i].production[j]);
                    else
                        addrslt(FF[i].production[j]); //else write as it is
                }

            }
        }
    }
}
int main()
{
    int i,j,l;
    string s;
    cout<<"Enter Number of production : ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>s;
        FF[i].non_terminal=s.substr(0,1);
        FF[i].production=s.substr(3);
    }
    cout<<"\nFirst :\n";
    for(i=0; i<n; i++)
    {
        cout<<"First of "<<FF[i].non_terminal[0]<<" : { ";
        l=FF[i].production.length();
        for(j=0; j<l; j++)
        {
            if(j==0)
            {
                if(FF[i].production[j]>='A'&& FF[i].production[j]<='Z') // if first element is non-terminal recursive mode e normal first function check korbe
                    First_normal(FF[i].production[j]);
                else
                    printf("%c, ",FF[i].production[j]); //terminal hole print
            }
            else if(FF[i].production[j-1]=='|')
            {
                if(FF[i].production[j]>='A'&& FF[i].production[j]<='Z') // if bar er porer element is non-terminal recursive mode e normal first function check korbe
                    First_normal(FF[i].production[j]);
                else
                    printf("%c, ",FF[i].production[j]); //terminal hole print
            }
        }
        printf("}\n");
    }
    printf("\nFollow:\n");
    int p,k,cnt=0;
    for(i=0; i<n; i++)
    {
        m=0;
        printf("Follow of %c : { ",FF[i].non_terminal[0]);
        memset(flw,'\0',sizeof(flw));
        follow(FF[i].non_terminal[0]);
        for(j=0; j<m; j++)
            printf("%c, ",flw[j]);
        printf("}\n");
    }
    return 0;
}
/* 5
E->TX
X->+TX|&
T->FY
Y->*FY|&
F->(E)|a*/
