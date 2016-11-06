 //
 //  main.cpp
 //  pa1
 //
 //  Created by Julia Chen on 10/30/16.
 //  Copyright © 2016 Julia Chen. All rights reserved.
 //
 //
 //  This program implements recursive integer multiplication and
 //  Karatsuba's multiplication algorithm.
 //
 //  The numbers are stored into string variables so that it can
 //  support large number multiplication. Calculations are done on
 //  reverse strings for more intuitive digit by digit arithmetic.
 //

#include <iostream>
#include <string>
#include <chrono>
#include "karatsuba.hpp"
#include "bigint.hpp"


int main(int argc, char * argv[]){
    std::string str1, str2;

    // query user for two numbers to multiply
    std::cout << "~~Karatsuba Multiplication Program~~" << std::endl;
    std::cout << "Enter the first number: ";
    std::cin >> str1;
    std::cout << "Enter the second number: ";
    std::cin >> str2;
    
    BigInt num1(str1);
    BigInt num2(str2);
        
    // reverse the num strings for easier digit by digit arithmetic
    num1.reverse_num();
    num2.reverse_num();
    
    // make sure both numbers have the same length
    if(num1.get_length() != num2.get_length()){
        num1.MakeSameLength(num2);
    }
    
    // make sure both numbers have an even length
    if(!num1.is_even_length()){
        num1.append_num("0");
    }
    if(!num2.is_even_length()){
        num2.append_num("0");
    }

    // start of the clock
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    
    // multiply the two numbers using Karatsuba algorithm
    BigInt result = Karatsuba(num1, num2);
    
    // end of the clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // flip the string to its original orientation and print result
    result.reverse_num();
    std::cout << "\nProduct = " << result.get_number() << std::endl;
    
    // calculate and display elapsed time of Karatsuba algorithm
    std::chrono::duration<double> elapsed_sec = end - start;
    std::cout << "Elapsed time: " << elapsed_sec.count() << "s\n";
    
    return 0;
}
