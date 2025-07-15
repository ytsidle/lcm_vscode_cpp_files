#include <bits/stdc++.h>
using namespace std;
int T,a,b;
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b;
		if(b-a==0) cout<<0<<endl;
		else if((b-a)%2==1||(a-b>=0&&(a-b)%2==0)) cout<<1<<endl;
		else{
			int z=b-a;
			if(z>0){
				if((z/2)%2==0) cout<<3<<endl;
				else cout<<2<<endl;
			}
			if(z<0){
				z=a-b;
				cout<<2<<endl;
			}
		}
	}
	return 0;
}
/*
1:b-a是一个奇数
1:a-b>=0&&a-b是一个偶数
否则:
z=b-a
kx-ay=z(k+a min)
*/