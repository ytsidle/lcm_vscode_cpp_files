#include <bits/stdc++.h>
using namespace std;
const int  MAX=5e4+10;
int n;
long long m=1;
bool a[MAX*1000];
int f[MAX+5];
long long t,tt;
void check_prime(long long n){
//	cout<<sqrt(n)<<"\n";
	for(long long i=1;f[i]<=sqrt(n)&&n!=2;i++){
		if(n%f[i]==0){
			cout<<"end\n";
			return;
		}
	}
	f[++t]=n;
	a[n]=1;
	++tt;
//	cout<<"strat"<<endl;
	for(long long i=1;n*i<=MAX;i++){
		a[n*i]=1;
		++tt;
	}
	return;
}
int get_num(long long n){
	int ans=0;
	for(int i=1;i<=sqrt(n);i++){
		if(a[i]){
			if(n%i==0){
				if(i*i==n){
					ans++;
				}else{
					ans+=2;
				}
			}
		}
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	while(1){
		m++;
//		cout<<m<<endl;
		check_prime(m);
		
		
//		for(int i=2;i<=t;i++){
//			cout<<f[i]<<" ";
//		}cout<<endl;
		if(get_num(m)==n){
			cout<<m/2<<endl;
			break;
		}
	}
	return 0;
}
