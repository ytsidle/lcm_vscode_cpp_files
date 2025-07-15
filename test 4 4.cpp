#include <bits/stdc++.h>
using namespace std;
int n,m,ans,l,r,mid,los,num;
int main(){
	while(cin>>n>>m){
		if(m==1) cout<<n;
		else{
			ans=0;
			for(int i=1;i<=n;i++){
				los=m;
				l=1,r=n,mid=(l+r)>>1,num=0;
				while(l<=r){
					if(mid>i){
						los-=1;
						r=mid-1;
					}else{
						l=mid+1;
					}mid=(r+l)>>1;
					num++;
				}
//				for(int j=l;j<=r;j++){
//					num++;//?
//					if(j==i) break;//?
//				}ans=max(ans,num);
			}cout<<ans;
		}
	}
	
	return 0;
}
