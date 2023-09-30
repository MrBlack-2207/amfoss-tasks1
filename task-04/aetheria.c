#include <stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    int c[a];
    for(int i=0;i<a;i++)
    scanf("%d",&c[i]);

    //finding min
    int min=0,count=0;
    for(int i=0;i<a;i++)
    {
        if(c[i]<c[min])
        min=i;
    }
    for(int j=0;j<a;j++)
    {
        if(c[j]==c[min])
        count++;
    }
    if(count==1)
    printf("%d",min+1);
    else
    printf("Still Aetheria");
}