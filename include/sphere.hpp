#ifndef SPHERE_H
#define SPHERE_H

#include "vec.hpp"

struct Sphere
{
    Sphere() : center(0, 0, 0), radius(0) {}
    Sphere(const Vec3f& c, float r) : center(c), radius(r) {}

    Vec3f center;
    float radius;
};

bool HitSphere(const Sphere& sph, const Vec3f& orig, const Vec3f& dir, float& t0) {
    Vec3f L = sph.center - orig;
    float tca = L * dir;
    float d2 = L * L - tca * tca;
    if (d2 > sph.radius*sph.radius) return false;
    float thc = sqrtf(sph.radius*sph.radius - d2);
    t0 = tca - thc;
    float t1 = tca + thc;
    if (t0 < 0) t0 = t1;
    if (t0 < 0) return false;
    return true;
}

#endif