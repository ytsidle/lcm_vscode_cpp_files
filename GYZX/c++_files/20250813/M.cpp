#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,S=1e4+10;
int n;
string st;
struct Trie{
    int ch[N][26],cnt,end[N];
    void insert(string &s){
        int p=1;
        for(int i=0;i<s.size();i++){
            int u=s[i]-'a';
            if(ch[p][u]==0){
                ++cnt;
                ch[p][u]=cnt;
            }
            p=ch[p][u];
        }
        end[p]=1;
    }
    int find(string &s){
        int p=1;
        for(int i=0;i<s.size();i++){
            int u=s[i]-'a';
            if(ch[p][u]==0) return 0;
            p=ch[p][u];
        }
        return end[p];
    }
}a,b;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>st;
        a.insert(st);
    }
    int m;
    cin>>m;
    while(m--){
        cin>>st;
        if(a.find(st)==1&&b.find(st)==0){
            cout<<"OK\n";
            b.insert(st);
        }
        else if(a.find(st)==1){
            cout<<"REPEAT\n";
        }else cout<<"WRONG\n";
    }
    return 0;
}