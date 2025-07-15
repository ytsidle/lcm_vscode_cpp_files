#include <bits/stdc++.h>
using namespace std;
const int MAX=100000+10;
int n,ma,mb,mc,bma,bmb,bmc;
struct item{
	int no,a,b,c;
}f[MAX];
bool cmp1(item a,item b){
	return a.a>b.a;
}
bool cmp2(item a,item b){
	return a.b>b.b;
}bool cmp3(item a,item b){
	return a.c>b.c;
}bool cmp4(item a,item b){
	return a.no<b.no;
}
void out(){
	for(int i=1;i<=n;i++){
		cout<<f[i].no<<" "<<f[i].a<<" "<<f[i].b<<" "<<f[i].c<<endl;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i].a>>f[i].b>>f[i].c;
		f[i].no=i;
	}
	bool flag=0;
	
		sort(f+1,f+1+n,cmp1);
		ma=f[1].a;
//	out();
		sort(f+1,f+1+n,cmp2);
		mb=f[1].b;
//	out();
		sort(f+1,f+1+n,cmp3);
		mc=f[1].c;
	
	for(int i=1;i<=n;i++){
		if(f[i].a==ma&&f[i].b==mb&&f[i].c==mc){
			printf("%d ",f[i].no);
			flag=1;
		}else{
			break;
		}
	}
//	out();


	if(!flag) cout<<-1;
	return 0;
}
