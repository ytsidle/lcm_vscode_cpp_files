#include <bits/stdc++.h>
using namespace std;
int a,b,n,m;
long long get_num(int day){
	if(day==1) return a;
	else if(day==2) return b;
	return get_num(day-1)+get_num(day-2);
}
int main(){
	
	cin>>a>>b>>m>>n;
	long long num=get_num(n);
	if(num<=m) cout<<num;
	else cout<<m;
	return 0;
}
