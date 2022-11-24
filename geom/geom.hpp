#include <iosfwd>
#include <cmath>

struct Rdec2D {
	
	double x = 0.0;
	double y = 0.0;

	Rdec2D (double x, double y) {

		this -> x = x;
		this -> y = y;
	}

	double lenght() {

		return std::sqrt(x*x + y*y);
	}
};

// Dec coordinats

Rdec2D& operator+=(Rdec2D& a, const Rdec2D& b);

Rdec2D operator+(Rdec2D a, const Rdec2D& b);

Rdec2D operator-(const Rdec2D& a);

Rdec2D& operator-=(Rdec2D& a, const Rdec2D& b);

Rdec2D operator-(Rdec2D a, const Rdec2D& b);

Rdec2D& operator*=(Rdec2D& a, const double& b);

Rdec2D operator*(const double& b, Rdec2D a);

Rdec2D operator*(Rdec2D a, const double& b);

double operator*(const Rdec2D& a, const Rdec2D& b);

Rdec2D& operator/=(Rdec2D& a, const double& b);

Rdec2D& operator/(Rdec2D a, const double& b);

bool operator==(const Rdec2D& a, const Rdec2D& b);

bool operator!=(const Rdec2D& a, const Rdec2D& b);

double Dot (const Rdec2D& a, const Rdec2D& b);

double Norm(const Rdec2D& a);



struct Rpol2D {

	double r = 0.0;
	double phi = 0.0;

	Rpol2D (double r, double phi) {

		this -> r = r;
		this -> phi = phi;
	}

	double lenght() {

		return r;
	}
};

Rdec2D convertToDec(const Rpol2D& a);

Rpol2D& operator*=(Rpol2D& a, const double& b);

Rpol2D operator*(const double& b, Rpol2D a);

Rpol2D operator*(Rpol2D a, const double& b);

Rpol2D& operator/=(Rpol2D& a, const double& b);

Rpol2D operator/(Rpol2D a, const double& b);

double atan2(double x, double y);

Rpol2D& operator+=(Rpol2D& a, const Rpol2D& b);

Rpol2D operator+(Rpol2D a, const Rpol2D& b);

Rpol2D operator-(const Rpol2D& a);

Rpol2D& operator-=(Rpol2D& a, const Rpol2D& b);

Rpol2D operator-(Rpol2D a, const Rpol2D& b);

bool operator==(const Rpol2D& a, const Rpol2D& b);

bool operator!=(const Rpol2D& a, const Rpol2D& b);

double operator* (const Rpol2D& a, const Rpol2D& b);

double Dot (const Rpol2D& a, const Rpol2D& b);

double Norm (const Rpol2D& a);


// Dec to Pol
Rpol2D convertToPol(const Rdec2D& a);