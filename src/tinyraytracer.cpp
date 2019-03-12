#include <fstream>
#include <vector>
#include "vec.hpp"

void render() {
    constexpr int width = 1024;
    constexpr int height = 768;
    std::vector<Vec3f> framebuffer(width * height);

    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            framebuffer[i+j*width] = Vec3f(j/float(height), i/float(width), 0);
        }
    }

    std::ofstream os;
    os.open("test.ppm");
    os << "P6\n" << width << ' ' << height << "\n255\n";
    for (int i = 0; i < height*width; ++i) {
        for (int j = 0; j < 3; ++j) {
            os << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
        }
    }
    os.close();
}

int main()
{
    render();
}
