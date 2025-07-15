#include <bits/stdc++.h>
using namespace std;
int a[6][6],f[6],l[6],hmaxs,lmin,s;
int main(){
    for(int i=1;i<=5;i++){
       
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
           
        }
    }
    for(int i=1;i<=5;i++){
    	int max_i=a[i][1],m1,n1;
    	for(int j=1;j<=5;j++){
    		max_i=max(a[i][j],max_i);
    		if(max_i==a[i][j]){
    			m1=i,n1=j;
			}
		}
		int flag=0; 
		int min_j=a[m1][n1];
		for(int k=1;k<=5;k++){
			if(a[k][n1]<min_j) {
				flag=1;break;
			}
		}if(flag==0){
			cout<<m1<<" "<<n1<<" "<<min_j<<endl;
			s++;
		}
	}
	if(!s) cout<<"not found";
}
