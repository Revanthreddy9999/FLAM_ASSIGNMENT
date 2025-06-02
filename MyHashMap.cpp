#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
    vector<int> mapArray;  // Direct-access array for keys 0 to 1,000,000

public:
    MyHashMap() {
        // Initialize all values to -1 indicating empty slots
        mapArray = vector<int>(1000001, -1);
    }

    // Inserts a (key, value) pair into the map or updates if key already exists
    void put(int key, int value) {
        mapArray[key] = value;
    }

    // Returns the value associated with the key, or -1 if not found
    int get(int key) {
        return mapArray[key];
    }

    // Removes the key and its value from the map
    void remove(int key) {
        mapArray[key] = -1;
    }
};

int main() {
    MyHashMap hashMap;
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    cout << hashMap.get(1) << endl; // Output: 1
    cout << hashMap.get(3) << endl; // Output: -1 (not found)
    hashMap.put(2, 1);
    cout << hashMap.get(2) << endl; // Output: 1 (updated)
    hashMap.remove(2);
    cout << hashMap.get(2) << endl; // Output: -1 (removed)
    return 0;
}
