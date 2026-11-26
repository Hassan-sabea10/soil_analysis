#include "ClaySoil.h"

ClaySoil::ClaySoil() : Soil() {}

ClaySoil::ClaySoil(string name, double dens, double moist,
                    double coh, double friction, double slope)
    : Soil(name, dens, moist, coh, friction, slope) {}

double ClaySoil::calculateBearingCapacity() const {
    double factor = 1.0 - (getMoisture() / 150.0);
    if (factor < 0.0) factor = 0.0;
    double capacity = getCohesion() * 5.7 * factor;
    return capacity;
}

string ClaySoil::assessLandslideRisk() const {
    if (getMoisture() > 60.0 && getSlopeAngle() > 15.0)
        return "High";
    if (getMoisture() > 40.0 || getSlopeAngle() > 10.0)
        return "Medium";
    return "Low";
}

string ClaySoil::getSoilType() const {
    return "Clay";
}
