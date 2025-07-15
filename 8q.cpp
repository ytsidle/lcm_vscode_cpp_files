#include <bits/stdc++.h>
using namespace std;
int n,out[20],h[20],lx[400],rx[400],ans[90000][20],hn,un;//hn表有的数量,un表示用的i(out数组)
bool a[15][15];
void add(){
    hn++;
    for(int i=1;i<=n;i++){
        ans[hn][i]=out[i];
    }
}
void dfs(int x,int y){
    a[y][x]=1;

    if(h[y]==0&&rx[x+y]==0&&lx[n-y+x]==0){
        un++;
        out[un]=y;
        if(un<n){
            h[y]=1,rx[x+y]=1,lx[n-y+x]=1;
//            cout<<hn<<" "<<out[un]<<endl;
            for(int i=1;i<=n;i++){
                dfs(x+1,i);
            }
//            h[x]=0,rx[x+y]=0,lx[n-y+x]=0;
        }else{

            h[y]=1,rx[x+y]=1,lx[n-y+x]=1;
//            cout<<"test"<<endl;
//            for(int i=1;i<=n;i++){
//                cout<<out[i]<<" ";
//            }cout<<"endl\n";
            add();
        }
        h[y]=0,rx[x+y]=0,lx[n-y+x]=0;
        a[y][x]=0,out[un]=0,un--;
        return;
    }else{
        a[y][x]=0;
        return;
    }

}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        dfs(1,i);
    }
    //输出
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }printf("%d",hn);
    return 0;
}