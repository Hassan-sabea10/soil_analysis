#ifndef ROCKYSOIL_H
#define ROCKYSOIL_H

#include "Soil.h"

class RockySoil : public Soil {
public:
    RockySoil();
    RockySoil(string name, double dens, double moist,
             double coh, double friction, double slope);

    double calculateBearingCapacity() const override;
    string assessLandslideRisk() const override;
    string getSoilType() const override;
};

#endif
