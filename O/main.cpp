#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    int n, m, aboba1, aboba2;
    cin >> n >> m;
    bool visited[n+1] = {};
    bool isTeamOne[n+1] = {};
    vector<list<int>> anthonims = vector<list<int>>(n+1);
    for (int i = 1; i <= n; i++)
        anthonims[i] = list<int>();
    for (int i = 1; i <= m; i++){
        cin >> aboba1 >> aboba2;
        anthonims[aboba1].push_front(aboba2);
        anthonims[aboba2].push_front(aboba1);
    }
    queue<int> q = queue<int>();
    while (true){
        if (q.empty()){
            for (int i = 1; i <= n; i++){
                if (visited[i])
                    continue;
                if (anthonims[i].empty())
                    continue;
                q.push(i);
                isTeamOne[i] = true;
                break;
            }
        }
        if (q.empty()){
            cout <<"YES"; return 0;
        }
        for (auto it = anthonims[q.front()].begin(); it != anthonims[q.front()].end(); it++){
            if (visited[*it]){
                if (isTeamOne[*it] == isTeamOne[q.front()]){
                    cout << "NO"; return 0;
                }
            }

            else{
                q.push(*it);
                isTeamOne[*it] = !isTeamOne[q.front()];
            }
        }
        visited[q.front()] = true;
        q.pop();

    }

    return 0;
}