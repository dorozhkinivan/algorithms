#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, k;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> k;
    bool zero = false;
    bool loop = false;
    if (a*b - c != a)
    for (int i = 0; i < k;i++)
    {
        a = a * b;
        if (a >= c)
            a -= c;
        else{
            zero = true;
            break;
        }
        if (a > d){
            a = d;
            if (loop == true){
                break;
            }
            loop = true;

        }

    }
    if (zero)
        a = 0;
    cout << a;
    return 0;
}
