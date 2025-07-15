#include <bits/stdc++.h>
using namespace std;
struct Node{
	int x,y;
}points[5000];
set<pair<int,int> > s;
int n,m,x,y;
int fx[4]={-1,0,1,0};
int fy[4]={0,1,0,-1};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>points[i].x>>points[i].y;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<4;j++){
			int tx=points[i].x+fx[j],ty=points[i].y+fy[j];
//			cout<<tx<<"dd"<<ty<<endl;
			bool flag=1;
			for(int k=1;k<=n;k++){
				if(points[k].x==tx&&points[k].y==ty){
					flag=0;
					break;
				}
			}if(flag){
				s.insert({tx,ty});
			}
		}
	}cout<<s.size()<<endl;
	for(auto it=s.begin();it!=s.end();it++){
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	return 0;
}
