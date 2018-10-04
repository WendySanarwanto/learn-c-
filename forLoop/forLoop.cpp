#include <iostream>

using namespace std;

bool parameterisedForLoop(int forLoopLength) {
    for(int i = 0; i < forLoopLength; i++) {
        if(forLoopLength >= 10){
            return true;
        }
    }
    return false;
}

int main() {
    cout << parameterisedForLoop(11) << endl;
}
