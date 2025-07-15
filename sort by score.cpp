#include <bits/stdc++.h>
using namespace std;
struct stu{
	int score;
	string name;
}stus[25];
int n;
bool cmp(stu a,stu b){
	if(a.score!=b.score) return a.score>b.score;
	else{
		return a.name<b.name;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>stus[i].name>>stus[i].score;
	}
	sort(stus+1,stus+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<stus[i].name<<" "<<stus[i].score<<endl;
	}
	return 0;
}
