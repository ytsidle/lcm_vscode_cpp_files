#include <bits/stdc++.h>
using namespace std;
int n,a[6000][6000],sl,tp=1,ans,to[6000],anss[6000],lea=0;
void dfs(int num,int fa){
	int cn=0;
	for(int i=1;i<=n;i++){
		if(a[num][i]&&i!=fa){
			anss[i]=min(anss[num],min(anss[i],a[num][i]));
			dfs(i,num);
			cn++;
		}
	}
	if(!cn) lea=num;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int l,r,le;
		cin>>l>>r;
		a[l][r]=a[r][l]=le;
		if(sl!=le&&sl!=0){
			tp=0;
		}else sl=le;
	}
	memset(anss,0x3f,sizeof(anss));
	if(n==2){
		cout<<a[1][2];
		exit(0);
	}else if(tp){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[1][i]) cnt++;
		}cout<<cnt*sl;
	}else{
		dfs(1,0);
		
		cout<<anss[lea];
	}
	return 0;
}
