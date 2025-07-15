#include <bits/stdc++.h>
using namespace std;
const int M=1e4+10;
int T,n,k,q,task[M][3],s[M][M];
int solve(int c,int num,int lp){
	if(c==0){
		if(num!=1) return 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=s[i][0];j++){
				if(s[i][j]==num&&i!=lp) return 1;
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i!=lp){
			for(int j=2;j<=s[i][0];j++){
				if(s[i][j]==num){
					for(int len=2;len<=k;len++){
						int re=solve(c-1,s[i][j-len+1],i);
						if(re){
//							cout<<s[i][j-len+1]<<"|"<<s[i][j]<<endl;
							return re;
						} 
					}
				}
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&s[i][0]);
			for(int j=1;j<=s[i][0];j++){
				scanf("%d",&s[i][j]);
			}
		}
		for(int i=1;i<=q;i++){
			scanf("%d%d",&task[i][1],&task[i][2]);
			int r=solve(task[i][1],task[i][2],0);
			printf("%d\n",r);
		}
	}
	return 0;
}
