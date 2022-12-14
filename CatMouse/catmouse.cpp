#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <limits>
#include "geom/geom.hpp"


const double EPS = 2 * std::numeric_limits<double>::min();

Rdec2D noAcseleration(const Rdec2D& delta) { return Rdec2D(0, 0); }

Rdec2D simpleAcseleraiotnCat(const Rdec2D& delta) { return (delta / Norm(delta)) * ((1 / Norm(delta))); }
Rdec2D simpleAcseleraiotnMouse(const Rdec2D& delta) { return -(delta / Norm(delta)) * ((1 / Norm(delta))); }

Rdec2D& updateVel(Rdec2D& vel, Rdec2D& acs) {

	vel += acs;
	return vel;
}

int model(const double& dt, const double& catStrikeDist,
		Rdec2D& rCat, Rdec2D& rMouse, Rdec2D& velCat,
		Rdec2D& velMouse, Rdec2D (*acsCat)(const Rdec2D&),
		Rdec2D (*acsMouse)(const Rdec2D&)) {

	Rdec2D prvDeltaR;
	double dist = 0;

	//std::cout << rCat << " " << rMouse << '\n';
	//std::cout << velCat << " " << velMouse << '\n';

	for (double t = 0; t < (double)1e7; t += dt) {


		std::cout << "t " << t << '\n'; 
		std::cout << "coords " << rCat << " " << rMouse << '\n';
		std::cout << "vel " << velCat << " " << velMouse << '\n';

		Rdec2D deltaR = (rMouse - rCat);
		velCat = (deltaR / Norm(deltaR)) * Norm(velCat);
		//std::cout << "deltaR: " << deltaR << '\n';
		if (rMouse.y + EPS > 0) {
			std::cout << "Mouse escaped under the cupboard\n";
			return 1;
		}
		else if ((t != 0 && t != dt) && (Norm(deltaR) - Norm(prvDeltaR)) > EPS) {
			std::cout << "Mouse ran away\n";
			return 2;
		}
		else if (Norm(deltaR) - catStrikeDist < EPS) {
			std::cout << "Cat cougth the mouse\n";
			return 3;
		}

		rMouse += (velMouse * dt);
		rCat += (velCat * dt);

		velMouse = updateVel(velMouse, dt * acsMouse(deltaR));
		velCat = updateVel(velCat, dt * acsCat(deltaR));

		//std::cout << rCat << " " << rMouse << '\n';
		//std::cout << velCat << " " << velMouse << '\n';

		prvDeltaR = deltaR;
	}
	return -1;
}

// model(dt, catStrikeDist, rCat, rMouse, velCat, velMouse, &acsCat, &acsMouse)


TEST_CASE("straigth line & no acseleration") {

	const double dt = 0.1;
	const double catStrikeDist = 1;

	CHECK(model(dt, 1,
				Rdec2D(0, -5),
				Rdec2D(0, -2),
				Rdec2D(0, 2),
				Rdec2D(0, 2),
				&noAcseleration,
				&noAcseleration) == 1);
	CHECK(model(dt, 1,
				Rdec2D(0, -2),
			    Rdec2D(0, -5),
			    Rdec2D(0, -1),
			    Rdec2D(0, -2),
			    &noAcseleration,
			    &noAcseleration) == 2);
	CHECK(model(dt, 1,
				Rdec2D(0, -4),
				Rdec2D(0, -3),
				Rdec2D(0, 1),
				Rdec2D(0, 1),
				&noAcseleration,
				&noAcseleration) == 3);
}

// model(dt, catStrikeDist, rCat, rMouse, velCat, velMouse, &acsCat, &acsMouse)

TEST_CASE("diagonal line & no acseleration") {

	const double dt = 0.1;
	const double catStrikeDist = 1;

	CHECK(model(dt, 1,
				Rdec2D(-3, -3),
				Rdec2D(-1, -1),
				Rdec2D(1, 1),
				Rdec2D(1, 1),
				&noAcseleration,
				&noAcseleration) == 1);
	CHECK(model(dt, 1,
				Rdec2D(-1, -1),
				Rdec2D(-3, -3),
				Rdec2D(-1, -1),
				Rdec2D(-1, -1),
				&noAcseleration,
				&noAcseleration) == 2);
	CHECK(model(dt, 1,
				Rdec2D(-6, -6),
				Rdec2D(-8, -8),
				Rdec2D(1, 1),
				Rdec2D(2, 2),
				&noAcseleration,
				&noAcseleration) == 3);
}

// model(dt, catStrikeDist, rCat, rMouse, velCat, velMouse, &acsCat, &acsMouse)

TEST_CASE("straigth line & acseleration") {

	const double dt = 0.1;
	const double catStrikeDist = 1;

	CHECK(model(dt, 1,
				Rdec2D(0, -5),
				Rdec2D(0, -2),
				Rdec2D(0, 2),
				Rdec2D(0, 2),
				&simpleAcseleraiotnCat,
				&simpleAcseleraiotnMouse) == 1);
	CHECK(model(dt, 1,
				Rdec2D(0, -2),
			    Rdec2D(0, -5),
			    Rdec2D(0, -1),
			    Rdec2D(0, -2),
			    &simpleAcseleraiotnCat,
			    &simpleAcseleraiotnMouse) == 2);
	CHECK(model(dt, 1,
				Rdec2D(0, -5),
				Rdec2D(0, -3),
				Rdec2D(0, 1),
				Rdec2D(0, 1),
				&simpleAcseleraiotnCat,
				&noAcseleration) == 3);
}