#include <iostream>
#include <list>
#include <vector>
using namespace std;


int main()
{
    int n, k;
    char aboba;
    cin >> n;
    bool secondIsBigger = false;
    list<int> l1 = list<int>();
    list<int> l2 = list<int>();
    vector<int> vec = vector<int>();
    for (int i = 0; i < n; i++){
        cin >> aboba;
        if (aboba == '+'){
            cin >> k;
            l2.push_back(k);
            if (secondIsBigger){
                l1.push_back(l2.front());
                l2.pop_front();
                secondIsBigger = false;
            }
            else{
                secondIsBigger = true;
            }
        }
        else if (aboba == '*'){
            cin >> k;
            if (secondIsBigger){
                secondIsBigger = false;
                l1.push_back(l2.front());
                l2.pop_front();
                l2.push_front(k);

            }
            else{
                secondIsBigger = true;
                l2.push_front(k);
            }

        }
        else{
            if (secondIsBigger){
                l1.push_back(l2.front());
                vec.push_back(l1.front());
                l1.pop_front();
                l2.pop_front();
                secondIsBigger = false;
            }
            else{
                vec.push_back(l1.front());
                l1.pop_front();
                secondIsBigger = true;
            }
        }
    }
    for (int i = 0; i < vec.size();i++)
        cout << vec[i] << endl;
    return 0;
}
