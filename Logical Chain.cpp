#include <bits/stdc++.h>
using namespace std;
const int maxn = 252;
template <const int N>
class BitSet { // 手写bitset，[]只重载了获取值，不能直接改值，得用set等完成
private:
	static const int size = (N >> 6) + ((N & 63) != 0);
    
	uint64_t a[size];
	int find_after(int x) const {
		for (int i = x; i < size; i++) {
			if (a[i]) return __builtin_ctzll(a[i]) ^ (i << 6);
		}
		return N;
	}
public:
    const int sz = N;
	BitSet() {memset(a, 0, sizeof(a));}
	BitSet(const BitSet<N>& x) {memcpy(a, x.a, sizeof(a));}
	
	int get(int x) const {return a[x >> 6] >> (x & 63) & 1;}
	int operator[] (int x) const { return get(x);}
	void set(int x, int val = 1) {
		if (x >= N || x < 0) return;
		if (val == 0) a[x >> 6] &= ~(1ULL << (x & 63));
		else a[x >> 6] |= 1ULL << (x & 63);
	}
	void reset(int x) {set(x, 0);}
	void flip(int x) {
		if (x >= N || x < 0) return;
		a[x >> 6] ^= 1ULL << (x & 63);
	}
	void set() {for (int i = 0; i < size; i++) a[i] = -1ULL;}
	void reset() {memset(a, 0, sizeof(a));}
	void flip() {for (int i = 0; i < size; i++) a[i] = ~a[i];}
	
	int count() const {
		int res = 0;
		for (int i = 0; i < size; i++) res += __builtin_popcountll(a[i]);
		return res;
	}
	
	BitSet<N> operator~ () const {
		BitSet<N> res;
		for (int i = 0; i < size; i++) res.a[i] = ~a[i];
		return res;
	}
	
	BitSet<N> operator<< (const int& len) const {
		BitSet<N> res; 
		uint64_t last = 0;
		for (int i = 0; i + (len >> 6) < size; i++) {
			res.a[i + (len >> 6)] = last | (a[i] << (len & 63));
			if (len & 63) last = a[i] >> (64 - (len & 63));
		}
		return res;
	}
	BitSet<N> operator>> (const int& len) const {
		BitSet<N> res; 
		uint64_t last = 0;
		for (int i = size - 1; i >= (len >> 6); i--) {
			res.a[i - (len >> 6)] = last | (a[i] >> (len & 63));
			if (len & 63) last = a[i] << (64 - (len & 63));
		}
		return res;
	}
	
	BitSet<N>& operator&= (const BitSet<N>& x) {
		for (int i = 0; i < size; i++) a[i] &= x.a[i];
		return *this;
	}
	BitSet<N>& operator|= (const BitSet<N>& x) {
		for (int i = 0; i < size; i++) a[i] |= x.a[i];
		return *this;
	}
	BitSet<N>& operator^= (const BitSet<N>& x) {
		for (int i = 0; i < size; i++) a[i] ^= x.a[i];
		return *this;
	}
	
	BitSet<N>& operator<<= (const int& len) {return *this = *this << len;}
	BitSet<N>& operator>>= (const int& len) {return *this = *this >> len;}
	
	BitSet<N> operator& (const BitSet<N>& x) const {
		BitSet<N> res;
		for (int i = 0; i < size; i++) res.a[i] = a[i] & x.a[i];
		return res;
	}
	BitSet<N> operator| (const BitSet<N>& x) const {
		BitSet<N> res;
		for (int i = 0; i < size; i++) res.a[i] = a[i] | x.a[i];
		return res;
	}
	BitSet<N> operator^ (const BitSet<N>& x) const {
		BitSet<N> res;
		for (int i = 0; i < size; i++) res.a[i] = a[i] ^ x.a[i];
		return res;
	}
	
	bool any() const {
		for (int i = 0; i < size; i++) if (!a[i]) return false;
		return true;
	}
	bool none() const {
		for (int i = 0; i < size; i++) if (a[i]) return false;
		return true;
	}
	
	int first() const {return find_after(0);}
	int next(int x) const {
		uint64_t cur = a[x >> 6] >> (x & 63) >> 1;
		if (cur) return __builtin_ctzll(cur) + x + 1;
		return find_after((x >> 6) + 1);
	}
	int _Find_first() const {return first();} 
	int _Find_next(int x) const {return next(x);}
};
static BitSet<252> g[252],g2[252],vis;
static vector<int> out;
static int n,m,ccnt;
static char t[252];
void dfs(int x){
    vis.set(x);
    for(int v=g[x]._Find_first();v<g[x].sz;v=g[x]._Find_next(v)){
        if(!vis[v])dfs(v);
    }
    out.push_back(x);
}
void dfs2(int x){
    vis.set(x);
    ccnt++;
    for(int v=g2[x]._Find_first();v<g2[x].sz;v=g2[x]._Find_next(v)){
        if(!vis[v]) dfs2(v);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>(t);
            for(int j=0;j<n;j++){
                if(t[j]=='1'){
                    g[i].set(1+j);
                    g2[1+j].set(i);
                }
                
            }
        }
        for(int i=1;i<=m;i++){
            int k;
            cin>>k;
            while(k--){
                int u,v;
                cin>>u>>v;
                g[u].flip(v);
                g2[v].flip(u);
            }
            
            vis.reset();
            out.clear();
            for(int j=1;j<=n;j++){
                if(!vis[j]){
                    dfs(j);
                }
            }
        //    cout<<"end\n";
            vis.reset();
            ccnt=0;
            int ans=0;
            for(auto it=out.rbegin();it!=out.rend();it++){
                if(!vis[*it]){
                    ccnt=0;
                    dfs2(*it);
                    ans+=1ll*(ccnt-1)*ccnt/2;
                }
            }
            cout<<ans<<"\n";
        }
        for(int i=0;i<=n;i++){
            g[i].reset();
            g2[i].reset();
        }
    }
    return 0;
}