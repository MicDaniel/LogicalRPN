#pragma once
#include<iostream>
#include<stack>
#include<conio.h>
#include<string>

using namespace std;

string InfixToRPN(string expression);
int HasHigherPrecedence(char operator1, char operator2);
bool IsOperator(char ch);
bool IsOperand(char ch);
int GetOperatorWeight(char switch_op);
int NumberOfSent(string expression);

