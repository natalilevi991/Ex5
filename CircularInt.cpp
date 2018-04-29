#include "CircularInt.hpp"

//constructor
CircularInt::CircularInt()
{
	this->min = 1;
	this->max = 12;
	this->mid = 1;
}

CircularInt::CircularInt(int a, int b)
{
	this->min = a;
	this->max = b;
	this->mid = min;
}
//copy constructor
CircularInt::CircularInt(CircularInt & other)
{
	this->min = other.min;
	this->max = other.max;
	this->mid = other.mid;
}

CircularInt & CircularInt::operator+=(const CircularInt & other)
{
	this->mid = this->mid + other.mid;
	if (this->mid > this->max) {
		this->mid = this->mid % this->max;
	}
	return *this;
}

CircularInt & CircularInt::operator+=(int num)
{
	this->mid = this->mid + num;
	if (this->mid > this->max) {
		this->mid = this->mid % this->max;
	}
	return *this;

}

CircularInt & CircularInt::operator-=(const CircularInt & other)
{
	this->mid = this->mid - other.mid;
	if (this->mid < this->min) {
		this->mid = this->mid + this->max;
	}
	return *this;
}

CircularInt & CircularInt::operator-=(int num)
{
	this->mid = this->mid - num;
	if (this->mid < this->min) {
		this->mid = this->mid + this->max;
	}
	return *this;
}

CircularInt & CircularInt::operator++()
{
	this->mid = this->mid + 1;
	if (this->mid > this->max) {
		this->mid = this->mid % this->max;
	}
	return *this;

}

CircularInt CircularInt::operator++(int)
{
	CircularInt temp(*this);
	this->mid = this->mid + 1;
	if (this->mid > this->max) {
		this->mid = this->mid % this->max;
	}
	return temp;
}

CircularInt & CircularInt::operator--()
{
	this->mid = this->mid - 1;
	if (this->mid < this->min) {
		this->mid = this->mid + this->max;
	}
	return *this;
}

CircularInt CircularInt::operator--(int)
{
	CircularInt temp(*this);
	this->mid = this->mid - 1;
	if (this->mid < this->min) {
		this->mid = this->mid + this->max;
	}
	return temp;
}


CircularInt CircularInt::operator+(int num)
{
	CircularInt temp(*this);
	temp.mid += num;
	if (this->mid > this->max) {
		this->mid = this->mid % this->max;
	}
	return temp;
}

CircularInt CircularInt::operator+(CircularInt & other)
{
	CircularInt temp(other);
	temp.mid += other.mid;
	if (temp.mid > this->max) {
		temp.mid = temp.mid % this->max;
	}
	return temp;
}

CircularInt CircularInt::operator-(CircularInt other)
{
	CircularInt temp(*this);
	this->mid = this->mid - other.mid;
	if (this->mid < this->min) {
		this->mid = this->mid + this->max;
	}
	return temp;
}

CircularInt CircularInt::operator-(int num)
{
	CircularInt temp(*this);
	this->mid = this->mid - num;
	if (this->mid < this->min) {
		this->mid = this->mid + this->max;
	}
	return temp;
}

CircularInt CircularInt::operator-()
{
	CircularInt temp(*this);
	temp.mid = max - this->mid;
	return temp;
}

CircularInt & CircularInt::operator*=(int num)
{
	this->mid = (mid*num) % max;
	return *this;
}

CircularInt & CircularInt::operator*=(const CircularInt & other)
{
	this->mid = (mid*other.mid) % max;
	return *this;
}

CircularInt CircularInt::operator/=(int num)
{
	this->mid = (this->mid / num)%max;
	return *this;
}

CircularInt CircularInt::operator/=(const CircularInt & other)
{
	this->mid = (this->mid / other.mid)%max;
	return *this;
}

CircularInt & CircularInt::operator=(int num)
{
	this->mid = num;
	if (this->mid > max) {
		this->mid = this->mid % max;
	}
	if (this->mid < min) {
		this->mid = this->mid + max;
	}
	return(*this);
}

CircularInt & CircularInt::operator=(CircularInt & other)
{
	if (this->max != other.max || this->min != other.min) {
		throw("the range is different");
	}
	else {
		this->max = other.max;
		this->min = other.min;
		this->mid = other.mid;
	}
	return *this;
}

CircularInt & operator-(int num, CircularInt & other)
{
	CircularInt temp(other);
	temp.mid = num;
	temp -= other.mid;
//	int ans = temp.mid;
	return temp;
}

CircularInt & operator*(CircularInt & other, int num)
{
	return other * num;
}
	

CircularInt & operator*(CircularInt & other, CircularInt & obj)
{
	CircularInt temp(other);
	temp.mid = (temp.mid * obj.mid) % temp.max;
	return temp;
	// TODO: insert return statement here
}

CircularInt & operator*(int num, CircularInt & other)
{
	CircularInt temp(other);
	temp.mid = (temp.mid * num) % temp.max;
	return temp;

}

CircularInt operator/(CircularInt & other, int num)
{
	CircularInt temp(other);
	temp.mid = (temp.mid / num) % temp.max;
	return temp;
}

CircularInt operator/(CircularInt & other, CircularInt & obj)
{
	CircularInt temp(other);
	temp.mid = (temp.mid / obj.mid) % temp.max;
	return temp;
}

CircularInt operator/(int num, CircularInt & other)
{
	CircularInt temp(other);
	temp.mid = (temp.mid / num) % temp.max;
	return temp;
}

CircularInt operator+(int num,CircularInt& other)
{
	CircularInt temp(other);
	temp.mid += num;
	if (temp.mid > temp.max) {
		temp.mid = temp.mid % temp.max;
	}
	return temp;
}

bool operator==(CircularInt & other, int num)
{
	if (other.mid == num) {
		return true;
	}
	return false;
}

bool operator==(CircularInt & other, CircularInt & obj)
{
	if (other.mid == obj.mid) {
		return true;
	}
	return false;
}

bool operator==(int num, CircularInt & other)
{
	if (num == other.mid) {
		return true;
	}
	return false;
}

bool operator!=(CircularInt & other, int num)
{
	if (other.mid != num) {
		return true;
	}
	return false;
}

bool operator!=(CircularInt & other, CircularInt & obj)
{
	if (other.mid != obj.mid) {
		return true;
	}
	return false;
}

bool operator!=(int num, CircularInt & other)
{
	if (num != other.mid) {
		return true;
	}
	return false;
}

bool operator<=(CircularInt & other, int num)
{
	if (other.mid <= num) {
		return true;
	}
	return false;
}

bool operator<=(CircularInt & other, CircularInt & obj)
{
	if (other.mid <= obj.mid) {
		return true;
	}
	return false;
}

bool operator<=(int num, CircularInt & other)
{
	if (num <= other) {
		return true;
	}
	return false;
}

bool operator<(CircularInt & other, int num)
{
	if (other.mid < num) {
		return true;
	}
	return false;
}

bool operator<(CircularInt & other, CircularInt & obj)
{
	if (other.mid < obj.mid) {
		return true;
	}
	return false;
}

bool operator<(int num, CircularInt & other)
{
	if (num < other) {
		return true;
	}
	return false;
}

bool operator>=(CircularInt & other, int num)
{
	if (other.mid >= num) {
		return true;
	}
	return false;
}

bool operator>=(CircularInt & other, CircularInt & obj)
{
	if (other.mid >= obj.mid) {
		return true;
	}
	return false;
}

bool operator>=(int num, CircularInt & other)
{
	if (num >= other) {
		return true;
	}
	return false;
}

bool operator>(CircularInt & other, int num)
{
	if (other.mid > num) {
		return true;
	}
	return false;
}

bool operator>(CircularInt & other, CircularInt & obj)
{
	if (other.min > obj.mid) {
		return true;
	}
	return false;
}

bool operator>(int num, CircularInt & other)
{
	if (num > other) {
		return true;
	}
	return false;
}

ostream& operator<< (ostream& os, const CircularInt& c)
{
		os << c.mid;
		return os;
}


