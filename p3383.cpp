#include <bits/stdc++.h>
using namespace std;

const int size = 10001000;
bool notprime[size];
int n,m;

int main()
{
    int n,m;
    cin>>n>>m;
    notprime[0]=notprime[1]=true;
    for(int i=2;i<n;i++)
        if(!notprime[i])
            for(int j=i+i;j<=n;j+=i)
                notprime[j]=true;
    for(int i=0;i<m;i++)
	{
        int d;
        cin>>d;
        if(notprime[d])cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}
