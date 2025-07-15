#include <bits/stdc++.h>
using namespace std;
int t1h,t1m,t2h,t2m,t;
int main(){
	cin>>t1h>>t1m>>t2h>>t2m;
	t=t2h*60+t2m-t1h*60-t1m;
	cout<<t/60<<" "<<t%60;
	return 0;
}
