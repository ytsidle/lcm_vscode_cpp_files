#include <bits/stdc++.h>
using namespace std;
int n,onum,ans[15][15],answer[15][15],outn;
bool use[15]={false};
void outs(){
    outn++;
    for(int i=1;i<=n;i++){
        answer[outn][i]=answer[0][i];
    }
}
void out(){
    for(int x=1;x<=3;x++){
        for(int i=1;i<=n;i++){
            cout<<answer[x][i]<<" ";
        }cout<<endl;
    }cout<<outn<<endl;

//    cout<<"out"<<endl;

}
bool is_ok(int i,int j){
    ans[i][j]=1;
    //横向
    for(int k=1;k<=n;k++){
        if(k!=j&&ans[i][k]==1){
            ans[i][j]=0;
            return false;

        }
    }//竖向
    for(int k=1;k<=n;k++){
        if(k!=i&&ans[k][j]==1){
            ans[i][j]=0;
            return false;
        }
    }//斜向
    bool type=false;
    for(int k=1;k<=n;k++){
        if(ans[k][k]==1&&type==false){
            type=true;
        }else if(ans[k][k]==1&&type==true){
            ans[i][j]=0;
            return false;
        }
    }type=false;
    for(int k=1;k<=n;k++){
        if(ans[k][n-k+1]==1&&type==false){
            type=true;
        }else if(ans[k][n-k+1]==1&&type==true){
            ans[i][j]=0;
            return false;
        }
    }
//    type=false;
    int si=(i<j?1:i-j+1),sj=(i<j?j-i+1:1);
    for(int k=0;si+k<=n&&sj+k<=n;k++){
        if(ans[si+k][sj+k]==0&&k!=0){
            return true;
        }else if(ans[si+k][sj+k]==1&&k!=0){
            ans[i][j]=0;
            return false;
        }
    }
    ans[i][j]=0;
}
void dfs(int i,int j){

        if(is_ok(i,j)){
//            cout<<"Ok:"<<i<<" "<<j<<endl;/
            onum++;

            answer[0][onum]=i;
            use[i]=true;
            ans[i][j]=1;
            if(onum<n) {
                for(int k=1;k<=n;k++){
                    if(!use[k]){
                        dfs(k,j+1);
                        use[k]=false;
                    }
                }use[i]=false;
                ans[i][j]=0;
                return;
            }else{
                outs();
                onum--;
                use[i]=false;
                ans[i][j]=0;
                return;
            }
        }else{

            return;
        }
        onum--;


}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        if(outn==3){
            break;
        }
        dfs(i,1);
        use[i]=false;
//        cout<<outn<<endl;
    }
    out();
    ans[1][6]=1;
    cout<<is_ok(2,5);
    return 0;
}