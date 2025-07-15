#include <bits/stdc++.h>
using namespace std;
const int M=1e7+10;
long long p[M];
int f[M],k,use[10],len;
char s[10]="";
void build(){
	f[0]=f[1]=1;
	for(int i=2;i<=M;i++){
		if(f[i]==0){
			p[++k]=i;
		}
		for(int j=1;j<=k&&i*p[j]<=M;j++){
			f[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
//dfs暴力枚举所有可能
void dfs(int c,int sum){
	if(c==len+1){
		if(f[sum]==0){
			//是质数
			//保证肯定是最小
			cout<<sum<<endl;
			exit(0);
		}return;
	}
	
	for(int i=1;i<=len;i++){
		if(!use[i]){
			use[i]=1;
			dfs(c+1,sum*10+(s[i]-'0'));
			use[i]=0;
		}
	}
}

int main(){
	build();
	scanf("%s",s+1);
	len=strlen(s+1);
	sort(s+1,s+1+strlen(s+1));
//	cout<<s[1];
	dfs(1,0);
	cout<<-1;
	return 0;
}
