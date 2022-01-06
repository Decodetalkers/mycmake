#include "mp4.h"
#include <iostream>
using namespace video::mp4;
mp4::mp4(int length) : length(length){};
void mp4::get_length() { std::cout << this->length << std::endl; }
