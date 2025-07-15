#include <bits/stdc++.h>
using namespace std;
const int M=2e5+102;
struct Data{
	int a,c;
}data[M];
int n,q;
long long s[M];
bool cmp(Data a,Data b){
	return a.a<b.a;
}
int bfind(int num){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(data[mid].a<=num) l=mid+1;
		else r=mid-1;
	}return r;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>data[i].a>>data[i].c;
	}
	sort(data+1,data+1+n,cmp);
	int mid_num=data[(n-1)/2+1].a,m;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+data[i].a;
	}
	cin>>q;
	cout<<bfind(40)<<endl;
	for(int i=1;i<=q;i++){
		cin>>m;
		cout<<"as:";
		if(m==mid_num){
			cout<<0<<endl;
			continue;
		}if(m<mid_num){
			cout<<s[(n-1)/2+1]-s[bfind(m)]<<endl;
			continue;
		}
		cout<<s[bfind(m)]-s[(n-1)/2]<<endl;
	}
	return 0;
}
