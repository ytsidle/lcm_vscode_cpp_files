#include <bits/stdc++.h>
using namespace std;

int n,num,num1,b[6];
//string t;
//void ins(int nums[]){
//	for(int i=1;i<=n)
//}
int main(){
	cin>>n;
	set<int> a;
	
	for(int i=1;i<=n;i++){
		for(int i=1;i<=5;i++){
			cin>>b[i];
		}
		

//		a.insert(t);
		for(int j=1;j<=5;j++){
			num=b[j];
			for(int x=1;x<=9;x++){
				b[j]=(num+x)%10;
				a.insert(*b);
			}b[j]=num;
		}
		for(int j=1;j<6;j++){
			num=b[j];
			num1=b[j+1];
			for(int x=1;x<=9;x++){
				
				b[j]=(num+x)%10;
				b[j+1]=(num1+x)%10;
				a.insert(*b);
				cout<<*b;

			}b[j]=num;
			b[j+1]=num1;
		}
	}
	cout<<a.size();
	return 0;
}
