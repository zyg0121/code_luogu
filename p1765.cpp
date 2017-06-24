#include <bits/stdc++.h>
using namespace std;

string a;
int total;

int main()
{
	ios::sync_with_stdio(false);
	getline(cin,a);
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='a'||a[i]=='d'||a[i]=='g'||a[i]=='j'||a[i]=='m'||
		   a[i]=='p'||a[i]=='t'||a[i]=='w'||a[i]==' ')
		   total++;
		if(a[i]=='b'||a[i]=='e'||a[i]=='h'||a[i]=='k'||a[i]=='n'||
		   a[i]=='q'||a[i]=='u'||a[i]=='x')
		   	total+=2;
		if(a[i]=='c'||a[i]=='f'||a[i]=='i'||a[i]=='l'||a[i]=='o'||
		   a[i]=='r'||a[i]=='v'||a[i]=='y')
		   	total+=3;
		if(a[i]=='s'||a[i]=='z')
			total+=4;
	}
	cout<<total<<endl;
	return 0;
}
