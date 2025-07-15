#include <bits/stdc++.h>
using namespace std;
string  a[40],b[40],s,d;
int t,pa,pb;
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i]>>b[i];
	}
	cin>>s>>d;
	for(int i=1;i<=t;i++){
		if(a[i]==s)pa=i;
		if(a[i]==d)pb=i;
	}if(pa&&pb&&pa<pb){
		cout<<"Yes\n"<<b[pa]<<"\n"<<b[pb];
	}else cout<<"No";
	return 0;
}
