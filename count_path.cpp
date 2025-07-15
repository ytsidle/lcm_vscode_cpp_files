#include <bits/stdc++.h>
using namespace std;
const int MAX=2e4+5;
int n,m,f[MAX],fa,fb,t[MAX],cnt;
bool a[MAX][MAX];
void out(){
	for(int i=1;i<=cnt;i++){
		f[t[i]]++;
		cout<<t[i]<<endl;
	}
}
void dfs(int num,int tnum){
	f[num]++;
	t[++cnt]=num;
	if(num!=tnum){
		for(int i=1;i<=n;i++){
	
		if(i!=num){
			bool flag=1;
			for(int j=1;j<cnt;j++){
				if(t[i]==num) flag=0;
			}if(flag){
				dfs(i,tnum);
				
			}
		}cnt--;
		
	}
	}else{
		out();
		cnt--;
	}


}
int main(){
	cin>>n>>m;
	for(int i=1;i<n;i++){
		scanf("%d%d",&fa,&fb);
		a[fa][fb]=1;
		a[fb][fa]=1;
	}for(int i=1;i<=m;i++){
		scanf("%d%d",&fa,&fb);
		dfs(fa,fb);
	}for(int i=1;i<=n;i++){
		printf("%d ",f[i]);
	}
	return 0;
}
