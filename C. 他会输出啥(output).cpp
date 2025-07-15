#include <bits/stdc++.h>
using namespace std;
string t;
char ca,cb;
int a[20],k,tp;
long long ans;
void solve1(int f,int s,int t){
	if(t>0)for(int i=f;i<s;i+=t) ans+=i;
	else for(int i=f;i>s;i+=t) ans+=i;
}
void solve(int f,int s,int t){
	if(f==s)return;
	long long lens=abs(s-f),rs=lens%abs(t)==0?f+1ll*t*(lens/abs(t)-1):f+1ll*t*(lens/abs(t));
	lens=abs(rs-f)/abs(t)+1;
	ans+=(rs+f)*lens/2;
//	cout<<f<<" "<<rs<<" "<<lens<<endl;
}
int main(){
	freopen("output.in","r",stdin);
	freopen("output.out","w",stdout);
//	solve(3,-1,-2);
//	cout<<ans;
//	ans=0;
	getline(cin,t);
	getline(cin,t);
	ca=t[4];
	k=15;
	for(int i=1;i<=2;i++){
		a[tp++]=stoi(t.substr(k,t.find(",",k)-k));
		k=t.find(",",k)+1;
	}
	
	a[tp++]=stoi(t.substr(k,t.find(")",k)-k));
	getline(cin,t);
	k=16;
	int typ=0;
	for(int i=1;i<=2;i++){
		string tmp=(t.substr(k,t.find(",",k)-k));
		k=t.find(",",k)+1;
		if(tmp[0]>='a'&&tmp[0]<='z') typ=i;
		else a[tp++]=stoi(tmp);
	}
	a[tp++]=stoi(t.substr(k,t.find(")",k)-k));
	cb=t[5];
	getline(cin,t);
	getline(cin,t);
	int need=0;
	if(a[2]<0) need=1;
	if(typ==0){

		for(int i=a[0];need^(i<a[1]);i+=a[2]){
			solve(a[3],a[4],a[5]);
		}
	}if(typ==1){
		for(int i=a[0];need^(i<a[1]);i+=a[2]){
			solve(i,a[3],a[4]);
		}
	}if(typ==2){
		for(int i=a[0];need^(i<a[1]);i+=a[2]){
			solve(a[3],i,a[4]);
		}
	}
//	printf("%d %d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4],a[5]);
//	cout<<typ<<" "<<ans;
	printf("%lld",ans);
	return 0;
}
