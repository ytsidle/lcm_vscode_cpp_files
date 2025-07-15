#include <bits/stdc++.h>
using namespace std;
int n,a[110],ans;
//bool check(int pos){
//	int goal=a[pos];
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(a[i]+a[j]==goal&&i!=j){
////				cout<<a[i]<<" "<<a[j]<<endl;
//				return 1;
//			}
//		}
//	}return 0;
//}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i!=j){
				for(int x=1;x<=n;x++){
					if(x!=i&&x!=j&&a[i]+a[j]==a[x]){
//						cout<<a[i]<<" "<<a[j]<<endl;
						ans++;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}