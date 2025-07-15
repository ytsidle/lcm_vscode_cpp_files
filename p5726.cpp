#include <bits/stdc++.h>
using namespace std;
int n,a[1030];
//vector <int> a;
long long sum=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=2;i<n;i++){
		sum+=a[i];
	}
	printf("%.2f\n",sum*1.0/(n-2));
//	cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum/n;
	return 0;
}
