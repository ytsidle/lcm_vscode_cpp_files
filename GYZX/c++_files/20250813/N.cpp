/*
Problem:Luogu P10470前缀统计
author : Lai_Chengming
*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
struct Trie
{
    int ch[N][26],cnt,sum[N];
    void init(){
        for(int i=0;i<=n;i++)
        for(int j=0;j<=25;j++)
        ch[i][j]=0;
        cnt=0;
        for(int i=0;i<=n;i++) sum[i]=0;
    }
    void insert(string &s){
        //先加完点建好边
        //然后再累计上子树
        int p=1;
        for(int i=0;i<s.size();i++){
            int u=s[i]-'a';
            if(ch[p][u]==0){
                ch[p][u]=++cnt;
            }
            p=ch[p][u];
        }
        sum[p]++;
    }
    int find(string &s){
        int p=1;
        int ans=0;
        for(int i=0;i<s.size();i++){
            int u=s[i]-'a';
            if(ch[p][u]==0) return ans;//太长了不存在
            p=ch[p][u];
            ans+=sum[p];
        }
        return ans;
    }
}tr;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    tr.init();
    for(int i=1;i<=n;i++){
        string st;
        cin>>st;
        tr.insert(st);
    }
    for(int i=1;i<=m;i++){
        string st;
        cin>>st;
        cout<<tr.find(st)<<"\n";
    }
    return 0;
}