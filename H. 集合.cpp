#include <bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int p[M],k,a,b,pn;
bitset<M> f;
void init(){
	f[0]=f[1]=1;
	for(int i=2;i<=b;i++){
		if(!f[i]){
			p[++k]=i;
		}
		for(int j=1;j<=k;j++){
			f[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
int main(){
	cin>>a>>b>>pn;
	init();
	int pup=lower_bound(p,p+1+k,max(a,pn))-p;
	for(int i=pup;p[i]<=b;i++){
		while(int j=1;p[i]*j<=b;j++){
			
		}
	}
	return 0;
}
