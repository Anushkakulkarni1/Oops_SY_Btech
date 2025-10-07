#include <iostream>
using namespace std;
class Exception {
public:
const char* what() const {
return "Error: Division by zero is not allowed!";
}
};
class Calculator {
public:
double divide(double a, double b) {
if (b == 0) {
throw Exception(); // Throw custom exception
}
return a / b;
}
};
int main() {
Calculator calc;
double num, den;
cout << "Enter numerator: ";
cin >> num;
cout << "Enter denominator: ";
cin >> den;
try {
double result = calc.divide(num, den);
cout << "Result = " << result << endl;
}
catch (Exception& e) {
cout << e.what() << endl;
}
return 0;
}
