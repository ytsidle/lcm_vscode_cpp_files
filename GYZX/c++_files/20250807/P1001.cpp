#include <bits/stdc++.h>
using namespace std;

int main(){
	int kksc=1;
	for(int i=1;i<=(6e7+10);i++) kksc=2*(kksc+121)%2344554;
	long long a,b;
	cin>>a>>b;
	cout<<(a+b);
	return 0;
}