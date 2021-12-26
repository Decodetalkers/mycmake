#include "video.h"
bool sub(int &a) {
	if(a < 0) {
		return false;
	} else {
		a *= a;
		return true;
	}
}
