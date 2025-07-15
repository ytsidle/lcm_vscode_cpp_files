#include <bits/stdc++.h>
using namespace std;
string as;

int n;
void fun(string a){
	char t;
	int an=0,tmp=0,pos=0;
	while(a[0]){
		tmp=0;
		pos=a.find(a[0]);
		t=a[0];
		while(a[pos]==t){
			tmp++;
			a.erase(pos,1);
			pos=a.find(t);
		}if(tmp%2==1){
//			cout<<tmp<<" "<<an<<endl;
			an++;
		}
	}if(an<=1){
		cout<<"Yes"<<endl;;
	}else{
		cout<<"No"<<endl;
	}
}
int main(){
	scanf("%d",&n);
	cout<<n<<endl;
//	cout<<"\n";
	for(int i=1;i<=n;i++){
//		scanf("%s",&as);
		cin>>as;
//		cout<<"\n";
		fun(as);
	}
	

	return 0;
}
