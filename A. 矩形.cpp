#include <bits/stdc++.h>
using namespace std;
//#define first st
//#define second nd
const int M=1e4+10;
struct Square{
	pair<int,int> ul,dl,ur,dr;//up_l,down_l,up_r,down_r
	Square(pair<int,int> a,pair<int,int> b):dl(a),ur(b),ul({a.first,b.second}),dr({b.first,a.second}){
	}
};
int x,y,a,b;
short int cf[M][M];
int mx,my,smx=INT_MAX,smy=INT_MAX;
long long sum=0;
void add(Square s){
	int sy=s.dl.second,ty=s.ur.second,sx=s.ul.first,tx=s.ur.first;
//	cout<<ty<<"y"<<sy<<"x"<<sx<<"x"<<tx<<endl;
//	swap(sy,ty);
	ty-=1;tx-=1;
	mx=max(mx,tx),my=max(my,ty);
	smx=min(smx,sx),smy=min(smy,sy);
	for(int i=sy;i<=ty;i++){
		cf[i][sx]++;
		cf[i][tx+1]--;
	}
}
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
//	Square d({0,0},{2,3});
//	cout<<(d.ul.first)<<" "<<(d.ul.second);
	scanf("%d%d%d%d",&x,&y,&a,&b);
	Square A({x,y},{a,b});
	scanf("%d%d%d%d",&x,&y,&a,&b);
	Square B({x,y},{a,b});
	scanf("%d%d%d%d",&x,&y,&a,&b);
	Square C({x,y},{a,b});
//	cout<<(A.ur.second)<<"A"<<(A.dl.second)<<endl;	
	//暴力加差分
	add(A);
	add(B);
	add(C);
	int num=0;
	for(int i=smy;i<=my;i++){
		for(int j=smx;j<=mx;j++){
//			cout<<cf[i][j]<<" ";
			if(j==0){
				num=cf[i][j];
			}else{
				cf[i][j]+=cf[i][j-1];
				num=cf[i][j];
			}
			if(num==3){
				sum++;
			}
//			cout<<num<<" ";
		}
//		cout<<endl;
	}
//	cout<<smx<<" "<<mx<<" "<<smy<<" "<<my;
	printf("%lld",sum);
	return 0;
}
