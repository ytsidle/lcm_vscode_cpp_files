#include <bits/stdc++.h>
using namespace std;
long long fun(int sp,int ti,int rt,int tot){
	long long ans=0;
	ans=tot/(ti+rt)*ti*1ll*sp;
	ans+=min((tot%(ti+rt)),ti)*sp*1ll;
	return ans;
}
int main(){
	int a,b,c,d,e,f,x;
	cin>>a>>b>>c>>d>>e>>f>>x;
	long long pa=fun(b,a,c,x);
	long long pb=fun(e,d,f,x);
//	cout<<pa<<" "<<pb<<endl;
	if(pa>pb){
		cout<<"Takahashi";
	}else if(pa==pb){
		cout<<"Draw";
	}else cout<<"Aoki";
	return 0;
}
