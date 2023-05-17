#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    stack<pair<int, char>> st;
    int numbers[s.size()];
    int currentSmall = 0;
    int currentBig = 0;
    for (int i = 0; i < s.size(); i++){
        if (!st.empty()){
            pair<int, char> c = st.top();
            if ((s[i] - c.second) == -32){
                st.pop();
                currentBig++;
                numbers[currentBig - 1] = c.first;
                continue;
            }
            else if ((s[i] - c.second) == 32){
                st.pop();
                currentSmall++;
                numbers[c.first - 1] = currentSmall;
                continue;
            }
        }
            if (s[i] >= 'A' && s[i] <= 'Z'){
                currentBig++;
                st.push(pair<int, char>{currentBig, s[i]});
            }
            else if (s[i] >= 'a' && s[i] <= 'z'){
                currentSmall++;
                st.push(pair<int, char>{currentSmall, s[i]});
            }

    }
    if (st.empty()){
        cout << "Possible" << endl;
        for (int i = 0; i < s.size()/2; i++)
            cout << numbers[i] << " ";
    }
    else
        cout << "Impossible";
    return 0;
}

