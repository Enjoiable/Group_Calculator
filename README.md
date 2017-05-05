


# Group_Calculator
As a group we will create a calculator that will take in inputs and increament the variables each time around.

SECTION A.. Readme ffor reference.

Individual assignments{}

The project will be to create a program that can do algebra, with one special
twist: every time you use a variable, it will update its value afterwards. So
if x equals 3, then x+x would return 7, since x was 3 the first time, and then
4 the next time, and would be 5 afterwards.

You will read one line of input at a time. The input will be in one of three
forms:
1) Create a variable. All variables are single letters, like x or y. They can
hold values only between 0 and 255.
Valid Example: LET x = 7
Error: LET x = 9 (you can't redeclare a variable - x is already declared to be 7.)
Error: LET bob = 27 (bob is 3 letters)
Error: LET y = 300 (300 is out of range)
Error: z = 2 (forgot the LET)

On an error, print "BAD INPUT" and quit. You should probably make a die()
function.

2) Input an algebraic equation. The code will output the result (or BAD INPUT
if the user types in something bad) of the algebra. Note THERE IS NO ORDER OF
OPERATIONS, just parse the equation from left to right.
So if x = 2 and y = 10, x + y * 2 will output 24, not 22.

x will then be equal to 3, and y will be equal to 11, since every time you
access the value of a variable, it will postincrement the value after returning
it. So if the next line is x + y * 2 again, it will output 28.

You must support the following algebraic operations:
+ (addition)
- (subtraction)
* (multiplication)
/ (division)
^ (exponentiation)
% (modulus)

Precodition: Every operand and operator will have a space before it, you don't
have to check for this.

3) If the line contains "quit" (or "QUIT") or is just an end of file, then the  program terminates.


SECTION B) Individual Task(before debug)
 
Jose Moreno~  In charge of disgning the main() so that it reads in the input correctly from the user and branches it to the following fuction that EMily will write to compute the value of the two variables passed in, also side note if the user enters something like x * y * 2 make sure it doesnt't leave out the * 2 to  the resulting expression.

Hayley Andrews~  In charge of going through and figuring out where all of the different errors can occur inside of the code and designing a kill fuction that will end the program when they occur.

Christian Coggan~ In chrage of creating a class with the data struture of your choice that will be able to take and store the data of chars in its structure. using get and set methods to control the variables so that can be called from a function.(Name it cacluator or what ever you like).

Emily Kroker~ In charge of designing the funtions that can be called to within the class that  Coggan is writing all of the above operations so the member variables can be easily accessed through the main. Don't worry about checking for errors Hayley will handle that from inside of your code by designing some test files.

If you have any_questions please email me at zoovery@gmail.com

***** One final note...

All of thje code must either be written, or pasted to the main.cc file of gethub so we all get credit! We need to make sure theres a clear history of who all worked on the project! 
