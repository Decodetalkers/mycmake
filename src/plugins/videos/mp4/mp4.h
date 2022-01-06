#ifndef MP4_H
#define MP4_H

namespace video {
namespace mp4 {
class mp4 {
public:
  mp4(int length = 0);
  // virtual ~mp4();
  void get_length();

private:
  int length;
};
} // namespace mp4
} // namespace video

#endif // !MP4_H
