//
// Created by Adam Szokalski on 31/10/2018.
//

#ifndef BIGINT_BIGINT_H
#define BIGINT_BIGINT_H

#include <iostream>
#include <string>
#include <vector>

using Multiprecision = std::vector<uint_fast8_t>;

class BigInt{
private:

    //PRIVATE VARIABLES

    Multiprecision num{};                                                   //Vector that stores digits of the integer
    bool isSigned{};                                                        //Defines if the integer is signed or unsigned

    //PRIVATE CONST FUNCTIONS

    int CountDigits(long long n) const;                                     //Counts digits of a long long int

    //PRIVATE CONST CONVERSIONS
    //PRIVATE CONST CONVERSIONS

    Multiprecision ToVector(std::string x) const;                           //string --> vector<uint_fast8_t>

    Multiprecision ToVector(long long x) const;                             //long long int --> vector<uint_fast8_t>

    std::string ToString(Multiprecision x) const;                           //vector<uint_fast8_t> --> string

    long long ToInt(Multiprecision x) const;                                //vector<uint_fast8_t> --> long long int

    //PRIVATE CONST MATHEMATICAL FUNCTIONS

    Multiprecision Add(Multiprecision x, Multiprecision y) const;           //(vector<uint_fast8_t>, vector<uint_fast8_t>) --> vector<uint_fast8_t> + vector<uint_fast8_t>
public:

    //CONSTRUCTORS

    BigInt();                                                               //Default constructor (set 0)

    explicit BigInt(Multiprecision root);                                            //Set from vector<uint_fast8_t> constructor

    explicit BigInt(std::string root);                                               //Set from string constructor

    explicit BigInt(long long root);                                                 //Set from long long int constructor

    //FRIENDSHIP DECLARATIONS

    friend BigInt operator+(const BigInt &x, const BigInt &y);              //Gives operator+ access to private function: Multiprecision Add(Multiprecision x, Multiprecision y)

    //PUBLIC CONST FUNCTIONS

    std::string GetString() const;                                          //Return the value of BigInt [num] as string

    long long GetInt() const;                                               //Return the value of BigInt [num] as long long int

    std::vector<uint_fast8_t> GetVector() const;                            //Return the value of BigInt [num] as vector<uint_fast8_t>

    void Print() const;                                                     //Cout the value of BigInt [num]

    //PUBLIC NON CONST FUNCTIONS

    void Set(Multiprecision root);                                          //Set from vector<uint_fast8_t>

    void Set(std::string root);                                             //Set from string

    void Set(long long root);                                               //Set from long long int

    void Extend(std::string root);                                          //Add digits to the end of num


    //ONE ARGUMENT MATHEMATICAL FUNCTIONS

    void Add(Multiprecision x);                                             //Add a number expressesed in vector<uint_fast8_t> to num

    void Add(std::string x);                                                //Add a number expressesed in string to num

    void Add(long long x);                                                  //Add a number expressesed in long long int to num

    void Add(BigInt x);                                                     //Add a number expressesed in BigInt to num

    //TWO ARGUMENT MATHEMATICAL FUNCTIONS

    void Add(std::string x, std::string y);                                 //Add a sum of numbers expressesed in string to num

    void Add(long long x, long long y);                                     //Add a sum of numbers expressesed in long long int to num

    void Add(BigInt x, BigInt y);                                           //Add a sum of numbers expressesed in vector<uint_fast8_t> to num
};

//OPERATOR OVERLOADS

std::ostream &operator << (std::ostream &os, BigInt const &m);              //Overloads operator<< to cout the value of BigInt.GetString()

std::istream & operator >> (std::istream &in,  BigInt &c);                  //Overloads operator>> to cin the value of BigInt.SetString(in)

BigInt operator+(const BigInt &x, const BigInt &y);                         //Overloads operator+ to add types BigInt and BigInt


#endif //BIGINT_BIGINT_H
