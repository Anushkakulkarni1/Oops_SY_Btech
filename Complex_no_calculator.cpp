#include <iostream>
using namespace std;

class complex {
    float x, y;
public:
    complex() {
        x = 0;
        y = 0;
    }
    complex(float a, float b) {
        x = a;
        y = b;
    }
    complex operator +(complex);
    friend complex operator *(complex c1, complex c2);
    friend istream& operator >>(istream& in, complex& obj);
    friend ostream& operator <<(ostream& out, const complex& obj);
};

// Operator overloading for addition
complex complex :: operator +(complex c) {
    complex temp;
    temp.x = x + c.x;
    temp.y = y + c.y;
    return temp;
}

// Operator overloading for multiplication
complex operator *(complex c1, complex c2) {
    complex temp;
    temp.x = (c1.x * c2.x) - (c1.y * c2.y);
    temp.y = (c1.x * c2.y) + (c1.y * c2.x);
    return temp;
}

// >> operator is overloaded (Input)
istream& operator >>(istream& in, complex& obj) {
    cout << "Enter real part: ";
    in >> obj.x;
    cout << "Enter imaginary part: ";
    in >> obj.y;
    return in;
}

// << operator is overloaded (Output)
ostream& operator <<(ostream& out, const complex& obj) {
    out << obj.x << " + i" << obj.y;
    return out;
}

int main() {
    complex c1, c2, c3, c4;

    cin >> c1;
    cin >> c2;

    cout << "\nFirst Complex Number: " << c1;
    cout << "\nSecond Complex Number: " << c2;

    c3 = c1 + c2;         // Addition
    cout << "\nSum: " << c3;

    c4 = c1 * c2;         // Multiplication
    cout << "\nMultiplication: " << c4 << endl;

    return 0;
}
