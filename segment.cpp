#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int f[MAX],x[MAX][2],t,l,r,n,m;
bool is_du(int l,int r){
	int re=0;
	for(int i=l;i<=r;i++){
		if(f[i]){
			re++;
		}
	}if(re==1) return 0;
	else return 1;
}
int main(){
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		
		memset(f,0,sizeof(f));
		memset(x,0,sizeof(x));
		scanf("%d%d",&n,&m);
		int min_p=0,max_p=0,max_ps[MAX]={},cnt=0,max_cha=0;
		memset(max_ps,0,sizeof(max_ps));
		memset(f,0,sizeof(f));
		f[0]=INT_MAX;
		for(int i=1;i<=n;i++){
			
			scanf("%d%d",&x[i][0],&x[i][1]);
			l=x[i][0],r=x[i][1];
			
			
			for(int j=l;j<=r;j++){
				f[j]++;
				if(f[j]<f[min_p]){
					min_p=j;
				}else if(f[j]>f[max_p]){
					max_p=j;
				}
			}
		}for(int i=1;i<=n;i++){
			if(f[i]==f[max_p]){
				cnt++;
				max_ps[cnt]==i;
			}
		}
		memset(f,0,sizeof(f));
		f[0]=INT_MAX;
		for(int i=1;i<=n;i++){
			l=x[i][0],r=x[i][1];
			for(int i=1;i<=cnt;i++){
				max_p=max_ps[i];
				if(l<=max_p&&r>=max_p && is_du(l,r)){
					for(int j=l;j<=r;j++){
						f[j]++;
						if(f[j]<f[min_p]){
							min_p=j;
						}else if(f[j]>f[max_p]){
							max_p=j;
						}
					}	
				}max_cha=max(max_cha,f[max_p]-f[min_p]);
			}
	

		}cout<<max_cha<<endl;
		
		
	}
	
	return 0;
}
