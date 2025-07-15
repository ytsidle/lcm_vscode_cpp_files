#include <bits/stdc++.h>
using namespace std;
const int M=2e6+10;
int n,q,top,stn[M];
char s[M],st[M];
//并查集
int f[M];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
	if(find(x)!=find(y)){
		f[y]=f[x];
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		f[i]=i;
		f[n+i]=n+i;
	} 
	for(int i=1;i<=n;i++){
		if(s[i] == '(' ){
			st[++top]='(';
			stn[top]=i;
		}
		else if(top!=0){
			//建边
			
			merge(stn[top],i);
			top--;
		}
		if(s[i]=='('&&s[i-1]==')'){
			merge(i-1,i);
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		if(s[l]=='('&&s[r]==')'){
			if(find(l)==find(r)){
				cout<<"Yes\n";
			}else cout<<"No\n";
		}else cout<<"No\n";
	}
	return 0;
}
