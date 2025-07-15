#include <bits/stdc++.h>
using namespace std;
#define M 10010
bool f[M];
int n,k,p[M],cnt;
void init(){
	f[0]=f[1]=1;
	for(int i=2;i<=n;i++){
		if(!f[i]){
			p[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*p[j]<=n;j++){
			f[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
int main(){
	cin>>n>>k;
	init();
	
//	for(int i=1;i<=cnt;i++)cout<<p[i]<<"  ";
	bool flag=0;
	for(int i=2;i<=n-k;i++){
		if((!f[i])&&(!f[i+k])){
			cout<<i<<" "<<i+k<<endl;
			flag=1;
		}
	}
	if(!flag){
		cout<<"empty";
	}
	return 0;
}
