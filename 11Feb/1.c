// FCFS

#include<stdio.h>
#include<sys/types.h>
#define MAX 5

int p[MAX][6];
int copy[MAX];
int min()
{
    int min = p[0][1], i;
    for(i = 1; i < MAX; i++)
    {
        if(p[i][1] < min)
            min = p[i][1];
    }
    return min;
}

int find_min_pos(int m)
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        if(p[i][1] == m)
            break;
    }
    return i;
}

void display()
{
    int i, j;
    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if(j == 1)
                printf("%d\t", copy[i]);
            else
                printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int i, j;
    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    for(i = 0; i < MAX; i++)
    {
        copy[i] = p[i][1];
    }
    int ct = 0, min_at;
    for(i = 0; i < MAX; i++)
    {
        min_at = find_min_pos(min());
        ct = p[min_at][2] + ct;
        p[min_at][3] = ct;
        p[min_at][4] = p[min_at][3] - p[min_at][1];
        p[min_at][5] = p[min_at][4] - p[min_at][2];
        p[min_at][1] = 1000; //increasing value of covered nodes
    }
    printf("\n\n");
    display();
    return 0;
}