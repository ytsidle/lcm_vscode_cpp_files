#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	cin>>n>>m;
	for(int i=0;i<=n/5;i++){
		for(int j=0;j<=n/3;j++){
			for(int x=0;x/3<=(n-5*i-3*j);x+=3){
				if(i+x+j==m&&x/3+i*5+j*3==n){
					cout<<i<<" "<<j<<" "<<x<<endl;
				}
			}
		}
	}
	return 0;
}
