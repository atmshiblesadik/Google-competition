#include <bits/stdc++.h>
using namespace std;
int test = 0, tc = 0;
int search_engine, quries, answer;
char search_engine_name[101][101];
char query_search_engine[101][101];
int main(void) {
    scanf("%d", &test);
    while (test--) {
        scanf("%d ", &serach_engine);
        for (int i = 0; i < search_engine; ++i) {
            gets(search_engine_name[i]);
        }
        scanf("%d ", &quries);
        for (int i = 0; i < quries; ++i) {
            gets(query_search_engine[i]);
        }
        answer = 0;

        printf("Case #%d: %d\n", ++tc, answer);
    }

    return 0;
}

