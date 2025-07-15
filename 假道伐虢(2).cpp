#include <bits/stdc++.h>
using namespace std;
#define int long long
int spec=1,n,m,a[2000],vis[2000],ans;
vector<int> v[2000];
priority_queue<pair<int,int>,deque<pair<int,int> >,greater<pair<int,int> > > qu;//小 
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	//bfs大法好
	//如果能到达x,联通块都可以有x,所以全局x
	int x=0;
	qu.push({a[1],1});
	while(!qu.empty()){
		pair<int,int> head=qu.top();
		int id=head.second,p=head.first;
		qu.pop();
		if((x>=a[id]||id==1)&&vis[id]==0){
			vis[id]=1;
			x+=a[id];
			for(int i=0;i<v[id].size();i++){
				int to=v[id][i];
				if(vis[to]==0){
					qu.push({a[to],to});

				}
			}
		}
	}cout<<x;
	return 0;
}
