#include <bits/stdc++.h>
using namespace std;
string a,b,c,l[4];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b>>c;
	if(a==b&&b==c){
		cout<<0;
		return 0;
	}
	int ans=2;
	l[1]=a,l[2]=b,l[3]=c;
	sort(l+1,l+4);
	a=l[1],b=l[2],c=l[3];
	int num1=a[0],num2=b[0],num3=c[0];
	char ac=a[1],bc=b[1],cc=c[1];
//	cout<<a<<" "<<b<<" "<<c<<"\n";
	if(ac==bc&&bc==cc&&num1+1==num2&&num2+1==num3){
		cout<<0;
		return 0;
	}
	if(a==b) ans=min(ans,1);
	if(a==c) ans=min(ans,1);
	if(b==c) ans=min(ans,1);
	if(num1+1==num2&&num2+1==num3||(num1==num2&&num2==num3)){//数字连续,或全部一样
		//有任何一对一样
		if(ac==bc||ac==cc||bc==cc) ans=min(ans,1);
	}
	else{
		//数字无法构成顺子，刻子
		//分类讨论字母
		//只有一个连续或者相等：1
		if(num1+1==num2){
			if(ac==bc) ans=min(ans,1);
		}
		if(num1+1==num3){
			if(ac==cc) ans=min(ans,1);
		}if(num2+1==num3){
			if(bc==cc) ans=min(ans,1);
		}
	}
	cout<<ans;
	return 0;
}