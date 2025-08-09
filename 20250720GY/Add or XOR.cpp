#include <bits/stdc++.h>
using namespace std;
/*
对于a<b,一定有解
如果y<x 且a二进制下最后一位为0,则答案为有0就用y,没0就用x
否则为(b-a)*x
如果a=b+1,且a最后一位是一,则有解答案为y
否则-1
*/
int T,a,b,x,y;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>a>>b>>x>>y;
		if(a==b) cout<<"0\n";
		else if(a<b){
			if(y<x){
				int u=b-a;
				if(a%2==0) cout<<(u/2)*(y+x)+(u%2)*y<<"\n";
				else cout<<(u/2)*(x+y)+(u%2)*x<<"\n";
			}else cout<<(b-a)*x<<"\n";
		}else{
			if((a^1)==b) cout<<y<<"\n";
			else cout<<"-1\n";
		}
	}
	return 0;
}
