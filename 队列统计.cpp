#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
int a[MAX],mp[MAX],fp[MAX],n,l,cm,cf,ans;
char t;
int main(){
	cin>>n>>l;
	for(int i=1;i<=n;i++){
		cin>>t;
		if(t=='M') a[i]=1;
		else a[i]=2;
	}
	for(int i=1;i<=l;i++){
		if(a[i]==1){
			mp[i]=mp[i-1]+1;
			cm++;
		}else fp[i]=fp[i-1]+1,cf++;
	}
	if(cm==l||cf==l) ans++;
	for(int i=l+1;i<=n;i++){
		//若是男生
		if(a[i]==1&&a[i-1]==1){
			int tn=mp[i-1];
//			if(a[i-l]==1) tn--;
			mp[i]=tn+1;
		}else if(a[i]==2&&a[i-1]==2){
			int tn=fp[i-1];
//			if(a[i-l]==2) tn--;
			fp[i]=tn+1;
		}
		else if(a[i]==1 &&a[i-1]==2){
			mp[i]=1;
		}else fp[i]=1;
		if(mp[i]>=l) ans++;
		if(fp[i]>=l) ans++;
	}
//	for(int i=1;i<=n;i++) cout<<mp[i]<<" "<<fp[i]<<" "<<a[i]<<endl;
	cout<<ans;
	return 0;
}
