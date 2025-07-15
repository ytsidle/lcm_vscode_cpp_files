#include <bits/stdc++.h>
using namespace std;
const int M=1e6+10;
int n,m,whp[M],hid[M],idh[M];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		whp[i]=i,hid[i]=i,idh[i]=i;
	}
	while(m--){
		int typ;
		cin>>typ;
		if(typ==1){
			int a,b;
			cin>>a>>b;
			whp[a]=hid[b];
		}if(typ==2){
			int a,b;
			cin>>a>>b;
			swap(hid[a],hid[b]);
			idh[hid[a]]=a,idh[hid[b]]=b;
		}
		if(typ==3){
			int a;
			cin>>a;
			cout<<idh[whp[a]]<<"\n";
		}
	}
	return 0;
}
