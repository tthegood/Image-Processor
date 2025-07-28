#include "Image.h"
#include <cassert>

void applySobel(const Image &src, Image &dst);

int main() {
    const int W = 5, H = 5;
    Image src(W, H);
    for (int y = 0; y < H; ++y)
        for (int x = 0; x < W; ++x)
            src.at(x, y) = (x > 1 && x < 3 && y > 1 && y < 3) ? 255 : 0;

    Image dst;
    applySobel(src, dst);

    // Edges around the white square
    assert(dst.at(1,2) > 0);
    assert(dst.at(2,1) > 0);
    assert(dst.at(3,2) > 0);
    assert(dst.at(2,3) > 0);

    // Corners remain dark
    assert(dst.at(0,0) == 0);
    assert(dst.at(4,4) == 0);

    return 0;
}
