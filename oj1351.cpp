#include <bits/stdc++.h>
using namespace std;
int a,c=1;
int main(){
	while(a>=0&&c>=0){
		c=40-a*8;
		if(c%3==0&&a!=0&&c/3!=0){
			c/=3;
			cout<<a<<" "<<c<<endl;
		}
		a++;
	}
	return 0;
}
