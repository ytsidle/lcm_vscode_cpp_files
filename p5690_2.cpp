#include <bits/stdc++.h>
using namespace std;
int a,b,sum;
bool is_ok(int n,int m){
	if(n>=1 && n<=12 && m>=1){
		if(n==1 || n==3 ||n==5 || n==7 || n==8 || n==10 || n==12){
			if(m<=31){
//				cout<<"in";
				return true;
//				exit(0);
			}
		}else if(n!=2){
//			cout<<n;
			if(m<=30){
//				cout<<"in";
				return true;
//				exit(0);/
			}
		}else if(n==2){
//			cout<<"in";
			if(m<=28){
				return true;
			}
		}
		return false;
	}
	return false;
}
int main(){
	scanf("%d-%d",&a,&b);
//	cout<<a<<b;
	if(is_ok(a,b)){
		cout<<0;
		exit(0);
	}else{
		if(!is_ok(a,1)){
			sum++;
			a=a%10;
		}
		if(!is_ok(a,b)) sum++;
	}
	cout<<sum;
	return 0;
}
