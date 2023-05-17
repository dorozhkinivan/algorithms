#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    int indexes[n+1];
    int kol[n+1] = {};
    vector<list<int>> indList = vector<list<int>>(n+1);
    multiset<pair<int, int>> sumIndex = multiset<pair<int, int>>();
    bool isVisited[n+1] = {};
    int visited = 0;
    queue<int> q = queue<int>();
    for (int i = 1; i <= n; i++){
        indList[i] = list<int>();
    }
    for (int i = 1; i <= n; i++){
        cin >> indexes[i];
        if (i != indexes[i]){
            indList[indexes[i]].push_front(i);
            kol[indexes[i]]++;
        }
        else{
            ans++;
            q.push(i);
        }

    }

    for (int i = 1; i <= n; i++)
        //if (kol[i] > 0)
        sumIndex.insert(make_pair(kol[i], i));


    while (true){
        //cout << endl;
        //for (int i = 1; i <= n; i++)
        //    cout << (!isVisited[i] ? "FALSE " : "TRUE ");
        //cout << endl;
        if (q.empty()){
            if (!sumIndex.empty()){
                auto it = prev(sumIndex.end());
                if (isVisited[(*it).second]){
                    sumIndex.erase(it);
                    continue;
                }
                ans++;
                isVisited[(*it).second] = true;
                for (auto it1 = indList[(*it).second].begin(); it1 != indList[(*it).second].end(); it1++)
                    if (!isVisited[*it1])
                        q.push(*it1);
                if (!isVisited[indexes[(*it).second]])
                    q.push(indexes[(*it).second]);
                sumIndex.erase(it);
            }
            else{
                cout << ans;
                return 0;
            }
        }
        if (q.empty())
            continue;
        if (isVisited[q.front()]){
            q.pop();
            continue;
        }
        isVisited[q.front()] = true;
        for (auto it1 = indList[q.front()].begin(); it1 != indList[q.front()].end(); it1++)
            if (!isVisited[*it1])
                q.push(*it1);
        if (!isVisited[indexes[q.front()]])
            q.push(indexes[q.front()]);
        q.pop();
    }
    cout << ans;
    return 0;
}