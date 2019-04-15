// Memory Allocation

#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout<<"Enter memory partition size: ";
    int n;
    cin>>n;
    int m[n];
    cout<<"Enter partition\n";
    for(int i = 0; i < n; i++)
        cin>>m[i];
    cout<<"Enter number of request: ";
    int r;
    cin>>r;
    int a[r];
    cout<<"Enter request block size\n";
    for(int i = 0; i < r; i++)
        cin>>a[i];
    int copy_m[n];
    for(int i = 0; i < n; i++)
        copy_m[i] = m[i];
    // First Fit
    cout<<"\nFirst Fit Sequence:\n";
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i] < m[j])
            {
                cout<<a[i]<<" -> "<<copy_m[j]<<"\n";
                m[j] -= a[i];
                break;
            }            
        }
    }

    int flag[r][n];
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < n; j++)
            flag[i][j] = 0;
    }


    for(int i = 0; i < n; i++)
        m[i] = copy_m[i];
    // Best Fit
    cout<<"\nBest Fit Sequence:\n";
    int bb[r][n];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < n; j++)
            bb[i][j] = 1000;  //Random High value
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i] < m[j])
            {
                bb[i][j] = m[j] - a[i];
            }
        }
    }
    // for(int i = 0; i < r; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout<<bb[i][j]<<"\t";
    //     }
    //     cout<<"\n";
    // }
    int j;
    for(int i = 0; i < r; i++)
    {
        int min = 999;
        for(j = 0; j < n; j++)
        {
            int k;
            if(bb[i][j] < min)
            {
                int sum = 0;
                for(k = 0; k < i; k++)
                {
                    if(flag[k][j] == 0)
                        sum += 1;
                }
                if(sum == i)
                    min = bb[i][j];
            }
        }
        for(j = 0; j < n; j++)
        {
            if(bb[i][j] == min && flag[i][j] == 0)
                break;
        }
        if(a[i] < m[j] && flag[i][j] == 0)
        {
            cout<<a[i]<<" -> "<<copy_m[j]<<"\n";
            flag[i][j] = 1;
        }
    }


    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < n; j++)
            flag[i][j] = 0;
    }

    for(int i = 0; i < n; i++)
        m[i] = copy_m[i];
    // Worst Fit
    cout<<"\nWorst Fit Sequence:\n";
    // int bb[r][n];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < n; j++)
            bb[i][j] = 0;  //Random Low value
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i] < m[j])
            {
                bb[i][j] = m[j] - a[i];
            }
        }
    }
    // for(int i = 0; i < r; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout<<bb[i][j]<<"\t";
    //     }
    //     cout<<"\n";
    // }
    for(int i = 0; i < r; i++)
    {
        int max = 0;
        for(j = 0; j < n; j++)
        {
            int k;
            if(bb[i][j] > max)
            {
                int sum = 0;
                for(k = 0; k < i; k++)
                {
                    if(flag[k][j] == 0)
                        sum += 1;
                }
                if(sum == i)
                    max = bb[i][j];
            }
        }
        for(j = 0; j < n; j++)
        {
            if(bb[i][j] == max && flag[i][j] == 0)
                break;
        }
        if(a[i] < m[j] && flag[i][j] == 0)
        {
            cout<<a[i]<<" -> "<<copy_m[j]<<"\n";
            flag[i][j] = 1;
        }
    }
    return 0;
}
