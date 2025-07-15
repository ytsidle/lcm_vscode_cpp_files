#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=2e5+10;
int n,m;
//链式前向星
struct Edge{
	int v,tp,next;
}edge[2*M]; 
int pre[N],k,rb[N],s,t,d[N];
map<int,int> vis;
void add(int u,int v){
	edge[++k]={v,1,pre[u]};
	pre[u]=k;
	edge[++k]={u,2,pre[v]};
	pre[v]=k;
}
void bfs(int num){
	queue<int> q;
	q.push(num);
	
	while(!q.empty()) {
		int head=q.front();
		rb[head]=1;
		q.pop();
		for(int i=pre[head];i;i=edge[i].next){
			if(edge[i].tp==2){
				q.push(edge[i].v) ;
				
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
	}
	cin>>s>>t;
	bfs(t);

	memset(d,0x3f,sizeof(d));
	d[s]=0;
	for(int i=1;i<=n;i++){
		for(int j=pre[i];j;j=edge[j].next){
			if(edge[j].tp==1){
				rb[i]=(rb[i]&&rb[edge[j].v]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		int mi=0;
		for(int j=1;j<=n;j++){
			if(d[j]<d[mi]&&vis[j]==0) mi=j;
		}
		if(mi==0) continue;
		vis[mi]=1;
//		cout<<"MI:"<<mi<<endl;
		for(int j=pre[mi];j;j=edge[j].next){
			if(edge[j].tp==1&&vis[edge[j].v]==0&&rb[edge[j].v]){
//				cout<<edge[j].v<<endl;
				if(d[mi]+1<d[edge[j].v]){
					d[edge[j].v]=d[mi]+1;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++) cout<<rb[i]<<" ";
//	cout<<endl;
	if(d[t]==0x3f3f3f3f)cout<<-1;
	else cout<<d[t];
	return 0;
}