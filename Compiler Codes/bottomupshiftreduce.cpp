#include<bits/stdc++.h>
using namespace std;
struct s
{
    char nt[10];
    char pro[10];
} g[10];
int n;
int main()
{
    printf("Enter no of production: ");
    scanf("%d\n",&n);
    int i,lp,sp,r,j,k;
    char s[100],st[100],ip[100];
    for(i=1; i<=n; i++)
    {
        cin>>s;
        strncpy(g[i].nt,s,1);
        strcpy(g[i].pro,&s[3]);

    }
    printf("Enter input: ");
    cin>>ip;
    i=0;
    sp=0;
    st[sp]=ip[i];
    lp=strlen(ip);
    i++;
    sp++;
    cout<<"\nStack\tInput\tAction";
    do
    {
        r=1;
        while(r!=0)
        {
            printf("\n$");
            for(j=0; j<sp; j++)
                cout<<st[j];
            cout<<"\t";
            for(j=i; j<lp; j++)
                cout<<ip[j]<<"";
            cout<<"$\t";
            if(r==2)
                cout<<"reduced";
            else
                cout<<"shifted";
            r=0;
            for(j=0; j<sp; j++)
            {
                char ts[10];
                int c=0,l;
                for(k=j; k<sp; k++)
                {
                    ts[c]=st[k];
                    c++;
                }
                ts[c]='\0';
                for(k=1; k<=n; k++)
                {
                    if(strcmp(ts,g[k].pro)==0)
                    {
                        for(l=j; l<10; l++)
                            st[l]='\0';
                        st[j]=g[k].nt[0];
                        sp=j+1;
                        r=2;
                    }
                }
            }
        }
        st[sp]=ip[i];
        i++;
        sp++;
    }
    while(strlen(st)!=1&&sp!=lp);
    if(strlen(st)==1)
        printf("\n String accepted\n");
    else
        printf("\nnot");
    return 0;
}
/*
 E->E*E
 E->(E)
 E->id
*/

