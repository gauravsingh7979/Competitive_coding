#include <iostream>
#include <vector>
using namespace std;

long long permutations(string s) {
    int n = s.size();
    vector <int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;

    long long res = 1;
    for (int i = 1; i <= n; i++) res *= i;

    for (int f : freq) {
        for (int i = 1; i <= f; i++) res /= i;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        string best = s;
        long long bestVal = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                string temp = s;
                temp[i] = s[j];   // exactly one operation
                long long val = permutations(temp);
                if (val < bestVal) {
                    bestVal = val;
                    best = temp;
                }
            }
        }

        cout << best << "\n";
    }
    return 0;
}
