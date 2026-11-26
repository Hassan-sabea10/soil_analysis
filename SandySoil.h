#ifndef SANDYSOIL_H
#define SANDYSOIL_H

#include "Soil.h"

class SandySoil : public Soil {
public:
    SandySoil();
    SandySoil(string name, double dens, double moist,
             double coh, double friction, double slope);

    double calculateBearingCapacity() const override;
    string assessLandslideRisk() const override;
    string getSoilType() const override;
};

#endif
