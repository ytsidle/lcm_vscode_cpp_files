#include <bits/stdc++.h>
using namespace std;
int a[110],n,x,sum,num=0;
int main(){
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(sum+a[i]<=x){
			sum+=a[i];
			num=i;
		}else{
			break;
		}
	}
	cout<<num;
	return 0;
}
