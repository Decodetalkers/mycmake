#include "train.h"
#include <iostream>
namespace Train {
serdesvm serde(serdecsv input) {
  int len = input.size();
  vector<double> first{};

  vector<vector<double>> second{};
  for (auto apair : input) {
    first.push_back(apair.first);
    second.push_back(apair.second);
  }
  return make_pair(first, second);
};

} // namespace Train
