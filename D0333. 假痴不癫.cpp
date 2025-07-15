#include <bits/stdc++.h>
using namespace std;
int n,k;
int is_p[6000];
int main(){
	cin>>n>>k;
	is_p[0]=0;
	is_p[1]=1;
	for(int i=2;i<=5600;i++){
		is_p[i]=1;
		for(int j=2;j<=sqrt(i);j++){
			is_p[i]&=!(i%j==0);
		}
	}
	
	for(int i=1;i<=n;i++){
		if(is_p[i]) continue;
		for(int j=i-1;j>=max(1,i-k);j--){
			if(!is_p[j]){
				//敌方先下必输
				is_p[i]=1;
			}
		}
	}
	if(is_p[n]) cout<<"33DAI";
	else cout<<"Kitten";
	return 0;
}
