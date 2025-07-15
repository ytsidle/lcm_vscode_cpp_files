#include <bits/stdc++.h>
using namespace std;
int a[4],ans;
char t;
int get_num(){
	return a[1]*100+a[2]*10+a[3];
}
bool cmp(int a,int b){
	return a>b;
}
void set_num(){
	sort(a+1,a+4);
	int small=get_num();
	
	sort(a+1,a+4,cmp);
	int big=get_num();
//	cout<<big<<" "<<small<<endl;
	int num=big-small;
	for(int i=3;i>=1;i--){
		a[i]=num%10;
		num/=10;
	}
}
int main(){
	for(int i=1;i<=3;i++){
		cin>>t;
		a[i]=t-'0';
	}
	int cnt=0;
	while(get_num()!=495&&cnt<=10){
//		cout<<get_num()<<endl;
		set_num();
		ans++;
		cnt++;
	}cout<<ans;
	return 0;
}
