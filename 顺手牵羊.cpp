#include <bits/stdc++.h>
using namespace std;
int n,k,a[2000][2000];
int equals=1,maxs=0,ks=0;
struct Data{
	int x,y,mk;
}ds[1000100];
bool cmp(Data a,Data b){
	return a.mk>b.mk;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			ds[++ks]={i,j,a[i][j]};
			maxs=max(maxs,a[i][j]);
			if(j>=2){
				if(a[i][j]!=a[i][j-1]){
					equals=0;
				}
			}
			if(i>=2){
				if(a[i][j]!=a[i-1][j]) equals=0;
			}
		}
	}
	
	if(equals==1){
		cout<<a[1][1];
		exit(0);
	}
	if(k==1){
		cout<<maxs;
		exit(0);
	}sort(ds+1,ds+1+ks,cmp);
	for(int i=k;i<=ks;i++){
		int cnt=0;
		for(int j=1;j<i;j++){
			if((ds[i].x>=ds[j].x&&ds[i].y>=ds[j].y)||(ds[i].x<=ds[j].x&&ds[i].y<=ds[j].y)){
				cnt++;
			}
		}
		if(cnt==k-1){
			cout<<ds[i].mk;
			exit(0);
		}
	}
	return 0;
}
