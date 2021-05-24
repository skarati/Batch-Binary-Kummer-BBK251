#include <iostream>
#include <unistd.h>
#include "bbk251.h"
#include "fieldelement.h"
#include "vec.h"

#ifdef TIMEINDIVIDUALMULTS
extern void mult6(vec *,const vec *,const vec *);
extern void mult7(vec *,const vec *,const vec *);
extern void mult8(vec *,const vec *,const vec *);
extern void mult27(vec *,const vec *,const vec *);
extern void mult28(vec *,const vec *,const vec *);
extern void mult29(vec *,const vec *,const vec *);
extern void mult30(vec *,const vec *,const vec *);
extern void mult83(vec *,const vec *,const vec *);
extern void mult84(vec *,const vec *,const vec *);
extern void mult85(vec *,const vec *,const vec *);
extern void mult83_eval(vec *,vec *,vec *,const vec *);
extern void mult84_eval(vec *,vec *,vec *,const vec *);
extern void mult85_eval(vec *,vec *,vec *,const vec *);
extern void mult83_interp(vec *,const vec *,const vec *,const vec *);
extern void mult84_interp(vec *,const vec *,const vec *,const vec *);
extern void mult85_interp(vec *,const vec *,const vec *,const vec *);
extern void mult251(vec *,const vec *,const vec *);
#endif

using namespace std;

long long cpucycles(void)
{
  unsigned long long result;
  asm volatile(".byte 15;.byte 49;shlq $32,%%rdx;orq %%rdx,%%rax"
    : "=a" (result) ::  "%rdx");
  return result;
}

#define TIMINGS 50
long long t[TIMINGS + 1];

void printtimings(const char *s)
{
  int i;
  cout << s;
  long long min;
  min = t[1] - t[0];
  for (i = 0;i < TIMINGS;++i) if (t[i + 1] - t[i] < min) min = t[i + 1] - t[i];
  cout << " " << min << ":";
  for (i = 0;i < TIMINGS && i < 7;++i) cout << " " << t[i + 1] - t[i];
  cout << "\n";
}

void printtimings128(const char *s)
{
  int i;
  cout << s;
  long long min;
  min = t[1] - t[0];
  for (i = 0;i < TIMINGS;++i) if (t[i + 1] - t[i] < min) min = t[i + 1] - t[i];
  cout << " " << min / 128 << ":";
  for (i = 0;i < TIMINGS && i < 7;++i) cout << " " << (t[i + 1] - t[i]) / 128;
  cout << "\n";
}

int main()
{
  fieldelement u;
  vec control;
  vec n[251];
  fieldelement v;
  fieldelement w;
  vec h[600];
  vec f[300];
  vec g[300];
  vec r[300];
  int i;
  int j;
  unsigned long long b0;
  unsigned char npstr[128][32];
  unsigned char pstr[128][32];
  unsigned char nstr[128][32];

  for (i = 0;i < 128;++i) for (j = 0;j < 32;++j) npstr[i][j] = random();
  for (i = 0;i < 128;++i) for (j = 0;j < 32;++j) pstr[i][j] = random();
  for (i = 0;i < 128;++i) for (j = 0;j < 32;++j) nstr[i][j] = random();

  bbk251(npstr,pstr,nstr);
  printf("\n");

  for (i = 0;i < 128;++i) {
    printf("n=0");
    for (j = 0;j < 251;++j) if (nstr[i][j / 8] & (1 << (j & 7))) printf("+2^%d",j);
    printf("\n");
    printf("w=0");
    for (j = 0;j < 251;++j) if (pstr[i][j / 8] & (1 << (j & 7))) printf("+t^%d",j);
    printf("\n");
    printf("nw=0");
    for (j = 0;j < 251;++j) if (npstr[i][j / 8] & (1 << (j & 7))) printf("+t^%d",j);
    printf("\n");
    printf("\n");
  }

  b0 = vec_bitops; v = u * v; cout << "mult " << vec_bitops-b0 << "\n";
  b0 = vec_bitops; v = u + v; cout << "add " << vec_bitops-b0 << "\n";
  b0 = vec_bitops; v = u.square(); cout << "square " << vec_bitops-b0 << "\n";
  b0 = vec_bitops; v = u.times_d(); cout << "times_d " << vec_bitops-b0 << "\n";
  b0 = vec_bitops; v = u.inverse(); cout << "inverse " << vec_bitops-b0 << "\n";
  b0 = vec_bitops; conditionalswap(u,v,control); cout << "conditionalswap " << vec_bitops-b0 << "\n";
  b0 = vec_bitops; v = u.bbk251(n); cout << "bbk251 " << vec_bitops-b0 << "\n";

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); bbk251(npstr,pstr,nstr); }
  printtimings128("bbk251/128");
  printtimings("bbk251");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); v = u.bbk251(n); }
  printtimings("u.bbk251");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); v = u.inverse(); }
  printtimings("u.inverse");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); v = u.square(); }
  printtimings("u.square");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); u.putsquare(v); }
  printtimings("u.putsquare");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); v = u.times_d(); }
  printtimings("u.times_d");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); u.times_d(v); }
  printtimings("inline d");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); u.times_d_plus(v,w); }
  printtimings("inline d+");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); u.set_1(); }
  printtimings("set_1");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); u.set_0(); }
  printtimings("set_0");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); v = u + v; }
  printtimings("u+v");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); u.add(u,v); }
  printtimings("add");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); conditionalswap(u,v,control); }
  printtimings("cswap");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); v = u * v; }
  printtimings("u*v");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); u.multiply(v,u); }
  printtimings("multiply");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); transpose(u,nstr); }
  printtimings("transpose");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); transpose(nstr,u); }
  printtimings("invtrans");

#ifdef TIMEINDIVIDUALMULTS
  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult251(h,f,g); }
  printtimings("mult251");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult85(h,f,g); }
  printtimings("mult85");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult85_eval(h,f,g,r); }
  printtimings("eval");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult85_interp(h,f,g,g); }
  printtimings("interp");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult84(h,f,g); }
  printtimings("mult84");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult84_eval(h,f,g,r); }
  printtimings("eval");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult84_interp(h,f,g,g); }
  printtimings("interp");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult83(h,f,g); }
  printtimings("mult83");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult83_eval(h,f,g,r); }
  printtimings("eval");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult83_interp(h,f,g,g); }
  printtimings("interp");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult30(h,f,g); }
  printtimings("mult30");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult29(h,f,g); }
  printtimings("mult29");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult28(h,f,g); }
  printtimings("mult28");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult27(h,f,g); }
  printtimings("mult27");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult8(h,f,g); }
  printtimings("mult8");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult7(h,f,g); }
  printtimings("mult7");

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); mult6(h,f,g); }
  printtimings("mult6");
#endif

  for (i = 0;i <= TIMINGS;++i) { t[i] = cpucycles(); }
  printtimings("nothing");

  cout << flush;

  t[0] = cpucycles();
  for (i = 0;i < 8;++i) bbk251(npstr,pstr,nstr);
  t[1] = cpucycles();
  for (i = 0;i < 8;++i) bbk251(npstr,pstr,nstr);
  t[2] = cpucycles();
  cout << t[1] - t[0] << " " << t[2] - t[1] << "\n";

  cout << flush;

  fork();
  fork();

  t[0] = cpucycles();
  for (i = 0;i < 8;++i) bbk251(npstr,pstr,nstr);
  t[1] = cpucycles();
  for (i = 0;i < 8;++i) bbk251(npstr,pstr,nstr);
  t[2] = cpucycles();
  cout << t[1] - t[0] << " " << t[2] - t[1] << "\n";

  return 0;
}
