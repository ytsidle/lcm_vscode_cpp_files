#include <bits/stdc++.h>
using namespace std;
int day,back;
int main(){
	cin>>day>>back;
	for(int i=1;i<=back;i++){
		day+=1;
		if(day==8) day=1;
	}cout<<day;
	return 0;
}

