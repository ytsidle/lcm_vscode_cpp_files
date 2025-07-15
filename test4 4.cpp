#include <bits/stdc++.h>
using namespace std;
int n,m,ans,l,r,mid,los,num;
int main(){
	while(cin>>n>>m){
		if(m==1) cout<<n<<endl;
		else{
			ans=0;
			for(int i=1;i<=n;i++){
				los=m;
				l=1,r=n,mid=(l+r)>>1,num=0;
				while(l<r && los>1){
					if(mid>i){
						los-=1;
						r=mid-1;
					}else{
						l=mid+1;
					}mid=(r+l)>>1;
					num++;
				}for(int j=l;j<=r;j++){
					//?
					if(j==i) break;//?
					num++;
				}ans=max(ans,num);
				cout<<"i: "<<i<<"  num: "<<num<<endl;
			}cout<<ans<<endl;
		}
	}
	
	return 0;
}
