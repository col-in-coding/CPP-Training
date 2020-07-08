#include <assert.h>
#include <cmath>

#define PI 3.1415962

class VehicleModel {
public:
    virtual void Move(double v, double theta) = 0;
};

class ParticleModel : public VehicleModel {
public:
    void Move(double v, double phi) override {
        theta += phi;
        x += v * cos(theta);
        y += v * sin(theta);
    }

    double x;
    double y;
    double theta;
};

class BicycleModel : public ParticleModel {
public:
    void Move(double v, double phi) override {
        theta += v / L * tan(phi);
        x += v * cos(theta);
        y += v * sin(theta);
    }
    
    double L{2};
};


int main() {
  // Test function overriding
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);
  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
}