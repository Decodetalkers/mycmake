#include <iostream>
#include <memory>
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
  delete e;
  {
    std::vector<std::shared_ptr<videos>> vec_vedio{
        std::make_shared<mp4::mp4>(), std::make_shared<mov::mov>(90)};
    auto fg = std::make_shared<mov::mov>(10000);
    vec_vedio.push_back(fg);
    for (auto i : vec_vedio) {
      i->get_length();
    }
    vec_vedio.pop_back();
  }
  std::cout << "test" << std::endl;
  return 0;
}
