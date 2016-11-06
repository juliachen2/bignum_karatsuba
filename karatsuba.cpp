//
//  karatsuba.cpp
//  pa1
//
//  Created by Julia Chen on 10/30/16.
//  Copyright © 2016 Julia Chen. All rights reserved.
//

#include <string>
#include <algorithm>
#include "karatsuba.hpp"

// implement Karatsuba multiplication algorithm
BigInt Karatsuba(BigInt num1, BigInt num2){
    if(num1.get_length() == 1 and num2.get_length() == 1){
        return num1.Multiply(num2);
    }
    else{
        if(num1.get_length() != num2.get_length()){
            num1.MakeSameLength(num2);
        }
        
        size_t half = num1.get_length() / 2;
        BigInt a = num1.get_number().substr(half);
        BigInt b = num1.get_number().substr(0, half);
        BigInt c = num2.get_number().substr(half);
        BigInt d = num2.get_number().substr(0, half);
        
        BigInt ac = Karatsuba(a, c);
        BigInt bd = Karatsuba(b, d);
        BigInt abcd = Karatsuba(a.AddBigInt(b), c.AddBigInt(d));
        
        abcd = abcd.SubtractBigInt(ac);
        abcd = abcd.SubtractBigInt(bd);
        
        for(int i =0; i < half; i++){
            abcd.insert_num("0");
            ac.insert_num("0");
            ac.insert_num("0");
        }
        
        BigInt final = ac.AddBigInt(bd);
        final = final.AddBigInt(abcd);
        
        if(final.get_number()[final.get_length()-1] == '0'){
            final.remove_num(final.get_length()-1, 1);
        }
        
        return final;
    }
}

