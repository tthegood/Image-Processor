#include "Image.h"
#include <iostream>

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <in.pgm> <out.pgm>\n";
    return 1;
  }
  Image img;
  if (!img.loadPGM(argv[1])) {
    std::cerr << "Failed to load " << argv[1] << "\n";
    return 2;
  }
  Image edges;
  applySobel(img, edges);
  if (!edges.savePGM(argv[2])) {
    std::cerr << "Failed to save " << argv[2] << "\n";
    return 3;
  }
  std::cout << "Wrote edges to " << argv[2] << "\n";
  return 0;
}
