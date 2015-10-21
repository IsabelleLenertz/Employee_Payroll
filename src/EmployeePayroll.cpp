//============================================================================
// Name        : EmployeePayroll.cpp
// Author      : Isabelle Delmas
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Utilities.hpp"
using namespace std;

int main() {

	string userAnswer = "";

	while (userAnswer != "han solo")
	{
		userAnswer = Utilities::inputString("Who shot first? ", 0, 20);
		userAnswer = Utilities::makeLowerCase(userAnswer);
	}

	cout << "There is nothing more in here, you should look in the v2 branch." << endl;
	return 0;
}
