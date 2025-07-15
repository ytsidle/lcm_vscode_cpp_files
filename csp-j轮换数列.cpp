#include <bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
int s=1,e,a[MAX],n,m;
void move(long long num){
	num%=n;
	if(num!=0){
		s+=n-num;
		e=s-1;
		if(e==0) e=4;
	}
}void exthird(int num){
	num%=3;
	int fp=s;
	int sp=(s+1)%n==0?n:(s+1)%n;
	int tp=(s+2)%n==0?n:(s+2)%n;
//	cout<<fp<<" "<<sp<<" "<<tp<<endl;
	for(int i=1;i<=num;i++){
		int thi=a[tp];
		a[tp]=a[sp];
		a[sp]=a[fp];
		a[fp]=thi;
	}

}
int main(){
	scanf("%d%d",&n,&m);
	iota(a+1,a+1+n,1);
	e=n;
	for(int i=1;i<=m;i++){
		long long tn;
		char op;
		scanf("%lld%c",&tn,&op);
		if(op=='a'){
			move(tn);
		}else{
			exthird(tn);
		}
	}
	int cnt=s;
	while(1){
		printf("%d ",a[cnt]);
		if(cnt==e){
			break;
		}
		cnt=(cnt+1)%n==0?n:(cnt+1)%n;
		
	}
	return 0;
}
