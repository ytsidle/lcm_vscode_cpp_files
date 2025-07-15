#include <bits/stdc++.h>
using namespace std;
const int MAX=505;
int f[MAX][MAX],n,ans;
void fun(int a,int b){
	int i=n+1-a,j=n+1-b;
	if(i>=a){
		if(i==a){
			if(j>b){
				if(f[a][b]==f[i][j]){
//					cout<<a<<" "<<b<<" "<<i<<" "<<j<<endl;
					ans++;
				}
			}
		}else{
			if(f[a][b]==f[i][j]){
//				cout<<a<<" "<<b<<" "<<i<<" "<<j<<endl;
				ans++;
			}
		}
	}
	
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&f[i][j]);
			
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			fun(i,j);
		}
	}
cout<<ans;
	return 0;
}
