#include <stdio.h>
int main()
{
    int a;
    scanf("%d\n",&a);
    int out[a];
    for(int i=0;i<a;i++)
    {
        int count=0;
        char str[7];
        scanf("%s",str);
        if(str[0]!='a')
        count++;
        if(str[1]!='m')
        count++;
        if(str[2]!='f')
        count++;
        if(str[3]!='o')
        count++;
        if(str[4]!='s')
        count++;
        if(str[5]!='s')
        count++;
        out[i]=count;
    }
    for(int j=0;j<a;j++)
    printf("%d\n",out[j]);
}