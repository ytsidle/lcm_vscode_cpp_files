#include <bits/stdc++.h>
using namespace std;
struct child{
	int sum,a,b;
}f[1100];
int n;
bool cmp(child a,child b){
	if(a.sum!=b.sum) return a.sum>b.sum;
	else return a.a>b.a;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i].a>>f[i].b;
		f[i].sum=f[i].a+f[i].b;
	}sort(f+1,f+1+n,cmp);
	for(int i=1;i<=n;i++){
		cout<<f[i].a<<" "<<f[i].b<<endl;
	}
	return 0;
}
