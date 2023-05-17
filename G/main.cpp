#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) const {
        return a.second > b.second;
    }
};

void sw(char* a, char*b){
    char c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    int swapLevel=0;
    string s;
    cin >> s;
    int kols[26];
    multiset<pair<int, int>, cmp> vals = multiset<pair<int, int>, cmp>();
    map<int, int> mm = map<int, int>();
    int p;
    for (int i = 0; i < 26; i++){
        cin >> p;
        mm.insert(make_pair(i, p));
        vals.insert(make_pair(i, p));
    }
    for (int i = 0; i < 26; i++)
        kols[i] = 0;
    for (int i = 0; i < s.length(); i++){
        kols[s[i] - 'a']++;
    }
    int len = s.length();
    for (auto i = vals.begin(); i != vals.end(); i++){
        if (kols[(*i).first] >= 2){

            for (int j = swapLevel+1; j < s.length()-swapLevel; j++){
                if (s[j] - 'a' == (*i).first){
                    sw(&(s[swapLevel]), &(s[j]));
                    break;
                }
            }
            for (int j = s.length()-swapLevel-2; j >= swapLevel+1; j--){

                if (s[j] - 'a' == (*i).first){
                    sw(&(s[s.length()-1-swapLevel]), &(s[j]));
                    break;
                }
            }
            kols[(*i).first]-=2;
            swapLevel++;
        }
    }

    cout << s;
    return 0;
}