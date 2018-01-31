#pragma once

namespace ar {
	template<class T>
	void copy(T* src,T* dst,size_t len) {
		if (src == nullptr || dst == nullptr) {
			return;
		}
		T* s = src;
		T* d = dst;
		while (len--) {
			*d++ = *s++;
		}
	}
}