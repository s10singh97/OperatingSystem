// Bankers Algo

#include<iostream>
using namespace std;

int main()
{
    int p, r;
    cout<<"Enter number of resorces: ";
    cin>>r;
    cout<<"Enter number of processes: ";
    cin>>p;
    int mm[p][r], am[p][r], nm[p][r];
    cout<<"Enter Maximum Matrix: \n";
    for(int i = 0; i < p; i++)
        for(int j = 0; j < r; j++)
            cin>>mm[i][j];
    for(int i = 0; i < p; i++)
    {
        for(int j = 0; j < r; j++)
        {
            cout<<mm[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"Enter Allocation Matrix: \n";
    for(int i = 0; i < p; i++)
        for(int j = 0; j < r; j++)
            cin>>am[i][j];
    for(int i = 0; i < p; i++)
    {
        for(int j = 0; j < r; j++)
        {
            cout<<am[i][j]<<"\t";
        }
        cout<<"\n";
    }
    for(int i = 0; i < p; i++)
        for(int j = 0; j < r; j++)
            nm[i][j] = mm[i][j] - am[i][j];
    cout<<"Need Matrix : \n";
    for(int i = 0; i < p; i++)
    {
        for(int j = 0; j < r; j++)
        {
            cout<<nm[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"Enter Total matrix\n";
    int t[r];
    for(int i = 0; i < r; i++)
        cin>>t[i];
    for(int i = 0; i < r; i++)
        cout<<t[i]<<"\t";
    cout<<"\n";
    int ca[r], temp[r];
    for(int i = 0; i < r; i++)
    {
        int sum = 0;
        for(int j = 0; j < p; j++)
        {
            sum += am[j][i];
        }
        temp[i] = sum;
    }
    cout<<"Current Available Matrix: \n";
    for(int i = 0; i < r; i++)
    {
        ca[i] = t[i] - temp[i];
    }
    for(int i = 0; i < r; i++)
    {
        cout<<ca[i]<<"\t";
    }
    cout<<"\n";

    int flag[p][r];
    cout<<"\nSafe sequence: ";
    for(int i = 0; i < p; i++)
        for(int j = 0; j < r; j++)
            flag[i][j] = 0;
    for(int k = 0; k < p; k++)
    {
        for(int i = 0; i < p; i++)
        {
            for(int j = 0; j < r; j++)
            {
                if(nm[i][j] <= ca[j])
                    flag[i][j] = 1;
                else
                    flag[i][j] = 0;                
            }
        }
        for(int i = 0; i < p; i++)
        {
            int sum = 0;
            for(int j = 0; j < r; j++)
            {
                sum += flag[i][j];
            }
            if(sum == 3)
            {
                cout<<"P"<<i<<"\t";
                for(int j = 0; j < r; j++)
                {
                    ca[j] += am[i][j];
                    nm[i][j] = 1000; //Increasing value of covered processes
                }
            }
        }
    }
    return 0;
}