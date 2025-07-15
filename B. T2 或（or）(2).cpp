#include <bits/stdc++.h>
using namespace std;
inline int get_or(int num){
	if(num==0) return 0;
	int wei=log2(num);
	return pow(2,wei+1)-1;
}
int t,l,r;
inline void solve(){
	l=get_or(l-1);
	r=get_or(r);
	printf("%d\n",r-l);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&l,&r);
		solve();
	}
	return 0;
}
