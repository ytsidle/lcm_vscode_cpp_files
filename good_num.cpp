#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	if((n%5==0)||(n%3==0&&n<=20)){
		cout<<"YES";
	}else cout<<"NO";
	return 0;
}
