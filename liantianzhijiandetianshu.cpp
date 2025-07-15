#include <bits/stdc++.h>
using namespace std;
int year,month,day,year2,month2,day2,ans;
int date[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool is_run(int year){
	if(year%100!=0){
		return year%4==0;
	}else{
		return year%400==0;
	}
}
int days(int y,int m,int d){
	int sum=0;
	for(int i=1;i<y;i++){
		if(is_run(i)){
			sum+=366;
		}else{
			sum+=365;
		}
	}for(int i=1;i<m;i++){
		sum+=date[i];
		if(i==2&&is_run(y)) sum+=1;
	}sum+=d;
	return sum;
}
int main(){
	cin>>year>>month>>day;
	cin>>year2>>month2>>day2;
	cout<<days(year2,month2,day2)-days(year,month,day);

	return 0;
}
