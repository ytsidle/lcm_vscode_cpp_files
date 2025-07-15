#include<bits/stdc++.h>
using namespace std;
//模拟退火
//快读快写
#define ld long double
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
const double begint=10000,endt=1e-12,change=0.999;

int n,pos[20],f[20][4];
int best_ans=INT_MAX;
void S(int times){
    int x,y,tmp_ans;
    while(times--){
        for(double T=begint;T>endt;T*=change){
            //随机交换
            do{
                x=rand()%n+1;
                y=rand()%n+1;
            }while(x==y);
            swap(pos[x], pos[y]);
            //计算当前状态的得分
            int now_ans=0;
            for(int i=1;i<=n;i++){
                now_ans+=abs(pos[i]-pos[f[i][1]])+abs(pos[i]-pos[f[i][2]])+ abs(pos[i]-pos[f[i][3]]);
            }
            //接受新状态
            if(now_ans<=best_ans){
                best_ans=now_ans;
            }else if(exp((best_ans-now_ans)/T)<(double)rand()/(RAND_MAX+1.0)){
                swap(pos[x], pos[y]); // 恢复交换
            }
        }
    }
    return ;
}
int main(){
    srand(time(0));
    n=read();
    for(int i=1;i<=n;i++){
        f[i][1]=read();
        f[i][2]=read();
        f[i][3]=read();
        pos[i]=i;
    }
    //模拟退火
    S(3);
    write(best_ans/2);
    return 0;
}