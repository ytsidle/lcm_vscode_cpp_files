#include <bits/stdc++.h>
using namespace std;
int n;
struct stu{
	int ch,ma,en,no,zong;
}stus[350];
bool cmp(stu a,stu b){
	if(a.zong!=b.zong) return a.zong>b.zong;
	else{
		if(a.ch!=b.ch) return a.ch>b.ch;
		else{
			return a.no<b.no;
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>stus[i].ch>>stus[i].ma>>stus[i].en;
		stus[i].no=i;
		stus[i].zong=stus[i].ch+stus[i].en+stus[i].ma;
	}sort(stus+1,stus+n+1,cmp);
	for(int i=1;i<=5;i++){
		cout<<stus[i].no<<" "<<stus[i].zong<<endl;
	}
	return 0;
}
