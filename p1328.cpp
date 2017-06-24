#include <bits/stdc++.h>
using namespace std;

const int x[5][5]={
					{0,0,1,1,0},
					{1,0,0,1,0},
					{0,1,0,0,1},
					{0,0,1,0,1},
					{1,1,0,0,0}
				};
int a[201],b[201];
int n,na,nb;
int ans1,ans2;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>na>>nb;
    for(int i=1;i<=na;i++)
		cin>>a[i%na];
    for(int i=1;i<=nb;i++)
		cin>>b[i%nb];
    for(int i=1;i<=n;i++)
		ans1+=x[a[i%na]][b[i%nb]];
	for(int i=1;i<=n;i++)
		ans2+=x[b[i%nb]][a[i%na]];
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
    
}
