#include <bits/stdc++.h>
using namespace std;
//作为一位合格的OIer,欧拉筛是必会技能
const int M=5e7+10;
int k,s,e,cnt;
int p[M];
bool f[M];
void init(){
	f[0]=f[1]=1;
	for(int i=2;i<=e;i++){
		if(f[i]==0){
			p[++k]=i;
		}for(int j=1;p[j]*i<=e;j++){
			f[p[j]*i]=1;
			if(i*p[j]>=s&&i*p[j]<=e&&f[i]==0) cnt++;
			if(i%p[j]==0) break;
		}
	}
}
int main(){
	cin>>s>>e;
	init();

	cout<<cnt;
	return 0;
}
