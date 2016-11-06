//
//  BigInt.cpp
//  pa1
//
//  Created by Julia Chen on 11/6/16.
//  Copyright © 2016 Julia Chen. All rights reserved.
//

#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include "bigint.hpp"

// Empty constructor that initializes number to 0
BigInt::BigInt(){ number_ = "0"; }

// String constructor that initialize number to a given string
BigInt::BigInt(std::string str){ number_ = str; }

// Returns length of the object
size_t BigInt::get_length() { return this->get_number().length(); }

// Returns the number object as a string
std::string BigInt::get_number(){ return this->number_; }

// Reverses the number object
void BigInt::reverse_num(){ std::reverse(this->number_.begin(), this->number_.end()); }

// Appends a string digit to the number object
void BigInt::append_num(std::string str){ this->number_.append(str); }

// Inserts a string digit to the "beginning" of the number object
void BigInt::insert_num(std::string str){ this->number_.insert(0, str); }

// Removes a string digit/s from the number object
void BigInt::remove_num(size_t pos, int end){ this->number_.erase(pos, end); }

// Converts a single digit of a number object to an integer
int BigInt::to_int(int index){ return (static_cast<int>(this->get_number()[index]) - 48); }

// Returns true if a number object has an even length
bool BigInt::is_even_length(){
    if(this->get_length() % 2 == 0){
        return true;
    }
    return false;
}

// Compares the two numbers to find which number is the smallest in length.
// Then it pads the smaller number with zeros
void BigInt::MakeSameLength(BigInt &num){
    size_t len;
    if(this->get_length() > num.get_length()){
        len = this->get_length() - num.get_length();
        for(int i = 0; i < len; i++){
            num.append_num("0");
        }
        
    }
    else if(this->get_length() < num.get_length()){
        len = num.get_length() - this->get_length();
        for(int i = 0; i < len; i++){
            this->append_num("0");
        }
    }
}

// Adds two number objects together
BigInt BigInt::AddBigInt(BigInt &num){
    // make both numbers the same length
    if(this->get_length() != num.get_length()){
        this->MakeSameLength(num);
    }
    
    int temp;
    BigInt sum;
    for(int i = 0; i < this->get_length(); i++){ 
        temp = this->to_int(i) + num.to_int(i) + sum.to_int(i); // sum of single digit addition
        sum.number_[i] = '0' + temp % 10; // set the ones digit of sum
        if(temp < 10 && (i+1) != this->get_length()){
            // append zero to sum if there are digits left to add
            sum.append_num("0");
        }
        else if(temp > 9){
            // append sum with a carry (1) to add
            sum.append_num("1");
        }
    }
    return sum; 
}

// Subtracts one number from another
BigInt BigInt::SubtractBigInt(BigInt &num){
    // make both numbers the same length
    if(this->get_length() != num.get_length()){
        this->MakeSameLength(num);
    }
    
    int temp;
    BigInt diff;
    for(int i = 0; i < this->get_length(); i++){
        // difference of single digit subtraction
        temp = this->to_int(i) - num.to_int(i) - diff.to_int(i); 
        if(temp >= 0){ // difference is positive
            diff.number_[i] = '0' + temp; // set the ones digit of diff
            if((i+1) != this->get_length()){
                // append zero to diff if there are digits left to subtract
                diff.append_num("0");
            }
        }
        else if (temp < 0){ // difference is negative
            diff.number_[i] = '0' + (10 + temp); // convert negative number to its complement (+)
            diff.append_num("1"); // append diff with a carry (1) to subtract
        }
    }
    return diff;
}

// Multiplies two single digit numbers (due to nature of Karatsuba implementation)
BigInt BigInt::Multiply(BigInt &num){
    int temp;
    BigInt product;
    temp = this->to_int(0) * num.to_int(0); // product of single digit multplication
    product.number_[0] = '0' + temp % 10; // set ones digit of product
    if(temp > 9){ // append product (tens digit) with carry
        product.append_num(std::to_string(temp / 10));
    }
    return product;
}