// SJF (static)

#include<stdio.h>
#include<sys/types.h>
// #define n 5

int p[10][6];
int copy[10];
int copy_2[10];
int min(int n)
{
    int min = p[0][1], i;
    for(i = 1; i < n; i++)
    {
        if(p[i][1] < min)
            min = p[i][1];
    }
    return min;
}

int find_min_pos(int m, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(p[i][1] == m)
            break;
    }
    return i;
}

int min_b(int n)
{
    int min = p[0][2], i;
    for(i = 1; i < n; i++)
    {
        if(p[i][2] < min)
            min = p[i][2];
    }
    return min;
}

int find_min_pos_bt(int m, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(p[i][2] == m)
            break;
    }
    return i;
}

void display(int n)
{
    int i, j;
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if(j == 1)
                printf("%d\t", copy[i]);
            else if(j == 2)
                printf("%d\t", copy_2[i]);
            else
                printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i, j, n;
    printf("Enter number of inputs(less than 10): ");
    scanf("%d", &n);
    printf("Enter data row-wise\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    for(i = 0; i < n; i++)
    {
        copy[i] = p[i][1];
    }
    for(i = 0; i < n; i++)
    {
        copy_2[i] = p[i][2];
    }
    int ct = 0, min_at;
    for(i = 0; i < n; i++)
    {
        min_at = find_min_pos(min(n), n);
        if(p[min_at][1] < ct)
        {
            int min_bt;
            min_bt = find_min_pos_bt(min_b(n), n);
            ct = p[min_bt][2] + ct;
            p[min_bt][3] = ct;
            p[min_bt][4] = p[min_bt][3] - p[min_bt][1];
            p[min_bt][5] = p[min_bt][4] - p[min_bt][2];
            p[min_bt][2] = 1000; //increasing value of covered nodes
        }
        else
        {
            ct = p[min_at][1] + p[min_at][2];
            p[min_at][3] = ct;
            p[min_at][4] = p[min_at][3] - p[min_at][1];
            p[min_at][5] = p[min_at][4] - p[min_at][2];
            p[min_at][1] = 1000; //increasing value of covered nodes
            p[min_at][2] = 1000; //increasing value of covered nodes
        }        
    }
    printf("\n\n");
    display(n);
    return 0;
}