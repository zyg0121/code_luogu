#include <bits/stdc++.h>
using namespace std;

string str;
int n;

void dfs(int sta,int end)
{
	int mid=(end+sta)/2;
	if(sta!=end)
	{
		dfs(sta,mid);
		dfs(mid+1,end);
	}
	int sum0 = 0,sum1 = 0;
	for(int i=sta;i<=end;i++)
	{
		if(str[i]=='0')
			sum0++;
		else
			sum1++;
	}
	if(end-sta+1==sum0)
		cout<<'B';
	else if(end-sta+1==sum1)
		cout<<'I';
	else
		cout<<'F';
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>str;
	int len=str.size();
	dfs(0,len-1);
	cout<<endl;
	return 0;
}
