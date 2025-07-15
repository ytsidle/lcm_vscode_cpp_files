#include <bits/stdc++.h>
using namespace std;
const   int MAX=38;
/*
	思路:
	1.模拟出入栈
	为end时结束
*/
int zhan[MAX],len,num=1,n,ans;
bool in(){
	if(num<=n){
		cout<<"In"<<n<<endl;
		zhan[++len]=num;
		num++;
	}
	return num<=n;
}bool push(){
	if(len!=0){
		cout<<"out"<<zhan[len]<<endl;
		zhan[len]=0;
		--len;
	}return len!=0;

}void dfs(bool mode){
	
	if(num<=n){
		if(mode==0){
//			if(in()){
//				dfs(0);
//				dfs(1);
//			}
			in();
		}
		
		
		else{
//			if(push()){
//				dfs(0);
//				dfs(1);
//			}
			push();
		}
		dfs(0);
		dfs(1);
	}else{
		ans++;
	}
}
int main(){
	cin>>n;
	dfs(0);
	cout<<ans;
	return 0;
}
