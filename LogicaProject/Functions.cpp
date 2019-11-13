#include"Functions.h"
#include"LogicalOperations.h"


void initialize0(int a[], int n)
{
	for (int i = 0; i <= n; i++)
		a[i] = 0;
}

int postfixInterp(string expression, int truthTable[][100], int n) {
	stack<char> Stack;
	int ct = 1;

	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] >= 'a' && expression[i] <= 'z')
			Stack.push(expression[i]);
		else {
			char ch = expression[i];
			switch (ch)
			{
			case '!': {
				char op = Stack.top();
				int col[1025];
				Stack.pop();
				getColumn(truthTable, col, n, op - 'a' + 1);
				int* p = negationOperator(col, pow(2, n));
				for (int i = 1; i <= pow(2, n); i++) {
					truthTable[i][n + ct] = p[i];
				}
				Stack.push('a' + n + ct - 1);
				ct++;
				break; 
			}
			case '&': {
				char op2 = Stack.top();
				Stack.pop();
				char op1 = Stack.top();
				Stack.pop();
				int col1[1025], col2[1025];
				getColumn(truthTable, col1, n, op1 - 'a' + 1);
				getColumn(truthTable, col2, n, op2 - 'a' + 1);
				int *p = andOperation(col1, col2, pow(2, n));
				for (int i = 1; i <= pow(2, n); i++) {
					truthTable[i][n + ct] = p[i];
				}
				Stack.push('a' + n + ct - 1);
				ct++;
				break;
			}
			case '|': {
				char op2 = Stack.top();
				Stack.pop();
				char op1 = Stack.top();
				Stack.pop();
				int col1[1025], col2[1025];
				getColumn(truthTable, col1, n, op1 - 'a' + 1);
				getColumn(truthTable, col2, n, op2 - 'a' + 1);
				int *p = orOperation(col1, col2, pow(2, n));
				for (int i = 1; i <= pow(2, n); i++) {
					truthTable[i][n + ct] = p[i];
				}
				Stack.push('a'+ n + ct - 1);
				ct++;
				break;
			}
			case '>': {
				char op2 = Stack.top();
				Stack.pop();
				char op1 = Stack.top();
				Stack.pop();
				int col1[1025], col2[1025];
				getColumn(truthTable, col1, n, op1 - 'a' + 1);
				getColumn(truthTable, col2, n, op2 - 'a' + 1);
				int *p = implicationOperator(col1, col2, pow(2, n));
				for (int i = 1; i <= pow(2, n); i++) {
					truthTable[i][n + ct] = p[i];
				}
				Stack.push('a' + n + ct - 1);
				ct++;
				break;
			}
			case '=': {
				char op2 = Stack.top();
				Stack.pop();
				char op1 = Stack.top();
				Stack.pop();
				int col1[1025], col2[1025];
				getColumn(truthTable, col1, n, op1 - 'a' + 1);
				getColumn(truthTable, col2, n, op2 - 'a' + 1);
				int *p = equalityOperator(col1, col2, pow(2, n));
				for (int i = 1; i <= pow(2, n); i++) {
					truthTable[i][n + ct] = p[i];
				}
				Stack.push('a' + n + ct - 1);
				ct++;
				break;
			}
			default:
				break;
			}
		}
	}
	return ct-1;
}

void getColumn(int Matrix[][100], int column[], int n, int c){
	initialize0(column, pow(2,n));

	for (int i = 1; i <= pow(2, n); i++) {
		column[i] = Matrix[i][c];
	}
}

void Interpretare(int column[], int n)
{
	bool contingenta = false;
	bool nesatisfiabila = true;
	bool satisfiabila = false;
	bool tautologie = true;

	for (int i = 1; i <= pow(2, n); i++) {
		if (column[i] == 1) {
			nesatisfiabila = false;
			satisfiabila = true;
			break;
		}
	}

	for (int i = 1; i <= pow(2, n); i++) {
		if (column[i] == 0) {
			tautologie = false;
			if (nesatisfiabila == false) {
				contingenta = true;
				satisfiabila = false;
			}
			break;
		}
	}

	if (tautologie == true)
		std::cout << "\nPropozitia este o tautologie.\n";
	else if (satisfiabila == true)
		std::cout << "\nPropoztia este satisfiabila.\n";
	else if (nesatisfiabila == true)
		std::cout << "\nPropozitia este nesatisfiabila\n";
	else if (contingenta == true)
		std::cout << "\nPropozitia este contingenta\n";
}
