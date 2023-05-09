//-------------------------------------------------------------
// File: Source.cpp
//-------------------------------------------------------------
//Assignment: Project 2
//Programmer: Mya Nanthavongdouangsy
//Instructor: Susmitha Padda
//-------------------------------------------------------------
//Program: This program will ask user for a string and will go 
//         through the stack implementation for the given grammar:
//		   E -> TQ
//		   Q -> +TQ | -TQ | epsilon
//		   T -> FR
//		   R -> *FR | /FR | epsilon
//		   F -> (E) | a
//		   Program will output string given and output the stack 
//		   after each implementation. Program will also check if 
//         the string is valid for the grammat or not. 
//-------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

void currentStack(vector<char>& stack);
bool stackImplement(vector<char>& stack, char item);
//-------------------------------------------------------------
//main()
//-------------------------------------------------------------
int main() {

	vector<char> stack;
	string input = " ";
	char item = ' ';
	bool isValid;
	char ans = ' ';

	do {
		cout << "Input a string to trace: ";
		cin >> input;
		cout << endl;

		system("pause"); //pause screen
		system("cls"); //clear screen

		cout << "Input: " << input << endl << endl;

		stack.push_back('$'); //root node
		stack.push_back('E');

		currentStack(stack);

		for (unsigned i = 0; i < input.size(); i++) { //iterating through string

			item = input[i];  //assining input value to char to send to function
			isValid = stackImplement(stack, item);

			if (!isValid) {
				break;
			}
			if (stack.back() == input[i]) {
				cout << input[i] << " found.\n";
				currentStack(stack);
				cout << "Now popping " << input[i] << " from stack...\n";
				stack.pop_back();
				currentStack(stack);
			}
		}
	



	if (!isValid) {
		cout << "String is not accepted/ Invalid.\n\n";
	}
	else 
		cout << "String is accepted/ Valid.\n\n";


	system("pause"); //pause screen
	system("cls"); //clear screen

	cout << "Would you like to input another string (Y/N)? "; //ask user to rerun program. 
	cin >> ans;
	if (ans == 'n' || ans == 'N') {

		cout << "Closing program now...\n\n";
		break;
	}
	else {
		if (!stack.empty()) {
			while (true) {
				stack.pop_back();
			}
		}
	}

	system("pause"); //pause screen
	system("cls"); //clear screen


}while(ans == 'y' || ans == 'Y');


	return 0;
}
//---- end of main() ------------------------------------------

//-------------------------------------------------------------
//stackImplement()
//-------------------------------------------------------------
bool stackImplement(vector<char>& stack, char item) { //stack implementation


	if (item == 'a') { 

		if (stack.back() == 'E') {

			cout << "Popping E from stack...\n";
			stack.pop_back();
			cout << "Pushing TQ to stack...\n";
			stack.push_back('Q');
			stack.push_back('T');

			currentStack(stack);

		}
		if (stack.back() == 'T') {

			cout << "Popping T from stack...\n";
			stack.pop_back();
			cout << "Pushing FR to stack...\n";
			stack.push_back('R');
			stack.push_back('F');

			currentStack(stack);

		}
		if (stack.back() == 'F') {

			cout << "Popping F from stack...\n";
			stack.pop_back();
			cout << "Pushing a to stack...\n";
			stack.push_back('a');
		}
		return true;
	}
	else if (item == '+') { 
		 
		if (stack.back() != 'Q') {
			while (stack.back() != 'Q') {
				cout << "Popping " << stack.back() << " from stack...\n";
				stack.pop_back();
			}
		}
		if (stack.back() == 'Q') {
			
			cout << "Popping Q from stack...\n";
			stack.pop_back();
			cout << "Pushing +TQ to stack...\n";
			stack.push_back('Q');
			stack.push_back('T');
			stack.push_back('+');
		}
		return 1;
	}
	else if (item == '-') {

		if (stack.back() != 'Q') {
			while (stack.back() != 'Q') {
				cout << "Popping " << stack.back() << " from stack...\n";
				stack.pop_back();
			}
		}
		if (stack.back() == 'Q') {
			
			cout << "Popping Q from stack...\n";
			stack.pop_back();
			cout << "Pushing -TQ to stack...\n";
			stack.push_back('Q');
			stack.push_back('T');
			stack.push_back('-');

		}

		return 1;
	}
	else if (item == '*') {

		if (stack.back() != 'R') {
			while (stack.back() != 'R') {
				cout << "Popping " << stack.back() << " from stack...\n";
				stack.pop_back();
			}
		}
		if (stack.back() == 'R') {

			cout << "Popping R from stack...\n";
			stack.pop_back();
			cout << "Pushing *FR to stack...\n";
			stack.push_back('R');
			stack.push_back('F');
			stack.push_back('*');

		}
		return 1;
	}
	else if (item == '/') {

		if (stack.back() != 'R') {
			while (stack.back() != 'R') {
				cout << "Popping " << stack.back() << " from stack...\n";
				stack.pop_back();
			}
		}
		if (stack.back() == 'R') {

			cout << "Popping R from stack...\n";
			stack.pop_back();
			cout << "Pushing /FR to stack...\n";
			stack.push_back('R');
			stack.push_back('F');
			stack.push_back('/');

		}
		return 1;
	}
	else if (item == '(') {

		if (stack.back() == 'Q' || stack.back() == 'R' || stack.back()== '$') {
			
			while (true) {
				if (stack.back() == '$') {
					cout << "Pushing E to stack...\n";
					stack.push_back('E');

					break;
				}
				else {
					cout << "Popping " << stack.back() << " from stack...\n";
					stack.pop_back();
				}
			}

		}
		if (stack.back() == 'E') {

			cout << "Popping E from stack...\n";
			stack.pop_back();
			cout << "Pushing TQ to stack...\n";
			stack.push_back('Q');
			stack.push_back('T');

			currentStack(stack);
		}
		if (stack.back() == 'T') {

			cout << "Popping T from stack...\n";
			stack.pop_back();
			cout << "Pushing FR to stack...\n";
			stack.push_back('R');
			stack.push_back('F');

			currentStack(stack);

		}
		if (stack.back() == 'F') {

			cout << "Popping F from stack...\n";
			stack.pop_back();
			cout << "Pushing (E) to stack...\n";
			stack.push_back(')');
			stack.push_back('E');
			stack.push_back('(');
		}
		return 1;
	}
	else if (item == ')') {

		if (stack.back() != ')') {
			while (stack.back() != ')') {
				cout << "Popping " << stack.back() << " from stack...\n";
				stack.pop_back();
			}
		}
		if (stack.back() == ')') {
			return 1;
		}
		return 1;
	} 
	else if (item == '$') { 

		if (stack.back() != '$') {
			while (stack.back() != '$') {
				cout << "Popping " << stack.back() << " from stack...\n";
				stack.pop_back();
			}
		}
		if (stack.back() == '$') {
			currentStack(stack);
		}
		return 1;
	}
	else {
		return 0;
	}


}
//---- end of stackImplement() --------------------------------
//-------------------------------------------------------------
//currentStack()
//-------------------------------------------------------------
void currentStack(vector<char>& stack) { //output current stack

	cout << "Current Stack: [ ";
	for (char j : stack) {
		cout << "'" << j << "' ";
	}
	cout << "]\n\n";
}
//---- end of currentStack() ----------------------------------
/*---- OUTPUT -------------------------------------------------
Input a string to trace: (a+a)*a$

Press any key to continue . . .
------ screen clear ----------------
Input: (a+a)*a$

Current Stack: [ '$' 'E' ]

Popping E from stack...
Pushing TQ to stack...
Current Stack: [ '$' 'Q' 'T' ]

Popping T from stack...
Pushing FR to stack...
Current Stack: [ '$' 'Q' 'R' 'F' ]

Popping F from stack...
Pushing (E) to stack...
( found.
Current Stack: [ '$' 'Q' 'R' ')' 'E' '(' ]

Now popping ( from stack...
Current Stack: [ '$' 'Q' 'R' ')' 'E' ]

Popping E from stack...
Pushing TQ to stack...
Current Stack: [ '$' 'Q' 'R' ')' 'Q' 'T' ]

Popping T from stack...
Pushing FR to stack...
Current Stack: [ '$' 'Q' 'R' ')' 'Q' 'R' 'F' ]

Popping F from stack...
Pushing a to stack...
a found.
Current Stack: [ '$' 'Q' 'R' ')' 'Q' 'R' 'a' ]

Now popping a from stack...
Current Stack: [ '$' 'Q' 'R' ')' 'Q' 'R' ]

Popping R from stack...
Popping Q from stack...
Pushing +TQ to stack...
+ found.
Current Stack: [ '$' 'Q' 'R' ')' 'Q' 'T' '+' ]

Now popping + from stack...
Current Stack: [ '$' 'Q' 'R' ')' 'Q' 'T' ]

Popping T from stack...
Pushing FR to stack...
Current Stack: [ '$' 'Q' 'R' ')' 'Q' 'R' 'F' ]

Popping F from stack...
Pushing a to stack...
a found.
Current Stack: [ '$' 'Q' 'R' ')' 'Q' 'R' 'a' ]

Now popping a from stack...
Current Stack: [ '$' 'Q' 'R' ')' 'Q' 'R' ]

Popping R from stack...
Popping Q from stack...
) found.
Current Stack: [ '$' 'Q' 'R' ')' ]

Now popping ) from stack...
Current Stack: [ '$' 'Q' 'R' ]

Popping R from stack...
Pushing *FR to stack...
* found.
Current Stack: [ '$' 'Q' 'R' 'F' '*' ]

Now popping * from stack...
Current Stack: [ '$' 'Q' 'R' 'F' ]

Popping F from stack...
Pushing a to stack...
a found.
Current Stack: [ '$' 'Q' 'R' 'a' ]

Now popping a from stack...
Current Stack: [ '$' 'Q' 'R' ]

Popping R from stack...
Popping Q from stack...
Current Stack: [ '$' ]

String is accepted/ Valid.

Press any key to continue . . .
------ screen clear ----------------
Would you like to input another string (Y/N)? y
Press any key to continue . . .
------ screen clear ----------------
Input a string to trace: (a+e)$

Press any key to continue . . .
------ screen clear ----------------
Input: (a+e)$

Current Stack: [ '$' 'E' ]

Popping E from stack...
Pushing TQ to stack...
Current Stack: [ '$' 'Q' 'T' ]

Popping T from stack...
Pushing FR to stack...
Current Stack: [ '$' 'Q' 'R' 'F' ]

Popping F from stack...
Pushing (E) to stack...
( found.
Current Stack: [ '$' 'Q' 'R' ')' 'E' '(' ]

Now popping ( from stack...
Current Stack: [ '$' 'Q' 'R' ')' 'E' ]

Popping E from stack...
Pushing TQ to stack...
Current Stack: [ '$' 'Q' 'R' ')' 'Q' 'T' ]

Popping T from stack...
Pushing FR to stack...
Current Stack: [ '$' 'Q' 'R' ')' 'Q' 'R' 'F' ]

Popping F from stack...
Pushing a to stack...
a found.
Current Stack: [ '$' 'Q' 'R' ')' 'Q' 'R' 'a' ]

Now popping a from stack...
Current Stack: [ '$' 'Q' 'R' ')' 'Q' 'R' ]

Popping R from stack...
Popping Q from stack...
Pushing +TQ to stack...
+ found.
Current Stack: [ '$' 'Q' 'R' ')' 'Q' 'T' '+' ]

Now popping + from stack...
Current Stack: [ '$' 'Q' 'R' ')' 'Q' 'T' ]

String is not accepted/ Invalid.

Press any key to continue . . .
------ screen clear ----------------
Would you like to input another string (Y/N)? n
Closing program now...


C:\Users\user\Desktop\cs\CS\Languages\C++\Project2_v-CPSC323\x64\Debug\Project2_v-CPSC323.exe (process 14456) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
-------------------------------------------------------------*/