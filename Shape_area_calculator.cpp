#include <iostream>
using namespace std;
class shape{
public:
	int b;
	int h;
	void getdata();
	virtual void display()=0;
};
void shape::getdata(){
	cout<<"\nEnter height: ";
	cin>>h;
	cout<<"Enter base: ";
	cin>>b;
}
class triangle:public shape{
	void display(){
		cout<<"Area of triangle: "<<0.5*b*h;
	}
};
class rectangle:public shape{
	void display(){
		cout<<"Area of rectangle: "<<b*h;
	}
};
int main() {
	shape *ptr;
	triangle t;
	ptr=&t;
	ptr->getdata();
	ptr->display();
	rectangle r;
	ptr=&r;
	ptr->getdata();
	ptr->display();
}
