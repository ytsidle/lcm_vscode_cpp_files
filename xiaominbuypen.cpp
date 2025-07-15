#include <bits/stdc++.h>
using namespace std;
int x,y,z,q,sum;
int main(){
	cin>>x>>y>>z>>q;
	sum=2*x+5*y+3*z;
	if(sum<=q){
		cout<<"Yes"<<endl<<q-sum;
	}else cout<<"No\n"<<sum-q;
	return 0;
}
