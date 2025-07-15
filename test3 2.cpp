#include <bits/stdc++.h>
using namespace std;
string s1,s2;
void dfs(int l,int r,int l1,int r1){//s1中序,s2前序
	if(l<=r)
		g=s2[l];
		p=s1.find(g);
//		ls=s1.substr(0,p);
//		rs=s1.substr(p+1);
		dfs(l,p,)
		cout<<g;
}
int main(){
	
	cin>>s1;
	cin>>s2;
	
	dfs(0,s1.length()-1,0,s1.length()-1);
	return 0;
}
