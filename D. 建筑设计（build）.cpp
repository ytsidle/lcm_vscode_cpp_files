#include <bits/stdc++.h>
using namespace std;
bool is_rect(int za,int zb,int la,int lb){
	if(min(za,zb)>min(la,lb)){
		swap(za,la);swap(zb,lb);
	}
	return max(za,zb)>min(la,lb);
}
int squ1[7],squ2[7];
int main(){
	for(int i=1;i<=6;i++) cin>>squ1[i];
	for(int i=1;i<=6;i++) cin>>squ2[i];
	int num=0;
	for(int i=1;i<=3;i++){
		num+=is_rect(squ1[i],squ1[i+3],squ2[i],squ2[i+3]);
	}
	if(num==3){
		cout<<"Yes";
	}else cout<<"No";
	return 0;
}
