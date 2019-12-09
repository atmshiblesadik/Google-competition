#include <bits/stdc++.h>
using namespace std;
int test = 0, tc = 0;
int n, m, pos;
string first, second;
set<int> teamA, teamB;
map<string, int> name_id;
vector<int> name_pair[101];
bool possible = true;
bool visit[101];
void mapping_team(int player, int team) {
    visit[player] = true;
    queue<pair<int, int> > team_order;
    team_order.push({player, team});
    teamA.insert(player);
    while (!team_order.empty()) {
        player = team_order.front().first, team = team_order.front().second;
        team_order.pop();
        if (team) {
            for (auto it: name_pair[player]) {
                if (!visit[it]) {
                    teamB.insert(it);
                    team_order.push({it, 0});
                    visit[it] = true;
                }
                else {
                    teamB.insert(it);
                }
            }
        }
        else {
            for (auto it: name_pair[player]) {
                if (!visit[it]) {
                    teamA.insert(it);
                    team_order.push({it, 1});
                    visit[it] = true;
                }
                else {
                    teamA.insert(it);
                }
            }
        }
    }
}
int main(void) {
    cin >> test;
    while (test--) {
        cin >> n;
        name_id.clear();
        teamA.clear(), teamB.clear();
        possible = true;
        for (int i = 0; i < 101; ++i) name_pair[i].clear();
        m = 0;
        for (int i = 0; i < n; ++i) {
            cin >> first >> second;
            if (name_id.find(first) == name_id.end()) {
                name_id[first] = m++;
            }
            if (name_id.find(second) == name_id.end()) {
                name_id[second] = m++;
            }
            name_pair[name_id[first]].push_back(name_id[second]);
            name_pair[name_id[second]].push_back(name_id[first]);
        }
        memset(visit, false, sizeof visit);
        for (int i = 0; i < m; ++i) {
            if (!visit[i]) {
                mapping_team(i, 1);
            }
        }
        for (auto it: teamA) {
            if (teamB.find(it) != teamB.end()) {
                possible = false;
                break;
            }
        }
        if (possible) printf("Case #%d: YES\n", ++tc);
        else printf("Case #%d: NO\n", ++tc);
    }
    return 0;
}
