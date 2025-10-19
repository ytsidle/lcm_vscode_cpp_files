#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, a[N], lst[N];
bool vis[N]; // 标记每个数是否选过
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > heap, mn, mx; // {ed[x], x} 小根
//priority_queue<pair<int, int>> mx;
int ans[N], cnt;
int main() {
	freopen("subsequence.in", "r", stdin);
	freopen("subsequence.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		lst[a[i]] = i;
	}
	
	for (int i = 1; i <= n; ++i)
		if (lst[i]) heap.push({lst[i], i});

	for (int i = 1, now = 0; i <= n; ++i) {
		while (!heap.empty() && vis[heap.top().second])
			heap.pop();
		if (heap.empty()) break;
		int ed = heap.top().first; // 没有选过的，最后出现位置最小的数的最后出现位置，注意不要pop
		
		while (now < ed) {
			++now;
			mx.push({-a[now], now});
			mn.push({a[now], now});
		}
		
//		cerr << mx.top().second << '\n';
		while (mx.size()&&(mx.top().second < i || vis[-mx.top().first])) mx.pop();
		while (mn.size()&&(mn.top().second < i || vis[mn.top().first])) mn.pop();
		int pos = cnt % 2 ? mn.top().second : mx.top().second;
		
//		cerr << i << ' ' << ed << ' ' << pos << '\n';
		
		ans[++cnt] = a[pos]; vis[a[pos]] = true; i = pos;
	}
	
	cout << cnt << '\n';
	for (int i = 1; i <= cnt; ++i)
		cout << ans[i] << ' ';
}
/*
10
3 5 2 3 1 3 4 2 1 3 

5 1 4 2 3

用小根堆维护所有未选数的ed

ed[x]表示x最后出现的位置
每次找没选过且ed值最小的数进行选择，记选择的数的位置为p

[p+1,n]
*/