#ifndef MP4_H
#define MP4_H

#include "base_video.h"
namespace video::mp4 {
enum class Style { Big, Small };
class mp4 : public video::videos {
public:
  using ll = long long;
  mp4(int length = 0, Style video = Style::Big, ll size = 1000);
  mp4(Style video);
  ~mp4();
  void get_length();
  void get_size();

private:
  int length;
  ll size;
  Style video;
};

} // namespace video::mp4

#endif // !MP4_H
