#include <bits/stdc++.h>
using namespace std;
int n,ans=1;
int main(){
	cin>>n;
	int a=n%10;
	n/=10;
	int b=n%10;
	n/=10;
	int c=n%10;
	int mi=min(a,min(b,c));
	int ma=max(a,max(b,c));
	cout<<mi+9-ma+(c!=mi);
	return 0;
}
