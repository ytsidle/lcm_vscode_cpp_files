#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

#define ld long double
#define ll long long

const ld PI = 3.141592653589793;
const ll N = 1e5 + 10;
ll n;
ld x[N], y[N];

inline ld dist(ld lk, ld x_val, ld y_val, ld denom) {
    return abs(lk * x_val - y_val) * denom;
}

pair<ld, ld> fc(ld lk, ld denom) {
    ld sum = 0.0, sum_sq = 0.0;
    for (ll i = 1; i <= n; ++i) {
        ld di = dist(lk, x[i], y[i], denom);
        sum += di;
        sum_sq += di * di;
    }
    ld mean_dist = sum / n;
    ld variance = (sum_sq - (sum * sum) / n) / n;
    return {variance, mean_dist};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }

    // 预计算所有角度的三角函数值
    vector<ld> tan_table(181);
    vector<ld> denom_table(181);
    vector<ld> angles;
    for (int deg = -90; deg <= 90; ++deg) {
        ld rad = deg * PI / 180.0;
        tan_table[deg + 90] = tan(rad);
        ld denom = 1.0 / sqrt(tan_table[deg + 90] * tan_table[deg + 90] + 1.0);
        denom_table[deg + 90] = denom;
        angles.push_back(deg);
    }

    vector<tuple<ld, ld, ld>> results(181);
    #pragma omp parallel for
    for (int idx = 0; idx < 181; ++idx) {
        ld ang = angles[idx];
        auto res = fc(tan_table[idx], denom_table[idx]);
        results[idx] = make_tuple(ang, res.first, res.second);
    }

    // 找到最佳角度（最小方差）
    ld best_ang = 0, best_var = 1e18, best_avg = 0;
    for (int i = 0; i < 181; ++i) {
        auto [ang, var, avg] = results[i];
        if (var < best_var) {
            best_var = var;
            best_ang = ang;
            best_avg = avg;
        }
    }

    cout << "start" << fixed << setprecision(16) << best_ang << " " << best_var << "\n";

    // 精细搜索优化
    ld current_ang = best_ang;
    ld step = 0.5, adj = 1.0 / 15.0;
    ll iterations = 42;
    while (iterations--) {
        ld lower = current_ang - step;
        ld upper = current_ang + step;
        step *= 0.5;

        ld min_var_refined = best_var;
        ld refined_ang = current_ang;
        ld refined_avg = best_avg;

        for (ld angle = lower; angle <= upper; angle += adj) {
            ld rad = angle * PI / 180.0;
            ld lk = tan(rad);
            ld denom = 1.0 / sqrt(lk * lk + 1.0);
            auto [var, avg] = fc(lk, denom);

            if (var < min_var_refined) {
                min_var_refined = var;
                refined_ang = angle;
                refined_avg = avg;
            }
        }

        if (min_var_refined < best_var) {
            best_var = min_var_refined;
            best_ang = refined_ang;
            best_avg = refined_avg;
        }

        adj /= 2.0;
    }

    cout << "end:" << fixed << setprecision(16) << best_ang << " " << best_var << "\n";

    // 计算最佳斜率并作最小二乘拟合截距
    ld final_rad = best_ang * PI / 180.0;
    ld ansk = tan(final_rad);
    ld b0 = 0.0;
    for (ll i = 1; i <= n; ++i) {
        b0 += (y[i] - ansk * x[i]);
    }
    b0 /= n;

    cout << "y=" << fixed << setprecision(16) << ansk << "x+" << b0 << "\n";

    return 0;
}