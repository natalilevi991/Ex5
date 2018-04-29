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

int CircularInt::range(int min, int max, int mid)
{
		if (mid > max) {
			mid = mid % max;
		}
		if (mid < min) {
			mid = mid + max;
		}
		return mid;
	}




CircularInt & CircularInt::operator+=(CircularInt & other)
{
	this->mid = this->mid + other.mid;
	this->mid = range(this->min, this->max, this->mid);
	return *this;
}

CircularInt & CircularInt::operator+=(int num)
{
	this->mid = this->mid + num;
	this->mid = range(this->min, this->max, this->mid);
	return *this;
}

CircularInt & CircularInt::operator-=(CircularInt & other)
{
	this->mid = this->mid - other.mid;
	this->mid = range(this->min, this->max, this->mid);
	return *this;
}

CircularInt & CircularInt::operator-=(int num)
{
	this->mid = this->mid - num;
	this->mid = range(this->min, this->max, this->mid);
	return *this;
}

CircularInt & CircularInt::operator++()
{
	this->mid = this->mid + 1;
	this->mid = range(this->min, this->max, this->mid);
	return *this;

}

CircularInt CircularInt::operator++(int)
{
	CircularInt temp(*this);
	this->mid = this->mid + 1;
	this->mid = range(this->min, this->max, this->mid);
	return temp;
}

CircularInt & CircularInt::operator--()
{
	this->mid = this->mid - 1;
	this->mid = range(this->min, this->max, this->mid);
	return *this;
}

CircularInt CircularInt::operator--(int)
{
	CircularInt temp(*this);
	this->mid = this->mid - 1;
	this->mid = range(this->min, this->max, this->mid);
	return temp;
}


CircularInt CircularInt::operator+(int num)
{
	CircularInt temp(*this);
	temp.mid += num;
	temp.mid = range(this->min, this->max, temp.mid);
	return temp;
}

CircularInt CircularInt::operator+(CircularInt & other)
{
	CircularInt temp(other);
	temp.mid += other.mid;
	temp.mid = range(this->min, this->max, temp.mid);
	return temp;
}

CircularInt CircularInt::operator-(CircularInt other)
{
	CircularInt temp(*this);
	this->mid = this->mid - other.mid;
	this->mid = range(this->min, this->max, this->mid);
	return temp;
}

CircularInt CircularInt::operator-(int num)
{
	CircularInt temp(*this);
	this->mid = this->mid - num;
	this->mid = range(this->min, this->max, this->mid);
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
	this->mid = (mid*num);
	this->mid = range(this->min, this->max, this->mid);
	return *this;
}

CircularInt & CircularInt::operator*=(CircularInt & other)
{
	this->mid = (mid*other.mid);
	this->mid = range(this->min, this->max, this->mid);
	return *this;
}

CircularInt CircularInt::operator/=(int num)
{
	this->mid = (this->mid / num);
	this->mid = range(this->min, this->max, this->mid);
	return *this;
}

CircularInt CircularInt::operator/=(CircularInt & other)
{
	this->mid = (this->mid / other.mid);
	this->mid = range(this->min, this->max, this->mid);
	return *this;
}

CircularInt & CircularInt::operator=(int num)
{
	this->mid = range(this->min, this->max, num);
	return *this;
}

CircularInt & CircularInt::operator=(CircularInt & other)
{
	if (this->max != other.max || this->min != other.min)
		throw "The ranges is different";
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


