#include"functionsRPN.h"
#include"Functions.h"


void TruthTable(int A[][100], int n);
void  PrintTruthTable(int A[][100], int n);

int main() {
	string expression;
	int A[1025][100];
	cout << "Enter infix expression \n";
	getline(cin, expression);
	string postfix = InfixToRPN(expression);
	cout << "Output = " << postfix << endl;
	int n = NumberOfSent(postfix);

	TruthTable(A, n);
	cout <<"Sunt "<< n <<" propozitii simple."<< '\n';
	PrintTruthTable(A, n);

	int ct = postfixInterp(postfix, A, n);
	
	for (int i = 1; i <= pow(2, n); i++) {
		for (int j = 1; j <= n + ct; j++) {
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
	
	int finalAnswer[1025];
	getColumn(A, finalAnswer, n, n + ct);
	for (int i = 1; i <= pow(2, n); i++)
		std::cout << finalAnswer[i] << ' ';
	Interpretare(finalAnswer, n);

	_getch();
	return 0;
}



void TruthTable(int A[][100], int n) {
	bool switchTF = true;//face schimbarea truth - false
	int switcher = (int)pow(2, n);
	for (int j = 1; j <= n; j++) {
		switchTF = true;
		switcher /= 2;
		for (int i = 1; i <= (int)pow(2, n); i++) {
			if (switchTF == true)
				A[i][j] = 1;
			else
				A[i][j] = 0;
			if (i % (switcher) == 0)
				if (switchTF == true)
					switchTF = false;
				else
					switchTF = true;
		}
	}
}

void PrintTruthTable(int A[][100], int n)
{
	for (int i = 1; i <= (int)pow(2, n); i++) {
		for (int j = 1; j <= n; j++) {
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
}



