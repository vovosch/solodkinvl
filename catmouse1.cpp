#include <iostream>
#include <limits>
#include "geom/geom.hpp"


const double EPS = 2 * std::numeric_limits<double>::min();


int model(const double& dt, const double& catStrikeDist,
		Rdec2D& rCat, Rdec2D& rMouse, Rdec2D& velCat, Rdec2D& velMouse) {

	Rdec2D prvDeltaR;
	double dist = 0;

	for (double t = 0; t < (double)1e5; t += dt) {

		Rdec2D deltaR = (rMouse - rCat);

		if (Norm(rMouse - Rdec2D(0, 0)) < EPS && Norm(rCat - Rdec2D(0, 0)) < EPS) {
			std::cout << dist << '\n';
			return 0;
		}
		else if (rMouse.y + EPS > 0 ||
			((t != 0 && t != dt) && (Norm(deltaR) - Norm(prvDeltaR)) > EPS)) {
			return 1;
		}
		else if (Norm(deltaR) - catStrikeDist < EPS) {
			return -1;
		}

		rMouse += (velMouse * dt);
		rCat += (velCat * dt);
		dist += Norm(velCat * dt);

		velCat = (deltaR / Norm(deltaR)) * Norm(velCat);

		prvDeltaR = deltaR;
	}
	return 0;
}

Rdec2D findVelCat(const double& catStrikeDist, Rdec2D& rCat, Rdec2D& rMouse, Rdec2D velMouse) {

	Rdec2D lVel = velMouse;
	Rdec2D rVel = Norm(rCat + rMouse) * (velMouse) + velMouse;

	double dt = 0.001;
	int res = -1;

	while (res && Norm(rVel) - Norm(lVel) > EPS) {

		std::cout << lVel << " " << rVel << '\n';

		Rdec2D mVel = (lVel + rVel) / 2.0;

		res = model(dt, catStrikeDist, rCat, rMouse, mVel, velMouse);
		if (res > 0) {
			lVel = mVel;
			std::cout << 1 << " ";
		}
		else {
			rVel = mVel;
			std::cout << -1 << " ";
		}

		dt = std::max(dt / 10, (double)1e-9);
	}

	return lVel;
}


int main() {

	findVelCat(1, Rdec2D(-3, 0), Rdec2D(0, -3), Rdec2D(0, 1));
}