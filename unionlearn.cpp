#include <bits/stdc++.h>
using namespace std;
union un{
	int a,b,c;
	char t;
}U;
int main(){
	cin>>U.a;
	cin>>U.b;
	cout<<U.b<<" "<<U.a;
	return 0;
}
