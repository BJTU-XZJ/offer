#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
void replaceSpace(char *str, int length)
{
    int i, count=0;
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]==' ')
            count++;
    }
    int newlen = length + count*2;
    int p1 = length-1;
    int p2 = newlen-1;
    char newstr[newlen];
    for(i=p1; i>=0; i--)
    {
        if(str[i]!=' ')
        {
            newstr[p2--]=str[i];
        }
        else
        {
            newstr[p2--]='0';
            newstr[p2--]='2';
            newstr[p2--]='%';
        }
    }
    for(i=0; i<newlen; i++)
        printf("%c", newstr[i]);
}
int main()
{
    char str[]="w a h";
    replaceSpace(str, strlen(str));
    return 0;
}
