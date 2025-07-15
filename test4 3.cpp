#include <bits/stdc++.h>
using namespace std;
//use binary cut(left):smaller ans
int n,k,a[100030],b[100030];
long long sum,ans=LONG_LONG_MAX;
long long f(int l,int r){
	long long res=0;
	for(int i=l;i<=r+1;i++){
		if(i!=r+1) res+=abs(a[i]-a[i+1]);
		else res+=abs(a[r+1]-a[r]);
	}return res;
}
void dfs(int num,int c){
	for(int i=1;i<=(num-k+1);i++){
		if(c>1){
			b[c]=i;
			dfs(num-i,c-1);
		}else{
			b[c]=num;b[c-1]=n;
			sum=0;
			for(int i=k;i>=0;i--){
				sum+=f(b[i],b[i+1]);
			}ans=min(sum,ans);
		}
	}
}

//bool fun(int ns,int ks,int b[],long long v){
//	if(ks<k&&n>=1){
//		for(int i=1;i<=n;i++){
//			b[1]=i;
//			fun(n-i,ks-1,b,v);
//		}
//	}else if(n>0 && ks==k){
//	long long sum=0;
//		for(int i=1;i<=n;i++){
//			b[ks]=i;
//			
//			for(int i=1;i<=k;i++){
//				sum+=f(b[i-1],b[i]);
//			}if(sum<=v) return true;
//		}
//	}return false;
//
//}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
//		r+=a[i];
	}
//input
//	unsigned long long l=1,mid=(r+l)>>1;
//	while(l<=r){
//		int* nul={};
//		cout<<"in"<<endl;
//		if(fun(n-1,1,nul,mid)){
//			r=mid-1;
//			
//		}else l=mid+1;
//	}
//	ans=l;
	//use递归法
	dfs(n,k);
	cout<<ans;
	return 0;
}
