#include<stdio.h>
#include<stdlib.h>
void check_comment(char);
void multi_comment();
FILE *fp,*fp2;
int main()
{
    char c;
    fp=fopen("mm.txt","r");
    fp2=fopen("mt.txt","w");
    while((c=fgetc(fp))!=EOF)
        check_comment(c);
    fclose(fp);
    fclose(fp2);
}
void check_comment(char c)
{
    char d;
    if(c=='/')
    {
        if((d=fgetc(fp))=='*')
            multi_comment();
        else
        {
            fputc(c,fp2);
            fputc(d,fp2);

        }
    }
    else
    fputc(c,fp2);

}
void multi_comment()
{
    char d,e;
        while((d=fgetc(fp))!=EOF)
        {
            if(d=='*')
            {
                e=fgetc(fp);
                if(e=='/')
                    return;
            }
        }

}
