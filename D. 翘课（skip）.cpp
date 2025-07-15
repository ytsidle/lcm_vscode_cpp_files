#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[550][550],b[550][550],c[550][3],ans;
vector<vector<int> > q;
int main(){
	freopen("skip.in","r",stdin);
	freopen("skip.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		int cnt=0,use=0;
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==1){
				if(!use){
					c[i][1]=j;
					c[i][2]=j;
					use=1;
				}else{
					
					b[i][j]=cnt;
//					cout<<cnt;
					cnt=0;
				}
				q.push_back({b[i][j],i,j});
			}else cnt++;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<b[i][j]<<" ";
//		}cout<<endl;
//	}
	sort(q.begin(),q.end());
//	cout<<q[q.size()-1][0];
	int count = 0;
	for(int i=q.size()-1;i>=0;i--){
		if(count==k) break;
		int A=q[i][1],B=q[i][2];
		if(c[i][1]==B){
			a[A][B]=0;
			while(c[i][1]<=c[i][2]&&a[A][c[i][1]]==0){
				c[i][1]++;
			}
			count++;
		}else if(c[i][2]==B){
			a[A][B]=0;
			while(c[i][2]>=c[i][1]&&a[A][c[i][2]]==0){
				c[i][2]--;
			}
			count++;
		}
	}
	for(int i=1;i<=n;i++){
		ans+=(a[i][2]-a[i][1]+1);
	}
	printf("%d",ans);
	return 0;
}
