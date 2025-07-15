#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, U;
    cin >> N >> U;
    
    vector<vector<int>> grid(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= N; ++j) {
            grid[i][j] = (s[j - 1] == '#');
        }
    }
    
    int half = N / 2;
    int sum = 0;
    for (int ar = 1; ar <= half; ++ar) {
        for (int ac = half + 1; ac <= N; ++ac) {
            int r1 = ar, c1 = ac;
            int r2 = ar, c2 = N - ac + 1;
            int r3 = N - ar + 1, c3 = ac;
            int r4 = N - ar + 1, c4 = N - ac + 1;
            int cnt = grid[r1][c1] + grid[r2][c2] + grid[r3][c3] + grid[r4][c4];
            sum += min(cnt, 4 - cnt);
        }
    }
    
    cout << sum << '\n';
    
    while (U--) {
        int r, c;
        cin >> r >> c;
        
        // Calculate the adjusted row and column to find the representative of the quadrant group
        int adjusted_r = (r <= half) ? r : (N - r + 1);
        int adjusted_c = (c > half) ? c : (N - c + 1);
        int ar = adjusted_r;
        int ac = adjusted_c;
        
        // Calculate old contribution
        int r1 = ar, c1 = ac;
        int r2 = ar, c2 = N - ac + 1;
        int r3 = N - ar + 1, c3 = ac;
        int r4 = N - ar + 1, c4 = N - ac + 1;
        
        int old_cnt = grid[r1][c1] + grid[r2][c2] + grid[r3][c3] + grid[r4][c4];
        int old_contrib = min(old_cnt, 4 - old_cnt);
        sum -= old_contrib;
        
        // Toggle the cell's state
        grid[r][c] ^= 1;
        
        // Calculate new contribution
        int new_cnt = grid[r1][c1] + grid[r2][c2] + grid[r3][c3] + grid[r4][c4];
        int new_contrib = min(new_cnt, 4 - new_cnt);
        sum += new_contrib;
        
        cout << sum << '\n';
    }
    
    return 0;
}