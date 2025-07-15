#include <bits/stdc++.h>
using namespace std;
long double dta,x1,x2,x;
int t,m,a,b,c;
int res[2];
int gcd(int a,int b){
	if(a==0){
		return b;
	}else if(b==0){
		return a;
	}else{
		if(a>=b){
			return gcd(b,a%b);
		}else{
			return gcd(b,a);
		}
		
	}
}
void fpq(long double v){
    int q,p;

//    int li[2];
    for(q=1;q<=m;q++){
        if(int(v*q)==v*q){
            p=v*q;
            cout<<"in1";
            if(gcd(p,q)==1){
                cout<<"in2";
                res[0]=p,res[1]=q;
//                return li;
            }
        }
    }
//    return li;
    res[0]=0,res[1]=0;
}
void print(long double x){
    fpq(x);
    int p=res[0],q=res[1];
    //有理数判断&输出----------start------------
    if(p!=0 && q!=0){
        if(q==1){
            printf("%d\n",p);
        }else{
            printf("%d/%d\n",p,q);
        }
    }
}
int main(){
//    fpq(-7);
//    cout<<res[1];
	scanf("%d%d",&t,&m);
	for(int i=1;i<=t;i++){
		scanf("%d%d%d",&a,&b,&c);
		dta=b*b-(4*a*c);
		if(dta<0){
			printf("NO\n");
		}else{
            bool type=0;
			x1=((-b)+sqrt(dta))/(2*a);
			x2=((-b)-sqrt(dta))/(2*a);
			if(x1>x2){
                x=x1;
            }else{
                type=1;
                x=x2;
            }
            if(a*x*x+b*x+c==0){
                cout<<"in";
                print(x);
            }
            //-----------------------end------------------
            //无理数输出--------------start--------------------
            else{
                long double q1=(-b)/2;
                long double q2;
                int r=b*b-4*a*c;
                if(type){
                	q2=-(1/2);
                }else{
                	q2=(1/2);
                }
                if(q1!=0){
                    printf("-%d/2+",b);
                }if(q2==1){
                	printf("sqrt(%d)",r);
				}else if(q2/1==q2){
                    printf("%.0f*sqrt(%d)\n",q2,r);
                }else if(int q3=int(1/q2)/1==1/q2){
                	printf("sqrt(%d)/%d\n",r,q3);
				}else{
                    fpq(q2);
					int d=res[0],c=res[1];
					printf("%d*sqrt(%d)/%d\n",c,r,d);
				}
            }

		}
	}
//	cout<<gcd(12,18);

	return 0;
}
