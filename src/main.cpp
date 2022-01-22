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

  auto messages = Train::serde(output);

  int sizeOfProblem = output.size();
  int elements = 7;
  svm_problem prob;
  svm_node *x_space;
  prob.l = sizeOfProblem;
  prob.y = Malloc(double, prob.l);
  prob.x = Malloc(struct svm_node *, prob.l);
  x_space = Malloc(struct svm_node, (elements + 1) * prob.l);
  for (size_t i = 0; i < prob.l; i++) {
    prob.y[i] = messages.first[i];
  }
  int j = 0;
  for (size_t i = 0; i < prob.l; i++) {
    prob.x[i] = &x_space[j];
    for (int k = 0; k < messages.second[i].size(); ++k, ++j) {
      x_space[j].index = k + 1;                 // index of value
      x_space[j].value = messages.second[i][k]; // value
      cout << "x_space[" << j << "].index = " << x_space[j].index << endl;
      cout << "x_space[" << j << "].value = " << x_space[j].value << endl;
    }
    x_space[j].index = -1; // state the end of data vector
    x_space[j].value = 0;
    cout << "x_space[" << j << "].index = " << x_space[j].index << endl;
    cout << "x_space[" << j << "].value = " << x_space[j].value << endl;
    j++;
  }
  for (int i = 0; i < prob.l; ++i) {
    cout << "line " << i << endl;
    cout << prob.y[i] << "---";
    for (int k = 0; k < elements; ++k) {
      int index = (prob.x[i][k].index);
      double value = (prob.x[i][k].value);
      cout << index << ":" << value << " ";
    }
    cout << endl;
  }
  svm_parameter svmpara = Initialize_svm_parameter();
  // std::cout << "message" << std::endl;
  svm_model *svm_model = svm_train(&prob, &svmpara);
  // std::cout << "message" << std::endl;
  svm_node *testX1 = new svm_node[8];
  testX1[0].index = 1;
  testX1[0].value = 50.8449;
  testX1[1].index = 2;
  testX1[1].value = -19.0803;
  testX1[2].index = 3;
  testX1[2].value = 138.693;
  testX1[3].index = 4;
  testX1[3].value = 139.965;
  testX1[4].index = 5;
  testX1[4].value = 109.852;
  testX1[5].index = 6;
  testX1[5].value = 65.1941;
  testX1[6].index = 7;
  testX1[6].value = -7.0376;
  testX1[7].index = -1;
  int testY1 = svm_predict(svm_model, testX1);
  std::cout << "Predict is" << testY1 << std::endl;
  svm_node *testX2 = new svm_node[8];
  testX2[0].index = 1;
  testX2[0].value = 97.9966;
  testX2[1].index = 2;
  testX2[1].value = 30.4499;
  testX2[2].index = 3;
  testX2[2].value = 17.1093;
  testX2[3].index = 4;
  testX2[3].value = 9.06223;
  testX2[4].index = 5;
  testX2[4].value = 3.90266;
  testX2[5].index = 6;
  testX2[5].value = -0.163966;
  testX2[6].index = 7;
  testX2[6].value = 3.47124;
  testX2[7].index = -1;
  int testY2 = svm_predict(svm_model, testX2);
  std::cout << "Predict is" << testY2 << std::endl;
  delete[] testX1;
  delete[] testX2;
  delete svm_model;

  std::cout << "message11" << std::endl;
  return 0;
}
