#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;




int main() {
    string aboba;
    pair<int, int> nm = make_pair(0, 0);
    pair<int, int> f = make_pair(0, 0);
    pair<int, int> l = make_pair(0, 0);
    cin >> nm.first >> nm.second;
    cin >> f.first >> f.second;
    cin >> l.first >> l.second;
    char arr[nm.first + 2][nm.second + 2];
    int len[nm.first + 2][nm.second + 2];
    char vects[nm.first + 2][nm.second + 2];
    for (int i = 0; i < nm.first + 2; i++) {
        if (i != 0 && i != nm.first + 1)
            cin >> aboba;
        for (int j = 0; j < nm.second + 2; j++) {
            if (i != 0 && i != nm.first + 1 && j != 0 && j != nm.second + 1)
                arr[i][j] = aboba[j-1];
            len[i][j] = 10000000;
            vects[i][j] = '-';
        }
    }

    queue<pair<int, int>> ordQueue = queue<pair<int, int>>();
    ordQueue.push(f);
    len[f.first][f.second] = 0;
    vects[f.first][f.second] = 's';

    while (!ordQueue.empty()) {
        auto it = ordQueue.front();
        pair<int, int> cur = ordQueue.front();
        ordQueue.pop();
        if (vects[cur.first][cur.second] == 's') {
            if (arr[cur.first+1][cur.second] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first+1][cur.second]) {
                ordQueue.push(make_pair(cur.first + 1, cur.second));
                len[cur.first + 1][cur.second] = len[cur.first][cur.second] + 2;
                vects[cur.first+1][cur.second] = 'S';
            }
            if (arr[cur.first+1][cur.second] == '.' && len[cur.first][cur.second] + 1 < len[cur.first+1][cur.second]) {
                ordQueue.push(make_pair(cur.first + 1, cur.second));
                len[cur.first+1][cur.second] = len[cur.first][cur.second] + 1;
                vects[cur.first+1][cur.second] = 'S';
            }
            if (arr[cur.first][cur.second + 1] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first][cur.second + 1]) {
                ordQueue.push(make_pair(cur.first, cur.second + 1));
                len[cur.first][cur.second + 1] = len[cur.first][cur.second] + 2;
                vects[cur.first][cur.second+1] = 'E';
            }
            if (arr[cur.first][cur.second + 1] == '.' && len[cur.first][cur.second] + 1 < len[cur.first][cur.second + 1]) {
                ordQueue.push(make_pair(cur.first, cur.second + 1));
                len[cur.first][cur.second + 1] = len[cur.first][cur.second] + 1;
                vects[cur.first][cur.second+1] = 'E';
            }

            if (arr[cur.first][cur.second - 1] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first][cur.second - 1]) {
                ordQueue.push(make_pair(cur.first, cur.second - 1));
                len[cur.first][cur.second - 1] = len[cur.first][cur.second] + 2;
                vects[cur.first][cur.second-1] = 'W';
            }
            if (arr[cur.first][cur.second - 1] == '.' && len[cur.first][cur.second] + 1 < len[cur.first][cur.second - 1]) {
                ordQueue.push(make_pair(cur.first, cur.second - 1));
                len[cur.first][cur.second - 1] = len[cur.first][cur.second] + 1;
                vects[cur.first][cur.second-1] = 'W';
            }

            if (arr[cur.first-1][cur.second] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first-1][cur.second]) {
                ordQueue.push(make_pair(cur.first - 1, cur.second));
                len[cur.first - 1][cur.second] = len[cur.first][cur.second] + 2;
                vects[cur.first-1][cur.second] = 'N';
            }
            if (arr[cur.first-1][cur.second] == '.' && len[cur.first][cur.second] + 1 < len[cur.first-1][cur.second]) {
                ordQueue.push(make_pair(cur.first - 1, cur.second));
                len[cur.first-1][cur.second] = len[cur.first][cur.second] + 1;
                vects[cur.first-1][cur.second] = 'N';
            }
        }


        else if (vects[cur.first][cur.second] == 'N') {
            if (arr[cur.first][cur.second + 1] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first][cur.second + 1]) {
                ordQueue.push(make_pair(cur.first, cur.second + 1));
                len[cur.first][cur.second + 1] = len[cur.first][cur.second] + 2;
                vects[cur.first][cur.second+1] = 'E';
            }
            if (arr[cur.first][cur.second + 1] == '.' && len[cur.first][cur.second] + 1 < len[cur.first][cur.second + 1]) {
                ordQueue.push(make_pair(cur.first, cur.second + 1));
                len[cur.first][cur.second + 1] = len[cur.first][cur.second] + 1;
                vects[cur.first][cur.second+1] = 'E';
            }

            if (arr[cur.first][cur.second - 1] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first][cur.second - 1]) {
                ordQueue.push(make_pair(cur.first, cur.second - 1));
                len[cur.first][cur.second - 1] = len[cur.first][cur.second] + 2;
                vects[cur.first][cur.second-1] = 'W';
            }
            if (arr[cur.first][cur.second - 1] == '.' && len[cur.first][cur.second] + 1 < len[cur.first][cur.second - 1]) {
                ordQueue.push(make_pair(cur.first, cur.second - 1));
                len[cur.first][cur.second - 1] = len[cur.first][cur.second] + 1;
                vects[cur.first][cur.second-1] = 'W';
            }

            if (arr[cur.first-1][cur.second] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first-1][cur.second]) {
                ordQueue.push(make_pair(cur.first - 1, cur.second));
                len[cur.first - 1][cur.second] = len[cur.first][cur.second] + 2;
                vects[cur.first-1][cur.second] = 'N';
            }
            if (arr[cur.first-1][cur.second] == '.' && len[cur.first][cur.second] + 1 < len[cur.first-1][cur.second]) {
                ordQueue.push(make_pair(cur.first - 1, cur.second));
                len[cur.first-1][cur.second] = len[cur.first][cur.second] + 1;
                vects[cur.first-1][cur.second] = 'N';
            }
        }


        else if (vects[cur.first][cur.second] == 'S') {
            if (arr[cur.first][cur.second + 1] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first][cur.second + 1]) {
                ordQueue.push(make_pair(cur.first, cur.second + 1));
                len[cur.first][cur.second + 1] = len[cur.first][cur.second] + 2;
                vects[cur.first][cur.second+1] = 'E';
            }
            if (arr[cur.first][cur.second + 1] == '.' && len[cur.first][cur.second] + 1 < len[cur.first][cur.second + 1]) {
                ordQueue.push(make_pair(cur.first, cur.second + 1));
                len[cur.first][cur.second + 1] = len[cur.first][cur.second] + 1;
                vects[cur.first][cur.second+1] = 'E';
            }

            if (arr[cur.first][cur.second - 1] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first][cur.second - 1]) {
                ordQueue.push(make_pair(cur.first, cur.second - 1));
                len[cur.first][cur.second - 1] = len[cur.first][cur.second] + 2;
                vects[cur.first][cur.second-1] = 'W';
            }
            if (arr[cur.first][cur.second - 1] == '.' && len[cur.first][cur.second] + 1 < len[cur.first][cur.second - 1]) {
                ordQueue.push(make_pair(cur.first, cur.second - 1));
                len[cur.first][cur.second - 1] = len[cur.first][cur.second] + 1;
                vects[cur.first][cur.second-1] = 'W';
            }

            if (arr[cur.first+1][cur.second] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first+1][cur.second]) {
                ordQueue.push(make_pair(cur.first + 1, cur.second));
                len[cur.first + 1][cur.second] = len[cur.first][cur.second] + 2;
                vects[cur.first+1][cur.second] = 'S';
            }
            if (arr[cur.first+1][cur.second] == '.' && len[cur.first][cur.second] + 1 < len[cur.first+1][cur.second]) {
                ordQueue.push(make_pair(cur.first + 1, cur.second));
                len[cur.first+1][cur.second] = len[cur.first][cur.second] + 1;
                vects[cur.first+1][cur.second] = 'S';
            }
        }

        else if (vects[cur.first][cur.second] == 'W') {


            if (arr[cur.first][cur.second - 1] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first][cur.second - 1]) {
                ordQueue.push(make_pair(cur.first, cur.second - 1));
                len[cur.first][cur.second - 1] = len[cur.first][cur.second] + 2;
                vects[cur.first][cur.second-1] = 'W';
            }
            if (arr[cur.first][cur.second - 1] == '.' && len[cur.first][cur.second] + 1 < len[cur.first][cur.second - 1]) {
                ordQueue.push(make_pair(cur.first, cur.second - 1));
                len[cur.first][cur.second - 1] = len[cur.first][cur.second] + 1;
                vects[cur.first][cur.second-1] = 'W';
            }

            if (arr[cur.first+1][cur.second] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first+1][cur.second]) {
                ordQueue.push(make_pair(cur.first + 1, cur.second));
                len[cur.first + 1][cur.second] = len[cur.first][cur.second] + 2;
                vects[cur.first+1][cur.second] = 'S';
            }
            if (arr[cur.first+1][cur.second] == '.' && len[cur.first][cur.second] + 1 < len[cur.first+1][cur.second]) {
                ordQueue.push(make_pair(cur.first + 1, cur.second));
                len[cur.first+1][cur.second] = len[cur.first][cur.second] + 1;
                vects[cur.first+1][cur.second] = 'S';
            }
            if (arr[cur.first-1][cur.second] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first-1][cur.second]) {
                ordQueue.push(make_pair(cur.first - 1, cur.second));
                len[cur.first - 1][cur.second] = len[cur.first][cur.second] + 2;
                vects[cur.first-1][cur.second] = 'N';
            }
            if (arr[cur.first-1][cur.second] == '.' && len[cur.first][cur.second] + 1 < len[cur.first-1][cur.second]) {
                ordQueue.push(make_pair(cur.first - 1, cur.second));
                len[cur.first-1][cur.second] = len[cur.first][cur.second] + 1;
                vects[cur.first-1][cur.second] = 'N';
            }
        }


        else if (vects[cur.first][cur.second] == 'E') {



            if (arr[cur.first+1][cur.second] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first+1][cur.second]) {
                ordQueue.push(make_pair(cur.first + 1, cur.second));
                len[cur.first + 1][cur.second] = len[cur.first][cur.second] + 2;
                vects[cur.first+1][cur.second] = 'S';
            }
            if (arr[cur.first+1][cur.second] == '.' && len[cur.first][cur.second] + 1 < len[cur.first+1][cur.second]) {
                ordQueue.push(make_pair(cur.first + 1, cur.second));
                len[cur.first+1][cur.second] = len[cur.first][cur.second] + 1;
                vects[cur.first+1][cur.second] = 'S';
            }
            if (arr[cur.first-1][cur.second] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first-1][cur.second]) {
                ordQueue.push(make_pair(cur.first - 1, cur.second));
                len[cur.first - 1][cur.second] = len[cur.first][cur.second] + 2;
                vects[cur.first-1][cur.second] = 'N';
            }
            if (arr[cur.first-1][cur.second] == '.' && len[cur.first][cur.second] + 1 < len[cur.first-1][cur.second]) {
                ordQueue.push(make_pair(cur.first - 1, cur.second));
                len[cur.first-1][cur.second] = len[cur.first][cur.second] + 1;
                vects[cur.first-1][cur.second] = 'N';
            }
            if (arr[cur.first][cur.second + 1] == 'W' && len[cur.first][cur.second] + 2 < len[cur.first][cur.second + 1]) {
                ordQueue.push(make_pair(cur.first, cur.second + 1));
                len[cur.first][cur.second + 1] = len[cur.first][cur.second] + 2;
                vects[cur.first][cur.second+1] = 'E';
            }
            if (arr[cur.first][cur.second + 1] == '.' && len[cur.first][cur.second] + 1 < len[cur.first][cur.second + 1]) {
                ordQueue.push(make_pair(cur.first, cur.second + 1));
                len[cur.first][cur.second + 1] = len[cur.first][cur.second] + 1;
                vects[cur.first][cur.second+1] = 'E';
            }

        }


    }
    int ans = len[l.first][l.second];
    string ansStr = "";
    if (ans == 10000000){
        cout << -1;
        return 0;
    }

    pair<int, int> el = make_pair(l.first, l.second);
    while (vects[el.first][el.second] != 's'){
        ansStr = vects[el.first][el.second] + ansStr;
        if (vects[el.first][el.second] == 'E')
            el.second--;
        else if (vects[el.first][el.second] == 'W')
            el.second++;
        else if (vects[el.first][el.second] == 'N'){
            el.first++;
        }

        else if (vects[el.first][el.second] == 'S')
            el.first--;
    }
    cout << ans << endl << ansStr;

    return 0;
}
