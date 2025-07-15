#include <bits/stdc++.h>
using namespace std;
int y1,m1,d1,y2,m2,d2;
bool is_in(int num,int a[]){
	for(int i=1;i<=a.size()-1;i++){
		if(a[i]==num){
			return 1;
		}
	}return 0;
}
int main(){
	cout<<is_in(1,[1,2,3]);
	return 0;
}
