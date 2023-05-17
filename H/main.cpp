#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int kol[10001] = {};
    for (int i = 0; i < 10001; i++)
        kol[i] = 0;
    int aboba;
    for (int i = 0; i < n; i++){
        cin >> aboba;
        ans += aboba;
        kol[aboba]++;
    }
    int overflow = 0;
    int ind = 10000;
    while (true){
        if (kol[ind] + overflow < k){
            overflow += kol[ind];
            ind--;
        }
        else if (kol[ind] + overflow == k){
            ans -= ind;
            ind--;
            overflow = 0;
        }
        else{
            kol[ind]-= (k-overflow);
            ans -= ind;
            overflow = 0;
        }
        if (ind == 0 || (ind == 1 && kol[1] + overflow < k))
            break;

    }
    cout << ans;
    return 0;
}
