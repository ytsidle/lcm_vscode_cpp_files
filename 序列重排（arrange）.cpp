#include <bits/stdc++.h>
using namespace std;
//左右开弓
const int MAX=1e6+10;
int a[MAX],n,counts[MAX],ans[MAX],k;
int main(){
	freopen("arrange.in","r",stdin);
	freopen("arrange.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	counts[1]=1;
	while(l<r){
		counts[l]++;
		counts[r]++;
		ans[++k]=a[l]+a[r];
		if(counts[l]==2) l++;
		if(counts[r]==2) r--;
	}
//	for(int i=1;i<=k;i++) cout<<ans[i]<<" ";
	sort(ans+1,ans+1+k);
 	ans[0]=-1;
 	for(int i=1;i<=k;i++){
 		if(ans[i-1]+1<ans[i]){
 			printf("%d",ans[i-1]+1);
 			return 0;
		}
	}
	printf("%d",ans[k]+1);
	return 0;
}
