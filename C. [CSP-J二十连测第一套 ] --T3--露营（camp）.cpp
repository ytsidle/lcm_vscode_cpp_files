#include <bits/stdc++.h>
using namespace std;
struct Point{
	int x,y;
};
int ans=INT_MAX,k,flag;
int jv(Point a2,Point b2){
	return abs(a2.x-b2.x)+abs(a2.y-b2.y);
}
cmp(Point a,Point b){
	return a.y!=a.y?a.y<b.y:a.x<b.x;
}
int main(){
	Point a,b,c;
	scanf("%d%d",&a.x,&a.y);
	scanf("%d%d",&b.x,&b.y);
	scanf("%d%d",&c.x,&c.y);
	Point al[3]={a,b,c};
	sort(al,al+2,cmp);
	/*
		情况1:
		'	**/
			*/*
			/**'
	*/
	flag=1;
	for(int i=1;i<3;i++){
		if(al[i].x<al[i-1].x){
			flag=0;
			break;
		}
	}
	if(flag){
		ans=min((jv(al[0],al[1])+jv(al[1],al[2])),(jv(al[0],al[2])+jv(al[1],al[2])));
		printf("%d",ans+3);
	}
	
	return 0;
}
