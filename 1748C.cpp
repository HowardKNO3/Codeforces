#include <bits/stdc++.h>
#define MAXN 200005
#define ll long long 

using namespace std; 

int main () {
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        int score = 0;
        cin >> n;
        ll input[n] = {};
        for (int i = 0; i < n; i++) {
            cin >> input[i];
        }
        ll prefix_sum[n] = {};
        ll now_sum = 0;
        for (int i = 0; i < n; i++) {
            now_sum += input[i];
            prefix_sum[i] = now_sum;
        }
        int index = 0;
        while (input[index] != 0 && index < n) {
            if (prefix_sum[index] == 0) {
                score++;
            }
            index++;
        }
        vector<int> zero_pos;
        for (int i = 0; i < n; i++) {
            if (input[i] == 0) {
                zero_pos.push_back(i);
            }
        }
        zero_pos.push_back(n);
        /*
        for (int i = 0; i < zero_pos.size(); i++) {
            cout << zero_pos[i] << " ";
        }
        */
        for (int i = 0; i < zero_pos.size() - 1; i++) {
            vector<ll> v;
            for (int j = zero_pos[i]; j < zero_pos[i + 1]; j++) {
                v.push_back(prefix_sum[j]);
            }
            sort(v.begin(), v.end());
            int max_cnt = 0;
            int now_cnt = 1;
            for (int i = 1; i < v.size(); i++) {
                if (v[i] != v[i - 1]) {
                    max_cnt = max(max_cnt, now_cnt);
                    now_cnt = 1;
                } else {
                    now_cnt++;
                }
            }
            max_cnt = max(max_cnt, now_cnt);
            score += max_cnt;
        }
        cout << score << endl;
    }
}
