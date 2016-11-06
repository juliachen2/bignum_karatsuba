//
//  BigInt.hpp
//  pa1
//
//  Created by Julia Chen on 11/6/16.
//  Copyright © 2016 Julia Chen. All rights reserved.
//
//  Stores and manipulates large intergers.
//

#ifndef bigint_hpp
#define bigint_hpp

#include <string>

class BigInt{
public:
    // Empty constructor
    BigInt();
    
    // String constructor
    BigInt(std::string s);
    
    // Returns length of number
    size_t get_length();
    
    // Returns number as a string
    std::string get_number();

    // Reverses the digits of a number
    void reverse_num();
    
    // Appends a string digit to number
    void append_num(std::string);
    
    // Inserts a string digit to the "beginning" of number
    void insert_num(std::string);
    
    // Removes a digit/s from a number
    void remove_num(size_t, int);

    // Converts a single digit (char) of a number to an integer
    int to_int(int);
    
    // Checks if the number of digits is even
    bool is_even_length();
    
    // Makes two numbers equal in length by padding zeros
    void MakeSameLength(BigInt &);
    
    // Add two numbers together
    BigInt AddBigInt(BigInt &);
    
    // Subtract one number from another
    BigInt SubtractBigInt(BigInt &);
    
    // Multiply two numbers
    BigInt Multiply(BigInt &);
    
private:
    std::string number_;
};

#endif /* bigint_hpp */
