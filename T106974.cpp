#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int a[3][MAX];
int n;
int main(){
	cin>>n;
	cin>>a[1][1];
	for(int i=1;i<n;i++){
		scanf("%d",&a[2][i]);
		if(a[2][i]==3){
			a[1][i-1]=1;
			a[1][i]=1;
			a[1][i+1]=1;
		}
	}
	for(int i=1;i<n;i++){
		if(a[2][i]!=3){
			if(a[2][i]>(a[1][i-1]+a[1][i]+a[1][i+1])){
				int num=a[2][i]-(a[1][i-1]+a[1][i]+a[1][i+1]),t=0;
				for(int j=3;j>=1 && t<num;j--){
					if(a[1][i-2+j]==0) t++,a[1][i-2+j]=1;
				}
			}

		}
	}
	for(int i=2;i<=n;i++){
		printf("%d ",a[1][i]);
	}
	cout<<endl;
	cout<<a[1][n]+a[1][n-1];
	return 0;
}
