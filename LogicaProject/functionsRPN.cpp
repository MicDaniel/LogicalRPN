#include"functionsRPN.h"

string InfixToRPN(string expression) {
	stack<char> operatori;
	string postfix = "";

	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == ' ')
			continue;
		else if (IsOperator(expression[i])) {
			while (!operatori.empty() && HasHigherPrecedence(operatori.top(), expression[i])
				&& operatori.top() != '(')
			{
				postfix += operatori.top();
				operatori.pop();
			}
			operatori.push(expression[i]);
		}
		else if (IsOperand(expression[i])) {
			postfix += expression[i];
		}
		else if (expression[i] == '(') {
			operatori.push(expression[i]);
		}
		else if (expression[i] == ')') {
			while (!operatori.empty() && operatori.top() != '(') {
				postfix += operatori.top();
				operatori.pop();
			}
			operatori.pop();
		}
	}
	while (!operatori.empty()) {
		postfix += operatori.top();
		operatori.pop();
	}
	return postfix;
}

int GetOperatorWeight(char ch) {
	int weight = -1;

	switch (ch)
	{
	case '!':
		weight = 5;
		break;
	case '&':
		weight = 4;
		break;
	case '|':
		weight = 3;
		break;
	case '>':
		weight = 2;
		break;
	case '=':
		weight = 1;
		break;
	default:
		break;
	}

	return weight;
}

int NumberOfSent(string expression)
{
	int frecventaLitere['z' + 1];

	for (int i = 0; i <= 'z'; i++) {
		frecventaLitere[i] = 0;
	}

	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] >= 'a' && expression[i] <= 'z')
			frecventaLitere[expression[i]]++;
	}

	int counter = 0;
	for (int i = 0; i <= 'z'; i++) {
		if (frecventaLitere[i])
			counter++;
	}
	return counter;
}

int HasHigherPrecedence(char operator1, char operator2) {
	int op1Weight = GetOperatorWeight(operator1);
	int op2Weight = GetOperatorWeight(operator2);

	if (op1Weight > op2Weight)
		return true;
	else
		return false;
}

bool IsOperator(char c) {
	if (c == '&' || c == '|' || c == '>' || c == '=' || c == '!') {
		return true;
	}
	return false;
}

bool IsOperand(char c) {
	if (c >= 'a' && c <= 'z') {
		return true;
	}
	return false;
}