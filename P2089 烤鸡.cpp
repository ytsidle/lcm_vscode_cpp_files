#include <bits/stdc++.h>
using namespace std;
int n,a[16],sum,cnt;
void out(){
	for(int i=1;i<=10;i++){
		printf("%d ",a[i]);
	}printf("\n");
}
void dfs(int num,int sums){
	if(num<=10){
		for(int i=1;i<=3;i++){
			
			dfs(num+1,sums+i);
		}
	}else{
		if(sums==n) sum++;
	}
}void dfss(int num,int sums){
	if(num<=10){
		for(int i=1;i<=3;i++){
			a[num]=i;
			dfss(num+1,sums+i);
		}
	}else{
//		out();
		if(sums==n) out();
	}
}
int main(){
	cin>>n;
	dfs(1,0);
	cout<<sum<<endl;
	
	dfss(1,0);
	return 0;
}
