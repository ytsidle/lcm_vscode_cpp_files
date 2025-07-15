#include <cstdio>
#include <cstring>
using namespace std;
const unsigned int MAX=1e7+1;
int n,sum,s,day,d,i;
bool b[MAX],type;
bool check(int num){
	for(unsigned int i=1;i<num;i++){
		if(b[i]) return false;
	}
	return true;
}
int main(){
	memset(b,true,sizeof(b));
	scanf("%d",&n);
	
	while(sum<n){
		s=0;
		day++;
//		cout<<sum<<endl;
 		type=false;
		for(i=1;i<=n;i++){

			if(check(i) && b[i] && !type){
//					cout<<"ok : "<<i<<endl;
					s=0;
					type=true;
					b[i]=false;
					sum++;
					if(i==n){
						d=day;
				}
			}
			if(s==2){
				if(b[i]){
//					cout<<"ok : "<<i<<endl;
					s=0;
					b[i]=false;
					sum++;
					if(i==n){
						d=day;
					}
				}
			}
			if(b[i]){
				s++;
			}	
		}
	}
	printf("%d %d",day,d);
	return 0;
}
