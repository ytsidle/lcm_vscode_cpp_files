#include <bits/stdc++.h>
using namespace std;
const int MAX=2e6+10;
int a[MAX],n,x,ans;
bool f[MAX];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[a[i]]=1;
	}
	scanf("%d",&x);
	for(int i=1;i<=n;i++){
		if(f[a[i]]&&f[x-a[i]]&&a[i]!=x-a[i]&&x-a[i]>0){
//			cout<<a[i]<<" "<<x-a[i]<<endl;
			ans++;
			f[a[i]]=f[x-a[i]]=0;
		}
	}
	printf("%d",ans);
	return 0;
}