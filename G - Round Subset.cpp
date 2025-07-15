#include <bits/stdc++.h>
using namespace std;
int n,k,a[300],two[300],fiv[300];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int num=a[i];
		while(num%2==0){
			two[i]++;
			num/=2;
		}
		while(num%5==0){
			fiv[i]++;
			num/=5;
		}
	}

    return 0;
}