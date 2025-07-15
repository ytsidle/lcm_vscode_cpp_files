#include <bits/stdc++.h>
using namespace std;
int P=1e9+7;
int n,x,cnt;
long long sum=1;
const int M=2e6+10;
bitset<M> f;
vector<int> p;
map<int,int> m;
void init(){
	f[0]=f[1]=1;
	for(int i=2;i<=M;i++){
		if(f[i]==0){
			p.push_back(i);
		}for(int j=0;p[j]*i<=M;j++){
			f[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}
int main(){
	cin>>n;
	init();
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=0;j<p.size();j++){
			cnt=0;
			while(x%p[j]==0){
				cnt++;
			}if(cnt)m[p[j]]=m[p[j]]+cnt;
		}
	}
	for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
		sum*=(it->second+1);
		sum%=P;
	}
	cout<<sum;
	return 0;
}
