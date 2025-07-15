#include <bits/stdc++.h>
using namespace std;
const int MAX=2e4+20;
const long long L=1e9+10;
int m,l,a[MAX],s[MAX],b[MAX],li[MAX],pos[L][2],k[MAX],n,shen,klen;//k表示编号为i的人从几号出
unsigned long long sum;
int main(){
	//输入部分
	scanf("%d%d%d",&n,&m,&l);
	for(int i=2;i<=m;i++){
		scanf("%d",&a[i]);
	}
	a[1]=0;
	for(int i=1;i<=m;i++){
		scanf("%d",&li[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d",&s[i],&b[i]);
		pos[b[i]][0]=i;
	}
	shen=n;
	//开始处理
	while(shen>=1){
		if(shen!=1){
			for(int i=1;i<=n;i++){
				if(find(a,a+m+1,b[i])==a+m || li[b[i]]==0 && b[i]!=-1){
					int p=b[i];
					if(s[i]==0){
						if(p<l){
							pos[p][0]=pos[p][1];
							pos[p][1]=0;
							if(pos[p+1][0]!=0) pos[p+1][1]=i,b[i]=p+1;
							else pos[p+1][0]=i,b[i]=p+1;
						}else{
							pos[p][0]=pos[p][1];
							pos[p][1]=0;
							if(pos[0][0]!=0) pos[0][1]=i;
							else pos[0][0]=i;
							b[i]=0;
						}
					}
					if(s[i]==1){
						if(p>0){
							pos[p][0]=pos[p][1];
							pos[p][1]=0;
							if(pos[p-1][0]!=0) pos[p-1][1]=i,b[i]=p-1;
							else pos[p-1][0]=i,b[i]=p-1;
						}else{
							pos[p][0]=pos[p][1];
							pos[p][1]=0;
							if(pos[l][0]!=0) pos[l][1]=i,b[i]=l;
							else pos[l][0]=i,b[i]=l;
						}
					}
					
				}
				int *tpp=find(a+1,a+m+2,b[i]);
				if(tpp != a+m && li[b[i]] != 0){
					shen-=1;
					klen++;
					k[klen]=tpp-a;
					li[tpp-a]--;
				}
			}
		}else{
			bool type=1;
			klen++;
			for(long long i=1;i<=m;i++){
				if(li[i]!=0){
					k[klen]=i;
					type=0;
					break;
				}
			}if(type) k[klen]=0;
		}
	}
	//异或和计算
	sum=1*k[1];
	for(unsigned long long i=2;i<=klen;i++){
		sum=sum^(i*k[i]);
	}
	printf("%llu",&sum);
	return 0;
}
