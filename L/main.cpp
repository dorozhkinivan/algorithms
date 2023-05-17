#include <iostream>
#include <queue>
#include <set>
#include <list>
using namespace std;

int main()
{
    int n, k, aboba;
    list<int> q = list<int>();
    multiset<int> ms = multiset<int>();
    cin >> n >> k;
    int ans[n-k+1] = {};
    for (int i = 0; i < k; i++){
        cin >> aboba;
        q.push_back(aboba);
        ms.insert(aboba);
    }
    ans[0] = *(ms.begin());

    for (int i = 1; i < (n - k + 1); i++){
        cin >> aboba;
        q.push_back(aboba);
        ms.insert(aboba);
        auto it = ms.find(q.front());
        ms.erase(it);
        q.pop_front();
        ans[i] = *(ms.begin());

    }
    for (int i = 0; i < n-k+1; i++)
        cout << ans[i] << " ";
    return 0;
}
