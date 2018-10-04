#include <iostream>
#include <vector>

using namespace std;

template<class T>
void printVector(vector<T> list){
    for(auto item: list){
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    vector<int> intList = {3, 4, 5, 6};
    vector<string> stringList = {"i5", "i7", "i9", "Ryzen7", "Threadripper"};
    vector<float> floatList = { 200.00, 75.25, 150.5};
    printVector(intList);
    printVector(stringList);
    printVector(floatList);
}