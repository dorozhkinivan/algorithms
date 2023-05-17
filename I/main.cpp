#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, p, aboba;
    cin >> n >> k >> p;
    if (k == 0){
        cout << 0;
        return 0;
    }

    vector<list<int>> carsIndexes = vector<list<int>>(n+1);
    vector<int> indexesCars = vector<int> (p+1);
    set<int> onFloorNextIndexes = set<int>();
    set<int> onFloorCars = set<int>();
    int operations = 0;
    for (int i = 1; i <= p; i++){
        cin >> aboba;
        indexesCars[i] = aboba;
    }
    int startSecondPartIndex = -1;
    for (int i = 1; i <= p; i++){
        if (onFloorCars.size() == k){
            startSecondPartIndex = i;
            break;

        }

        if (onFloorCars.find(indexesCars[i]) == onFloorCars.end()){
            operations++;
            onFloorCars.insert(indexesCars[i]);
        }
    }
    if (startSecondPartIndex == -1)
    {
        cout << operations;
        return 0;
    }

    for (int i = startSecondPartIndex; i <= p; i++){
        carsIndexes[indexesCars[i]].push_back(i);
    }

    for (auto it = onFloorCars.begin(); it != onFloorCars.end(); ++it){
        if (!carsIndexes[*it].empty()){
            onFloorNextIndexes.insert(carsIndexes[*it].front());
            carsIndexes[*it].pop_front();
        }else{
            onFloorNextIndexes.insert(600000+*it);
        }

    }



    for (int i = startSecondPartIndex; i <= p; i++){


        int car = indexesCars[i];
        if (onFloorCars.find(car) != onFloorCars.end()){
            onFloorNextIndexes.erase(onFloorNextIndexes.begin());
        }
        else{
            operations++;
            auto it = onFloorNextIndexes.end();
            --it;
            if ((*it) >= 600000){
                onFloorCars.erase((*it) - 600000);
                onFloorCars.insert(car);

            }
            else{
                onFloorCars.erase(indexesCars[(*it)]);
                onFloorCars.insert(car);
            }
            onFloorNextIndexes.erase(it);
        }
            if (!carsIndexes[car].empty()){
                if (carsIndexes[car].front() <= i){
                    carsIndexes[car].pop_front();
                    if (!carsIndexes[car].empty()){
                        onFloorNextIndexes.insert(carsIndexes[car].front());
                        carsIndexes[car].pop_front();
                    }
                    else
                        onFloorNextIndexes.insert(600000+indexesCars[i]);
                }
                else{
                    onFloorNextIndexes.insert(carsIndexes[car].front());
                    carsIndexes[car].pop_front();
                }

            }
            else
                onFloorNextIndexes.insert(600000+indexesCars[i]);

    }
    cout << operations;
    return 0;
}
