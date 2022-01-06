#ifndef MOV_H
#define MOV_H
#include "base_video.h"
namespace video {
namespace mov {
class mov : public video::videos {
public:
  mov(int length = 100);
  ~mov();
  void get_length();

private:
  int length;
};

} // namespace mov
} // namespace video
#endif // !MOV_H
