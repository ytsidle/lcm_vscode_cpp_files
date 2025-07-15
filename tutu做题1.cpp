#include <bits/stdc++.h>
using namespace std;
int a,b,c,n,m,cnt=3,sum;
int main(){
	cin>>a>>b>>m>>n;
	sum=a+b;
//	cnt++;
	while(!(c>=m)&&cnt<=n){
		c=a+b;
		sum+=c;
		cnt++;
		a=b,b=c;

	}cout<<sum;
	return 0;
}
