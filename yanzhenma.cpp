#include <bits/stdc++.h>
using namespace std;
string a,b;
int main(){
	while(cin>>a>>b){
		if(a.size()==b.size()){
			bool flag=1;
			for(int i=0;i<a.length();i++){
				if(tolower(a[i])!=tolower(b[i])){
					flag=0;
					break;
				}
			}if(flag) cout<<"YES\n";
			else cout<<"NO\n";
		}else cout<<"NO\n";
		
	}
	return 0;
}
