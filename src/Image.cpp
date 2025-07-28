#include "Image.h"
#include <fstream>

Image::Image() = default;

Image::Image(int width, int height)
    : width_(width)
    , height_(height)
    , data_(new uint8_t[width * height]())  // note () for zero-init
{}

bool Image::loadPGM(const std::string &filename) {
    std::ifstream in(filename, std::ios::binary);
    if (!in) return false;

    std::string magic;
    in >> magic;
    if (magic != "P5") return false;

    in >> width_ >> height_ >> maxVal_;
    in.ignore(1);

    data_ = std::make_unique<uint8_t[]>(width_ * height_);
    in.read(reinterpret_cast<char *>(data_.get()), width_ * height_);
    return true;
}

bool Image::savePGM(const std::string &filename) const {
    std::ofstream out(filename, std::ios::binary);
    if (!out) return false;

    out << "P5\n" << width_ << " " << height_ << "\n" << maxVal_ << "\n";
    out.write(reinterpret_cast<const char *>(data_.get()), width_ * height_);
    return true;
}
