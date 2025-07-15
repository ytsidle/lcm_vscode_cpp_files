#include <bits/stdc++.h>
using namespace std;
int x,y,z,n,m,ans;
int main(){
	cin>>x>>y>>z>>n>>m;
//	如果每只公鸡 x 元，每只母鸡 y 元，每 z 只小鸡 1 元；现在有 n 元，买了 m 只鸡，共有多少种方案？
	for(int i=0;i<=m;i++){
		for(int j=0;j<=m&&i+j<=m;j++){
			if(i*x+j*y+(m-i-j)/z==n&&(m-i-j)%z==0){
//				cout<<i<<" "<<j<<" "<<m-i-j<<endl;
				ans++;
			}
		}
	}cout<<ans;
	return 0;
}
