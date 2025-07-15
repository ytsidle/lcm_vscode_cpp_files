#include <bits/stdc++.h>
using namespace std;
const int MAX=10000+100;
int n,a[MAX];
long long sum,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}sort(a+1,a+1+n);
	int tn=n;
	for(int i=1;i<tn;i++){
		
		sum=a[1]+a[2];
		ans+=sum;
		a[1]=sum;
		for(int j=2;j<n;j++){
			a[j]=a[j+1];
		}n-=1;
		int t=1;
		for(int j=2;j<=n;j++){
			if(a[t]>a[j]){
				swap(a[t],a[j]);
				t=j;
			}
		}
	}cout<<ans;
	return 0;
}
