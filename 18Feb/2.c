// SJF (dynamic-simple average)

#include<stdio.h>
#include<sys/types.h>

float p[10][4];
int copy[10];
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

void display(int n)
{
    int i, j;
    printf("PID\tAT\tBT\tPredicted BT\n\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(j == 1)
                printf("%d\t", copy[i]);
            else
                printf("%.1f\t", p[i][j]);
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
            scanf("%f", &p[i][j]);
        }
    }
    for(i = 0; i < n; i++)
    {
        copy[i] = p[i][1];
    }
    int min_at, sum = 0;
    for(i = 0; i < n; i++)
    {
        min_at = find_min_pos(min(n), n);
        sum = sum + p[min_at][2];
        p[min_at][3] = (float)(sum)/(i+1);
        p[min_at][1] = 1000; // Increase the value of covered node 
    }
    display(n);
    return 0;
}