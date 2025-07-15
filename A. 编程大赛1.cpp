#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
int d[MAX],d2[MAX];
int a[2629][2629],n,k,ans;
string name,school;
inline int ex(string a){
	return 100*(a[0]-'A'+1)+(a[1]-'A'+1);
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>name>>school;
		name=name.substr(0,2);
		d[i]=ex(name),d2[i]=ex(school);
		a[d[i]][d2[i]]++;
	}
	for(int i=1;i<=2628;i++){
		for(int j=i+1;j<=2628;j++){
			ans+=(a[i][j]*a[j][i]);
		}
	}
	cout<<ans;
	return 0;
}
