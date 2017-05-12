//Write all code and propose all updates in here! LL
#include<iostream>
#include<vector>
#include<cstdlib>
#include<sstream>
#include<algorithm>
using namespace std;

void die() {
	cout << "INVALID INPUT!" << endl;
	exit(0);
}


int  multiply(int x,int y){
	return x*y;
}
int addition(int x, int y){
	return x+y;
}
int subtract(int x, int y){
	return x-y;
}
int division(int x, int y){
	if (!y) die();
	return x/y;
}
int mod(int x, int y){
	if (!y) die();
	return x%y;
}
int exponential(int x, int y){
	if (y < 0) die();
	if (y == 0) return 1;
	else { 
		int a = 1;
		for (int i = 0; i < y; i++)
			a *= x;
		return a;
	}
}

struct variable{
	char name = '@'; //non variables will also be made into variables with name '@'
	int value;
	bool is_var = false;                //I decided we didnt need a class or member functions, this struct will attach a variable name to its value
	variable(int num) {value = num;}  //use this constructor for regular numbers, e.g. when user says "2 * 3"
	variable(char my_name, int num) {name = my_name; value = num; is_var = true;} //use this constructor to create an actual variable, e.g. when user says "LET x = 7"
};

int evaluate(vector<variable> &values, vector<char> &operators, vector<variable> &database)  {//give these vectors to me in reverse order so i can use pop_back. ex (2 * 3 + 5) -> {5,3,2} and {+,*}
	int x = values.back().value;
	if (values.back().is_var) {
		for (size_t i = 0; i < database.size(); i++) 
			if (database.at(i).name == values.back().name) database.at(i).value++; //increment any instance with that same name
		for (size_t i = 0; i < values.size(); i++)
			if (values.at(i).name == values.back().name) values.at(i).value++;
	}
	values.pop_back();
	if (!values.size()) return x; //how the recursion ends
	int y = values.back().value;
	if (values.back().is_var) {
		for (size_t i = 0; i < database.size(); i++)
			if (database.at(i).name == values.back().name) database.at(i).value++;
		for (size_t i = 0; i < values.size(); i++)
			if (values.at(i).name == values.back().name) values.at(i).value++;
	}
	values.pop_back();
	char op = operators.back();
	operators.pop_back();
	
	int z;
	if (op == '+') z = addition(x, y);
	else if (op == '-') z = subtract(x, y);
	else if (op == '*') z = multiply(x, y);
	else if (op == '/') z = division(x, y);
	else if (op == '^') z = exponential(x, y); //have fun with these, emily
	else if (op == '%') z = mod(x, y);
	else die();

	variable pushv(z);
	values.push_back(pushv); //put a new value back on the stack
	return evaluate(values, operators, database); //recursive function

}


int main() {
	vector<variable> var_database;
	vector<variable> vars;
	vector<char> ops;

	string s, w;
	while (cin) {
		char test_eof = cin.peek();
		if (test_eof == EOF) break;
		getline(cin,s);
		istringstream iss(s);
		iss >> w;
		if (w == "LET") //user is defining a variable
		{
			string var;
			iss >> var;
			if (var.size() != 1) die(); //variable names must be char
			string val;
			iss >> val;
			if (val != "=") die(); //LET x $ 4 wouldnt make sense
			iss >> val;
			int num = stoi(val); //grab the actual value of x
			
			char name = var.at(0);
			if (var_database.size())
			{
				for (auto it = var_database.begin(); it != var_database.end(); it++)
					if (it->name == name) var_database.erase(it); //no duplicate variable
			}
			variable barry(name, num);
			var_database.push_back(barry); //put x into our database
		}
		else if (w == "LOOP") //extra credit
		{
			;
		}
		else {
			//this character by character method isnt working for numbers bigger than 9
			for (char c : s) //parse the string 
			{
				if (isspace(c)) continue; //eat spaces
				if (isdigit(c))  //numbers
				{
					const char* d = &c;
					int x = atoi(d);
					variable t(x);
					vars.push_back(t);
				}
				else if (isalpha(c)) //variables
				{ 
					bool found = false;
					for (variable bob : var_database) 
					{
						if (bob.name == c) //if variable has been defined, then allow it to be used
						{
							vars.push_back(bob); 
							found = true;
						}
					}
					if (!found) die();
				}
				else if (c == '+' || 
						 c == '-' ||
						 c == '*' ||
						 c == '/' ||
						 c == '%' ||
						 c == '^')
				{
					ops.push_back(c);
				}
				else die();
			}
			reverse(vars.begin(), vars.end());
			reverse(ops.begin(), ops.end());
			cout << evaluate(vars, ops, var_database) << endl;
		}
			
	}//while

	
	
	
	/*while(cin){
	cin >> ws;
	char c = cin.peek();
	if (c == EOF) break;
	if (!isdigit(c)){
	
	if( c == 'L')
		else if( c == 'E')
	}	
	
	
	
	
	
	} */


	/*
	vector<variable> vars;
	variable one(6);	
	variable two(5);	
	variable three(3);	
	variable four(2);		
	vars.push_back(one);
	vars.push_back(two);
	vars.push_back(three);
	vars.push_back(four);

	vector<char> ops = {'-','+','*'};
	
	cout << evaluate(vars, ops) << endl; //2 * 3 + 5 - 6

	
	string eqn2 = "4-2*8+1";
	for (int i = eqn2.size()-1; i >=0; i--) { //this for loop parses a string without spaces. Note: runs backwards, on purpose
		if (i%2) ops.push_back(eqn2.at(i)); //1,3,5, etc should be the operators
		else {                              //0,2,4, etc should be the numbers
			const char* pointless = &eqn2.at(i); //atoi must take a "const char*"
			int n = atoi(pointless);   //how to turn "6" into 6, doesnt work for variables
			variable thing(n);
			vars.push_back(thing);
		}
	}
	cout << evaluate(vars, ops) << endl;
	
	variable x('x',3);
	vars.push_back(x);
	vars.push_back(x);  //evaluate x + x - x, where x starts at 3
	vars.push_back(x);
	ops = {'-','+'};
	cout << evaluate(vars, ops) << endl;


	cout << x.value << endl;
	vars.push_back(x);
	vars.push_back(x);  //evaluate x + x - x, where x should be 6 this time, but isnt
	vars.push_back(x);
	ops = {'-','+'};
	cout << evaluate(vars, ops) << endl;
*/

}//main







