#include "train.h"
#include <csv.h>
#include <iostream>
#include <memory>
#include <sound.h>
#include <svm.h>
#include <types>
#include <vector>
#include <video>
#define Malloc(type, n) (type *)malloc((n) * sizeof(type))

// test
constexpr svm_parameter Initialize_svm_parameter() {
  svm_parameter svmpara; // svm的相关参数
  svmpara.svm_type = C_SVC;
  svmpara.kernel_type = LINEAR;
  svmpara.degree = 3;
  svmpara.gamma = 0;
  svmpara.coef0 = 0;
  svmpara.nu = 0.5;
  svmpara.cache_size = 1; //缓存块大小
  svmpara.C = 1;
  svmpara.eps = 1e-3;
  svmpara.p = 0.1;
  svmpara.shrinking = 1;
  svmpara.probability = 0;
  svmpara.nr_weight = 0;
  svmpara.weight_label = NULL;
  svmpara.weight = NULL;
  return svmpara;
}
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
  std::cout << "message" << std::endl;
  auto messages = Train::serde(output);
  std::cout << "message4" << std::endl;
  svm_problem prob;
  prob.l = output.size();
  prob.y = Malloc(double, prob.l);
  prob.x = Malloc(struct svm_node *, prob.l);
  // svm_problem svmpro = [&messages, &output] {
  //   svm_problem temp;
  //   size_t len = output.size();
  //   temp.l = len;
  //   temp.y = messages.first;
  //	st d::cout << "message4" << std::endl;
  // temp.x = [&len, &messages] {
  //   svm_node **node = new svm_node *[len];
  //   std::cout << len << std::endl;
  //   for (size_t i = 0; i < len; i++) {
  //     node[i] = new svm_node[8];
  //     for (size_t j = 0; j < 7; j++) {
  //       svm_node node_ij;
  //       node_ij.index = j + 1;
  //       node_ij.value = messages.second[i][j];
  //       node[i][j] = node_ij;
  //     }
  //     std::cout << i << std::endl;
  //     svm_node node_last;
  //     node_last.index = -1;
  //     node_last.value = 0;
  //     node[i][7] = node_last;
  //     std::cout << i << std::endl;
  //   }
  //   std::cout << "message6" << std::endl;
  //   return node;
  // }();
  //  return temp;
  //}();
  // std::cout << "message" << std::endl;
  svm_parameter svmpara = Initialize_svm_parameter();
  // std::cout << "message" << std::endl;
  // svm_model *svm_model = svm_train(&svmpro, &svmpara);
  // std::cout << "message" << std::endl;
  // delete svm_model;
  std::cout << "message11" << std::endl;
  return 0;
}
