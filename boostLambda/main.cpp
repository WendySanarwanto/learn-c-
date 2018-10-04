#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/lambda/lambda.hpp>
#include <iostream>

using namespace std;
using namespace boost::multi_index;
using namespace boost;

typedef multi_index_container<double> double_set;

int main() {
    double_set doubleSet;
    doubleSet.insert(100.00);
    doubleSet.insert(10.00);
    doubleSet.insert(3.75);
    doubleSet.insert(80.00);
    doubleSet.insert(90.00);
    doubleSet.insert(50.00);
    
    std::pair<double_set::iterator, double_set::iterator> result = doubleSet.range(50.00 <= lambda::_1, lambda::_1 <= 200.00);
    for_each(result.first, result.second, [](double d){ cout << d << " "; });
    
    cout << endl;
}