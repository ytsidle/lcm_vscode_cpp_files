#include <bits/stdc++.h>
using namespace std;
int n,k;
struct Data{
	int x,y,jv;
}f[200][200],d[200];
bool cmp(Data a,Data b){
	return a.jv<b.jv;
}
void init(){
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(i!=j){
				f[i][++cnt].jv=abs(d[i].x-d[j].x)+abs(d[i].y-d[j].y);
				f[i][cnt].x=d[j].x,f[i][cnt].y=d[j].y;
			}
		}
		sort(f[i]+1,f[i]+1+cnt,cmp);
	}
}
void solve(int num){
	long long ans=INT_MAX;
	for(int i=1;i<=n;i++){
		long long xsum=0,ysum=0;
		for(int j=1;j<=num;j++){
			xsum+=f[i][j].x,ysum+=f[i][j].y;
		}
		xsum/=num,ysum/=num;
		long long an=0;
		for(int j=1;j<=num;j++){
			an+=abs(xsum-f[i][j].x)+abs(ysum-f[i][j].y);
		}
		ans=min(ans,an);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&d[i].x,&d[i].y);
	}
	//预处理(100*100次+100*log2(100))
	init();
	printf("0\n");//t==1一定为0
	for(int i=2;i<=k;i++){
		solve(i);
	}
	return 0;
}
