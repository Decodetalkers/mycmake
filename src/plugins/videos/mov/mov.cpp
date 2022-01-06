#include "mov.h"
#include <iostream>
using namespace video::mov;
mov::mov(int length) : length(length) {}
void mov::get_length() { std::cout << "mov" << this->length << std::endl; }
mov::~mov() { std::cout << "mov is " << this->length << "final" << std::endl; }
