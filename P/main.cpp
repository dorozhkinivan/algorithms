#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    int aboba;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; j++)
            for (int q = 0; q < n; q++){
                aboba = max(matrix[j][i], matrix[i][q]);
                if (aboba < matrix[j][q])
                    matrix[j][q] = aboba;
            }
    int max = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (max < matrix[i][j])
                max = matrix[i][j];
    cout << max;
    return 0;
}