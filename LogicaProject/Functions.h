#pragma once
#include<string>
#include<stack>
#include<iostream>

using namespace std;

void initialize0(int a[], int n);
int postfixInterp(string expression, int truthTable[][100], int n);
void getColumn(int Matrix[][100], int column[], int n, int c);
void Interpretare(int column[], int n);
 