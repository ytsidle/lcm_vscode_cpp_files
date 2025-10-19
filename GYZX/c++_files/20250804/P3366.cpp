#include <bits/stdc++.h>
using namespace std;
#define int long long
const int  MAX=2e5+10,N=5050;;
struct dy{
	int x,y;
	long  long z;
};
dy a[2*MAX];
int n,m,k=0;
long long sum=0;
int father[N];
bool cmp(dy as,dy bs){
	return as.z<bs.z;
}
int find(int x)
{
    return father[x]==x?x:father[x]=find(father[x]);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		
	}for(int i=1;i<=n;i++){
		father[i]=i;
	}sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		int fx=find(a[i].x),fy=find(a[i].y);
		//非环的情况(fx!=fy)
		if(fx!=fy){
			father[fy]=fx;
			k++;
			sum+=a[i].z;
			if(k==n-1) break;
		}
	}if(k==n-1) cout<<sum<<endl;
	else cout<<"orz\n";
	return 0;
}