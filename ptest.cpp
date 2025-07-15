#include <bits/stdc++.h>
using namespace std;
int a,*b;
int* p;
int main(){
	scanf("%d",&a);
//	cout<<a<<" "<<b<<endl;
	p=&a;
	b=p;
	cout<<*&a<<" "<<*b<<" "<<p<<endl;
	a*=*b;
	cout<<a<<" "<<*b;
	return 0;
}
