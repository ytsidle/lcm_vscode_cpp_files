#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int n,a[MAX],type;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(type==0){
			if(a[i]>=0){
				type=1;
			}else if(a[i]<=0) type=2;
		}else if(type==1&&a[i]<0){
			type=3;
		}else if(type==2&&a[i]>0)type=3;
	}
	sort(a+1,a+1+n);
	if(type==1){
		long long r=n,wh=0,A=0,B=0;
		while(r>=1){
			wh%=2;
			if(wh==0){
				A+=a[r--];
			}
			if(wh==1){
				B+=a[r--];
			}
			wh++;
		}
		printf("%lld",A-B);
		return 0;
	}
	if(type==2){
		long long l=1,wh=0,A=0,B=0;
		while(l<=n){
			wh%=2;
			if(wh==0){
				A+=a[l++];
			}if(wh==1){
				B+=a[l++];
			}
			wh++;
		}
		printf("%lld",abs(A)-abs(B));
		return 0;
	}
	else{
		long long l=1,wh=0,A=0,B=0;
		while(l<=n){
			wh%=2;
			if(wh==0){
				A+=a[l++];
			}if(wh==1){
				B+=a[l++];
			}
			wh++;
		}
		printf("%lld",abs(A)-abs(B));
	}
	return 0;
}
/*
sort(a+1,a+1+n)
Ⅰ:
A[i]>=0
1 2 2 2 2 3 4
a:4,2,2,1=9
b:3,2,2=7
9-7=2
Ⅱ:
-1 -2 -7 -8 -5 
sort: -8 -7 -5 -2 -1
1->n;
A:-8 -5 -1 14
B:-7 -2 9
5
Ⅲ:-1 2 3 -4 5 -6
-6 -4 -1 2 3 5
A:-6 -1 3=-4
B:-4 2 5=3
1

*/