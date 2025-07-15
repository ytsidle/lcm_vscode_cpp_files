#include <bits/stdc++.h>
using namespace std;
int n;
int dfs(int num){
	if(num==0) return 1;
	else if(num==1){
		return dfs(num-1);
	}else{
		return dfs(num-1)+dfs(num-2);
	}
}
int main(){
	while(cin>>n){
		cout<<dfs(n)<<endl;
	}
	return 0;
}
