#include <bits/stdc++.h>
using namespace std;
long long T,n,x,y,zyen,san;
char c;
int main(){
	cin>>T;
	while(T--){
//		scanf("%lld",&n);
		cin>>n;
		zyen=san=0;
		while(n--){
			cin>>c>>x>>y;
			if(c=='C'){
				if(x>=y) zyen++;
				else san++;
			}
			else{
				if(x>y) zyen++;
				else san++;
			}
		}
		if(zyen>san) cout<<"Yes"<<endl;
		else{
			cout<<"No"<<endl;
		}
		
	}
	return 0;
}
