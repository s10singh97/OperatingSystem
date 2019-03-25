// Priority W/O Preemption

#include<stdio.h>
#include<sys/types.h>
#define MAX 6

int p[MAX][7];
int copy[MAX];
int min(int ct)
{
    int min = p[0][3], i;
    for(i = 1; i < MAX; i++)
    {
        if(p[i][3] < min && p[i][1] <= ct)
            min = p[i][3];
    }
    return min;
}

int find_min_pos(int m, int ct)
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        if(p[i][3] == m && p[i][1] <= ct)
            break;
    }
    return i;
}

void display()
{
    int i, j;
    printf("PID\tAT\tBT\tPri\tCT\tTAT\tWT\n");
    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < 7; j++)
        {
            if(j == 3)
                printf("%d\t", copy[i]);
            else
                printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
}

int find_minat()
{
    int min = p[0][1], i;
    for(i = 1; i < MAX; i++)
    {
        if(p[i][1] < min)
            min = p[i][1];
    }
    return min;
}

int find_minat_pos(int m)
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        if(p[i][1] == m)
            break;
    }
    return i;
}

int main(int argc, char *argv[])
{
    int i, j;
    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < 4; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    for(i = 0; i < MAX; i++)
    {
        copy[i] = p[i][3];
    }
    int ct = 0, min_at, min_aat;
    for(i = 0; i < MAX; i++)
    {
        min_aat = find_minat_pos(find_minat());
        if(p[min_aat][1] < ct)
        {
            min_at = find_min_pos(min(ct), ct);
            ct = p[min_at][2] + ct;
            p[min_at][4] = ct;
            p[min_at][5] = p[min_at][4] - p[min_at][1];
            p[min_at][6] = p[min_at][5] - p[min_at][2];
            p[min_at][3] = 1000; //increasing value of covered nodes
        }
        else
        {
            ct = p[min_at][2] + p[min_at][1];
            p[min_at][4] = ct;
            p[min_at][5] = p[min_at][4] - p[min_at][1];
            p[min_at][6] = p[min_at][5] - p[min_at][2];
            p[min_at][3] = 1000; //increasing value of covered nodes
        }
        
    }
    printf("\n\n");
    display();
    return 0;
}