#include <bits/stdc++.h>
using namespace std;
long long n,ansa,ansx,ans=LONG_LONG_MAX;
int main(){
	cin>>n;
	for(int a=0;7*a<=2*n;a++){
		long long last=abs(7*a-n);
		if(last==0) continue;
		if(7*a<n){
			long long txo=last/4,txt=ceil(last/4.0);
			if(abs(last-txo*4)<ans){
				ansa=a,ansx=txo;ans=abs(last-txo*4);
				if(ans==0) break;
			}if(abs(last-txt*4)<ans){
				ansa=a,ansx=txt;ans=abs(last-txo*4);
				if(ans==0) break;
			}
		}else{
			//没救了,现在比就对了
			//tx=1
			long long tx=1;
			if(last<ans&&last>=4){
				ans=last;ansa=a;ansx=1;
			}
		}
	}
	cout<<ansa<<" "<<(ansa+ansx)<<" "<<(ansa+ansa+ansx)<<" "<<((ansa+ansx)+ansa+(ansa+ansx));
	return 0;
}
