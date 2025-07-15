#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
long long n,a,b,d[MAX],dui[MAX],k,ans;
struct Data{
	long long num,id;
}data[MAX];
bool cmp(Data cpa,Data cpb){
	return cpa.num>cpb.num;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>data[i].num>>data[i].id;
	}
	sort(data+1,data+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(d[j]+data[i].id==a||d[j]+data[i].id==b){
				ans+=min(data[i].num,data[dui[j]].num);
				data[i].num-=min(data[i].num,data[dui[j]].num);
				data[dui[j]].num-=min(data[i].num,data[dui[j]].num);
				
			}
		}
		if(data[i].num!=0){
			++k;
			d[k]=data[i].id;
			dui[k]=i;
		}
	}
	//自己对自己
	for(int i=1;i<=n;i++){
		if(2*data[i].id==a||2*data[i].id==b)ans+=(data[i].num/2);
	}
	cout<<ans;
	return 0;
}
