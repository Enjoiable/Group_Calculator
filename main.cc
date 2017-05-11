//Write all code and propose all updates in here! LL
#include<iostream>
#include<cmath>
#include<vector>
#include<cstdlib>
using namespace std;

//<<<<<<< HEAD
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
	return x/y;
}
int mod(int x, int y){
	return x%y;
}
int exponential(int x, int y){
	int a= pow(x, y);
	return a;
}

void die(){
cout<<"invalid input"<<endl;
exit(1);
}

struct variable{
	char name = '@'; //non variables will also be made into variables with name '@'
	int value;
	bool is_var = false;                //I decided we didnt need a class or member functions, this struct will attach a variable name to its value
	variable(int num) {value = num;}  //use this constructor for regular numbers, e.g. when user says "2 * 3"
	variable(char my_name, int num) {name = my_name; value = num; is_var = true;} //use this constructor to create an actual variable, e.g. when user says "LET x = 7"
};

int evaluate(vector<variable> &values, vector<char> &operators)  {//give these vectors to me in reverse order so i can use pop_back. ex (2 * 3 + 5) -> {5,3,2} and {+,*}
	int x = values.back().value;
	if (values.back().is_var) {
		for (size_t i = 0; i < values.size(); i++) 
			if (values.at(i).name == values.back().name) values.at(i).value++; //increment any instance with that same name
	}
	values.pop_back();
	if (!values.size()) return x; //how the recursion ends
	int y = values.back().value;
	if (values.back().is_var) {
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
	return evaluate(values, operators); //recursive function

}


int main() {
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


}//main







