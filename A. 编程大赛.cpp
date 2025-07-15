#include <bits/stdc++.h>
using namespace std;
const int MAX=2e3+10;
struct Data{
	string name,school;
}data[MAX];
map<string,int> m;
int a[MAX][MAX],n,k,ans;
string name,school;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>name>>school;
//		data[i]=a(name,school);
		name=name.substr(0,2);
		data[i]={name,school};
		if(m[data[i].school]==0){
			m[data[i].school]=++k;
		}
	}
	for(int i=1;i<=n;i++){
		a[m[data[i].name]][m[data[i].school]]++;
	}
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=k;j++){
			ans+=a[i][j]*a[j][i];
		}
	}
	cout<<ans;
	return 0;
}
