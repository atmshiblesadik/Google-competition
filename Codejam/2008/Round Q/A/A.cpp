#include <bits/stdc++.h>
using namespace std;
int test = 0, tc = 0;
int search_engine, quries, answer, total = 0, upper = 0;
int search_engine_counter[101];
string engine_name;
map<string, int> engine_id;
int main(void) {
    cin >> test;
    while (test--) {
        cin >> search_engine;
        engine_id.clear();
        getline(cin, engine_name);
        for (int i = 0; i < search_engine; ++i) {
            getline(cin, engine_name);
            engine_id[engine_name] = i;
        }
        cin >> quries;
        getline(cin, engine_name);
        memset(search_engine_counter, 0, sizeof(search_engine_counter));
        answer = 0;
        for (int i = 0; i < quries; ++i) {
            getline(cin, engine_name);
            search_engine_counter[engine_id[engine_name]] = 1;
            total = 0;
            for (int j = 0; j < search_engine; ++j) {
                if (search_engine_counter[j]) ++total;
            }
            if (total == search_engine) {
                ++answer;
                memset(search_engine_counter, 0, sizeof(search_engine_counter));
            }
            search_engine_counter[engine_id[engine_name]] = 1;
        }
        printf("Case #%d: %d\n", ++tc, answer);
    }
    return 0;
}
