#ifndef MOV_H
#define MOV_H
#include "base_video.h"
namespace video::mov {
class mov : public video::videos {
public:
  mov(int length = 100);
  ~mov();
  void get_length();

private:
  int length;
};

} // namespace video::mov
#endif // !MOV_H
