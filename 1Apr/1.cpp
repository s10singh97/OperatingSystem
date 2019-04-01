#include<iostream>
#include<queue>
#include<exception>
using namespace std;

int p[10][6];
int cp[10];
int cp_2[10];
int min(int n)
{
    int min = 100, i;
    for(i = 0; i < n; i++)
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
    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if(j == 1)
                printf("%d\t", cp[i]);
            else if(j == 2)
                printf("%d\t", cp_2[i]);
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

bool remaining(int n)
{
    for(int i = 0; i < n; i++)
    {
        if(p[i][2] > 0)
            return true;
    }
    return false;
}

int main() try
{
    int i, j, n, tq;
    queue<int> q;
    cout<<"Enter number of inputs(less than 10): ";
    cin>>n;
    cout<<"Enter data row-wise\n";
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 3; j++)
        {
            cin>>p[i][j];
        }
    }
    cout<<"Enter Time Quanta: ";
    cin>>tq;
    for(i = 0; i < n; i++)
        cp[i] = p[i][1];
    for(i = 0; i < n; i++)
        cp_2[i] = p[i][2];
    cout<<"Gant Chart\n";
    int min_at = min(n);
    int ct = min_at;
    int sobt = sum_of_bt(n);
    int min_aat = find_min_pos(min(n), n), lt;
    q.push(p[min_aat][0]);
    // printf("Hello\n");
    for(i = 0; sum_of_bt(n) != 0; i++)
    {    
        // printf("Hello_22\n");
            int ex = q.front();
            q.pop();
            printf("|P%d\t", ex);
            if(p[ex-1][2] >= tq)
            {
                lt = ct;
                ct += tq;
                p[ex-1][3] = ct;
                p[ex-1][2] -= tq;
            }
            else
            {
                lt = ct;
                ct += p[ex-1][2];
                p[ex-1][3] = ct;
                p[ex-1][2] = 0;
            }
            
            for(i = 0; i < n; i++)
            {
                if(p[i][1] > lt && p[i][1] <= ct && p[i][2] > 0)
                    q.push(p[i][0]);
            }
            if(p[ex-1][2] > 0)
                q.push(p[ex-1][0]);
            else
                p[ex-1][1] = 1000; //Covered nodes      
    }
    for(i = 0; i < n; i++)
    {
        p[i][4] = p[i][3] - cp[i];
        p[i][5] = p[i][4] - cp_2[i];
    }
    display(n);
    return 0;
}
catch(exception &e){
    cout<<e.what();
}