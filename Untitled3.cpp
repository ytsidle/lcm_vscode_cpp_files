#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
//结构体
struct matches{
	char name[30];
	int k,t,w;
	int no;
//	double score;
};
matches *to[MAX];
bool cmp(matches a,matches b){
	if(a.k!=b.k) return a.k>b.k;
	else if(a.k==b.k){
		return (a.t+(a.w)*20)<(b.t+(b.w)*20);
	}
}
int n,ti,wi;
long long tt,ww;
matches match[MAX];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",&match[i].name);
		tt=0,ww=0;
		scanf("%d",&match[i].k);
		for(int j=1;j<=match[i].k;j++){
			scanf("%d%d",&ti,&wi);
			tt+=ti;
			ww+=wi;
		}
		match[i].t=tt;
		match[i].w=ww;
		to[i]=&match[i];
	}
	sort(match+1,match+1+n,cmp);
	int nos=1;
	for(int i=1;i<=n;i++){
		match[i].no=nos;
		if(!((match[i].t+(match[i].w)*20)==(match[i+1].t+(match[i+1].w)*20))) nos++;
	}
	for(int i=1;i<=n;i++){
		printf("%s %d\n",to[i]->name,to[i]->no);
	}
	return 0;
}
