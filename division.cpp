//
// Created by Adam Szokalski on 01/11/2018.
//

#include "BigInt.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  MAIN FUNCTIONS

//Small division
Multiprecision BigInt::Divide(Multiprecision n, int d) const {
    if (d >= base) { return {'e', 'r', 'r', 'o', 'r'}; }
    int carry = 0;

    for (int i = (int)n.size() - 1; i >= 0; --i) {
        long long cur = n[i] + carry * 1ll * base;
        n[i] = uint_fast8_t(cur / d);
        carry = int (cur % d);
    }

    return n;
}

//Arbitrary precision division
BigInt BigInt::Divide(BigInt n, BigInt d) const {
    long m = d.GetVector().size() - 1;                         //magnitude
    int a = d.GetVector()[0];                                  //quick divisor
    BigInt q = n / a;                                          //quotient (result)
    BigInt r = d + 1;                                          //remainder (mod)

    while(r.Abs() >= d){
        r = n - (q * d);
        BigInt qn = q + (r / a);
        q = (q + qn) / 2;
    }
    r = n - (q * d);

    if(r.IsSigned()){
        q = q - 1;
        r = r + d;
    }

    return q;
}

BigInt BigInt::Divide(int x) const {
    return BigInt(Divide(GetVector(), x));
}

BigInt BigInt::Divide(BigInt x) const {
    BigInt z(GetVector());
    z.SetSign(IsSigned());
    return Divide(z, x);
}