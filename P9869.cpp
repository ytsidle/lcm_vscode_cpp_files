#include<bits/stdc++.h>
using namespace std;
int c,t;
const int N=1e5+5;
int f[2*N],vis[2*N],n,m;
int find(int x){
	if(vis[x]){
		vis[x]--;
		return f[x];
	}
	vis[x]++;
	return (f[x]==x)?(x):(f[x]=find(f[x]),vis[x]--);
}
void merge(int x,int y){
	if(find(x)!=find(y)){
		f[find(x)]=find(y);
	}
}
void solve(){
	cin>>n>>m;
	for(int i=2*n+1;i<=2*n+3;i++) f[i]=i;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=n+1;i<=2*n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		char op;
		cin>>op;
		if(op=='+') {
			int x,y;
			cin>>x>>y;
			merge(x,y);
			merge(x+n,y+n);
		}else if(op=='-'){
			int x,y;
			cin>>x>>y;
			merge(x,y+n);
			merge(x+n,y);
			
		}else {
			int x;
			cin>>x;
			switch(op){
				case 'T':
					merge(x,2*n+1);merge(x+n,2*n+2);
					break;
				case 'F':
					merge(x,2*n+2);merge(x+n,2*n+1);
					break;
				case 'U':
					merge(x,2*n+3);merge(x+n,2*n+3);
					break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(find(i)==find(i+n)){
			f[find(i)]=2*n+3;
		}
	}int ans=0;
	for(int i=1;i<=n;i++){
		if(find(i)==2*n+3)ans++;
	}
	cout<<ans<<endl; 
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}