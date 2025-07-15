#include <bits/stdc++.h>
using namespace std;
//作为一位合格的OIer,欧拉筛是必会技能
const int M=1e8+10;
int p[M],k,n;
bool f[M];
void init(){
	f[0]=f[1]=1;
	for(int i=2;i<=n;i++){
		if(f[i]==0){
			p[++k]=i;
		}for(int j=1;p[j]*i<=n;j++){
			f[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}
int main(){
	cin>>n;
	init();
	cout<<k;
//	for(int i=1;i<=k;i++) cout<<p[i]<<endl;
	return 0;
}
