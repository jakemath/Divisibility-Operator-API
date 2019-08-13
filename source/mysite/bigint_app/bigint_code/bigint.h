/*
 bigint.h
 Created by Jake Mathai on 2/4/2019.
 Copyright © 2019 Jake Mathai. All rights reserved.
 */

#ifndef bigint_h
#define bigint_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <numeric>
#include <random>
#include <vector>
#include <set>
#include <list>
#include <iterator>

using std::list;
using std::string;
using std::cout;
using std::endl;
using std::vector;

class bigint
{
public:
    bigint();   // Constructors
    bigint (string num);
    bigint (unsigned long long size, bool random);
    list<short>& get_data() { return data; }   // Reference to data
    friend std::ostream& operator << (std::ostream& out, const bigint& b);  // Outstream overload
    void operator ++(); // Increment
    bool operator < (const bigint& b) const;  // Comparison
    bool operator > (const bigint& b) const;
    bool operator == (const bigint& b) const { return data == b.data; }
    void operator = (const bigint& b) { data = b.data; }    // Assignment
    friend void operator + (bigint& sum, bigint& b);    // Addition
    friend void operator - (bigint& diff, bigint& b);   // Subtraction
    friend bigint operator * (const bigint& b, short k); // Optimized multiplication functions
    friend bigint operator * (const bigint& b1, const bigint& b2); // for different contexts
    friend void rule_multiply (bigint& product, const bigint& rule, short k);
    friend void div (bigint& b1, bigint& b2); // Div operator
    
private:
    list<short> data;  // Digits stored in reverse order in list
};

void split(const string& s, char c, vector<string>& p);

#endif /* bigint_h */
