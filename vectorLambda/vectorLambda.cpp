#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/lambda/lambda.hpp>

using namespace std;
using namespace boost::lambda;

void printVector(vector<int> vectorOfNumbers) {
    for(auto number : vectorOfNumbers) {
        cout << number << ", ";
    }
}

void printVectorInLambda(vector<int> vectorOfNumbers) {
    for_each(vectorOfNumbers.begin(), vectorOfNumbers.end(), [](int number){ cout << number << ", "; });
}

void printVectorInBoostLambda(vector<int> vectorOfNumbers) {
    for_each(vectorOfNumbers.begin(), vectorOfNumbers.end(), cout << _1 << ", ");
}

int main() {
    cout << "[INFO] Given 2 vectors of number:" << endl;
    vector<int> vectorOfNumbers = {1, 2, 3, 4};
    cout << "1st vector: [ ";
    for(int i = 0; i < vectorOfNumbers.size(); i++) {
        cout << vectorOfNumbers[i];
        if (i < vectorOfNumbers.size()-1){
            cout << ",";
        }
        cout << " ";
    }
    cout << "]"<< endl;

    cout << "2nd vector: [ ";
    vectorOfNumbers = {10, 11, 12, 13};
    printVector(vectorOfNumbers);
    cout << "]"<< endl << endl;
    
    cout << "[INFO] - Pushing back '1000' at tail of 2nd vector, gives: [ ";
    vectorOfNumbers.push_back(1000);
    printVectorInLambda(vectorOfNumbers);
    cout << "]" << endl;

    cout << "[INFO] - Poping back '1000' out of 2nd vector, gives: \t [ ";
    vectorOfNumbers.pop_back();
    printVectorInBoostLambda(vectorOfNumbers);
    cout << "]" << endl;

    cout << "[INFO] - Printing 2nd vector starting from the 2nd element: [ ";
    for_each(vectorOfNumbers.begin()+2, vectorOfNumbers.end(), [](int number){ cout << number << " "; });
    cout << "]" << endl;

    cout << "[INFO] - Display 1st element of 2nd vector: " << vectorOfNumbers.front() << endl;

    cout << "[INFO] - Display 3rd element of 2nd vector: " << vectorOfNumbers.at(2) << endl;

    cout << "[INFO] - Accessing out of range element of 2nd vector: ";
    try {
        cout << vectorOfNumbers.at(100) << endl;
    }catch(out_of_range& ex){
        cout << endl << "[ERROR] - Details: " << ex.what() << endl;
    }
}
