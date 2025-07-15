#include <bits/stdc++.h>
using namespace std;
int n,v,ln[21000],lv[21000],dp[21000],k,t=1,w,s,tv;
int main(){
	cin>>n>>v;
	for(int i=1;i<=n;i++){
		cin>>s>>w;tv=s;
		t=1;
		while(t<s){
			k++;
			ln[k]=t*w;
			lv[k]=t*tv;
			s=s-t;
			t*=2;
		}
		if(s>0){
			k++;
			ln[k]=s*w;
			lv[k]=s*tv;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=v;j>=ln[i];j--){
			dp[j]=max(dp[j],dp[j-ln[i]]+lv[i]);
		} 
	}
	cout<<dp[v];
	return 0;
}