#include <bits/stdc++.h>
using namespace std;
string a,b;
int main(){
	freopen("str.in","r",stdin);
	freopen("str.out","w",stdout);
	cin>>a>>b;
	if(a.size()!=b.size()){
		cout<<1<<endl;
		return 0;
	}
	int type=2;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			if(tolower(a[i])==tolower(b[i])){
				type=3;
			}else{
				type=4;
				break;
			}
		}
	}
	cout<<type;
	return 0;
}
