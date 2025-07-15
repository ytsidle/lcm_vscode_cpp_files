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
		}else{
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
		cout<<0<<1;
		exit(0);
	}else{
		if(!is_ok(a,1)){
			int t=10;
			while(!is_ok(a,1) && !(t<1)){
				if(a/t>0){
					a-=((a/t)*t);
					sum++;
				}
				t/=10;
			}

		}if(!is_ok(a,b)){
			int t=10;
			while(!is_ok(a,b) && !(t<1)){
				if(b/t>0){
					b-=((b/t)*t);
					sum++;
				}
				t/=10;
			}

		}
	}
	cout<<sum;
	return 0;
}
