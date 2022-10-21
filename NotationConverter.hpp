//DATA STRUCTURES SEC 2 PROJECT 2
//Zaber Raiyan Choudhury and Tayla Thompson

#ifndef NOTATIONCONVERTER_H
#define NOTATIONCONVERTER_H

#include "NotationConverterInterface.hpp"
#include "deque.hpp"

#include<iostream>
#include<cctype>
using namespace std;

class NotationConverter
{
public:
  virtual std::string postfixToInfix(std::string inStr);
  virtual std::string postfixToPrefix(std::string inStr);

  virtual std::string infixToPostfix(std::string inStr);
  virtual std::string infixToPrefix(std::string inStr);

  virtual std::string prefixToInfix(std::string inStr);
  virtual std::string prefixToPostfix(std::string inStr);

  string  toString();//converts deque to string

  private:
    LinkedDeque newfix;//converted equation
    LinkedDeque operation;//stores operation temporarily
    LinkedDeque variable;//stores the variables temporarily

};
#endif