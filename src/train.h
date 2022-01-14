#ifndef TRAIN_H
#define TRAIN_H

#include <vector>
using namespace std;
namespace Train {
typedef pair<vector<double>, vector<vector<double>>> serdesvm;
typedef vector<pair<int, vector<double>>> serdecsv;
serdesvm serde(serdecsv input);
} // namespace Train
#endif // !TRAIH
