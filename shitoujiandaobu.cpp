#include <bits/stdc++.h>
using namespace std;
int who_win(int a,int b){
	int wins[6]={2,0,5,0,0,0};
	if(a==b) return 0;
	else if(b==wins[a]) return 1;
	else return 2;
}
int n,na,nb,al[110],bl[110],af,bf,an,bn;
int main(){
	cin>>n>>na>>nb;
	for(int i=0;i<na;i++){
		cin>>al[i];
	}for(int i=0;i<nb;i++){
		cin>>bl[i];
	}
	for(int i=0;i<n;i++){
		af=al[i%na];
		bf=bl[i%nb];
		if(who_win(af,bf)==1){
			an++;
		}else if(who_win(af,bf)==2){
			bn++;
		}
	}if(an==bn) cout<<"draw\n";
	else if(an>bn) cout<<"A\n";
	else cout<<"B";
	return 0;
}

