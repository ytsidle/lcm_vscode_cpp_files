#include <bits/stdc++.h>
using namespace std;
string ss;
int s,t,w,a[30],ess;
char tc;
int main(){
	cin>>s>>t>>w;
	for(int i=s;i<=t;i++){
		ss+=('a'+i-1);
	}
	ess=ss[ss.size()-1]-ss[0];
//	cout<<ss<<endl;
	for(int i=0;i<w;i++){
		cin>>tc;
		a[i]=tc-ss[0];
	}
//	for(int i=0;i<w;i++){
//		cout<<a[i];
//	}
	for(int i=1;i<=5;i++){
		int p=w-1;
		a[p]++;
		while(a[p]>ess-(w-1-p)){
			p--;
			if(p==-1) return 1;
			a[p]++;
		}
		for(int j=p+1;j<=w-1;j++){
			a[j]=a[j-1]+1;
			if(a[j]>ess) return 2;
		}
		for(int j=0;j<=w-1;j++) cout<<char(ss[0]+a[j]);
		cout<<endl;
		
	}
	return 0;
}
