#include<iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    string a;
    cout<<"Enter String: ";
    cin>>a;
    cout<<"Enter frame size: ";
    int n;
    cin>>n;
    char f[n];
    int j = 0;
    int miss = 0;
    int hit = 0;
    for(int i = 0; i < a.length(); i++)
    {
        if(f[j] == a[i])
        {
            hit++;
            j = (j+1)%n;
        }
        else
        {
            miss++;
            f[j] = a[i];
            j = (j+1)%n;
        }
    }
    cout<<"Hit: "<<hit<<"\n";
    cout<<"Miss: "<<miss<<"\n";
    float hit_p = (float)hit*100/a.length();
    float miss_p = (float)miss*100/a.length();
    cout<<"Hit Percentage: "<<hit_p<<"\n";
    cout<<"Miss Percentage: "<<miss_p<<"\n";
    return 0;
}

