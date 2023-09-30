#include <stdio.h>
int main()
{
    int a,b,c,d,x=0,y=0,z=0;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        scanf("%d %d %d",&b,&c,&d);
        x=x+b;
        y=y+c;
        z=z+d;
    }
    if(x==0 && y==0 && z==0)
    printf("YES");
    else
    printf("NO");
}