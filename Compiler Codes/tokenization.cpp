#include<bits/stdc++.h>
using namespace std;
int main()
{
    string l,op="+-*/%";
    int f;
    ifstream file("token.txt");
    if(file.is_open())
    {
        while(getline(file,l))
        {
            cout<<l<<endl;
            if(l.find("#include<stdio.h>")!=string::npos)
            {
                cout<<"   - header file\n";
            }
            else if(l.find("main()")!=string::npos)
            {
                cout<<"   - main function\n";
            }
            else if(l.find("printf")!=string::npos)
            {
                printf("   - produces output, printf is a library function\n");
            }
             else if(l.find("scanf")!=string::npos)
            {
                cout<<"   - takes input, scanf is a library function\n";
            }
             else if(l.find("int")!=string::npos)
            {
                cout<<"   - int type variable\n";
            }

             else if(l.find("float")!=string::npos)
            {
                cout<<"   - float type variable\n";
            }
             else if(l.find("double")!=string::npos)
            {
                cout<<"   - double type variable\n";
            }
             else if(l.find("char")!=string::npos)
            {
                cout<<"   - char type variable\n";
            }
            else if(l.find("string")!=string::npos)
            {
                cout<<"   - string type variable\n";
            }
            else if(l.find("return")!=string::npos)
            {
                cout<<"   - return from function\n";
            }


            else
            {
                for(int j=0; j<op.length(); j++)
                    if(l.find(op[j])!=std::string::npos)
                    {
                        printf("   -  mathematical operation\n");
                    }
            }
        }
    }
    else
        cout<<"unable to open file\n";
    return 0;
}
