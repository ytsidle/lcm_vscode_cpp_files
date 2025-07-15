#include <bits/stdc++.h>
using namespace std;
inline int count(int num){
	int cnt=0,i=3;
	while(num!=0&&num!=1&&num%2==0){
		num/=2;
		cnt++;
	}
	while(num!=1){
		while(num%i==0&&num!=1){
			num/=i;
			cnt++;
		}
		i+=2;
	}
	return cnt;
}
int l,r,ans;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&l,&r);
	for(int i=l;i<=r;i++){
		ans=max(ans,count(i));
	}
	printf("%d",ans);
	return 0;
}
