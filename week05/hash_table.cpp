#include <cmath>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class HashTable {
    static const int PRIME_CONST = 31;
    static const int ARR_SIZE = 3001;
    int arr[ARR_SIZE];
    // list<int> arr[ARR_SIZE];

    public:
        HashTable() {
            fill_n(arr, ARR_SIZE, 0);
        }

        void put(string key, int value) {
            int index = hashFunc(key);
            arr[index] = value;
            // arr[index].push_front(value);
        }

        static int hashFunc(string key) {
            size_t sum; // unsigned it             
            for (int i = 0; i < key.length(); i++) {
                sum += (key[i] * (int)pow(PRIME_CONST, i)) % ARR_SIZE;
            }
            // sumatoria de abc -> a*p⁰+b*p¹+c*p²
            return sum % ARR_SIZE;
        }

        void printAll() {
            for (int i = 0; i < ARR_SIZE; i++) {
                if (arr[i] > 0) {
                    cout << arr[i] << ", ";
                }
            }
            cout << endl;
        }

        int get(string key){
            int index = hashFunc(key);
            return arr[index];
        }
};

int main() {
    HashTable hTable;
    hTable.put("abc", 1);
    hTable.put("longString", 200);
    hTable.put("veryLongString", 3000);
    hTable.printAll();
    cout << hTable.get("veryLongString") << endl; // O()
    return 0;
}