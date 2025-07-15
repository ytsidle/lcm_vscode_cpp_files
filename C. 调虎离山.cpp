#include <bits/stdc++.h>
using namespace std;
const int M=1e6+10;
unsigned long long a[M],n,m,ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
    unsigned long long tnum=(1ull<<m)-1;
//    cout<<tnum<<endl;
	for(int i=1;i<=n;i++){
		//LCA找gp
		unsigned long long acnt=0,bcnt=0,now=a[i],to=tnum;
		while(now!=to){
			if(now>to){
				now=(now>>1ull);
				acnt++;
			} 
			else {
				to=(to>>1ull);
				bcnt++;
			}
		}
		ans=max(acnt+bcnt,ans);
	}
	cout<<ans;
	return 0;
}
