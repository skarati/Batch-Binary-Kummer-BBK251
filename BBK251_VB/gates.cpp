#include "fieldelement.h"

unsigned long long vec_bitops = 0;

#include "251.cpp"

static void mult251(vec *h,const vec *f,const vec *g)
{
  vec r[NUMREGS];
  int i;
  for (i = 0;i < sizeof(arith)/sizeof(*arith);++i) {
    vec x;
    vec y;
    vec z;
    if (arith[i].x == 'f') x = f[arith[i].xn];
    else if (arith[i].x == 'g') x = g[arith[i].xn];
    else if (arith[i].x == 'r') x = r[arith[i].xn];
    else abort();
    if (arith[i].op == '$') {
      z = x;
    } else {
      if (arith[i].y == 'f') y = f[arith[i].yn];
      else if (arith[i].y == 'g') y = g[arith[i].yn];
      else if (arith[i].y == 'r') y = r[arith[i].yn];
      else abort();
      if (arith[i].op == '+') z = x + y; else z = x * y;
    }
    if (arith[i].z == 'h') h[arith[i].zn] = z;
    else if (arith[i].z == 'r') r[arith[i].zn] = z;
    else abort();
  }
}

void fieldelement::set_0(void)
{
  int i;
  for (i = 0;i < 251;++i) x[i] = _mm_set_epi32(0,0,0,0);
}

void fieldelement::set_1(void)
{
  int i;
  for (i = 0;i < 251;++i) x[i] = _mm_set_epi32(0,0,0,0);
  x[0] = _mm_set_epi32(0xffffffff,0xffffffff,0xffffffff,0xffffffff);
}

// overlap ok
void fieldelement::add (fieldelement &result,const fieldelement &b) const
{
  int i;
  for (i = 0;i < 251;++i) result.x[i] = (*this).x[i] + b.x[i];
}

fieldelement operator+(const fieldelement &a,const fieldelement &b)
{
  fieldelement result;
  a.add(result,b);
  return result;
}

void conditionalswap(fieldelement &a,fieldelement &b,vec control)
{
  int i;
  for (i = 0;i < 251;++i) {
    vec a0 = a.x[i];
    vec b0 = b.x[i];
    vec d0 = a0 + b0;
    d0 = d0 * control;
    a0 = a0 + d0;
    b0 = b0 + d0;
    a.x[i] = a0;
    b.x[i] = b0;
  }
}

// overlap ok
void fieldelement::multiply(fieldelement &result,const fieldelement &b) const
{
  vec h[501];
  mult251(h,x,b.x);
  int i;
  for (i = 244;i < 250;++i) {
    vec a = h[i + 251];
    h[i + 7] = h[i + 7] + a;
    h[i + 4] = h[i + 4] + a;
    h[i + 2] = h[i + 2] + a;
    h[i + 0] = h[i + 0] + a;
  }
  vec a0 = h[251];
  result.x[0] = h[0] + a0;
  vec a1 = h[252];
  result.x[1] = h[1] + a1;
  vec a2 = h[253]; vec a2a0 = a2 + a0;
  result.x[2] = h[2] + a2a0;
  vec a3 = h[254]; vec a3a1 = a3 + a1;
  result.x[3] = h[3] + a3a1;
  vec a4 = h[255];
  result.x[4] = h[4] + a4 + a2a0;
  vec a5 = h[256];
  result.x[5] = h[5] + a5 + a3a1;
  vec a6 = h[257]; vec a6a4 = a6 + a4;
  result.x[6] = h[6] + a6a4 + a2;
  vec a7 = h[258]; vec a7a5 = a7 + a5;
  for (i = 7;i < 239;i += 8) {
    vec r0 = h[i] + a7a5 + a3 + a0;
    result.x[i] = r0;
    a0 = h[i + 252];
    vec r1 = h[i + 1] + a0 + a6a4 + a1;
    result.x[i + 1] = r1;
    a1 = h[i + 253];
    vec r2 = h[i + 2] + a1 + a7a5 + a2;
    result.x[i + 2] = r2;
    a2 = h[i + 254]; a2a0 = a2 + a0;
    vec r3 = h[i + 3] + a2a0 + a6 + a3;
    result.x[i + 3] = r3;
    a3 = h[i + 255]; a3a1 = a3 + a1;
    vec r4 = h[i + 4] + a3a1 + a7 + a4;
    result.x[i + 4] = r4;
    a4 = h[i + 256];
    vec r5 = h[i + 5] + a4 + a2a0 + a5;
    result.x[i + 5] = r5;
    a5 = h[i + 257];
    vec r6 = h[i + 6] + a5 + a3a1 + a6;
    result.x[i + 6] = r6;
    a6 = h[i + 258]; a6a4 = a6 + a4;
    vec r7 = h[i + 7] + a6a4 + a2 + a7;
    result.x[i + 7] = r7;
    a7 = h[i + 259]; a7a5 = a7 + a5;
  }

  vec r0 = h[i] + a7a5 + a3 + a0;
  result.x[i] = r0;
  a0 = h[i + 252];
  vec r1 = h[i + 1] + a0 + a6a4 + a1;
  result.x[i + 1] = r1;
  a1 = h[i + 253];
  vec r2 = h[i + 2] + a1 + a7a5 + a2;
  result.x[i + 2] = r2;
  a2 = h[i + 254]; a2a0 = a2 + a0;
  vec r3 = h[i + 3] + a2a0 + a6 + a3;
  result.x[i + 3] = r3;
  a3 = h[i + 255]; a3a1 = a3 + a1;
  vec r4 = h[i + 4] + a3a1 + a7 + a4;
  result.x[i + 4] = r4;
  vec r5 = h[i + 5] + a2a0 + a5;
  result.x[i + 5] = r5;
  vec r6 = h[i + 6] + a3a1 + a6;
  result.x[i + 6] = r6;
  vec r7 = h[i + 7] + a2 + a7;
  result.x[i + 7] = r7;
  i += 8;
  r0 = h[i] + a3 + a0;
  result.x[i] = r0;
  r1 = h[i + 1] + a1;
  result.x[i + 1] = r1;
  r2 = h[i + 2] + a2;
  result.x[i + 2] = r2;
  r3 = h[i + 3] + a3;
  result.x[i + 3] = r3;
}

fieldelement operator*(const fieldelement &a,const fieldelement &b)
{
  fieldelement result;
  a.multiply(result,b);
  return result;
}

void fieldelement::putsquare(fieldelement &result) const
{
  vec *h = result.x;
  int i;
  vec a;
  vec b;
  vec u;
  vec v;
  vec w;

  b = x[129];
  v = x[130];

  for (i = 131;i < 247;i += 4) {
    a = x[i];
    u = a + v;
    h[2 * i - 244] = x[i - 122] + a; h[2 * i - 251] = u + b;
    v = x[i + 1];
    h[2 * i - 242] = x[i - 121] + v; h[2 * i - 249] = v + u;
    b = x[i + 2];
    u = b + v;
    h[2 * i - 240] = x[i - 120] + b; h[2 * i - 247] = u + a;
    v = x[i + 3];
    h[2 * i - 238] = x[i - 119] + v; h[2 * i - 245] = v + u;
  }
  
  vec x250 = x[250];
  vec x249 = x[249];
  vec x248 = x[248];
  vec x247 = x[247];
  vec h251 = x250 + x249;
  vec xx = x248 + x247;

  h[250] = x[125] + x247;
  h[243] = x247 + v + b;
  h[245] = xx + v;
  h[247] = x249 + xx;
  h[249] = h251 + x248;

  vec h256 = x[128] + x250;
  vec h254 = x[127] + x249;
  vec h252 = x[126] + x248;

  vec x130 = x[130];
  vec x129 = x[129];
  h[16] = x[8] + x130;
  h[14] = x[7] + x129;
  h[12] = x[6] + h256;
  h[10] = x[5] + h254;
  h[8] = x[4] + h252;
  h[6] = x[3] + x250;
  h[4] = x[2] + x249;
  h[2] = x[1] + x249;
  h[0] = x[0] + h251;

  h[1] = h252;
  vec f = h254 + h252;
  h[3] = f;
  h[5] = h256 + f;
  vec e = x129 + h256;
  h[7] = e + h254 + h251;
  h[9] = x130 + e + x250;
}

fieldelement fieldelement::square(void)
{
  fieldelement result;
  putsquare(result);
  return result;
}

void fieldelement::times_d(fieldelement &result) const
{
  vec *h = result.x;
  int i;

 	h[0] = x[0];
 	h[1] = x[1] + x[0];
 	for (i = 2;i < 7;++i) h[i] = x[i] + x[i - 1] + x[i - 2];
 	h[7] = x[7] + x[6] + x[5] + x[0];
 	h[8] = x[8] + x[7] + x[6] + x[1] + x[0];
 	h[9]  = x[9]  + x[8]  + x[7]  + x[2] + x[1] + x[0];
 	h[10] = x[10] + x[9]  + x[8]  + x[3] + x[2] + x[1];
 	h[11] = x[11] + x[10] + x[9]  + x[4] + x[3] + x[2];
 	h[12] = x[12] + x[11] + x[10] + x[5] + x[4] + x[3];
 	
 	for (i = 13;i < 251;++i) h[i] = x[i] + x[i - 1] + x[i - 2] + x[i - 7] + x[i - 8] + x[i - 9] + x[i - 13];
 	
  	vec a;
  	vec r[20];
  
  	i = 251;
  
  	a = x[i - 1] + x[i - 2] + x[i - 7] + x[i - 8] + x[i - 9] + x[i - 13];
  	h[0] = h[0] + a;
  	r[2] = h[2] + a;
	r[4] = h[4] + a;
	r[7] = h[7] + a;
	
	a = x[i - 1] + x[i - 6] + x[i - 7] + x[i - 8] + x[i - 12];
	h[1] = h[1] + a;
  	r[3] = h[3] + a;
	r[5] = h[5] + a;
	r[8] = h[8] + a;
	
	a = x[i - 5] + x[i - 6] + x[i - 7] + x[i - 11];
	h[2] = r[2] + a;
  	r[4] = r[4] + a;
	r[6] = h[6] + a;
	r[9] = h[9] + a;
	
	a = x[i - 4] + x[i - 5] + x[i - 6] + x[i - 10];
	h[3] = r[3] + a;
  	r[5] = r[5] + a;
	r[7] = r[7] + a;
	r[10] = h[10] + a;
	
	a = x[i - 3] + x[i - 4] + x[i - 5] + x[i - 9];
	h[4] = r[4] + a;
  	r[6] = r[6] + a;
	r[8] = r[8] + a;
	r[11] = h[11] + a;

	a = x[i - 2] + x[i - 3] + x[i - 4] + x[i - 8];
	h[5] = r[5] + a;
  	r[7] = r[7] + a;
	r[9] = r[9] + a;
	r[12] = h[12] + a;

	a = x[i - 1] + x[i - 2] + x[i - 3] + x[i - 7];
	h[6] = r[6] + a;
  	r[8] = r[8] + a;
	r[10] = r[10] + a;
	r[13] = h[13] + a;

	a = x[i - 1] + x[i - 2] + x[i - 6];
	h[7] = r[7] + a;
  	r[9] = r[9] + a;
	r[11] = r[11] + a;
	r[14] = h[14] + a;

 	a = x[i - 1] + x[i - 5];
 	h[8] = r[8] + a;
  	r[10] = r[10] + a;
	r[12] = r[12] + a;
	r[15] = h[15] + a;
 	
	
	a = x[i - 4];
	h[9] = r[9] + a;
  	r[11] = r[11] + a;
	r[13] = r[13] + a;
	r[16] = h[16] + a;
	
	
	
	a = x[i - 3];
	h[10] = r[10] + a;
  	r[12] = r[12] + a;
	r[14] = r[14] + a;
	r[17] = h[17] + a;
	
	
	
	a = x[i - 2];
	h[11] = r[11] + a;
  	r[13] = r[13] + a;
	r[15] = r[15] + a;
	r[18] = h[18] + a;
	

	a = x[i - 1];
	h[12] = r[12] + a;
  	r[14] = r[14] + a;
	r[16] = r[16] + a;
	r[19] = h[19] + a;
	
	h[13] = r[13];
	h[14] = r[14];
	h[15] = r[15];
	h[16] = r[16];
	h[17] = r[17];
	h[18] = r[18];
	h[19] = r[19]; 
}

void fieldelement::times_d_plus(fieldelement &result,const fieldelement &c) const
{
  times_d(result);
  result = result + c;
}

fieldelement fieldelement::times_d(void)
{
  fieldelement result;
  times_d(result);
  return result;
}

fieldelement fieldelement::inverse(void)
{
  int i;
  fieldelement u;
  fieldelement v;
  fieldelement w;
  fieldelement r;
  w = (*this) * ((*this) * (*this).square()).square();
  v = w * w.square().square().square();
  u = v.square().square();
  for (i = 8;i < 12;i += 2) u = u.square().square();
  w = v * u;
  v = w.square().square();
  for (i = 14;i < 24;i += 2) v = v.square().square();
  w = (*this) * (v * w).square();
  u = w.square();
  for (i = 26;i < 50;i += 2) u = u.square().square();
  r = w * u;
  u = r.square().square();
  for (i = 52;i < 100;i += 2) u = u.square().square();
  u = (u * r).square();
  for (i = 101;i < 125;i += 2) u = u.square().square();
  v = u * w;
  u = v.square();
  for (i = 126;i < 250;i += 2) u = u.square().square();
  return (u * v).square();
}

fieldelement fieldelement::bbk251(const vec n[251])
{
  fieldelement Z2; Z2.set_0();
  fieldelement X2; X2.set_1();
  vec control = n[250];
  fieldelement X3; X3 = *this;
  fieldelement Z3; Z3.set_1();
  fieldelement T0,T1;
  fieldelement D;
  int i;
  for (i = 250;i >= 0;--i) {
    conditionalswap(X2,X3,control);
    conditionalswap(Z2,Z3,control);
    	T0 = (X2 + Z2);
    	T1 = T0 * (X3 + Z3);
    	T1 = T1.square();
    	Z3 = (X2 * Z3) + (X3 * Z2);
    	Z3 = Z3.square();
    	X3 = T1 + Z3;
    	Z3 = Z3 * (*this);
    	Z2 = (X2 * Z2).square();
    	X2 = T0.square().square().times_d();
    if (i > 0) control = n[i] + n[i - 1];
  }
  conditionalswap(X2,X3,n[0]);
  conditionalswap(Z2,Z3,n[0]);
  return X2 * Z2.inverse();
}
