#include <bits/stdc++.h>
using namespace std;
//int str_to_int(string){
//	int t=1,cnt=0,re;
//	for(int i=string.length();i>=0;i--){
//		cnt=int(i-48);
//		re+=cnt*t;
//		t*=10;
//	}
//}
bool has_seven(int n){
	int t=1;
	while(n>0){
		if(n%10==7){
			return true;
		}
		n=n/10;
	}
	return false;
}
int n;
long long sum;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
//		cout<<"a:"<<i<<endl;
		if(has_seven(i)||i%7==0){
//			cout<<i<<endl;
			sum+=i;
		}
	}
	cout<<sum;
//	cout<<has_seven(n);
	return 0;
}
