#ifndef SPHERE_H
#define SPHERE_H

#include "vec.hpp"

struct Material
{
    Material() : albedo(1,0,0), diffuse_color(), specular_exponent() {}
    Material(const Vec3f& alb, const Vec3f& color, float exp)
        : albedo(alb), diffuse_color(color), specular_exponent(exp) {}

    Vec3f albedo;
    Vec3f diffuse_color;
    float specular_exponent;
};

struct Light 
{
    Light(const Vec3f& pos, float inten) : position(pos), intensity(inten) {}

    Vec3f position;
    float intensity;
};

Vec3f reflect(const Vec3f& I, const Vec3f& N) {
    return I - N*2.f*(I*N);
}

struct Sphere
{
    Sphere(const Vec3f& c, float r, const Material& m) : center(c), radius(r), material(m) {}

    Vec3f center;
    float radius;
    Material material;
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
