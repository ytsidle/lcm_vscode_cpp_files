#include <bits/stdc++.h> 
using namespace std;
const int P=2e4+7;
string s;
vector<string> hashs[(P+10)];
int tmp[5][5];
int fx[4]={-1,0,1,0};
int fy[4]={0,1,0,-1};
void to_tmp(string ss){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			tmp[i][j]=(ss[i*3+j-4]-'0');
//			cout<<tmp[i][j]<<" ";
		}
//		cout<<"\n";
	}
}
string to_s(){
	string an="";
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			an+=(tmp[i][j]+'0');
		}
	}
	return an;
}
bool check(string ss){
	long long has=0;
	for(int i=0;i<ss.size();i++){
		has+=(ss[i])*(i+1)*(i+1);
	}
	long long k=has%P;
	for(string tms:hashs[k]){
		if(tms==ss) return 1;
	}return 0;
}
void insert(string ss){
	long long has=0;
	for(int i=0;i<ss.size();i++){
		has+=(ss[i])*(i+1)*(i+1);
	}
	long long k=has%P;
	hashs[k].emplace_back(ss);
}
struct node{
	string now;
	int step;
};
int main(){
	cin>>s;
	if(s=="123804765"){
		cout<<0;
		exit(0) ;
	}
	queue<node> q;
	q.push({s,0}) ;
	while(!q.empty()){
		node he=q.front();
		q.pop();
//		cout<<he.now<<"as\n";
		to_tmp(he.now);
		int x,y;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
//				cout<<tmp[i][j]<<" ";
				if(tmp[i][j]==0){
					x=i,y=j;
//					break;
				}
			}
		}
//		cout<<x<<" "<<y<<endl;
		for(int i=0;i<4;i++){
			int tx=x+fx[i],ty=y+fy[i];
			if(tx>=1&&tx<=3&&ty>=1&&ty<=3){
//				cout<<"in\n";
				swap(tmp[x][y],tmp[tx][ty]);
				string ss=to_s();
				if(!check(ss)){
					
					q.push({ss,he.step+1}); 
					insert(ss);
					if(ss=="123804765"){
						cout<<he.step+1;
						exit(0);
					}
				}swap(tmp[x][y],tmp[tx][ty]) ;
			}
		}
	} 
	return 0;
}