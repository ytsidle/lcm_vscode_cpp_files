#include <bits/stdc++.h>
using namespace std;
const int M=1e5;
int a[M],n;
bool vis[M];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1,r=2,cnt=0;
	while(l<n&&r<=n){
		if(a[l]>=a[r]||vis[r]){
			r++;
		}else{
			vis[r]=1;
			l++;
			r++;
			
			cnt++;
		}
	}
	printf("%d",n-cnt);
	return 0;
}
