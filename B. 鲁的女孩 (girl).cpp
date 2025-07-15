#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int a[MAX],b[MAX],ans,n;
inline void solve(int num){
	int ap=num,bp=num,ans=0;
	while(1){
		bool tmp=0;
		if(a[ap-1]>a[ap]){
			swap(a[ap-1],a[ap]);
			ap-=1;
			tmp=1;
		}
		if(b[bp-1]>b[bp]){
			swap(b[bp-1],b[bp]);
			bp-=1;
			tmp=1;
		}
		if(!tmp){
			break;
		}
	}
	for(int i=1;i<=num;i++){
//		cout<<a[i]<<" "<<b[i]<<endl;
		ans=max(ans,a[i]+b[num-i+1]);
	}
	printf("%d\n",ans);
}
int main(){
	freopen("girl.in","r",stdin);
	freopen("girl.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}

	for(int i=1;i<=n;i++){
		if(i==1){
			printf("%d\n",a[1]+b[1]);
			continue;
		}
		solve(i);
	}
	return 0;
}
