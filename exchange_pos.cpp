#include <bits/stdc++.h>
using namespace std;
int a[25],n,as,ae,bs,be;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>as>>ae;
	cin>>bs>>be;
	for(int i=1;i<=n;i++){
		if(!((i>=as&&i<=ae)||(i>=bs&&i<=be))){
			cout<<a[i]<<" ";
		}else{
			if(i==as){
				for(int j=0;j<be-bs;j++){
					cout<<a[bs+j]<<" ";
					
				}i=ae;
			}else{
				for(int j=0;j<ae-as;j++){
					cout<<a[as+j]<<" ";
					
				}i=be;
			}
			
		}
	}
	return 0;
}
