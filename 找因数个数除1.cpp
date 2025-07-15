#include <bits/stdc++.h>
using namespace std;
int get_num(int num){
	int cnt=0;
	for(int i=2;i<=sqrt(num);i++){
		if(num%i==0){
			cnt++;
			if(num/i!=i){
				cnt++;
			}
		}
	}return cnt;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cout<<get_num(i)<<endl;
	}
	return 0;
}
