#include <bits/stdc++.h>
using namespace std;
double a,b,l,ta,cha=DBL_MAX;
int ma,mb;
int main(){
	cin>>a>>b>>l;
	for(int i=1;i<=l;i++){
		for(int j=1;j<=l;j++){
			if(__gcd(i,j)==1&&(i*1.0/j)>=(a/b)&&(i>j==a>b)){
				if((i*1.0/j)-(a/b)<cha){
					ma=i,mb=j;
					cha=(i*1.0/j)-(a/b);
				}
				
			}
		}
	}
	cout<<ma<<" "<<mb<<endl;
	return 0;
}
