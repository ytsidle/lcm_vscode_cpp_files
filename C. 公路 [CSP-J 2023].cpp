#include <bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int n,d,v[M],a[M],to[M];
long long ans,cf[M];
bool vis[M];
int main(){
	scanf("%d%d",&n,&d);
	int p=1;
	vis[1]=1;
	for(int i=1;i<n;i++) scanf("%d",&v[i]),cf[i]=cf[i-1]+v[i];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i>1){
			if(a[i]<a[p]){
				to[p]=i;
				if(i!=n)vis[i]=1;
				p=i;
			}
		}
	}
//	for(int i=1;i<=n;i++) cout<<to[i]<<endl;
	long long s=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			if(to[i]==0){
				ans+=((long long)ceil((cf[n-1]-cf[i-1]-s)*1.0/d))*a[i];
//				cout<<i<<":"<<((long long)ceil((cf[n-1]-cf[i-1]-s)*1.0/d))<<endl;
//				s=ceil((cf[n-1]-cf[i-1])*1.0/d)-((cf[n-1]-cf[i-1])*1.0/d);
			}
			else{
				ans+=((long long)ceil((cf[to[i]-1]-cf[i-1]-s)*1.0/d))*a[i];
				
//				cout<<i<<":"<<(ceil((cf[to[i]-1]-cf[i-1]-s)*1.0/d))<<":"<<((long long)ceil((cf[to[i]-1]-cf[i-1]-s)*1.0/d))*a[i]<<":";
				s=ceil((cf[to[i]-1]-cf[i-1]-s)*1.0/d)*d-(cf[to[i]-1]-cf[i-1]);
//				cout<<s<<endl;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
