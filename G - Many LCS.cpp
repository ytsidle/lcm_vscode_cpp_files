#include <bits/stdc++.h>
using namespace std;
const long long M=998244353;
long long ans;
int n,m,k;
char c[110],t[110],other[110];
int  vis[128];
const int MAXN = 150; 
long long C[MAXN+1][MAXN+1]; 
void Initial() 
{ 
    int i,j; 
    for(i=0; i<=MAXN; ++i) 
    { 
        C[0][i] = 0; 
        C[i][0] = 1; 
    } 
    for(i=1; i<=MAXN; ++i) 
    { 
        for(j=1; j<=MAXN; ++j) 
        C[i][j] = (C[i-1][j] + C[i-1][j-1]) % M; 
    } 
} 
int cnm(int n, int m) 
{ 
    return C[n][m]; 
} 
int qpow(int a,int b){
	if(b==0) return 1;
	if(b%2==1){
		return 1ll*a*qpow(a,b-1)%M;
	} else{
		int re=qpow(a,b/2);
		return 1ll*re*re%M;
	}
}
int count_okind(char* cs){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		vis[c[i]]++;
	}for(int i=1;i<=k;i++){
		vis[cs[i]]--;
	}
	int anss=0;
	for(int i='a';i<='z';i++){
//		cout<<vis[i]<<" ";
		if(vis[i]) anss++;
	}
//	cout<<endl;
	return anss;
}
int count_kind(char* cs){
	memset(vis,0,sizeof(vis));
	int anss=0;
	for(int i=1;i<=k;i++){
		if(vis[cs[i]]==0){
			vis[cs[i]]=1;
			anss++;
		}
	}return anss;
}
set<vector<int> > sv;
vector<int> tv;
void dfs(int now,int cnt,int to){
	if(cnt==to&&(sv.find(tv)==sv.end())){
		for(int item:tv){
			cout<<c[item]<<" ";
		}cout<<endl;
		ans+=1ll*qpow(26-count_okind(t),(m-to))*cnm(m,to);
//		cout<<"de:"<<(1ll*qpow(26-count_kind(t),(m-to))*cnm(m,to))<<endl;
		ans%=M;
		sv.insert(tv);
		return ;
	}if(now==n+1) return;
	//要
	if(t[cnt+1]!=c[now]){
		tv.push_back(now);
		t[cnt+1]=c[now];
		dfs(now+1,cnt+1,to);
	}
	tv.pop_back();
	dfs(now+1,cnt,to);
}
int main(){
	Initial() ;
	cin>>n>>m;
	cin>>c+1;
	for(k=0;k<=n;k++){
		if(k==0){
			k=n;
			cout<<qpow((26-count_kind(c)),m)<<endl;
			k=0;
			continue;
		}
		ans=0;
		//暴力枚举k
		memset(t,0,sizeof(t));
		memset(other,0,sizeof(other));
		sv.clear();
		tv.clear();
		dfs(1,0,k);
		cout<<ans<<endl;
	}
	return 0;
}
