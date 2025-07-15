#include <bits/stdc++.h>
using namespace std;
int a[110],n,k,cnt,num;
bool check(int n){
	for(int i=0;i<cnt;i++){
		for(int j=i+1;j<cnt;j++){
//			cout<<a[i]<<" "<<a[j]<<" "<<n<<endl;
			if(a[i]+a[j]==n) return false;
			
			
		}
	}return true;
}
int main(){
	cin>>n>>k;
	while(cnt<n){
		num+=1;
		if(num%k==0){
			if(check(num)){
			a[cnt]=num;
//			cout<<a[cnt]<<endl;
			cnt++;
			cout<<num<<" ";
			
		}
		}
	
	}
	return 0;
}
