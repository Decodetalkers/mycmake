#include <iostream>
#include <sound.h>
#include <types>
#include <vector>
#include <video>
// test
using namespace video;
int main(int argc, char *argv[]) {
  std::cout << "Hello " << std::endl;
  int a = 10;
  add(a);
  std::cout << a << std::endl;
  if (sub(a)) {
    std::cout << a << std::endl;
  }
  std::vector<float> vecx{1.11, 2, 3, 4, 5};
  mapp<float>(vecx);
  sound();
  auto *e = new mp4::mp4();
  e->get_length();
  std::vector<videos *> vec_vedio{new mp4::mp4(), new mov::mov(),
                                  new mov::mov(90)};
  vec_vedio.push_back(e);
  for (auto i : vec_vedio) {
    i->get_length();
  }
  return 0;
}
