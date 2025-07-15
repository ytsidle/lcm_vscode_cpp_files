#include <bits/stdc++.h>
using namespace std;
int n,a[25][25],pi,pj,num,filn=0;
bool sec(){
	int ti=pi-1,tj=pj+1;
	if(ti==0){
		ti=n;
	}if(tj>n){
		tj=1;
	}if(a[ti][tj]==0){
		num++,filn++;
		a[ti][tj]=num;
		pi=ti,pj=tj;
		return 1;
	}return 0;
}
void third(){
	int ti=pi+1;
	if(ti>n) ti=1;
	pi=ti;
	a[pi][pj]=++num;
	filn++;
}
int main(){
	scanf("%d",&n);
	//1步
	pi=1,pj=n/2+1,num=1;
	a[pi][pj]=num;
	filn++;
	while(filn<n*n){
		if(sec()==0){
			third();
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}cout<<endl;
	}
	return 0;
}
