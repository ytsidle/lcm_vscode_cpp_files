#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
char s[N];
int ls[N],rs[N],n;
int dfs(int num,int fa){
    if(s[num]=='0'){

        return num;
    }
    if(s[num]=='2'){
        ls[num]=num+1;
        int tp=dfs(num+1,num);
        dfs(tp+1,num);
        rs[num]=tp+1;
    }else{
        ls[num]=num+1;
        dfs(num+1,num);
    }
}
int main(){
    // cin>>s+1;
    scanf("%s",s+1);
    n=strlen(s+1);
    dfs(1,0);
    for(int i=1;i<=n;i++) cout<<ls[i]<<"  "<<i<<"  "<<rs[i]<<"\n";
    return 0;
}