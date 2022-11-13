#include <bits/stdc++.h>
#define MAXN 100005
#define ll long long
using namespace std; 

int occur[MAXN][10] = {};

bool check (int start, int len) {
    int this_occur[10] = {};
    for (int i = 0; i < 10; i++) {
        this_occur[i] = occur[start + len][i] - occur[start][i];
    }
    
    int max_occur = 0;
    for (int i = 0; i < 10; i++) {
        max_occur = max(max_occur, this_occur[i]);
    }
    int distinct = 0;
    for (int i = 0; i < 10; i++) {
        if (this_occur[i] != 0) {
            distinct++;
        }
    }
    //cout << s << " " << max_occur << " " << distinct << endl;
    return distinct >= max_occur;
}

int main () {
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        ll ans = 0;
        string s;
        cin >> n >> s;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                occur[i][j] = 0;
            }
        }
        int now[10] = {};
        for (int i = 1; i <= s.length(); i++) {
            now[s[i - 1] - '0']++;
            for (int j = 0; j < 10; j++) {
                occur[i][j] = now[j];
            }
        }
        for (int i = 1; i <= 100; i++) {
            for (int j = 0; j < n - i + 1; j++) {
                if (check(j, i)) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}