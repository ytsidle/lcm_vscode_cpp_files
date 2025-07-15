#include <bits/stdc++.h>
using namespace std;
const int MAX=505;
int f[MAX][MAX],n,ans;
void fun(int a,int b){
	for(int i=1;i<=a;i++){
		if(i==a){
			for(int j=1;j<b;j++){
				if(i+a==n+1&&j+b==n+1&&f[a][b]==f[i][j]){
					ans++;
					cout<<a<<" "<<b<<" "<<i<<endl;				}
			}
		}else{
			for(int j=1;j<=n;j++){
				if(i+a==n+1&&j+b==n+1&&f[a][b]==f[i][j]){
					ans++;
					cout<<a<<" "<<b<<" "<<i<<endl;
				}
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&f[i][j]);
			fun(i,j);
		}
	}
    cout<<ans;
	return 0;
}
