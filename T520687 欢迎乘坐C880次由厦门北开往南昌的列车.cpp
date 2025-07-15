#include <bits/stdc++.h>
using namespace std;
int T;
string st,se;
struct Data{
	string p;
	int o,t;
}d[40];
bool cmp(Data a,Data b){
	return a.o==b.o?a.t<b.t:a.o<b.o;
}
int main(){
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		cin>>d[i].p;
		scanf("%d:%d",&d[i].o,&d[i].t);
		
	}
	sort(d+1,d+1+T,cmp);
	cin>>st>>se;
	int sp=-1,ep=-1;
	for(int i=1;i<=T;i++){
//		cout<<d[i].p<<" "<<d[i].o<<":"<<d[i].t<<endl;
		if(d[i].p==st){
			sp=i;
			break;
		}
	}
	for(int i=1;i<=T;i++){
		if(d[i].p==se){
			ep=i;
			break;
		}
	}
	if(sp==-1||ep==-1){
		cout<<"No";
	}
	else if(sp>ep) cout<<"No";
	else{
		printf("Yes\n%d:%d\n%d:%d",d[sp].o,d[sp].t,d[ep].o,d[ep].t);
	}
	return 0;
}
