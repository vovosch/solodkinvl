#include <iostream>
#include <limits>
#include <iomanip>
#include "geom/geom.hpp"


const double EPS = 2 * std::numeric_limits<double>::min();


struct State {
	
	Rdec2D pos;
	Rdec2D vel;
	Rdec2D (*acs)(const Rdec2D&);

	State(Rdec2D pos, Rdec2D vel, Rdec2D (*acs)(const Rdec2D&)) {

		this -> pos = pos;
		this -> vel = vel;
		this -> acs = acs;
	}

	void updatePos(const double& dt) { pos += vel * dt; }
	void updateVel(const double& dt, const Rdec2D& delta) {
		vel += acs(delta) * dt;
	}
};

Rdec2D noAcseleration(const Rdec2D& delta) { return Rdec2D(0, 0); }

Rdec2D simpleAcseleraiotnCat(const Rdec2D& delta) { return (delta / Norm(delta)) * ((1 / Norm(delta))); }
Rdec2D simpleAcseleraiotnMouse(const Rdec2D& delta) { return -(delta / Norm(delta)) * ((1 / Norm(delta))); }

Rdec2D mouseAcs(const Rdec2D& delta) { return 0.1 * (delta) / (Norm(delta) + 1); }

void model(const double& dt, const double& catStrikeDist,
		State cat, State mouse) {

	Rdec2D prvDeltaR;
	double dist = 0;

	//std::cout << rCat << " " << rMouse << '\n';
	//std::cout << velCat << " " << velMouse << '\n';

	for (double t = 0; t < (double)1e7; t += dt) {

		std::cout << t << ','; 
		std::cout << cat.pos.x << ',' << cat.pos.y << ',';
		std::cout << mouse.pos.x << ',' << mouse.pos.y << ',';
		std::cout << cat.vel.x << ',' << cat.vel.y << ',';
		std::cout << mouse.vel.x << ',' << mouse.vel.y << ',';

		Rdec2D deltaR = (mouse.pos - cat.pos);
		std::cout << Norm(deltaR) << '\n';
		cat.vel = (deltaR / Norm(deltaR)) * Norm(cat.vel);
		//std::cout << "deltaR: " << deltaR << '\n';
		if (mouse.pos.y + EPS > 0) {
			//std::cout << "Mouse escaped under the cupboard\n";
			return;
		}
		else if ((t != 0 && t != dt) && (Norm(deltaR) - Norm(prvDeltaR)) > EPS) {
			//std::cout << "Mouse ran away\n";
			return;
		}
		else if (Norm(deltaR) - catStrikeDist < EPS) {
			//std::cout << "Cat cougth the mouse\n";
			return;
		}

		mouse.updatePos(dt);
		cat.updatePos(dt);

		mouse.updateVel(dt, deltaR);
		cat.updateVel(dt, deltaR);

		//std::cout << rCat << " " << rMouse << '\n';
		//std::cout << velCat << " " << velMouse << '\n';

		prvDeltaR = deltaR;
	}
	return;
}

int main() {

	std::freopen("example.csv", "w", stdout);
	std::cout << "t,rCat.x,rCat.y,rMouse.x,rMouse.y,velCat.x,velCat.y,velMouse.x,velMouse.y,delta" << '\n';
	std::cout << std::fixed << std::setprecision(12);
	model(0.1, 1,
		  State(Rdec2D(-3, -3), Rdec2D(1, 1), &noAcseleration),
		  State(Rdec2D(-1, -1), Rdec2D(0.5, 0.5), &mouseAcs));
}