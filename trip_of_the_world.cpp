#include <bits/stdc++.h>
using namespace std;
const int MAXS=1.2e6+10;
int f[MAXS],v[MAXS],w[MAXS],p[MAXS],n,m,tv,tw,tp,k,t;
int main(){
	scanf("%d%d",&n,&m);
	t=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&tw,&tp,&tv);//tw体积,tp价值,tv个数
		if(tv!=0){
			//二进制
			k=1;
			while(k<=tv){
				w[++t]=k*tw;
				p[t]=k*tp;
				v[t]=1;
				tv-=k;
				k*=2;
			}
			if(tv>0){
				w[++t]=tv*tw;
				p[t]=tv*tp;
				v[t]=1;
			}
		}else{
			w[++t]=tw;
			p[t]=tp;
			v[t]=tv;
		}
	}
	for(int i=1;i<=t;i++){
		if(v[i]==0){
			for(int j=w[i];j<=m;j++){
				f[j]=max(f[j],(f[j-w[i]]+p[i]));
			}
		}else{
			for(int j=m;j>=w[i];j--){
				f[j]=max(f[j],f[j-w[i]]+p[i]);
			}
		}
	}printf("%d",f[m]);
	return 0;
}
