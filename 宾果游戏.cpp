#include <bits/stdc++.h>
using namespace std;
int a[10][10];
int main(){
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			cin>>a[i][j];
		}
	}
	int xie,xie2;
	for(int i=1;i<=5;i++){
		int rown=0,coln=0;
		for(int j=1;j<=5;j++){
			if(a[i][j]==1) rown++;
			if(a[j][i]==1) coln++;
		}
		if(rown==5||coln==5){
			cout<<"Yes";
			return 0;
		}
		xie+=a[i][i],xie2+=a[i][5-i+1];
	}
	if(xie==5||xie2==5){
		cout<<"Yes";
		return 0;
	}cout<<"No";
	return 0;
}
