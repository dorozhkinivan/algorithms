#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int numbers[n] {};
    if (n == 1){
        cin >> n;
        cout << 1 << " " << 1;
        return 0;
    }
    if (n == 2){
        cin >> n;
        cin >> n;
        cout << 1 << " " << 2;
        return 0;
    }
     if (n == 3){
        cin >> n;
        int n1, n2;
        cin >> n1;
        cin >> n2;
     if (n == n1 && n1 == n2)
        cout << 1 << " " << 2;
     else
     	cout << 1 << " " << 3;
     return 0;
    }

    for (int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    int maxLen = 0;
    int maxIndex = -1;
    int first = 0;
    for (int i = 0; i < n-2; i++){
        if (numbers[i] == numbers[i+1] && numbers[i+1] == numbers[i+2]){
            if (i+1-first > maxLen){
                maxIndex = first;
                maxLen = i+2-first;
            }
            first = i+1;
        }

    }
    if (n - first > maxLen){
        maxIndex = first;
        maxLen = n - first;
    }

    if (maxIndex == -1){
        maxIndex = 0;
        maxLen = n;
    }
    cout << maxIndex + 1 << " " << maxIndex + maxLen;
    return 0;
}
