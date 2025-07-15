#include <bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int MAX=2e5+10;
long long n,a,b,k,ans;
pair<long long,long long> d[MAX];
struct Data{
	long long num,id;
}datas[MAX];
bool cmp(Data cpa,Data cpb){
	return cpa.num>cpb.num;
}
bool cmp2(pair<long long,long long> cpa,pair<long long,long long> cpb){
	return datas[cpa.nd].num>datas[cpb.nd].num;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>datas[i].num>>datas[i].id;
	}
	sort(datas+1,datas+1+n,cmp);
	for(int i=1;i<=n;i++){
		sort(d+1,d+1+k,cmp2);
		for(int j=1;j<=k;j++){
			if(d[j].st+datas[i].id==a||d[j].st+datas[i].id==b){
				if(datas[i].num!=0&&datas[d[j].nd].num!=0){
					ans+=min(datas[i].num,datas[d[j].nd].num);
					long long t=datas[i].num;
					datas[i].num-=min(datas[i].num,datas[d[j].nd].num);
					datas[d[j].nd].num-=min(t,datas[d[j].nd].num);
				} 
			}
		}
		if(datas[i].num){
			++k;
			d[k].st=datas[i].id;
			d[k].nd=i;
		}
	}
	//自己对自己
	for(int i=1;i<=n;i++){
		if(2*datas[i].id==a||2*datas[i].id==b)ans+=(datas[i].num/2);
	}
	cout<<ans;
	return 0;
}
