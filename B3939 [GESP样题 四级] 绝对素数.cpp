#include <bits/stdc++.h>
using namespace std;
int a,b;
bool is[110];

void find_p(){
	for(int i=2;i<=100;i++){
		if(!is[i]){
			for(int j=2*i;j<=100;j+=i){
				is[j]=1;
			}
		}
	}
}
int main(){
	cin>>a>>b;
	find_p();
	for(int i=a;i<=b;i++){
		int re=(i%10)*10+i/10;
			if((!is[i])&&(!is[re])){
				cout<<i<<endl;
			}
	}
	return 0;
}
