#ifndef VEC_H
#define VEC_H

#include <emmintrin.h>

extern unsigned long long vec_bitops;

class vec {
  __m128i x;
public:
  operator __m128i() const { return x; }
  vec(__m128i v) { x = v; }
  vec() { }

  inline friend vec operator+(const vec &a,const vec &b) __attribute__((always_inline))
  { 
  #ifdef VEC_COUNTBITOPS
    ++vec_bitops;
  #endif
    return _mm_xor_si128(a.x,b.x);
  }

  inline friend vec operator*(const vec &a,const vec &b) __attribute__((always_inline))
  { 
  #ifdef VEC_COUNTBITOPS
    ++vec_bitops;
  #endif
    return _mm_and_si128(a.x,b.x);
  }

} ;

#endif
