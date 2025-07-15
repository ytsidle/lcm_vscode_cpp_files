#include <bits/stdc++.h>
using namespace std;
int n,k,now,whom=0;
int is_p[6000],pr[6000],cnt;
int find(int num){
	for(int i=cnt;i>=1;i--){
		if(pr[i]<=num) return i;
	}return 0;
}
int main(){
	cin>>n>>k;
	is_p[0]=0;
	pr[++cnt]=0;
	is_p[1]=1;
	pr[++cnt]=1;
	for(int i=2;i<=6000;i++){
		is_p[i]=1;
		for(int j=2;j<=sqrt(i);j++){
			is_p[i]&=!(i%j==0);
		}
		if(is_p[i])pr[++cnt]=i;
	}
	if(is_p[n]){
		cout<<"33DAI";
		exit(0);
	}
	now=n;
	while(1){
		if(is_p[now]){
			if(whom==0) cout<<"33DAI";
//			cout<<whom;
			else cout<<"Kitten";
			exit(0);
		}
		//使其尽可能让它离质数最近
		now-=k;
		if((now-pr[find(now)])%2==0&&k==2) now++;
		whom^=1;
	}
	return 0;
}
