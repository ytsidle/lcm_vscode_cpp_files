#include <bits/stdc++.h>
using namespace std;
//找逆序对
//Tn^2能过
int a[200],T,n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		bool flag=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]>a[j]){
					cout<<"Yes\n";
					cout<<"2\n";
					cout<<a[i]<<" "<<a[j]<<"\n";
					flag=1;
					break;
				}
			}if(flag) break;
		}
		if(flag) continue;
		cout<<"No\n";
	}
	return 0;
}
