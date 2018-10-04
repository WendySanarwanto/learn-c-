#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>
#include <iostream>

using namespace std;
using namespace boost::multi_index;

// Employee struct
struct Employee {
    int     id;
    string  name;

    Employee(int id): id(id) {};
    Employee(int id, const string& name): id(id), name(name){};
    // Operator < is required to allow this type to be indexed by unique id, in MultiIndex
    bool operator < (const Employee& employee)const {return id < employee.id;};
};

// Define a multiply indexed set with indices by id and name
typedef multi_index_container<
    Employee,
    indexed_by<
        // Sort by employee::operator <
        ordered_unique<identity<Employee> >,

        // Sort by less<string> on name
        ordered_non_unique<member<Employee,string, &Employee::name> >
    >
> EmployeeSet;

void print_out_sorted_by_name(const EmployeeSet& employeeSet){
    // Get a view to index #1 (name)
    const EmployeeSet::nth_index<1>::type& name_index = employeeSet.get<1>();
    
    cout << "Print a list of Employees, shorted by their name:" << endl;
    cout << "-------------------------------------------------\n" << endl;
    int num = 1;
    for(auto employee: name_index) {
        cout << "Employee #" << num << endl;
        cout << "-----------------" << endl;
        cout << "Id     : " << employee.id << endl;
        cout << "Name   : " << employee.name << endl;
        cout << endl;
        num++;
    }    
}

void print_out_by_name(const EmployeeSet& employeeSet, const string name) {
    const EmployeeSet::nth_index<1>::type& name_index = employeeSet.get<1>();
    const int numResult = name_index.count(name);
    if (numResult <= 0) return;

    cout << "The result of searching employees by name: '"+name+"'" << endl;
    cout << "-------------------------------------------------\n" << endl;

    int num = 1;
    EmployeeSet::nth_index<1>::type::iterator result = name_index.find(name);
    for(int i=0; i<numResult;i++){
        
        cout << "Employee #" << num << endl;
        cout << "-----------------" << endl;
        cout << "Id     : " << result->id << endl;
        cout << "Name   : " << result->name << endl;
        cout << endl;
        num++;
        result++;
    }
}

void print_out_sorted_by_id(const EmployeeSet& employeeSet){
    const EmployeeSet::nth_index<0>::type& id_index = employeeSet.get<0>();    
    cout << "\nPrint a list of Employees, shorted by their id:" << endl;
    cout << "-------------------------------------------------\n" << endl;
    int num = 1;
    for(auto employee: id_index) {
        cout << "Employee #" << num << endl;
        cout << "-----------------" << endl;
        cout << "Id     : " << employee.id << endl;
        cout << "Name   : " << employee.name << endl;
        cout << endl;
        num++;
    }
}

void modify_name_by_id(EmployeeSet& employeeSet, const Employee target, const string newName){
    EmployeeSet::nth_index<0>::type& id_index = employeeSet.get<0>();
    const int numMatchedResult = id_index.count(target);
    if (numMatchedResult == 0) return;
    
    const EmployeeSet::nth_index<0>::type::iterator matchedResult = id_index.find(target);
    Employee modifiedTarget = *matchedResult;
    modifiedTarget.name = newName;
    id_index.replace(matchedResult, modifiedTarget);
}

int main() {
    EmployeeSet employees;
    employees.insert({1, "Johnny"});
    employees.insert({2, "Lisa"});
    employees.insert({3, "Billy"});
    employees.insert({4, "Paula"});
    employees.insert({5, "Steve"});
    employees.insert({6, "Lisa"});
    
    print_out_sorted_by_name(employees);
    cout << "/////////\n";
    print_out_sorted_by_id(employees);   

    cout << "/////////\n\n";
    // Find Record by name = "Lisa"
    print_out_by_name(employees, "Lisa");

    modify_name_by_id(employees, Employee(1), "Johnny Sin");
    print_out_by_name(employees, "Johnny Sin");

    modify_name_by_id(employees, Employee(6), "Lisa Wong");
    print_out_by_name(employees, "Lisa Wong");    
}