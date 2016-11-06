//
//  karatsuba.cpp
//  pa1
//
//  Created by Julia Chen on 10/30/16.
//  Copyright © 2016 Julia Chen. All rights reserved.
//
//  Implementation of Karatsuba multiplication for large numbers.
//      X * Y = 10^n ac + 10^(n/2) (ad + bc) + bd
//          where X = 10a + b, Y = 10c + d, n = length of X or Y
//  1. Recursively compute a*c
//  2. Recursively compute b*d
//  3. Recursively compute (a + b)(c + d)
//  4. Subtract #3 with #1 and #2
//

#include <string>
#include <algorithm>
#include "karatsuba.hpp"

BigInt Karatsuba(BigInt num1, BigInt num2){
    // base case: multiply numbers when both are single digts
    if(num1.get_length() == 1 and num2.get_length() == 1){ 
        return num1.Multiply(num2);
    }
    else{
        // make sure both numbers are the same length
        if(num1.get_length() != num2.get_length()){
            num1.MakeSameLength(num2);
        }
        
        // find the halfway point and split each number into two
        size_t half = num1.get_length() / 2; 
        BigInt a = num1.get_number().substr(half); // upper half of num1
        BigInt b = num1.get_number().substr(0, half); // lower half of numb1
        BigInt c = num2.get_number().substr(half); // upper half of num2
        BigInt d = num2.get_number().substr(0, half); // lower half of num2
        
        BigInt ac = Karatsuba(a, c); // a*c
        BigInt bd = Karatsuba(b, d); // b*d
        BigInt abcd = Karatsuba(a.AddBigInt(b), c.AddBigInt(d)); // (a + b)(c + d)
        
        abcd = abcd.SubtractBigInt(ac); // (a + b)(c + d) - ac
        abcd = abcd.SubtractBigInt(bd); // (a + b)(c + d) - ac - bd = ad + bc
        
        // pad the correct number of zeros based on formula, X*Y = 10^n ac + 10^(n/2)(ad + bc) + bd
        for(int i =0; i < half; i++){
            abcd.insert_num("0");
            ac.insert_num("0");
            ac.insert_num("0");
        }
        
        // compute the final result by adding the results of the three sub problems together
        BigInt final = ac.AddBigInt(bd); 
        final = final.AddBigInt(abcd);
        
        // remove an extraneous zero if there is one
        while(final.get_number()[final.get_length()-1] == '0' and final.get_length() > 1){
            final.remove_num(final.get_length()-1, 1);
        }
        
        return final;
    }
}

