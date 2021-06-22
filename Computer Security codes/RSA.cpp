/* ...Bismillahir Rahmanir Raheem --- Rabbi Zidni Ilma...*/
#include<bits/stdc++.h>
using namespace std;
#define ll        long long int
#define MOD       1000000007

bool isPrime(ll n)
{

    if (n <= 1)  return false;
    if (n <= 3)  return true;


    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;

    return true;
}
ll power(ll  n, ll  m)
{
    if (m == 0) return 1;
    ll x = power(n, m / 2);
    //ll y=power(n,m,MOD);
    // cout<<x<<endl;
    // cout<<y<<endl;
    if (!(m & 1)) return (x * x) % MOD;
    else return (((x * x) % MOD) * n) % MOD;
}
ll power2(ll  n, ll  m,ll M)
{
    if (m == 0) return 1;
    ll x = power2(n, m / 2,M);
    // cout<<x<<endl;
    if (!(m & 1)) return (x * x) % M;
    else return (((x * x) % M) * n) % M;
}
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int main()
{

    ll len,C,f,Dval,p,q,z,n,i,e,d=7;
    char text[200],c1,c2;
    string encryptedmessage="",decryptedmessage="";
    cout<<"Enter P & Q : ";

    srand(time(NULL));
    do
    {
        p=rand();
        q=rand();
    }
    while (!isPrime(p) || !isPrime(q) );

    // cin>>p;
    // cout<<"Enter Q : ";
    // cin>>q;
    //p=3,q=11;
    n=p*q,z=(p-1)*(q-1);

    while(d<z)
    {
        if (gcd(d,z)==1)
            break;
        else
            d++;
    }
    e= 2;
    while ((e*d)%z!=1)
    {
        e++;
    }
    // swap(d,e);
    cout<<"p : "<<p<<endl;
    cout<<"q : "<<q<<endl;
    cout<<"n : "<<n<<endl;
    cout<<"z : "<<z<<endl;
    cout<<"d: "<<d<<endl;
    cout<<"e: "<<e<<endl;
    cout<<"Enter Plaintext Length : ";
    cin>>len;
    cout<<"Enter Plaintext : ";
    cin>>text;
    cout<<endl;
    cout<<"Plaintext \t\t\t\t\tCiphertext(C)\t\t\t\t\t\t\n\n";
    cout<<"--------- \t\t\t\t\t-------------\t\t\t\t\t\t\n\n";
    cout<<"Symbolic\t\t Numeric\t\t P^"<<e<<"\t\t\tP^"<<e<<"(mod "<<n<<")\t\t\t\n\n";
    cout<<"--------\t\t -------\t\t ---\t\t\t-----------\t\t\t\n\n";
    for(i=0; i<len; i++)
    {
        f=text[i]-'A'+1;
        C=power(f,e) ;

        printf("%c\t\t\t%lld\t\t | \t%-11lld\t\t\t",text[i],f,C);

        //C%=n ;
        C=power2(f,e,n);
        printf("%lld\t\t | \t",C);
        cout<<"\n\n";
    }
    cout<<"\n\n";
    cout<<"\nAfter Decryption\n\n";
    cout<<"----------------\n\n";
    cout<<"C^"<<d<<"\t\t\tC^"<<d<<"(mod "<<n<<")\t\t   Symbolic\n\n";
    cout<<"---\t\t\t-----------\t\t   --------\n\n";
    for(i=0; i<len; i++)
    {
        f=text[i]-'A'+1;
        C=power(f,e) ;

        //  printf("%c\t\t\t%lld\t\t | \t%-11lld\t\t\t",text[i],f,C);

        //C%=n ;
        C=power2(f,e,n);
       // printf("%lld\t\t | \t",C);

        Dval= power(C,d);

        printf("%-11lld\t\t\t",Dval);
        // Dval%= n ;
        Dval=power2(C,d,n);

        printf("%lld\t\t\t",Dval);
        c1= char(C+'A'-1);
        c2= char(Dval+'A'-1);

        // printf("%-10c\n",c2);
        printf("%-5c\n",c2);

        encryptedmessage+=c1;
        decryptedmessage+=c2;
        // cout<<endl;
    }
    /*

    // printf("%lld\t\t | \t",C);
    Dval= power(C,d);

    printf("%-11lld\t\t\t",Dval);
    // Dval%= n ;
    Dval=power2(C,d,n);

    printf("%lld\t\t\t",Dval);
    c1= char(C+'A'-1);
    c2= char(Dval+'A'-1);

    // printf("%-10c\n",c2);
    printf("%-5c\n",c2);

    encryptedmessage+=c1;
    decryptedmessage+=c2;
    }*/

    cout<<"Encryted Message : "<<encryptedmessage<<endl;
    cout<<"Decryted Message : "<<decryptedmessage<<endl;

    return 0;
}



