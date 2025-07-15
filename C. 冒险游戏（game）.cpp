#include <bits/stdc++.h>
using namespace std;
int x,y,z;
int main(){
	cin>>x>>y>>z;
	if(x<0){
		x=-x;
		y=-y;
		z=-z;
	}
	if(0<=y&&y<=x){
		//有障碍
		if(y<z){
			cout<<-1;
			exit(0);
		}else{
			cout<<abs(0-z)+abs(x-z);
		}
	}else{
		cout<<x;
	}
	return 0;
}
