#ifndef MP4_H
#define MP4_H

#include "base_video.h"
namespace video::mp4 {
class mp4 : public video::videos {
public:
  mp4(int length = 0);
  ~mp4();
  void get_length();

private:
  int length;
};
} // namespace video::mp4

#endif // !MP4_H
