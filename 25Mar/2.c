// Priority With Preemption

#include<stdio.h>
#include<sys/types.h>

int p[10][7];
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

int min_b(int n, int ct)
{
    int min = -1, i;
    for(i = 0; i < n; i++)
    {
        if(p[i][3] > min && p[i][1] <= ct && p[i][2] > 0)
            min = p[i][3];
    }
    return min;
}

int find_min_pos_bt(int m, int n, int ct)
{
    int a = -1, i;
    for(i = 0; i < n; i++)
    {
        if(p[i][3] == m)
        {
            a=i;
            break;
        }
    }
    return a;
}

void display(int n)
{
    int i, j;
    printf("PID\tAT\tBT\tPri\tCT\tTAT\tWT\n\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 7; j++)
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

int sum_of_bt(int n)
{
    int i, sum = 0;
    for(i = 0; i < n ;i++)
        sum += p[i][2];
    return sum;
}

int main()
{
    int i, j, n;
    printf("Enter number of inputs(less than 10): ");
    scanf("%d", &n);
    printf("Enter data row-wise\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 4; j++)
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
    int min_at = min(n);
    int ct = min_at;
    int sobt = sum_of_bt(n);
    for(i = min_at; i < sobt+min_at; i++)
    {
        // min_at = find_min_pos(min(n), n);
        // if((p[min_at][1] <= ct) && (p[min_at][2] > 0))
            int min_bt;
            min_bt = find_min_pos_bt(min_b(n, ct), n, ct);
            ct = ct + 1;
            if(min_bt != -1)
            {  
                p[min_bt][2] -= 1;
                p[min_bt][4] = ct;
                p[min_bt][5] = p[min_bt][4] - p[min_bt][1];
            }          
    }
    // for Waiting Time
    for(i = 0; i < n; i++)
    {
        p[i][6] = p[i][5] - copy_2[i];
    }
    printf("\n\n");
    display(n);
    return 0;
}