#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int dp[MAX],n,d,v[MAX],a[MAX];
long long hlong(int f,int e){
	if(f==e){
		return 0;
	}else{
		long long ans=0;
		for(int i=f;i<e;i++){
			ans+=v[i];
		}return ans;
	}
}
int hol(long long len){
	if(len%d!=0){
		return len*1.0/d/1+1;
	}else return len/d;
}
int mins(int f,int e){
	int mini=INT_MAX;
	for(int i=f;i<=e;i++){
		mini=min(mini,a[i]);
	}return mini;
}
int minp(int f,int e){
	//mins(a[0]-a[e])中最小值的位置
	int mini=0;
	for(int i=f;i<=e;i++){
		if(a[i]<=a[mini]) mini = i;
	}return mini;
}
int main(){
	
	//输入
	scanf("%d%d",&n,&d);
	for(int i=1;i<n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	//初始化
	
	a[0]=INT_MAX;
	//动态规划开始
	//从二开始
	for(int i=2;i<=n;i++){
		auto p=minp(0,i-1);
		cout<<"i: "<<p<<endl;
		dp[i]=a[p]*hol(hlong(p,i))+dp[p];
	}
	for(int i=1;i<=n;i++){
		cout<<dp[i]<<" ";
	}
	printf("%d",dp[n]);
//	cout<<hol(10);
	return 0;
}

