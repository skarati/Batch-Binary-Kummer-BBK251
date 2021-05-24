#ifndef FIELDELEMENT_H
#define FIELDELEMENT_H

#include "vec.h"

class fieldelement {
  vec x[251];
  vec pad[1];
public:
  fieldelement(__m128i v) { int i; for (i = 1;i < 251;++i) x[i] = _mm_set_epi32(0,0,0,0); x[0] = v; }
  fieldelement() { }
  void set_0(void);
  void set_1(void);
  fieldelement square(void);
  fieldelement bbk251(const vec [251]);
  fieldelement times_d(void);
  fieldelement times_base(void);
  fieldelement inverse(void);
  void putsquare(fieldelement &) const;
  void times_d(fieldelement &) const;
  void times_base(fieldelement &) const;
  void times_d_plus(fieldelement &,const fieldelement &) const;
  void multiply(fieldelement &,const fieldelement &) const;
  void add(fieldelement &,const fieldelement &) const;
  friend void conditionalswap(fieldelement &,fieldelement &,vec);
  friend void conditionalswap2(fieldelement &,fieldelement &,fieldelement &,fieldelement &,fieldelement &,fieldelement &,vec);
  friend fieldelement operator+(const fieldelement &,const fieldelement &);
  friend fieldelement operator*(const fieldelement &,const fieldelement &);
  friend void transpose(fieldelement &,const unsigned char [128][32]);
  friend void transpose(unsigned char (&)[128][32],const fieldelement);
} ;

#endif
