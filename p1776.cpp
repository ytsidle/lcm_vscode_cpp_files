#include <bits/stdc++.h>
using namespace std;
const int MAX=1.7e6+10;
const int FMAX=4e5+10;
/*
价v,重w,量m
*/
int n,cw,f[FMAX],tv,tw,tms,v[MAX],w[MAX],k,s;//cw表车载能力
int main(){
	scanf("%d%d",&n,&cw);
	s=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&tv,&tw,&tms);
		k=1;
		while(k<=tms){
			v[++s]=tv*k;
			w[s]=tw*k;
			tms-=k;
			k*=2;
		}if(tms>0){
			v[++s]=tv*tms;
			w[s]=tw*tms;
		}
	}

	for(int i=1;i<=s;i++){
		for(int j=cw;j>=w[i];j--){
			f[j]=max(f[j],(f[j-w[i]]+v[i]));
		}

	}printf("%d",f[cw]);
	return 0;
}
