// LRTF

#include<iostream>
using namespace std;

int p[10][6];
int c_bt[10];

int min(int n)
{
    int min = 1000;
    for(int i = 0; i < n; i++)
        if(p[i][1] < min)
            min = p[i][1];
    return min; 
}

int find_min_pos(int m, int n)
{
    int i;
    for(i = 0; i < n; i++)
        if(p[i][1] == m && p[i][2] > 0)
            break;
    return i;
}

int max(int n, int ct)
{
    int max = 0;
    for(int i = 0; i < n; i++)
        if(p[i][2] > max && p[i][1] <= ct)
            max = p[i][2];
    return max;
}

int max_pos(int m, int n)
{
    int i;
    for(i = 0; i < n; i++)
        if(p[i][2] == m && p[i][2] > 0)
            break;
    return i;
}

int sum_of_bt(int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += p[i][2];
    return sum;
}

void display(int n)
{
    cout<<"PID\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(j == 2)
                cout<<c_bt[i]<<"\t";
            else
                cout<<p[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

int main(int argc, char const *argv[])
{
    cout<<"Enter number of Processes: ";
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cin>>p[i][j];
    for(int i = 0; i < n; i++)
        c_bt[i] = p[i][2];
    int min_at, ct = 0;
    for(int i = 0; sum_of_bt(n) != 0; i++)
    {
        min_at = find_min_pos(min(n), n);
        if(p[min_at][1] <= ct)
        {
            int max_bt = max_pos(max(n, ct), n);
            ct += 1;
            p[max_bt][3] = ct;
            p[max_bt][2] -= 1;
            p[max_bt][4] = p[max_bt][3] - p[max_bt][1];
            // display(n);
        }
        else
        {
            ct = p[min_at][1] + 1;
            p[min_at][3] = ct;
            p[min_at][2] -= 1;
            p[min_at][4] = p[min_at][3] - p[min_at][1];
            // display(n);
        }
    }
    for(int i = 0; i < n; i++)
        p[i][5] = p[i][4] - c_bt[i];
    display(n);
    return 0;
}
