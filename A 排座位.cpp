#include <bits/stdc++.h>
using namespace std;
int n,m;
string s="GBBG",s2="BGGB",s3="BG";
int main(){
	cin>>n>>m;
	if(n==1){
		for(int i=0;i<m;i++){
			cout<<s3[i%2];
		}return 0;
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=0;j<m;j++){
				cout<<s[j%4];
			}
		}else{
			for(int j=0;j<m;j++){
				cout<<s2[(j)%4];
			}
		}cout<<"\n";
	}
	return 0;
}
