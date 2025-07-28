#include "Image.h"
#include <cmath>

void applySobel(const Image &src, Image &dst) {
    int w = src.width();
    int h = src.height();
    dst = Image(w, h);

    static const int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    static const int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int y = 1; y < h - 1; ++y) {
        for (int x = 1; x < w - 1; ++x) {
            int sumX = 0, sumY = 0;
            for (int ky = -1; ky <= 1; ++ky) {
                for (int kx = -1; kx <= 1; ++kx) {
                    int pixel = src.at(x + kx, y + ky);
                    sumX += gx[ky + 1][kx + 1] * pixel;
                    sumY += gy[ky + 1][kx + 1] * pixel;
                }
            }
            int mag = std::min(255, static_cast<int>(std::sqrt(sumX*sumX + sumY*sumY)));
            dst.at(x, y) = static_cast<uint8_t>(mag);
        }
    }
}
