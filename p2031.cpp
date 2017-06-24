#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

string word[501],str;
int f[501];
int n,m;

bool cmp(int,int,int);
bool match(int,int);

int main()
{
	cin>>str;
	n=str.length();
	str=" "+str;
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>word[i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			if(match(j+1,i))
				f[i]=max(f[i],f[j]+1);
	cout<<f[n]<<endl;
	return 0;
}

bool cmp(int i,int r,int x)
{
	if(r-i+1<word[x].length())
		return false;
	for(int j=0;j<word[x].length();j++,i++)
		if(str[i]!=word[x][j])
			return false;
	return true;
}

bool match(int l,int r)
{
	for(int i=l;i<=r;i++)
		for(int j=1;j<=m;j++)
			if(cmp(i,r,j))
				return true;
	return false;
}
