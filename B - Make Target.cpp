#include <bits/stdc++.h>
using namespace std;
int a[100][100],n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int j=n+1-i;
		if(i<=j){
			int color=0;
			if(i%2==1){
				color=1;//黑
			}
			for(int as=i;as<=j;as++){
				for(int bs=i;bs<=j;bs++){
					a[as][bs]=color;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<((a[i][j]==1)?'#':'.');
		}cout<<"\n";
	}
	return 0;
}
