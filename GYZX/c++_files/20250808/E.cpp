#include <bits/stdc++.h>
using namespace std;
//#define tx x+num-1
//#define ty y+num-1
//#define check(x,y,num) !(sum[tx][ty]-sum[tx][y-1]-sum[x-1][ty]+sum[x-1][y-1])
//AC
int h,w,a[3050][3050],sum[3050][3050],t;
long long ans=0;
inline bool check(int x,int y,int num){
	int tx=x+num-1,ty=y+num-1;
//	if(t)
	return !(sum[tx][ty]-sum[tx][y-1]-sum[x-1][ty]+sum[x-1][y-1]);
}
int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>h>>w>>t;
//	h=3000,w=3000,t=0;
	for(int i=1;i<=t;i++){
		int x,y;
		cin>>x>>y;
		a[x][y]++;
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			int r=min(h-i+1,w-j+1),l=1,mid;
			while(l<=r){
				mid=(l+r)>>1;
				if(check(i,j,mid)) l=mid+1;
				else r=mid-1;
			}ans+=1ll*r;
//			cout<<i<<" "<<j<<" "<<r<<"\n";
		}
	}cout<<ans;
	return 0;
}