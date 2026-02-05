#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n <= 3) {
            cout << -1 << "\n";
            continue;
        }

        vector<int> used(n + 1, 0);
        vector<int> ans;

        ans.push_back(1);
        used[1] = 1;

        if (n >= 4) {
            ans.push_back(n);
            used[n] = 1;

            if (n - 1 != 3) {
                ans.push_back(n - 1);
                used[n - 1] = 1;
            }

            ans.push_back(3);
            used[3] = 1;
        }

        for (int i = n - 2; i >= 2; i--) {
            if (!used[i])
                ans.push_back(i);
        }

        for (int x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
