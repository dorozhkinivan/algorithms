#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
using namespace std;



int main()
{
    long long n, m, aboba;
    vector<pair<long long, long long>> requests = vector<pair<long long, long long>>();
    vector<long long> ans = vector<long long>();
    cin >> n >> m;//
    multiset<pair<long long, long long>> capInd = multiset<pair<long long, long long>>();
    map<long long, long long> indCap = map<long long, long long>();
    capInd.insert(make_pair(n, 1));
    indCap.insert({1, n});

    for (long long i = 0; i < m; i++){


        cin >> aboba;

        if (aboba > 0){
            auto it = capInd.lower_bound(make_pair(aboba, 0));
            if (it != capInd.end()){
                long long capac;
                long long startIndex;
                startIndex = (*it).second;
                capac = (*it).first;
                requests.push_back(make_pair(aboba, startIndex));
                capInd.erase(it);
                indCap.erase(startIndex);
                if (aboba < capac) {
                    capInd.insert(make_pair(capac - aboba, startIndex + aboba));
                    indCap.insert({startIndex + aboba, capac - aboba});
                }
                ans.push_back(startIndex);
            }
            else{
                requests.push_back(make_pair(-9, -9));
                ans.push_back(-1);
            }
        }
        else{
            requests.push_back(make_pair(-9, -9));
            //cout << "ABOBA3" << endl;
            aboba = -aboba;
            pair<long long, long long> p = requests[aboba-1];
            if (p.first == -9)
                continue;

            auto itNext = indCap.upper_bound(p.second);
            auto itPrev = itNext;
            bool flagNext = false;
            bool flagPrev = false;
            if (itNext != indCap.end())
                if (itNext->first == p.first + p.second)
                    flagNext = true;

            itPrev = itNext;
            if (itPrev != indCap.begin()){
                --itPrev;
                if (itPrev->second + itPrev->first == p.second)
                    flagPrev = true;
            }
            if (!flagNext && !flagPrev){
                indCap.insert({p.second, p.first});
                capInd.insert(make_pair(p.first, p.second));
            }
            else if (!flagNext && flagPrev){
                itPrev->second = itPrev->second+p.first;
                capInd.erase(make_pair(itPrev->second-p.first, itPrev->first));
                capInd.insert(make_pair(itPrev->second, itPrev->first));
            }
            else if (flagNext && !flagPrev){
                long long cap = itNext->second;
                long long ind = itNext->first;
                indCap.erase(itNext);
                capInd.erase(make_pair(cap, ind));
                indCap.insert(make_pair(p.second, p.first+cap));
                capInd.insert(make_pair(p.first+cap, p.second));
            }
            else{
                long long capNext = itNext->second;
                long long indNext = itNext->first;
                long long capPrev = itPrev->second;
                long long indPrev = itPrev->first;
                itPrev->second = itPrev->second+p.first+capNext;
                indCap.erase(itNext);
                capInd.erase(make_pair(capNext, indNext));
                capInd.erase(make_pair(capPrev, indPrev));
                capInd.insert(make_pair(capPrev+p.first+capNext, indPrev));
            }
        }
    }

    for (long long i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
