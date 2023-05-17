#include <iostream>
#include <vector>
using namespace std;

bool comp (string a, string b){
    string f = a + b;
    string s = b + a;
    for (int i = 0; i < s.length(); i++){
        if (f[i] != s[i])
            return f[i] > s[i];
    }
    return false;
}
int main()
{
    string s;
    vector<string> vec = vector<string>();
    while(cin >> s)
        vec.push_back(s);

    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (!comp(vec[j], vec[j+1]))
                swap(vec[j], vec[j+1]);
        }
    }

      for (auto i = vec.begin(); i != vec.end(); ++i){
        if ((*i)[0] != '0'){
            cout << *i;
            vec.erase(i);
        break;
        }
    }


    for (auto i = vec.begin(); i != vec.end(); ++i)
        cout << (*i);
    return 0;
}
