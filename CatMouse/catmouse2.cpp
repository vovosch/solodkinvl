// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"

#include <iostream>
#include <limits>
#include "geom/geom.hpp"


const double EPS = 2 * std::numeric_limits<double>::min();


struct State {

	Rdec2D pos;
	Rdec2D vel;
	Rdec2D (*acs)(const Rdec2D&) = [&](const Rdec2D& delta) { return Rdec2D(0, 0); };

	State(Rdec2D pos = {0, 0}, Rdec2D vel = 0;
		  Rdec2D acs = [&](const Rdec2D& delta) { return Rdec2D(0, 0); }) {

		this -> pos = pos;
		this -> vel = vel;
		this -> acs = acs;
	}

	void updatePos(const double& dt) {pos += vel * dt; }
	void updateVel(const double& dt, const Rdec2D& delta) { vel += (acs(delta) * dt); }
};

Rdec2D noAcseleration(const Rdec2D& delta) { return Rdec2D(0, 0); }

Rdec2D simpleAcseleraiotnCat(const Rdec2D& delta) { return (delta / Norm(delta)) * ((1 / Norm(delta))); }
Rdec2D simpleAcseleraiotnMouse(const Rdec2D& delta) { return -(delta / Norm(delta)) * ((1 / Norm(delta))); }

int model(const double& dt, const double& catStrikeDist,
		State cat, State mouse) {

	Rdec2D prvDeltaR;
	double dist = 0;

	for (double t = 0; t < (double)1e7; t += dt) {

		Rdec2D deltaR = (mouse.pos - mouse.pos);
		//std::cout << "deltaR: " << deltaR << '\n';
		if (mouse.pos.y + EPS > 0) {
			//std::cout << "Mouse escaped under the cupboard\n";
			return 1;
		}
		else if ((t != 0 && t != dt) && (Norm(deltaR) - Norm(prvDeltaR)) > EPS) {
			//std::cout << "Mouse ran away\n";
			return 2;
		}
		else if (Norm(deltaR) - catStrikeDist < EPS) {
			//std::cout << "Cat cougth the mouse\n";
			return 3;
		}

		if (t) {
			mouse.updatePos(dt);
			cat.updatePos(dt);

			mouse.updateVel(dt, deltaR);
			cat.updateVel(dt, deltaR);
		}

		cat.vel = (deltaR / Norm(deltaR)) * Norm(cat.vel);

		prvDeltaR = deltaR;
	}
	return -1;
}

// model(dt, catStrikeDist, stateMouse, stateCat)

int main() {}

// TEST_CASE("diagonal line & no acseleration") {

// 	const double dt = 0.1;
// 	const double catStrikeDist = 1;

// 	CHECK(model(dt, 1,
// 				State{Rdec2D(-3, -3),
// 				Rdec2D(-1, -1),
// 				Rdec2D(1, 1),
// 				Rdec2D(1, 1),
// 				&noAcseleration,
// 				&noAcseleration}) == 1);
// }