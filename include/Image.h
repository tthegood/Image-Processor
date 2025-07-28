#ifndef IMAGE_H
#define IMAGE_H

#include <cstdint>
#include <memory>
#include <string>

class Image {
public:
    Image();
    Image(int width, int height);
    bool loadPGM(const std::string &filename);
    bool savePGM(const std::string &filename) const;

    inline uint8_t &at(int x, int y) { return data_[y * width_ + x]; }
    inline const uint8_t &at(int x, int y) const { return data_[y * width_ + x]; }

    int width() const { return width_; }
    int height() const { return height_; }

private:
    int width_ = 0;
    int height_ = 0;
    int maxVal_ = 255;
    std::unique_ptr<uint8_t[]> data_;
};

void applySobel(const Image &src, Image &dst);
#endif // IMAGE_H
