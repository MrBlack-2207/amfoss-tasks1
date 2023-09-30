#include <stdio.h>

int main() {
    int a;
    scanf("%d\n",&a);
    char pr[a];
    for(int i=0;i<a;i++)
    {
        char grid[3][4];
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<4;k++)
            scanf("%c",&grid[j][k]);
        }
        if((grid[0][0]=='X' && grid[0][1]=='X' && grid[0][2]=='X')||(grid[0][0]=='X'&&grid[1][0]=='X'&& grid[2][0]=='X')||(grid[2][0]=='X'&& grid[2][1]=='X'&& grid[2][2]=='X')||(grid[0][2]=='X'&& grid[1][2]=='X'&& grid[2][2]=='X')||(grid[0][0]=='X'&& grid[1][1]=='X'&& grid[2][2]=='X')||(grid[0][2]=='X'&& grid[1][1]=='X'&&  grid[2][0]=='X')||(grid[1][0]=='X'&& grid[1][1]=='X'&&  grid[1][2]=='X')||(grid[0][1]=='X'&& grid[1][1]=='X'&&  grid[2][1]=='X'))
        pr[i] = 'X';
        else if((grid[0][0]=='O'&& grid[0][1]=='O'&& grid[0][2]=='O')||(grid[0][0]=='O'&&grid[1][0]=='O'&& grid[2][0]=='O')||(grid[2][0]=='O'&& grid[2][1]=='O'&& grid[2][2]=='O')||(grid[0][2]=='O'&& grid[1][2]=='O'&& grid[2][2]=='O')||(grid[0][0]=='O'&& grid[1][1]=='O'&& grid[2][2]=='O')||(grid[0][2]=='O'&& grid[1][1]=='O'&&  grid[2][0]=='O')||(grid[1][0]=='O'&& grid[1][1]=='O'&&  grid[1][2]=='O')||(grid[0][1]=='O'&& grid[1][1]=='O'&&  grid[2][1]=='O'))
        pr[i] = 'O';
        else if((grid[0][0]=='+'&& grid[0][1]=='+'&& grid[0][2]=='+')||(grid[0][0]=='+'&&  grid[1][0]=='+'&& grid[2][0]=='+')||(grid[2][0]=='+'&& grid[2][1]=='+'&& grid[2][2]=='+')||(grid[0][2]=='+'&& grid[1][2]=='+'&& grid[2][2]=='+')||(grid[0][0]=='+'&& grid[1][1]=='+'&& grid[2][2]=='+')||(grid[0][2]=='+'&& grid[1][1]=='+'&&grid[2][0]=='+')||(grid[1][0]=='+'&& grid[1][1]=='+'&&  grid[1][2]=='+')||(grid[0][1]=='+'&& grid[1][1]=='+'&&  grid[2][1]=='+'))
        pr[i] = '+';
        else
        pr[i]='a';
        
    }
    for(int i=0;i<a;i++)
    {
        if(pr[i]=='a')
        printf("DRAW\n");
        else
        printf("%c\n",pr[i]);
    }
}