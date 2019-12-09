#include <bits/stdc++.h>
using namespace std;
int test = 0, tc = 0;
int n, total = 0, answer = 0;
string cards[101];
int main(void) {
    cin >> test;
    while (test--) {
        cin >> n;
        answer = 0;
        getline(cin, cards[0]);
        for (int i = 0; i < n; ++i) {
            getline(cin, cards[i]);
            for (int j = i - 1; j >= 0; --j) {
                if (cards[i] < cards[j]) {
                    ++answer;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", ++tc, answer);
    }
    return 0;
}
