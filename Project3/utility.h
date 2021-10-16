/*
    Project 3 - Hashtable and Heapsort
    James Halladay
    Theory of Algorithms  
    10/10/2021


    Here we create the header file for our utility functions.
*/
#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

#include "hash.h"
#include "heap.h"

using namespace std;   



void utilitytest1();
void utilitytest2();
string scrub(string);
vector<element> readfile(string);
Hashtable read_file(string);
Hashtable read_file(string, double);
