#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <set>
using namespace std;
int main()
{
    string s;
    map<string,vector<int>> mapp = map<string,vector<int>>();
    stack<set<string>> st = stack<set<string>>();
    st.push(set<string>());
    while(cin >> s){
        if (s[0] == '{'){
            st.push(set<string>());
        }
        else if (s[0] == '}'){
            for (auto j = st.top().begin(); j != st.top().end(); j++){
                mapp.at(*j).pop_back();
                if (mapp.at(*j).size() == 0)
                    mapp.erase(*j);
            }
            st.pop();
        }
        else{
            size_t found = s.find("=");
            string firstVar = s.substr(0, found);
            string secondVar = s.substr(found+1, s.size());
            int secondVarInt;
            if (secondVar[0] < 'a'){
                secondVarInt = stoi(secondVar);
            }
            else{
                if (mapp.count(secondVar) >= 1){
                    secondVarInt = mapp[secondVar].back();
                }
                else
                    secondVarInt = 0;
            cout << secondVarInt << endl;
            }
            if (mapp.count(firstVar) == 1){
                if (st.top().count(firstVar) > 0)
                    mapp[firstVar][mapp[firstVar].size() - 1] = secondVarInt;
                else{
                    st.top().insert(firstVar);
                    mapp[firstVar].push_back(secondVarInt);
                }
            }
            else{
                st.top().insert(firstVar);
                vector<int> v = vector<int>();
                v.push_back(secondVarInt);
                mapp.insert(make_pair(firstVar, v));
            }
        }
    }

    return 0;
}
