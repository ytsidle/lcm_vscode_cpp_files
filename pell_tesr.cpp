#include<bits/stdc++.h>
using namespace std;
string he(string s1,string s2){
	int a[1001]={0},b[1001]={0},c[1001]={0};
	string r;
	int x1=s1.size(),x2=s2.size(),i,k;
	for(i=0;i<x1;i++){
		a[i]=s1[x1-i-1]-'0';
	}
	for(i=0;i<x2;i++){
		b[i]=s2[x2-i-1]-'0';
	}
	k=x1;
	if(x2>x1) k=x2;
	for(i=0;i<k;i++){
		c[i]=a[i]+b[i];
	}
	for(i=0;i<k;i++){
		if(c[i]>=10){
			c[i+1]=c[i+1]+c[i]/10;
			c[i]=c[i]%10;
		}
	}
	if(c[k]!=0) k++;
	char f;
	for(i=k-1;i>=0;i--){
		f=c[i]+'0';
		r=r+f;
	}
	return r;
}
string cheng(string s){
	string r;
	int a[1100]={0},i,x=s.size(),k;
	for(i=0;i<x;i++){
		a[i]=s[x-i-1]-'0';
	}
	k=x;
	for(i=0;i<x;i++){
		a[i]=a[i]*2;
	}
	for(i=0;i<x;i++){
		if(a[i]>=10){
			a[i+1]=a[i+1]+a[i]/10;
			a[i]=a[i]%10;
		}
	}
	if(a[k]!=0) k++;
	char f;
	for(i=k-1;i>=0;i--){
		f=a[i]+'0';
		r=r+f;
	}
	return r;
}
int main()
{
	string x,y,z;
    int n;
    cin>>n;
    x="1";
    y="2";
    for(int i=3;i<=n;i++){
		z=he(cheng(y),x);
		x=y;
		y=z;
	}
	if(n==1){
 		cout<<x;
	}else if(n==2){
		cout<<y;
	}else{
		cout<<z;
	}
    return 0;
}