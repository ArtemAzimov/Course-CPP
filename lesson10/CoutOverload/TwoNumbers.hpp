#pragma once

class TwoNumbers
{
	int a;
	int b;

public:
	TwoNumbers() : a(0), b(0) {}
	TwoNumbers(const int a, const int b) : a(a), b(b) {}
	~TwoNumbers() = default;

	int getA() const { return a; }
	int getB() const { return b; }
};

// TwoNumbers operator + (const TwoNumbers& lhs, const TwoNumbers& rhs)
// {
// 	TwoNumbers ret(lhs.getA() + rhs.getA(), lhs.getB() + rhs.getB());
// 	return ret;
// }

std::ostream& operator << (std::ostream& out, const TwoNumbers& tn)
{
	out << '[' << tn.getA() << ',' << tn.getB() << ']';
	return out;
}
