#include <bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6},n,ans;
inline int count(int num){
	if(num==0) return 6;
	int re=0;
	while(num){
		re+=a[num%10];
		num/=10;
	}
	return re;
}
int main(){
	cin>>n;
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=i;j++){
			if(count(i)+count(j)+count(i+j)+4==n){
//				cout<<i<<" "<<j<<" "<<i+j<<endl;
				if(i!=j)ans+=2;
				else ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
