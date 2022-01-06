#include "mp4.h"
#include <iostream>
using namespace video::mp4;
mp4::mp4(int length, Style video, ll size)
    : length(length), video(video), size(size){};
mp4::mp4(Style video) : length(100), video(video), size(1000){};
void mp4::get_length() { std::cout << this->length << std::endl; }
mp4::~mp4() {
  std::cout << "mp4 final" << std::endl;
  switch (this->video) {
  case Style::Big:
    std::cout << "Big" << std::endl;
  case Style::Small:
    std::cout << "Small" << std::endl;
  default:
    break;
  }
}
void mp4::get_size() { std::cout << this->size << std::endl; }
