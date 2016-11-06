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

// empty constructor
BigInt::BigInt(){ number_ = "0"; }

// string constructor
BigInt::BigInt(std::string str){ number_ = str; }

// returns length of number
size_t BigInt::get_length() { return this->get_number().length(); }

// returns length of number
std::string BigInt::get_number(){ return this->number_; }

// reverse the number
void BigInt::reverse_num(){ std::reverse(this->number_.begin(), this->number_.end()); }

// append to number
void BigInt::append_num(std::string str){ this->number_.append(str); }

// insert at the beginning of number
void BigInt::insert_num(std::string str){ this->number_.insert(0, str); }

// remove from number
void BigInt::remove_num(size_t pos, int end){ this->number_.erase(pos, end); }

// convert a single digit of a number to an integer
int BigInt::to_int(int index){ return (static_cast<int>(this->get_number()[index]) - 48); }

// checks if number of digits is an even number
bool BigInt::is_even_length(){
    if(this->get_length() % 2 == 0){
        return true;
    }
    return false;
}

// if number is not even, pad a zero in front
void BigInt::make_even(){ this->append_num("0"); }

// pad small number with zeros to the length of the bigger number
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

// add two numbers together
BigInt BigInt::AddBigInt(BigInt &num){
    if(this->get_length() != num.get_length()){
        this->MakeSameLength(num);
    }
    
    int temp;
    BigInt sum;
    for(int i = 0; i < this->get_length(); i++){
        temp = this->to_int(i) + num.to_int(i) + sum.to_int(i);
        sum.number_[i] = '0' + temp % 10; // ones digit of sum
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

// subtract onne number from another
BigInt BigInt::SubtractBigInt(BigInt &num){
    if(this->get_length() != num.get_length()){
        this->MakeSameLength(num);
    }
    
    int temp;
    BigInt diff;
    for(int i = 0; i < this->get_length(); i++){
        temp = this->to_int(i) - num.to_int(i) - diff.to_int(i);
        if(temp >= 0){
            diff.number_[i] = '0' + temp;
            if((i+1) != this->get_length()){
                // append zero to diff if there are digits left to subtract
                diff.append_num("0");
            }
        }
        else if (temp < 0){
            // convert (-) difference to its (+) complement
            diff.number_[i] = '0' + (10 + temp);
            // append diff with a carry (1) to subtract
            diff.append_num("1");
        }
    }
    
    
    return diff;
}

// multiply two single digit numbers
BigInt BigInt::Multiply(BigInt &num){
    int temp;
    BigInt product;
    temp = this->to_int(0) * num.to_int(0);
    product.number_[0] = '0' + temp % 10; // get ones digit of product
    if(temp > 9){ // append product (tens digit) with carry
        product.append_num(std::to_string(temp / 10));
    }
    return product;
}