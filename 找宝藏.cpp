#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+10,M=1e6+10;
int n,r,c;
struct node{
	int x,y,id,type;
}p[N];
int have1[M],have2[M];
int pre[N],nex[M],to[M],tot;
int pre2[N],nex2[M],to2[M],tot2;
map<pair<int,int>,int> mp;
int dfn[N],low[N],timestamp;
int scc[N],si[N],cnt;
int stk[N],top;
int in[N];
queue<int> q;
int f[N];
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={-1,1,-1,0,1,-1,0,1};
void add(int u,int v){
	to[++tot]=v;
	nex[tot]=pre[u];
	pre[u]=tot;
}
void add2(int u,int v){
	to2[++tot2]=v;
	nex2[tot2]=pre2[u];
	pre2[u]=tot2;
}
int cmp1(node n1,node n2){
	return n1.x<n2.x||n1.x==n2.x&&n1.type<n2.type;
}
int cmp2(node n1,node n2){
	return n1.y<n2.y||n1.y==n2.y&&n1.type>n2.type;
}
void tarjan(int u){
	dfn[u]=low[u]=++timestamp;
	stk[top++]=u;
	for(int v,i=pre[u];i;i=nex[i]){
		v=to[i];
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(!scc[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		cnt++;
		do{
			si[cnt]++;
			scc[stk[--top]]=cnt;
		}while(stk[top]!=u);
	}
}
void addEdge(){
	sort(p+1,p+1+n,cmp1);
	for(int i=1;i<=n;){
		if(!have1[p[i].x]){
			int now_x=p[i].x;
			do{
				i++;
			}while(p[i].x==now_x);
			continue;
		}
		int now_x=p[i].x=p[i].x,now=p[i].id;
		int last_i=i;
		i++;
		while(p[i].x==now_x&&p[i].type==1&&i<=n){
			add(p[i-1].id,p[i].id);
			i++;
		}
		add(p[i-1].id,p[last_i].id);
		while(p[i].x==now_x&&i<=n){
			add(now,p[i].id);
			i++;
		}
	}
	sort(p+1,p+1+n,cmp2);
	for(int i=1;i<=n;){
		if(!have2[p[i].y]){
			int  now_y=p[i].y;
			do{
				i++;
			}while(p[i].y==now_y);
			continue;
		}
		int now_y=p[i].y,tmp=i;
		while(p[i].y==now_y&&i<=n&&p[i].type==3) i++;
		int now=p[i].id,last_i=i;
		i++;
		while(p[i].y==now_y&&i<=n&&p[i].type==2){
			add(p[i-1].id,p[i].id);
			i++;
		}
		add(p[i-1].id,p[last_i].id);
		while(p[i].y==now_y&&i<=n){
			add(now,p[i].id);
			i++;
		}
		int j=tmp;
		while(p[j].y==now_y&&j<=n&&p[j].type==3){
			add(now,p[j].id);
			j++;
		}
	}
	pair<int,int> pair;
	for(int i=1;i<=n;i++){
		if(p[i].type==3){
			int x=p[i].x,y=p[i].y,id=p[i].id,tx,ty;
			for(int k=0;k<8;k++){
				tx=x+dx[k];
				ty=y+dy[k];
				pair={tx,ty};
				if(mp.find(pair)!=mp.end()) add(id,mp[pair]);
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&r,&c);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].type);
		p[i].id=i;
		mp[ {p[i].x,p[i].y}]=i;
		if(p[i].type==1) have1[p[i].x]=1;
		if(p[i].type==2) have2[p[i].y]=1;
	}
	addEdge();
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++){
		for(int j=pre[i];j;j=nex[j]){
			if(scc[i]!=scc[to[j]]) {
				add2(scc[i],scc[to[j]]);
				in[scc[to[j]]]++;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(!in[i]) q.push(i),f[i]=si[i];
	}
	int u,v;
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int i=pre2[u];i;i=nex2[i]){
			v=to2[i];
			f[v]=max(f[v],f[u]);
			if(!--in[v]) f[v]+=si[v],q.push(v);
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;i++) ans=max(ans,f[i]);
	printf("%d",ans);
	return 0;
}