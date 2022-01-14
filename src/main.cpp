#include <csv.h>
#include <iostream>
#include <memory>
#include <sound.h>
#include <svm.h>
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
  // for each is the same as range
  std::for_each(vecx.begin(), vecx.end(), [](float &elem) { elem += 1; });
  std::for_each(vecx.begin(), vecx.end(), [](float &elem) {
    std::cout << "After add " << elem << std::endl;
  });
  for (float &elem : vecx) {
    elem += 10;
  }
  for (float &elem : vecx) {
    std::cout << "After add " << elem << std::endl;
  }
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
  auto y = mp4::mp4(mp4::Style::Big);
  y.get_size();
  auto metacsv = libcsv::CSV_SERDER({0, 1, 2, 3, 4, 5, 6}, 14);
  std::vector<std::pair<int, std::vector<double>>> output;
  try {
    output = metacsv.get_messages("csvs/persion1.csv");
  } catch (char const *e) {
    std::cout << e << std::endl;
  } catch (std::invalid_argument e) {
    std::cout << "invalid_argument" << std::endl;
  }
  for (auto apair : output) {
    std::cout << apair.first << ",";
    for (auto name : apair.second) {
      std::cout << name << ",";
    }
    std::cout << std::endl;
  }
  return 0;
}
