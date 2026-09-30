#include<bits/stdc++.h>
using namespace std;
struct Ch{
    int id;
    int cnt;
    bool operator<(const Ch& rhs)const{
        return cnt<rhs.cnt;
    }
}c[27];
void init(){
    for(int i=1;i<=26;i++){
        c[i].id=i;
        c[i].cnt=0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        init();
        string s;
        cin>>s;
        if(s.size()==1){
            cout<<"Yes\n"<<s<<"\n";
            continue;
        }
        for(char ch:s) c[ch-'a'+1].cnt++;
        for(int i=1;i<=26;i++) if(c[i].cnt==0) c[i].cnt=1e9;
        sort(c+1,c+27);
        string ans="";
        int ls=0;
        for(int i=1;i<=26;i++){
            if(c[i].cnt==1e9) break;
            if(ls==0){
                ls=c[i].cnt;
                continue;
            }
            for(int j=1;j<=ls;j++){
                ans+=char(c[i].id+'a'-1)+char(c[i-1].id+'a'-1);
                cerr<<char(c[i].id+'a'-1)<<char(c[i-1].id+'a'-1)<<"\n";
            }
            ls=c[i].cnt-ls;
        }
        if(ans.size()!=s.size()) cout<<"No\n";
        else{
            cout<<"Yes\n"<<ans<<"\n";
        }
    }
    return 0;
}