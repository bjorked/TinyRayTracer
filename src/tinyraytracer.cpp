#include <cmath>
#include <fstream>
#include <limits>
#include <vector>
#include "sphere.hpp"
#include "vec.hpp"

Vec3f cast_ray(const Vec3f& orig, const Vec3f& dir, const Sphere& sph) {
    float sphere_dist = std::numeric_limits<float>::max();
    if (HitSphere(sph, orig, dir, sphere_dist)) {
        return {0.2, 0.7, 0.8};
    }
    return {0.4, 0.4, 0.3};
}

void render(const Sphere& sph) {
    constexpr int width = 1024;
    constexpr int height = 768;
    constexpr float fov = M_PI / 3;

    std::vector<Vec3f> framebuffer(width * height);

    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            float x = (2*(i + 0.5)/float(width) - 1) * tan(fov/2.)*width/float(height);
            float y = -(2*(j + 0.5)/float(height) - 1) * tan(fov/2.);
            Vec3f dir = Vec3f(x, y, -1).normalize();
            framebuffer[i+j*width] = cast_ray(Vec3f(0, 0, 0), dir, sph);
        }
    }

    std::ofstream os;
    os.open("test.ppm");
    os << "P6\n" << width << ' ' << height << "\n255\n";
    for (int i = 0; i < height*width; ++i) {
        for (int j = 0; j < 3; ++j) {
            os << char(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
        }
    }
    os.close();
}

int main()
{
    Sphere sphere(Vec3f(-3, 0, -16), 2);
    render(sphere);
}
