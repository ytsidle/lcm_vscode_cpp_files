#include <bits/stdc++.h>
using namespace std;
const int M=1e5+10;

int depth[M],f[M];
vector<int> c[M],ans;
int n,a,b;
void dfs(){
	queue<int> q;
	q.push(1);
	depth[1]=1;
	while(!q.empty()){
		int num=q.front();
		for(int i=0;i<c[num].size();i++){
			if(c[num][i]!=f[num]){
				f[c[num][i]]=num;
				depth[c[num][i]]=depth[num]+1;
				q.push(c[num][i]);
			}
		}
		q.pop();
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		c[b].push_back(a);
		c[a].push_back(b);
	}
	dfs();
	scanf("%d%d",&a,&b);
	int ad=depth[a],bd=depth[b];
	while(a!=b){
		if(ad>bd){
			ad--;
			a=f[a];
		}else{
			bd--;
			b=f[b];
		}
	}
	ans.push_back(b);
	while(b!=1){
		b=f[b];
		ans.push_back(b);
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	return 0;
}
