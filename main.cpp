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
#include <algorithm>
#include <chrono>
#include "karatsuba.hpp"
#include "bigint.hpp"


int main(int argc, char * argv[]){
    // numbers to be multiplied
    std::string str1 = "9999";
    std::string str2 = "9999";
    
    BigInt num1(str1);
    BigInt num2(str2);
    
    std::cout << "Multiply " << num1.get_number() << " and " << num2.get_number() << std::endl;
    
    // reverse the num strings for easier arithmetic
    num1.reverse_num();
    num2.reverse_num();
    
    // make sure both numbers have the same length
    if(num1.get_length() != num2.get_length()){
        num1.MakeSameLength(num2);
    }
    
    // make sure both numbers have an even length
    if(!num1.is_even_length()){
        num1.make_even();
    }
    if(!num2.is_even_length()){
        num2.make_even();
    }
    

    // start of the clock
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    
    // multiply the two numbers
    BigInt result = Karatsuba(num1, num2);
    
    // end of the clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // flip the string to its original orientation and print result
    result.reverse_num();
    std::cout << "Product = " << result.get_number() << std::endl;
    
    // calculate and display elapsed time of Karatsuba algorithm
    std::chrono::duration<double> elapsed_sec = end - start;
    std::cout << "\nElapsed time: " << elapsed_sec.count() << "s\n";
    
    return 0;
}
