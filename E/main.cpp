//коровы
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;
    int coord[n];
    for (int i = 0; i < n; i++)
        cin >> coord[i];
    int ideal = ((coord[n-1] - coord[0]) / (k-1));
    int first = 0;
    int last = ideal;

    while (true){
        int currentMaxMinimalDistance = (last + first) / 2;
        int kol = 1;
        int lastPosition = 0;
        for (int i = 1; i < n; i++){
            if (coord[i] - coord[lastPosition] >= currentMaxMinimalDistance){
                kol++;
                lastPosition = i;
            }
        }
        int t = currentMaxMinimalDistance;
        if (kol >= k){
            first = currentMaxMinimalDistance + 1;
        }
        else{
            last = currentMaxMinimalDistance - 1;
        }
        if (first > last){
            cout << last;
            break;
        }
    }

    return 0;
}