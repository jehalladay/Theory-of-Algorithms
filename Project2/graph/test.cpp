#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "list.h"

using namespace std;

void print_int(int);



int main() {

    // List<int> first;

    // first.traverse();

    // first.push(5);

    // first.traverse();
    // first.traverse(print_int);


    // cout << "Contents of Index 1: " << first.get(0) << endl;

    // // should abort with message "Index does not exist"
    // // cout << "Contents of Index 2: " << first.get(1) << endl; 


    // cout << "length: " << first.length() << endl;

    // first.delete_item(0);

    // cout << "length: " << first.length() << endl;

    // // should abort with message "Index does not exist"
    // // first.delete_item(1);

    // first.traverse();
    // first.traverse(print_int);

    // for(int i = 0; i <= 10; i++) {
    //     first.push(i+1);
    // }

    // cout << "print all indicies" << endl;
    // first.traverse();

    // cout << endl << "print contents for each indicie" << endl;
    // first.traverse(print_int);

    // cout << "testing bracket overloading" << endl;

    // cout << "first[0] = 1: " << first[0] << endl;
    // cout << "first[10] = 11: " << first[10] << endl;



    // cout << "testing list constructor with set length and fill" << endl;
    // List<int> second(10, 1);

    // cout << "length: " << second.length() << endl;
    // cout << "print contents for each indicie" << endl;
    // second.traverse(print_int);

    // cout << "second[0] = 1:" << second[0] << endl;
    // cout << "second[10] = 1:" << second[10] << endl;

    // cout << "testing construction of 2-dimensional lists" << endl;
    // List<List<int>> three_d(10, List<int>(10, 1));

    // cout << "length: " << three_d.length() << endl;
    
    // cout << "print contents for each indicie" << endl;
    
    // for(int i = 0; i < three_d.length(); i++) {
    //     cout << "three_d[" << i << "].length(): " << three_d[i].length() << endl;
    // }


    // cout << "All Tests Passed!" << endl;

    cout << "Hello" << endl;

    List<int> first;

    return 0;
}


void print_int(int val) {
    cout << val << endl;
}