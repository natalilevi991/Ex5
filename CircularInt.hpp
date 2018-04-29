#include <iostream>
using namespace std;
#include<string>


class CircularInt {

public:
	int min;
	int max;
	int mid;

	CircularInt();
	CircularInt(int a, int b);
	CircularInt(CircularInt& other);
	CircularInt& operator+=(CircularInt& other);
	CircularInt& operator+=(int num);
	CircularInt& operator-=(CircularInt& other);
	CircularInt& operator-=(int num);
	CircularInt& operator++();
	CircularInt operator++(int);
	CircularInt& operator--();
	CircularInt operator--(int);
	CircularInt operator+ (int num);
	CircularInt operator+ (CircularInt& other);
	CircularInt operator-(CircularInt other);
	CircularInt operator-(int num);
	CircularInt operator-();
	CircularInt& operator =(int num);
	CircularInt& operator =(CircularInt& other);
	friend CircularInt& operator- (int num, CircularInt other);
	CircularInt& operator*= (int num);
	friend CircularInt& operator* (CircularInt& other,int num);
	friend CircularInt& operator* (CircularInt& other, CircularInt& obj);
	friend CircularInt& operator* (int num,CircularInt& other);
	CircularInt operator /= (int num);
	CircularInt operator /= (CircularInt& other);
	friend CircularInt operator/ (CircularInt& other, int num);
	friend CircularInt operator/ (CircularInt& other, CircularInt& obj);
	friend CircularInt operator/ (int num , CircularInt& other);
	friend CircularInt operator+(int num,CircularInt& other);
	friend bool operator == (CircularInt& other, int num);
	friend bool operator == (CircularInt& other, CircularInt& obj);
	friend bool operator == (int num,CircularInt& other);
	friend bool operator != (CircularInt& other, int num);
	friend bool operator != (CircularInt& other, CircularInt& obj);
	friend bool operator != (int num, CircularInt& other);
	friend bool operator <= (CircularInt& other, int num);
	friend bool operator <= (CircularInt& other, CircularInt& obj);
	friend bool operator <= (int num, CircularInt& other);
	friend bool operator < (CircularInt& other, int num);
	friend bool operator <(CircularInt& other, CircularInt& obj);
	friend bool operator < (int num, CircularInt& other);
	friend bool operator >= (CircularInt& other, int num);
	friend bool operator >= (CircularInt& other, CircularInt& obj);
	friend bool operator >= (int num, CircularInt& other);
	friend bool operator > (CircularInt& other, int num);
	friend bool operator >(CircularInt& other, CircularInt& obj);
	friend bool operator > (int num, CircularInt& other);
	friend ostream& operator<< (ostream& os, const CircularInt& c);




};































