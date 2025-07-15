#include <iostream>
#include <vector>

using namespace std;
int f[1000010],graph[1000010][1000010];
int find(int x){
	return x==f[x]?x:find(f[x]);
}void merge(int x,int y){
	if(find(x)!=find(y))f[find(x)]=find(y);
}
int main() {
    int n, m, q, o;
    cin >> n >> m >> q >> o;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        merge(u,v);
        graph[u][v] = w;
        graph[v][u] = w;
    }

//    vector<vector<int>> queries(q);
    for (int i = 0; i < q; ++i) {
    	int u,v,w;
        cin >> u >> v >> w;
        if(o==1){
        	if(find(u)==find(v))cout<<"bougain\n";
        	else cout<<"villea\n";
		}else cout<<"bougain\n";
    }
	
    // 根据题目描述和特殊性质进行后续处理

    return 0;
}