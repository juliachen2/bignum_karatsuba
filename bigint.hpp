//
//  BigInt.hpp
//  pa1
//
//  Created by Julia Chen on 11/6/16.
//  Copyright © 2016 Julia Chen. All rights reserved.
//

#ifndef bigint_hpp
#define bigint_hpp

#include <string>

class BigInt{
public:
    // empty constructor
    BigInt();
    
    // string constructor
    BigInt(std::string s);
    
    // returns length of number
    size_t get_length();
    
    // returns number as a string
    std::string get_number();

    // reverse the number
    void reverse_num();
    
    // append to number
    void append_num(std::string);
    
    // insert at the beginning of number
    void insert_num(std::string);
    
    // remove from number
    void remove_num(size_t, int);

    // convert a single digit of a number to an integer
    int to_int(int);
    
    // checks if number of digits is an even number
    bool is_even_length();
    
    // if number is not even, pad a zero in front
    void make_even();
    
    // pad small number with zeros to the length of the bigger number
    void MakeSameLength(BigInt &);
    
    // add two numbers together
    BigInt AddBigInt(BigInt &);
    
    // subtract onne number from another
    BigInt SubtractBigInt(BigInt &);
    
    // multiply two numbers
    BigInt Multiply(BigInt &);
    
private:
    std::string number_;
};

#endif /* bigint_hpp */
