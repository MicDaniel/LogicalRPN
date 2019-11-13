#include"LogicalOperations.h"
#include"Functions.h"


int * andOperation(int operand1[], int operand2[], int n){
	static int p[1025];
	initialize0(p, n);

	for (int i = 1; i <= n; i++) {
		if (operand1[i] == 1 && operand2[i] == 1)
			p[i] = 1;
		else
			p[i] = 0;
	}
	return  p;
}

int * orOperation(int operand1[], int operand2[], int n)
{
	static int p[1025];
	initialize0(p, n);

	for (int i = 1; i <= n; i++)
		if (operand1[i] == 1 || operand2[i] == 1)
			p[i] = 1;
		else
			p[i] = 0;
	return p;
}

int * implicationOperator(int operand1[], int operand2[], int n)
{
	static int p[1025];
	initialize0(p, n);

	for (int i = 1; i <= n; i++)
		if (operand1[i] == 1 && operand2[i] == 0)
			p[i] = 0;
		else
			p[i] = 1;
	return p;
}

int * equalityOperator(int operand1[], int operand2[], int n)
{
	static int p[1025];
	initialize0(p, n);

	for (int i = 1; i <= n; i++)
		if (operand1[i] == operand2[i])
			p[i] = 1;
		else
			p[i] = 0;
	return p;
}

int * negationOperator(int operand[], int n)
{
	static int p[1025];
	initialize0(p, n);

	for (int i = 1; i <= n; i++)
		if (operand[i] == 1)
			p[i] = 0;
		else
			p[i] = 1;
	return p;
}