#include "bbk251.h"
#include "fieldelement.h"

inline void transpose4(__m128i *a)
{
  __m128i a0;
  __m128i a1;
  __m128i a2;
  __m128i a3;
  __m128i b0;
  __m128i b1;
  __m128i b2;
  __m128i b3;
  a0 = a[0];
  a1 = a[32];
  a2 = a[64];
  a3 = a[96];
  b0 = _mm_unpacklo_epi32(a0,a1);
  b1 = _mm_unpackhi_epi32(a0,a1);
  b2 = _mm_unpacklo_epi32(a2,a3);
  b3 = _mm_unpackhi_epi32(a2,a3);
  a[0] = _mm_unpacklo_epi64(b0,b2);
  a[64] = _mm_unpackhi_epi64(b0,b2);
  a[32] = _mm_unpacklo_epi64(b1,b3);
  a[96] = _mm_unpackhi_epi64(b1,b3);
}

void transpose16(__m128i *a)
{
  int i;
  for (i = 0;i < 128;i += 32) {
    __m128i a0 = a[i];
    __m128i a1 = a[i + 8];
    __m128i a2 = a[i + 16];
    __m128i a3 = a[i + 24];
    __m128i b0 = _mm_unpacklo_epi8(a0,a1);
    __m128i b1 = _mm_unpackhi_epi8(a0,a1);
    __m128i b2 = _mm_unpacklo_epi8(a2,a3);
    __m128i b3 = _mm_unpackhi_epi8(a2,a3);
    a[i] = _mm_unpacklo_epi16(b0,b2);
    a[i + 16] = _mm_unpackhi_epi16(b0,b2);
    a[i + 8] = _mm_unpacklo_epi16(b1,b3);
    a[i + 24] = _mm_unpackhi_epi16(b1,b3);
  }
  transpose4(a);
  transpose4(a + 8);
  transpose4(a + 16);
  transpose4(a + 24);
}

void transpose64(__m128i *a)
{
  int i;
  const __m128i lo32 = _mm_set_epi32(0x0f0f0f0f,0x0f0f0f0f,0x0f0f0f0f,0x0f0f0f0f);
  const __m128i hi32 = _mm_set_epi32(0xf0f0f0f0,0xf0f0f0f0,0xf0f0f0f0,0xf0f0f0f0);
  const __m128i lo64 = _mm_set_epi32(0x33333333,0x33333333,0x33333333,0x33333333);
  const __m128i hi64 = _mm_set_epi32(0xcccccccc,0xcccccccc,0xcccccccc,0xcccccccc);
  for (i = 0;i < 128;i += 8) {
    __m128i a0 = a[i];
    __m128i a1 = a[i + 2];
    __m128i a2 = a[i + 4];
    __m128i a3 = a[i + 6];
    __m128i b0 = _mm_xor_si128(_mm_and_si128(a0,lo64),_mm_slli_epi32(_mm_and_si128(a1,lo64),2));
    __m128i b1 = _mm_xor_si128(_mm_and_si128(a1,hi64),_mm_srli_epi32(_mm_and_si128(a0,hi64),2));
    __m128i b2 = _mm_xor_si128(_mm_and_si128(a2,lo64),_mm_slli_epi32(_mm_and_si128(a3,lo64),2));
    __m128i b3 = _mm_xor_si128(_mm_and_si128(a3,hi64),_mm_srli_epi32(_mm_and_si128(a2,hi64),2));
    a[i] = _mm_xor_si128(_mm_and_si128(b0,lo32),_mm_slli_epi32(_mm_and_si128(b2,lo32),4));
    a[i + 4] = _mm_xor_si128(_mm_and_si128(b2,hi32),_mm_srli_epi32(_mm_and_si128(b0,hi32),4));
    a[i + 2] = _mm_xor_si128(_mm_and_si128(b1,lo32),_mm_slli_epi32(_mm_and_si128(b3,lo32),4));
    a[i + 6] = _mm_xor_si128(_mm_and_si128(b3,hi32),_mm_srli_epi32(_mm_and_si128(b1,hi32),4));
  }
  transpose16(a);
  transpose16(a + 2);
  transpose16(a + 4);
  transpose16(a + 6);
}

void transpose(vec (&n)[251],const unsigned char nstr[128][32])
{
  int i;
  int itop;
  int j;
  const __m128i lo = _mm_set_epi32(0x55555555,0x55555555,0x55555555,0x55555555);
  const __m128i hi = _mm_set_epi32(0xaaaaaaaa,0xaaaaaaaa,0xaaaaaaaa,0xaaaaaaaa);
  __m128i r[256];
  for (i = 0;i < 128;i += 2) {
    __m128i n0 = _mm_loadu_si128((__m128i *) &nstr[i][0]);
    __m128i n2 = _mm_loadu_si128((__m128i *) &nstr[i][16]);
    __m128i n1 = _mm_loadu_si128((__m128i *) &nstr[i + 1][0]);
    __m128i n3 = _mm_loadu_si128((__m128i *) &nstr[i + 1][16]);
    r[i] = _mm_xor_si128(_mm_and_si128(n0,lo),_mm_slli_epi32(_mm_and_si128(n1,lo),1));
    r[i + 1] = _mm_xor_si128(_mm_and_si128(n1,hi),_mm_srli_epi32(_mm_and_si128(n0,hi),1));
    r[i + 128] = _mm_xor_si128(_mm_and_si128(n2,lo),_mm_slli_epi32(_mm_and_si128(n3,lo),1));
    r[i + 129] = _mm_xor_si128(_mm_and_si128(n3,hi),_mm_srli_epi32(_mm_and_si128(n2,hi),1));
  }
  transpose64(&r[0]);
  transpose64(&r[1]);
  transpose64(&r[128]);
  transpose64(&r[129]);
  for (itop = 0;itop < 120;itop += 8) {
    j =
      ((itop >> 3) & 8) |
      ((itop >> 1) & 16) |
      ((itop << 1) & 32) |
      ((itop << 3) & 64) ;
    for (i = 0;i < 8;++i) {
      n[itop + i] = r[j + i];
      n[itop + i + 128] = r[i + j + 128];
    }
  }
  for (itop = 120;itop < 128;itop += 8) {
    j =
      ((itop >> 3) & 8) |
      ((itop >> 1) & 16) |
      ((itop << 1) & 32) |
      ((itop << 3) & 64) ;
    for (i = 0;i < 8;++i) {
      n[itop + i] = r[j + i];
      if (itop + i + 128 < 251) n[itop + i + 128] = r[i + j + 128];
    }
  }
}

void transpose(unsigned char (&nstr)[128][32],const vec n[251])
{
  int i;
  int itop;
  int j;

  const __m128i lo = _mm_set_epi32(0x55555555,0x55555555,0x55555555,0x55555555);
  const __m128i hi = _mm_set_epi32(0xaaaaaaaa,0xaaaaaaaa,0xaaaaaaaa,0xaaaaaaaa);
  __m128i r[256];
  for (i = 0;i < 250;i += 2) {
    __m128i x = n[i];
    __m128i y = n[i + 1];
    r[i] = _mm_xor_si128(_mm_and_si128(x,lo),_mm_slli_epi32(_mm_and_si128(y,lo),1));
    r[i + 1] = _mm_xor_si128(_mm_and_si128(y,hi),_mm_srli_epi32(_mm_and_si128(x,hi),1));
  }
  __m128i x = n[i];
  r[i] = _mm_and_si128(x,lo);
  r[i + 1] = _mm_srli_epi32(_mm_and_si128(x,hi),1);
  r[i + 2] = _mm_set_epi32(0,0,0,0);
  r[i + 3] = _mm_set_epi32(0,0,0,0);
  r[i + 4] = _mm_set_epi32(0,0,0,0);
  r[i + 5] = _mm_set_epi32(0,0,0,0);
  transpose64(&r[0]);
  transpose64(&r[1]);
  transpose64(&r[128]);
  transpose64(&r[129]);
  for (itop = 0;itop < 128;itop += 8) {
    j =
      ((itop >> 3) & 8) |
      ((itop >> 1) & 16) |
      ((itop << 1) & 32) |
      ((itop << 3) & 64) ;
    for (i = 0;i < 8;++i) {
      _mm_storeu_si128((__m128i *) &nstr[i + j][0],r[itop + i]);
      _mm_storeu_si128((__m128i *) &nstr[i + j][16],r[itop + i + 128]);
    }
  }
}

void transpose(fieldelement &p,const unsigned char pstr[128][32])
{
  transpose(p.x,pstr);
}

void transpose(unsigned char (&pstr)[128][32],const fieldelement p)
{
  transpose(pstr,p.x);
}

void bbk251(unsigned char (&npstr)[128][32],const unsigned char pstr[128][32],const unsigned char nstr[128][32])
{
  vec n[251];
  fieldelement p;
  fieldelement np;
  transpose(n,nstr);
  transpose(p,pstr);
  np = p.bbk251(n);
  transpose(npstr,np);
}
