#include <bits/stdc++.h>
using namespace std;
string s,t;
char cha;
int n,q,a,b,c;
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	cin>>s;
	t=s;
	sort(t.begin(),t.end());
	cin>>q;
	int sta=0;
	for(int i=1;i<=q;i++){
		cin>>a;
		if(a==1){
			cin>>b>>cha;
			s[b-1]=cha;
			sta=1;
			t=s;
		}else{
			if(sta==1){
				sort(t.begin(),t.end());
				sta=0;
			}cin>>b>>c;
//			cout<<t<<" "<<s.substr(b-1,c-b+1)<<endl;
			if((int)t.find(s.substr(b-1,c-b+1))!=-1){
				cout<<"Yes\n";
			}else cout<<"No\n";
		}
	}
	return 0;
}
