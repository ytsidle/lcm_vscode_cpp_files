#include <iostream>
#include <queue>
using namespace std;
const int MAX=2000009;
int n,k;
queue<pair<int,int> > q;
bool f[2000100];
int main(){
	cin>>n>>k;
	q.push({n,0});
	f[n]=1;
	while(!q.empty()){
		int num=q.front().first,ans=q.front().second;
		if(num==k){
			cout<<ans;
			return 0;
		}
		q.pop();
		if(!f[num-1]&&num-1>=0){
			q.push({num-1,ans+1});
		}
		if(!f[num+1]&&num+1<=MAX){
			q.push({num+1,ans+1});
		}if(!f[num*2]&&num*2<=MAX){
			q.push({num*2,ans+1});
		}
	}
	return 0;
}
