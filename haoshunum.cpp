#include <bits/stdc++.h>
using namespace std;
int n,sum;
bool hao(int num){
	//拆分
	int z=0,o=0;
	while(num){
		if(num%2==0) z++;
		else o++;
		num/=2;
	}if(o>z) return 1;
	return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		if(hao(i)) sum++;
	}cout<<sum;
	return 0;
}
