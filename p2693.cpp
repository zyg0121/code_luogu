#include <iostream>
#include <set>
#include <vector>

int N;
std::vector<int> a(3);
std::vector<int> b(3);
std::set<std::vector<int> > _set;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin>>N;
	std::cin>>a[0]>>a[1]>>a[2];
	std::cin>>b[0]>>b[1]>>b[2];
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			for(int k=1;k<=5;k++) {
				std::vector<int> v(3);
				v[0] = (i+a[0]+N)%N;
 				v[1] = (j+a[1]+N)%N;
 				v[2] = (k+a[2]+N)%N;
 				
 				std::vector<int> v1(3);
				v1[0] = (i+b[0]+N)%N;
				v1[1] = (j+b[1]+N)%N;
				v1[2] = (k+b[2]+N)%N;
				
				_set.insert(v);
				_set.insert(v1);
			}
 	std::cout<<_set.size()<<std::endl;
 	return 0;
}
