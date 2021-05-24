#include "fieldelement.h"

unsigned long long vec_bitops = 0;

extern void mult6(vec *,const vec *,const vec *);
extern void mult7(vec *,const vec *,const vec *);
extern void mult8(vec *,const vec *,const vec *);
extern void mult27(vec *,const vec *,const vec *);
extern void mult28(vec *,const vec *,const vec *);
extern void mult29(vec *,const vec *,const vec *);
extern void mult30(vec *,const vec *,const vec *);

void mult6(vec *h,const vec *f,const vec *g)
{
  vec f0;
  vec f1;
  vec f2;
  vec f3;
  vec f4;
  vec f5;
  vec g0;
  vec g1;
  vec g2;
  vec g3;
  vec g4;
  vec g5;
  vec h0;
  vec h1;
  vec h2;
  vec h3;
  vec h4;
  vec h5;
  vec h6;
  vec h7;
  vec h8;
  vec h9;
  vec h10;

  f0 = f[0];
  g0 = g[0];
  h0 = f0 * g0;
  h[0] = h0;
  f1 = f[1];
  h1 = f1 * g0;
  f2 = f[2];
  h2 = f2 * g0;
  f3 = f[3];
  h3 = f3 * g0;
  f4 = f[4];
  h4 = f4 * g0;
  f5 = f[5];
  h5 = f5 * g0;

  g1 = g[1];
  h1 = h1 + f0 * g1;
  h[1] = h1;
  h2 = h2 + f1 * g1;
  h3 = h3 + f2 * g1;
  h4 = h4 + f3 * g1;
  h5 = h5 + f4 * g1;
  h6 = f5 * g1;

  g2 = g[2];
  h2 = h2 + f0 * g2;
  h[2] = h2;
  h3 = h3 + f1 * g2;
  h4 = h4 + f2 * g2;
  h5 = h5 + f3 * g2;
  h6 = h6 + f4 * g2;
  h7 = f5 * g2;

  g3 = g[3];
  h3 = h3 + f0 * g3;
  h[3] = h3;
  h4 = h4 + f1 * g3;
  h5 = h5 + f2 * g3;
  h6 = h6 + f3 * g3;
  h7 = h7 + f4 * g3;
  h8 = f5 * g3;

  g4 = g[4];
  h4 = h4 + f0 * g4;
  h[4] = h4;
  h5 = h5 + f1 * g4;
  h6 = h6 + f2 * g4;
  h7 = h7 + f3 * g4;
  h8 = h8 + f4 * g4;
  h9 = f5 * g4;

  g5 = g[5];
  h5 = h5 + f0 * g5;
  h[5] = h5;
  h6 = h6 + f1 * g5;
  h[6] = h6;
  h7 = h7 + f2 * g5;
  h[7] = h7;
  h8 = h8 + f3 * g5;
  h[8] = h8;
  h9 = h9 + f4 * g5;
  h[9] = h9;
  h10 = f5 * g5;
  h[10] = h10;
}

void mult7(vec *h,const vec *f,const vec *g)
{
  vec f0;
  vec f1;
  vec f2;
  vec f3;
  vec f4;
  vec f5;
  vec f6;
  vec g0;
  vec g1;
  vec g2;
  vec g3;
  vec g4;
  vec g5;
  vec g6;
  vec h0;
  vec h1;
  vec h2;
  vec h3;
  vec h4;
  vec h5;
  vec h6;
  vec h7;
  vec h8;
  vec h9;
  vec h10;
  vec h11;
  vec h12;

  f0 = f[0];
  f1 = f[1];
  f2 = f[2];
  f3 = f[3];

  g0 = g[0];
  h0 = f0 * g0;
  h[0] = h0;
  h1 = f1 * g0;
  h2 = f2 * g0;
  h3 = f3 * g0;
  g1 = g[1];
  h1 = h1 + f0 * g1;
  h[1] = h1;
  h2 = h2 + f1 * g1;
  h3 = h3 + f2 * g1;
  h4 = f3 * g1;
  g2 = g[2];
  h2 = h2 + f0 * g2;
  h[2] = h2;
  h3 = h3 + f1 * g2;
  h4 = h4 + f2 * g2;
  h5 = f3 * g2;
  g3 = g[3];
  h3 = h3 + f0 * g3;
  h[3] = h3;
  h4 = h4 + f1 * g3;
  h5 = h5 + f2 * g3;
  h6 = f3 * g3;

  g4 = g[4];
  h4 = h4 + f0 * g4;
  h5 = h5 + f1 * g4;
  h6 = h6 + f2 * g4;
  h7 = f3 * g4;
  g5 = g[5];
  h5 = h5 + f0 * g5;
  h6 = h6 + f1 * g5;
  h7 = h7 + f2 * g5;
  h8 = f3 * g5;
  g6 = g[6];
  h6 = h6 + f0 * g6;
  h7 = h7 + f1 * g6;
  h8 = h8 + f2 * g6;
  h9 = f3 * g6;

  f4 = f[4];
  f5 = f[5];
  f6 = f[6];
  h4 = h4 + f4 * g0;
  h[4] = h4;
  h5 = h5 + f5 * g0;
  h6 = h6 + f6 * g0;
  h5 = h5 + f4 * g1;
  h[5] = h5;
  h6 = h6 + f5 * g1;
  h7 = h7 + f6 * g1;
  h6 = h6 + f4 * g2;
  h[6] = h6;
  h7 = h7 + f5 * g2;
  h8 = h8 + f6 * g2;
  h7 = h7 + f4 * g3;
  h[7] = h7;
  h8 = h8 + f5 * g3;
  h9 = h9 + f6 * g3;
  g4 = g[4];
  h8 = h8 + f4 * g4;
  h[8] = h8;
  h9 = h9 + f5 * g4;
  h10 = h10 + f6 * g4;
  g5 = g[5];
  h9 = h9 + f4 * g5;
  h[9] = h9;
  h10 = h10 + f5 * g5;
  h11 = h11 + f6 * g5;
  g6 = g[6];
  h10 = h10 + f4 * g6;
  h[10] = h10;
  h11 = h11 + f5 * g6;
  h12 = h12 + f6 * g6;
  h[11] = h11;
  h[12] = h12;
}

void mult8(vec *h,const vec *f,const vec *g)
{
  vec f0;
  vec f1;
  vec f2;
  vec f3;
  vec f4;
  vec f5;
  vec f6;
  vec f7;
  vec g0;
  vec g1;
  vec g2;
  vec g3;
  vec g4;
  vec g5;
  vec g6;
  vec g7;
  vec h0;
  vec h1;
  vec h2;
  vec h3;
  vec h4;
  vec h5;
  vec h6;
  vec h7;
  vec h8;
  vec h9;
  vec h10;
  vec h11;
  vec h12;
  vec h13;
  vec h14;

  f0 = f[0];
  f1 = f[1];
  f2 = f[2];
  f3 = f[3];

  g0 = g[0];
  h0 = f0 * g0;
  h[0] = h0;
  h1 = f1 * g0;
  h2 = f2 * g0;
  h3 = f3 * g0;
  g1 = g[1];
  h1 = h1 + f0 * g1;
  h[1] = h1;
  h2 = h2 + f1 * g1;
  h3 = h3 + f2 * g1;
  h4 = f3 * g1;
  g2 = g[2];
  h2 = h2 + f0 * g2;
  h[2] = h2;
  h3 = h3 + f1 * g2;
  h4 = h4 + f2 * g2;
  h5 = f3 * g2;
  g3 = g[3];
  h3 = h3 + f0 * g3;
  h[3] = h3;
  h4 = h4 + f1 * g3;
  h5 = h5 + f2 * g3;
  h6 = f3 * g3;

  g4 = g[4];
  h4 = h4 + f0 * g4;
  h5 = h5 + f1 * g4;
  h6 = h6 + f2 * g4;
  h7 = f3 * g4;
  g5 = g[5];
  h5 = h5 + f0 * g5;
  h6 = h6 + f1 * g5;
  h7 = h7 + f2 * g5;
  h8 = f3 * g5;
  g6 = g[6];
  h6 = h6 + f0 * g6;
  h7 = h7 + f1 * g6;
  h8 = h8 + f2 * g6;
  h9 = f3 * g6;
  g7 = g[7];
  h7 = h7 + f0 * g7;
  h8 = h8 + f1 * g7;
  h9 = h9 + f2 * g7;
  h10 = f3 * g7;

  f4 = f[4];
  f5 = f[5];
  f6 = f[6];
  f7 = f[7];
  h4 = h4 + f4 * g0;
  h[4] = h4;
  h5 = h5 + f5 * g0;
  h6 = h6 + f6 * g0;
  h7 = h7 + f7 * g0;
  h5 = h5 + f4 * g1;
  h[5] = h5;
  h6 = h6 + f5 * g1;
  h7 = h7 + f6 * g1;
  h8 = h8 + f7 * g1;
  h6 = h6 + f4 * g2;
  h[6] = h6;
  h7 = h7 + f5 * g2;
  h8 = h8 + f6 * g2;
  h9 = h9 + f7 * g2;
  h7 = h7 + f4 * g3;
  h[7] = h7;
  h8 = h8 + f5 * g3;
  h9 = h9 + f6 * g3;
  h10 = h10 + f7 * g3;
  g4 = g[4];
  h8 = h8 + f4 * g4;
  h[8] = h8;
  h9 = h9 + f5 * g4;
  h10 = h10 + f6 * g4;
  h11 = f7 * g4;
  g5 = g[5];
  h9 = h9 + f4 * g5;
  h[9] = h9;
  h10 = h10 + f5 * g5;
  h11 = h11 + f6 * g5;
  h12 = f7 * g5;
  g6 = g[6];
  h10 = h10 + f4 * g6;
  h[10] = h10;
  h11 = h11 + f5 * g6;
  h12 = h12 + f6 * g6;
  h13 = f7 * g6;
  g7 = g[7];
  h11 = h11 + f4 * g7;
  h[11] = h11;
  h12 = h12 + f5 * g7;
  h[12] = h12;
  h13 = h13 + f6 * g7;
  h[13] = h13;
  h14 = f7 * g7;
  h[14] = h14;
}

void mult27(vec *h,const vec *f,const vec *g)
{
  const int n = 7;
  vec f1[2 * n];
  vec f2[n];
  vec f3[n];
  vec f4[n];
  vec g1[2 * n];
  vec g2[n];
  vec g3[n];
  vec g4[n];
  vec u[2 * 2 * n - 1];
  vec u2[2 * n - 1];
  vec u3[2 * n - 1];
  vec u4[2 * n - 1];
  int i;

  for (i = 0;i < n - 1;++i) {
    vec fi0 = f[i];
    vec fi1 = f[i + n];
    vec fi2 = f[i + 2 * n];
    vec fi3 = f[i + 3 * n];
    vec u = fi0 + fi1;
    vec v = fi2 + fi3;
    f1[i] = fi0 + fi2;
    f1[i + n] = fi1 + fi3;
    f2[i] = u;
    f3[i] = v;
    f4[i] = u + v;
  }
  for (i = n - 1;i < n;++i) {
    vec fi0 = f[i];
    vec fi1 = f[i + n];
    vec fi2 = f[i + 2 * n];
    vec u = fi0 + fi1;
    vec v = fi2;
    f1[i] = fi0 + fi2;
    f1[i + n] = fi1;
    f2[i] = u;
    f3[i] = v;
    f4[i] = u + v;
  }
  for (i = 0;i < n - 1;++i) {
    vec gi0 = g[i];
    vec gi1 = g[i + n];
    vec gi2 = g[i + 2 * n];
    vec gi3 = g[i + 3 * n];
    vec u = gi0 + gi1;
    vec v = gi2 + gi3;
    g1[i] = gi0 + gi2;
    g1[i + n] = gi1 + gi3;
    g2[i] = u;
    g3[i] = v;
    g4[i] = u + v;
  }
  for (i = n - 1;i < n;++i) {
    vec gi0 = g[i];
    vec gi1 = g[i + n];
    vec gi2 = g[i + 2 * n];
    vec u = gi0 + gi1;
    vec v = gi2;
    g1[i] = gi0 + gi2;
    g1[i + n] = gi1;
    g2[i] = u;
    g3[i] = v;
    g4[i] = u + v;
  }

  mult7(h,f,g);
  mult7(h + 2 * n,f + n,g + n);
  mult7(h + 2 * 2 * n,f + 2 * n,g + 2 * n);
  mult6(h + 2 * 2 * n + 2 * n,f + 2 * n + n,g + 2 * n + n);
  mult7(u,f1,g1);
  mult7(u + 2 * n,f1 + n,g1 + n);
  mult7(u2,f2,g2);
  mult7(u3,f3,g3);
  mult7(u4,f4,g4);

  for (i = 0;i < n - 3;++i) {
    vec h0 = h[i];
    vec h12 = h[i + n] + h[i + 2 * n];
    vec h34 = h[i + 3 * n] + h[i + 4 * n];
    vec h56 = h[i + 5 * n] + h[i + 6 * n];
    vec h7 = h[i + 7 * n];
    vec x0 = u[i];
    vec x12 = u[i + n] + u[i + 2 * n];
    vec x3 = u[i + 3 * n];
    vec h1 = h12 + h0 + u2[i];
    vec b = h34 + h12 + u2[i + n];
    vec c = h34 + h56 + u3[i];
    vec h6 = h7 + h56 + u3[i + n];
    h[i + n] = h1;
    h[i + 6 * n] = h6;
    h[i + 2 * n] = b + h0 + x0;
    h[i + 3 * n] = c + h1 + x12 + x0 + u4[i];
    h[i + 4 * n] = h6 + b + x12 + x3 + u4[i + n];
    h[i + 5 * n] = h7 + c + x3;
  }
  for (i = n - 3;i < n - 1;++i) {
    vec h0 = h[i];
    vec h12 = h[i + n] + h[i + 2 * n];
    vec h34 = h[i + 3 * n] + h[i + 4 * n];
    vec h56 = h[i + 5 * n] + h[i + 6 * n];
    vec x0 = u[i];
    vec x12 = u[i + n] + u[i + 2 * n];
    vec x3 = u[i + 3 * n];
    vec h1 = h12 + h0 + u2[i];
    vec b = h34 + h12 + u2[i + n];
    vec c = h34 + h56 + u3[i];
    vec h6 = h56 + u3[i + n];
    h[i + n] = h1;
    h[i + 6 * n] = h6;
    h[i + 2 * n] = b + h0 + x0;
    h[i + 3 * n] = c + h1 + x12 + x0 + u4[i];
    h[i + 4 * n] = h6 + b + x12 + x3 + u4[i + n];
    h[i + 5 * n] = c + x3;
  }

  h[2 * n - 1] = h[3 * n - 1] + h[n - 1] + u2[n - 1];
  h[2 * 2 * n + 2 * n - 1] = h[2 * 2 * n + 3 * n - 1] + h[2 * 2 * n + n - 1] + u3[n - 1];
  vec w = u[3 * n - 1] + u[n - 1] + u4[n - 1];
  vec v = h[n - 1 + 2 * n] + h[n - 1 + 2 * 2 * n];
  h[n - 1 + 2 * n] = v + h[n - 1] + u[n - 1];
  h[n - 1 + 2 * 2 * n] = h[n - 1 + 3 * 2 * n] + v + u[n - 1 + 2 * n];
  h[2 * 2 * n - 1] = h[3 * 2 * n - 1] + h[2 * n - 1] + w;
}

void mult28(vec *h,const vec *f,const vec *g)
{
  const int n = 7;
  vec f1[2 * n];
  vec f2[n];
  vec f3[n];
  vec f4[n];
  vec g1[2 * n];
  vec g2[n];
  vec g3[n];
  vec g4[n];
  vec u[2 * 2 * n - 1];
  vec u2[2 * n - 1];
  vec u3[2 * n - 1];
  vec u4[2 * n - 1];
  int i;

  for (i = 0;i < n;++i) {
    vec fi0 = f[i];
    vec fi1 = f[i + n];
    vec fi2 = f[i + 2 * n];
    vec fi3 = f[i + 3 * n];
    vec u = fi0 + fi1;
    vec v = fi2 + fi3;
    f1[i] = fi0 + fi2;
    f1[i + n] = fi1 + fi3;
    f2[i] = u;
    f3[i] = v;
    f4[i] = u + v;
  }
  for (i = 0;i < n;++i) {
    vec gi0 = g[i];
    vec gi1 = g[i + n];
    vec gi2 = g[i + 2 * n];
    vec gi3 = g[i + 3 * n];
    vec u = gi0 + gi1;
    vec v = gi2 + gi3;
    g1[i] = gi0 + gi2;
    g1[i + n] = gi1 + gi3;
    g2[i] = u;
    g3[i] = v;
    g4[i] = u + v;
  }

  mult7(h,f,g);
  mult7(h + 2 * n,f + n,g + n);
  mult7(h + 2 * 2 * n,f + 2 * n,g + 2 * n);
  mult7(h + 2 * 2 * n + 2 * n,f + 2 * n + n,g + 2 * n + n);
  mult7(u,f1,g1);
  mult7(u + 2 * n,f1 + n,g1 + n);
  mult7(u2,f2,g2);
  mult7(u3,f3,g3);
  mult7(u4,f4,g4);

  for (i = 0;i < n - 1;++i) {
    vec h0 = h[i];
    vec h12 = h[i + n] + h[i + 2 * n];
    vec h34 = h[i + 3 * n] + h[i + 4 * n];
    vec h56 = h[i + 5 * n] + h[i + 6 * n];
    vec h7 = h[i + 7 * n];
    vec x0 = u[i];
    vec x12 = u[i + n] + u[i + 2 * n];
    vec x3 = u[i + 3 * n];
    vec h1 = h12 + h0 + u2[i];
    vec b = h34 + h12 + u2[i + n];
    vec c = h34 + h56 + u3[i];
    vec h6 = h7 + h56 + u3[i + n];
    h[i + n] = h1;
    h[i + 2 * n] = b + h0 + x0;
    h[i + 3 * n] = c + h1 + x12 + x0 + u4[i];
    h[i + 4 * n] = h6 + b + x12 + x3 + u4[i + n];
    h[i + 5 * n] = h7 + c + x3;
    h[i + 6 * n] = h6;
  }

  h[2 * n - 1] = h[3 * n - 1] + h[n - 1] + u2[n - 1];
  h[2 * 2 * n + 2 * n - 1] = h[2 * 2 * n + 3 * n - 1] + h[2 * 2 * n + n - 1] + u3[n - 1];
  vec w = u[3 * n - 1] + u[n - 1] + u4[n - 1];
  vec v = h[n - 1 + 2 * n] + h[n - 1 + 2 * 2 * n];
  h[n - 1 + 2 * n] = v + h[n - 1] + u[n - 1];
  h[n - 1 + 2 * 2 * n] = h[n - 1 + 3 * 2 * n] + v + u[n - 1 + 2 * n];
  h[2 * 2 * n - 1] = h[3 * 2 * n - 1] + h[2 * n - 1] + w;
}

void mult29(vec *h,const vec *f,const vec *g)
{
  const int n = 7;
  vec f1[2 * n];
  vec f2[n];
  vec f3[n];
  vec f4[n];
  vec g1[2 * n];
  vec g2[n];
  vec g3[n];
  vec g4[n];
  vec u[2 * 2 * n - 1];
  vec u2[2 * n - 1];
  vec u3[2 * n - 1];
  vec u4[2 * n - 1];
  int i;

  for (i = 0;i < n;++i) {
    vec fi0 = f[i];
    vec fi1 = f[i + n];
    vec fi2 = f[i + 2 * n];
    vec fi3 = f[i + 3 * n];
    vec u = fi0 + fi1;
    vec v = fi2 + fi3;
    f1[i] = fi0 + fi2;
    f1[i + n] = fi1 + fi3;
    f2[i] = u;
    f3[i] = v;
    f4[i] = u + v;
  }
  for (i = 0;i < n;++i) {
    vec gi0 = g[i];
    vec gi1 = g[i + n];
    vec gi2 = g[i + 2 * n];
    vec gi3 = g[i + 3 * n];
    vec u = gi0 + gi1;
    vec v = gi2 + gi3;
    g1[i] = gi0 + gi2;
    g1[i + n] = gi1 + gi3;
    g2[i] = u;
    g3[i] = v;
    g4[i] = u + v;
  }

  mult7(h,f,g);
  mult7(h + 2 * n,f + n,g + n);
  mult7(h + 2 * 2 * n,f + 2 * n,g + 2 * n);
  mult7(h + 2 * 2 * n + 2 * n,f + 2 * n + n,g + 2 * n + n);
  mult7(u,f1,g1);
  mult7(u + 2 * n,f1 + n,g1 + n);
  mult7(u2,f2,g2);
  mult7(u3,f3,g3);
  mult7(u4,f4,g4);

  vec f28 = f[28];
  vec g28 = g[28];

  for (i = 0;i < n - 1;++i) {
    vec h0 = h[i];
    vec h12 = h[i + n] + h[i + 2 * n];
    vec h34 = h[i + 3 * n] + h[i + 4 * n];
    vec h56 = h[i + 5 * n] + h[i + 6 * n];
    vec h7 = h[i + 7 * n];
    vec x0 = u[i];
    vec x12 = u[i + n] + u[i + 2 * n];
    vec x3 = u[i + 3 * n];
    vec h1 = h12 + h0 + u2[i];
    vec b = h34 + h12 + u2[i + n];
    vec c = h34 + h56 + u3[i];
    vec h6 = h7 + h56 + u3[i + n];
    h[i + n] = h1;
    h[i + 2 * n] = b + h0 + x0;
    h[i + 3 * n] = c + h1 + x12 + x0 + u4[i];
    h[i + 4 * n] = h6 + b + x12 + x3 + u4[i + n] + f28 * g[i] + g28 * f[i];
    h[i + 5 * n] = h7 + c + x3 + f28 * g[i + n] + g28 * f[i + n];
    h[i + 6 * n] = h6 + f28 * g[i + 2 * n] + g28 * f[i + 2 * n];
    h[i + 7 * n] = h7 + f28 * g[i + 3 * n] + g28 * f[i + 3 * n];
  }

  h[2 * n - 1] = h[3 * n - 1] + h[n - 1] + u2[n - 1];
  h[2 * 2 * n + 2 * n - 1] = h[2 * 2 * n + 3 * n - 1] + h[2 * 2 * n + n - 1] + u3[n - 1];
  vec w = u[3 * n - 1] + u[n - 1] + u4[n - 1];
  vec v = h[n - 1 + 2 * n] + h[n - 1 + 2 * 2 * n];
  h[n - 1 + 2 * n] = v + h[n - 1] + u[n - 1];
  h[n - 1 + 2 * 2 * n] = h[n - 1 + 3 * 2 * n] + v + u[n - 1 + 2 * n];
  h[2 * 2 * n - 1] = h[3 * 2 * n - 1] + h[2 * n - 1] + w;

  i = 6; h[i + 28] = h[i + 28] + f28 * g[i] + g28 * f[i];
  i = 13; h[i + 28] = h[i + 28] + f28 * g[i] + g28 * f[i];
  i = 20; h[i + 28] = h[i + 28] + f28 * g[i] + g28 * f[i];
  h[55] = f28 * g[27] + g28 * f[27];
  h[56] = f28 * g28;
}

void mult30(vec *h,const vec *f,const vec *g)
{
  vec f1[15];
  vec f2[8];
  vec f3[8];
  vec f4[8];
  vec g1[15];
  vec g2[8];
  vec g3[8];
  vec g4[8];
  vec u[30 - 1];
  vec u2[15];
  vec u3[15];
  vec u4[15];
  int i;

  vec r0;
  vec r1;
  vec r2;
  vec r3;

  for (i = 0;i < 7;++i) {
    r0 = f[i];
    r1 = f[i + 8];
    r2 = f[i + 15];
    r3 = f[i + 23];
    vec u = r0 + r1;
    vec v = r2 + r3;
    f1[i] = r0 + r2;
    f1[i + 8] = r1 + r3;
    f2[i] = u;
    f3[i] = v;
    f4[i] = u + v;
  }
  r0 = f[7];
  r1 = f[22];
  f2[7] = r0;
  f3[7] = r1;
  r0 = r0 + r1;
  f1[7] = r0;
  f4[7] = r0;

  for (i = 0;i < 7;++i) {
    r0 = g[i];
    r1 = g[i + 8];
    r2 = g[i + 15];
    r3 = g[i + 23];
    vec u = r0 + r1;
    vec v = r2 + r3;
    g1[i] = r0 + r2;
    g1[i + 8] = r1 + r3;
    g2[i] = u;
    g3[i] = v;
    g4[i] = u + v;
  }
  r0 = g[7];
  r1 = g[22];
  g2[7] = r0;
  g3[7] = r1;
  r0 = r0 + r1;
  g1[7] = r0;
  g4[7] = r0;

  mult8(h,f,g);
  mult7(h + 16,f + 8,g + 8);
  mult8(h + 30,f + 15,g + 15);
  mult7(h + 46,f + 23,g + 23);
  mult8(u,f1,g1);
  mult7(u + 16,f1 + 8,g1 + 8);
  mult8(u2,f2,g2);
  mult8(u3,f3,g3);
  mult8(u4,f4,g4);

  h[16 - 1] = h[24 - 1] + h[i] + u2[i];
  h[30 + 16 - 1] = h[30 + 24 - 1] + h[30 + i] + u3[i];
  u[16 - 1] = u[24 - 1] + u[i] + u4[i];
  for (i = 0;i < 8 - 3;++i) {
    vec h0 = h[i];
    vec h12 = h[i + 8] + h[i + 16];
    vec h4 = h[i + 30];
    vec r = h12 + h0 + u2[i];
    h[i + 8] = r;
    h[i + 16] = h[i + 24] + h12 + u2[i + 8];
    vec h56 = h[i + 38] + h[i + 46];
    vec s = h56 + h4 + u3[i];
    h[i + 38] = s;
    h[i + 46] = h[i + 54] + h56 + u3[i + 8];
    vec u0 = u[i];
    vec u12 = u[i + 8] + u[i + 16];
    u[i + 16] = u[i + 24] + u12 + u4[i + 8];
    vec v = h[i + 15] + h4;
    h[i + 15] = v + h0 + u0;
    h[i + 30] = h[i + 45] + v + u[i + 15];
    vec w = h[i + 23] + s;
    h[i + 23] = w + r + u12 + u0 + u4[i];
    h[i + 38] = h[i + 53] + w + u[i + 23];
  }
  for (i = 8 - 3;i < 8 - 1;++i) {
    vec h12 = h[i + 8] + h[i + 16];
    h[i + 8] = h12 + h[i] + u2[i];
    h[i + 16] = h12 + u2[i + 8];
    vec h56 = h[i + 38] + h[i + 46];
    h[i + 38] = h56 + h[i + 30] + u3[i];
    h[i + 46] = h56 + u3[i + 8];
    vec u12 = u[i + 8] + u[i + 16];
    u[i + 8] = u12 + u[i] + u4[i];
    u[i + 16] = u12 + u4[i + 8];
  }
  for (i = 8 - 3;i < 8;++i) {
    vec v = h[i + 15] + h[i + 30];
    h[i + 15] = v + h[i] + u[i];
    h[i + 30] = h[i + 45] + v + u[i + 15];
  }
  for (i = 8 - 3;i < 8 - 2;++i) {
    vec w = h[i + 23] + h[i + 38];
    h[i + 23] = w + h[i + 8] + u[i + 8];
    h[i + 38] = h[i + 53] + w + u[i + 23];
  }
  h[30 - 1] = h[45 - 1] + h[15 - 1] + u[15 - 1];
}

// f1[28],ft[28+1],ft1[28+1],f[28]
void mult83_eval(vec *f1,vec *ft,vec *ft1,const vec *f)
{
  int i;
  vec c = f[28];
  ft[0] = f[0];
  f1[28 - 1] = f[28 - 1] + f[28 - 1 + 28];
  f1[0] = f[0] + f[0 + 28] + f[0 + 2 * 28];
  for (i = 1;i < 28 - 1;i += 2) {
    vec a = f[i];
    vec b = f[i + 28];
    vec d;
    vec e = f[i + 2 * 28];
    ft[i] = a + c;
    d = a + b + e;
    f1[i] = d;
    ft1[i] = d + c;
    c = b + f[2 * 28 + i - 1];
    a = f[i + 1];
    b = f[i + 1 + 28];
    ft[i + 1] = a + c;
    d = a + b + f[i + 1 + 2 * 28];
    f1[i + 1] = d;
    ft1[i + 1] = d + c;
    c = b + e;
  }
  ft[28 - 1] = f[28 - 1] + c;
  ft1[28 - 1] = f1[28 - 1] + c;
  c = f[28 + 28 - 1] + f[2 * 28 + 28 - 1 - 1];
  ft1[0] = f1[0];
  ft[28] = c;
  ft1[28] = c;
}

// h1[2*n-1],ht[2*n+1],ht1[2*n+1]; h0[2*n-1] in h; hinf[2*n-3] in h+4*n
void mult83_interp(vec *h,const vec *h1,const vec *ht,const vec *ht1)
{
  const int n = 28;
  int i;
  vec vsum;
  vec r[2 * n + 1];
  vec v[3 * n + 1]; 
  vec u[2 * n - 1]; 
  for (i = 0;i < 4;++i) {
    r[i] = ht[i] + ht1[i];
    r[i + n] = ht[i + n] + ht1[i + n];
  }
  for (i = 0;i < 1;++i) r[i + 2 * n] = ht[i + 2 * n] + ht1[i + 2 * n];
  for (i = n - 2;i < n;++i) r[i + n] = ht[i + n] + ht1[i + n];
  for (i = n - 2;i < n;++i) r[i] = ht[i] + ht1[i];
  vsum = h[1] + ht[1] + r[0] + h[4 * n];
  v[0] = vsum;
  for (i = 2;i < 4;++i) {
    vsum = vsum + h[i] + ht[i] + r[i - 1] + h[4 * n + i - 1];
    v[i - 1] = vsum;
  }
  for (i = 0;i < 1;++i) v[i + 2 * n] = ht[i + 2 * n] + r[i + 2 * n - 1] + r[i + n] + h[6 * n + i - 4];
  for (i = 1;i < 2;++i) v[i + 2 * n] = r[i + 2 * n - 1] + r[i + n];
  for (i = 2;i < 3;++i) v[i + 2 * n] = r[i + n];
  for (i = 3;i < 4;++i) v[i + 2 * n] = r[i + n];
  for (i = 0;i < 1;++i) v[i + 3 * n] = r[i + 2 * n];
  for (i = 0;i < 4;++i) {
    vec hin = h[i + n];
    vec c = hin + h[i] + h1[i];
    vec d = hin + h1[i + n];
    u[i] = c;
    u[i + n] = d;
    v[i + n] = ht[i + n] + r[i + n - 1] + r[i] + c + h[5 * n + i - 1] + h[5 * n + i - 4];
    v[i + 2 * n] = v[i + 2 * n] + d;
  }
  vec a = r[3];
  vec b = r[3 + n];
  for (i = 4;i < n - 2;++i) {
    vec hi = h[i];
    vec hin = h[i + n];
    vec hti = ht[i];
    vec htin = ht[i + n];
    vec e = h[4 * n + i - 1] + h[4 * n + i - 4] + a;
    vec f = h[5 * n + i - 1] + h[5 * n + i - 4] + b;
    a = hti + ht1[i];
    b = htin + ht1[i + n];
    vec c = hin + hi + h1[i];
    vec d = hin + h1[i + n];
    u[i] = c;
    u[i + n] = d;
    vsum = vsum + hti + hi + e;
    v[i - 1] = vsum;
    v[i + n] = htin + a + c + f;
    v[i + 2 * n] = b + d;
  }
  vsum = vsum + ht[n - 2] + a;
  v[n - 2 + n] = ht[n - 2 + n] + b + r[n - 2];
  for (i = n - 2;i < n - 1;++i) u[i] = h[i + n] + h[i] + h1[i];
  for (i = n - 2;i < n - 1;++i) u[i + n] = h[i + n] + h1[i + n];
  for (i = n - 2;i < n - 1;++i) vsum = vsum + h[i] + h[4 * n + i - 1] + h[4 * n + i - 4];
  for (i = n - 2;i < n - 1;++i) v[i + n] = v[i + n] + u[i] + h[5 * n + i - 4];
  for (i = n - 2;i < n - 1;++i) v[i + 2 * n] = r[i + n] + u[i + n];
  v[n - 3] = vsum;
  for (i = n - 1;i < n;++i) v[i + 2 * n] = r[i + n];
  for (i = n - 1;i < n;++i) u[i] = h[i] + h1[i];
  for (i = n - 1;i < n;++i) vsum = vsum + ht[i] + r[i - 1] + h[i] + h[4 * n + i - 1] + h[4 * n + i - 4];
  for (i = n - 1;i < n;++i) v[i + n] = ht[i + n] + r[i + n - 1] + r[i] + u[i] + h[5 * n + i - 4];
  v[n - 2] = vsum;

  vsum = vsum + v[n];
  v[n - 1] = vsum;
  for (i = 0;i < n;++i) { vsum = vsum + v[i + n + 1]; v[i + n] = vsum; }
  for (i = 0;i < n - 3;++i) {
    vec vi = v[i];
    vec vin = v[i + n];
    vec a = h[i + 4 * n];
    vsum = vsum + v[i + 2 * n + 1];
    h[i + n] = u[i] + a + vi;
    h[i + 2 * n] = u[i + n] + h[5 * n + i] + vin + vi;
    h[i + 3 * n] = vsum + vin;
    h[i + 4 * n] = vsum + a;
  }
  for (i = n - 3;i < n - 1;++i) { vsum = vsum + v[i + 2 * n + 1]; v[i + 2 * n] = vsum; }
  for (i = n - 3;i < n;++i) h[i + n] = u[i] + h[4 * n + i] + v[i];
  for (i = n - 3;i < n - 1;++i) h[i + 2 * n] = u[i + n] + v[i + n] + v[i];
  for (i = n - 1;i < n;++i) h[i + 2 * n] = v[i + n] + v[i];
  for (i = n - 3;i < n - 1;++i) h[i + 3 * n] = v[i + 2 * n] + v[i + n];
  for (i = n - 1;i < n;++i) h[i + 3 * n] = v[i + n];
  for (i = n - 3;i < n - 1;++i) h[i + 4 * n] = v[i + 2 * n] + h[i + 4 * n];
}

void mult83(vec *h,const vec *f,const vec *g)
{
  vec f1[28];
  vec g1[28];
  vec h1[2 * 28 - 1];
  vec ft[28 + 1];
  vec gt[28 + 1];
  vec ht[2 * 28 + 1];
  vec ft1[28 + 1];
  vec gt1[28 + 1];
  vec ht1[2 * 28 + 1];
  mult28(h,f,g);
  mult27(h + 4 * 28,f + 2 * 28,g + 2 * 28);
  mult83_eval(f1,ft,ft1,f);
  mult83_eval(g1,gt,gt1,g);
  mult28(h1,f1,g1);
  mult29(ht,ft,gt);
  mult29(ht1,ft1,gt1);
  mult83_interp(h,h1,ht,ht1);
}

// f1[28],ft[30],ft1[30]
void mult84_eval(vec *f1,vec *ft,vec *ft1,const vec *f)
{
  int i;
  vec fi;
  vec fi28;
  vec fi56;
  vec f12i;
  fi = f[0];
  fi28 = f[28];
  fi56 = f[56];
  f1[0] = fi + fi28 + fi56;
  ft[0] = fi;
  ft1[0] = f1[0];
  f12i = fi28;
  for (i = 1;i < 27;i += 2) {
    vec a;
    fi = f[i];
    fi28 = f[i + 28];
    a = fi28 + fi56;
    fi56 = f[i + 56];
    vec b = fi + fi28 + fi56;
    f1[i] = b;
    ft[i] = fi + f12i;
    ft1[i] = b + f12i;
    f12i = a;
    fi = f[i + 1];
    fi28 = f[i + 1 + 28];
    a = fi28 + fi56;
    fi56 = f[i + 1 + 56];
    b = fi + fi28 + fi56;
    f1[i + 1] = b;
    ft[i + 1] = fi + f12i;
    ft1[i + 1] = b + f12i;
    f12i = a;
  }
    vec a;
    fi = f[i];
    fi28 = f[i + 28];
    a = fi28 + fi56;
    fi56 = f[i + 56];
    vec b = fi + fi28 + fi56;
    f1[i] = b;
    ft[i] = fi + f12i;
    ft1[i] = b + f12i;
    f12i = a;
  ft[28] = f12i;
  ft[29] = fi56;
  ft1[28] = f12i;
  ft1[29] = fi56;
}

// h1[55],ht[59],ht1[59]; h0[55] already in h; hinf[55] already in h+2*56
void mult84_interp(vec *h,const vec *h1,const vec *ht,const vec *ht1)
{
  int i;
  vec r[57];
  vec v[85]; 
  vec u[55]; 
  vec vsum;

  for (i = 0;i < 4;++i) r[i] = ht[i] + ht1[i];
  for (i = 0;i < 4;++i) r[i + 28] = ht[i + 28] + ht1[i + 28];
  for (i = 0;i < 1;++i) r[i + 56] = ht[i + 56] + ht1[i + 56];
  for (i = 27;i < 28;++i) r[i] = ht[i] + ht1[i];
  for (i = 27;i < 28;++i) r[i + 28] = ht[i + 28] + ht1[i + 28];

  vsum = ht[1] + r[1 - 1] + h[1] + h[112 + 1 - 1];
  v[0] = vsum;
  vsum = vsum + ht[2] + r[2 - 1] + h[2] + h[112 + 2 - 1];
  v[1] = vsum;
  vsum = vsum + ht[3] + r[3 - 1] + h[3] + h[112 + 3 - 1];
  v[2] = vsum;
  for (i = 0;i < 4;++i) {
    vec ui = h[i + 28] + h[i] + h1[i];
    u[i] = ui;
    v[i + 28] = ht[i + 28] + r[i + 27] + r[i] + ui + h[140 + i - 1] + h[140 + i - 4];
  }
  for (i = 0;i < 2;++i) {
    vec ui28 = h[i + 28] + h1[i + 28];
    u[i + 28] = ui28;
    v[i + 56] = ht[i + 56] + r[i + 55] + r[i + 28] + ui28 + h[168 + i - 4];
  }
  for (i = 2;i < 3;++i) {
    vec ui28 = h[i + 28] + h1[i + 28];
    u[i + 28] = ui28;
    v[i + 56] = ht[i + 56] + r[i + 28] + ui28 + h[168 + i - 4];
  }
  for (i = 3;i < 4;++i) {
    vec ui28 = h[i + 28] + h1[i + 28];
    u[i + 28] = ui28;
    v[i + 56] = r[i + 28] + ui28;
  }
  for (i = 0;i < 1;++i) v[i + 84] = r[i + 56];

  vec a = r[3];
  vec b = r[3 + 28];
  for (i = 4;i < 27;++i) {
    vec hi = h[i];
    vec hi28 = h[i + 28];
    vec hti = ht[i];
    vec hti28 = ht[i + 28];
    vec e = h[112 + i - 4] + h[112 + i - 1] + a;
    vec f = h[140 + i - 4] + h[140 + i - 1] + b;
    a = hti + ht1[i];
    b = hti28 + ht1[i + 28];
    vec c = hi28 + hi + h1[i];
    vec d = hi28 + h1[i + 28];
    u[i] = c;
    u[i + 28] = d;
    vsum = vsum + hti + hi + e;
    v[i - 1] = vsum;
    v[i + 28] = hti28 + a + c + f;
    v[i + 56] = b + d;
  }
  for (i = 27;i < 28;++i) {
    vec vin;
    vsum = vsum + ht[i] + a;
    vin = ht[i + 28] + b + r[i];
    v[i + 56] = r[i + 28];
    u[i] = h[i] + h1[i];
    vsum = vsum + h[i];
    vin = vin + u[i];
    vsum = vsum + h[112 + i - 1];
    vin = vin + h[140 + i - 1];
    vsum = vsum + h[112 + i - 4];
    vin = vin + h[140 + i - 4];
    v[i + 28] = vin;
  }

  v[26] = vsum;
  vsum = vsum + v[28];
  v[27] = vsum;
  for (i = 0;i < 28;++i) {
    vsum = vsum + v[i + 29];
    v[i + 28] = vsum;
  }
  for (i = 0;i < 27;++i) {
    vec vi = v[i];
    vec vi28 = v[i + 28];
    vec a = h[i + 112];
    vsum = vsum + v[i + 57];
    h[i + 28] = u[i] + a + vi;
    h[i + 56] = u[i + 28] + h[140 + i] + vi28 + vi;
    h[i + 84] = vsum + vi28;
    h[i + 112] = vsum + a;
  }
  for (i = 27;i < 28;++i) {
    vec vi = v[i];
    vec vin = v[i + 28];
    h[i + 28] = u[i] + h[112 + i] + vi;
    h[i + 56] = vin + vi;
    h[i + 84] = vin;
  }
}

void mult84(vec *h,const vec *f,const vec *g)
{
  vec f1[28];
  vec g1[28];
  vec h1[55];
  vec ft[30];
  vec gt[30];
  vec ht[59];
  vec ft1[30];
  vec gt1[30];
  vec ht1[59];
  mult28(h,f,g);
  mult28(h + 2 * 56,f + 56,g + 56);
  mult84_eval(f1,ft,ft1,f);
  mult84_eval(g1,gt,gt1,g);
  mult28(h1,f1,g1);
  mult30(ht,ft,gt);
  mult30(ht1,ft1,gt1);
  mult84_interp(h,h1,ht,ht1);
}

// f1[29],ft[29+1],ft1[29+1],f[29]
void mult85_eval(vec *f1,vec *ft,vec *ft1,const vec *f)
{
  int i;
  vec c;
  vec fi29;
  vec fi;
  vec f1i;
  vec fi58;
  vec fi59;

  for (i = 0;i < 2;++i) f1[i] = f[i] + f[i + 29] + f[i + 2 * 29];
  f1[29 - 2] = f[29 - 2] + f[29 - 2 + 29];
  f1[29 - 1] = f[29 - 1] + f[29 - 1 + 29];
  ft[0] = f[0];

  c = f[29];
  ft[1] = f[1] + c;
  ft1[1] = f1[1] + c;

  fi29 = f[30];
  fi58 = f[58];
  fi59 = f[59];
  for (i = 2;i < 29 - 3;i += 2) {
    fi = f[i];
    c = fi29 + fi58;
    fi29 = f[i + 29];
    fi58 = f[i + 58];
    f1i = fi + fi29 + fi58;
    f1[i] = f1i;
    ft[i] = fi + c;
    ft1[i] = f1i + c;
    fi = f[i + 1];
    c = fi29 + fi59;
    fi29 = f[i + 30];
    fi59 = f[i + 59];
    f1i = fi + fi29 + fi59;
    f1[i + 1] = f1i;
    ft[i + 1] = fi + c;
    ft1[i + 1] = f1i + c;
  }
  for (i = 29 - 3;i < 29 - 2;++i) {
    vec fi = f[i];
    vec f1i;
    c = fi29 + f[2 * 29 + i - 2];
    fi29 = f[i + 29];
    f1i = fi + fi29 + f[i + 2 * 29];
    f1[i] = f1i;
    ft[i] = fi + c;
    ft1[i] = f1i + c;
  }
  for (i = 29 - 2;i < 29;++i) {
    c = f[29 + i - 1] + f[2 * 29 + i - 2];
    ft[i] = f[i] + c;
    ft1[i] = f1[i] + c;
  }

  c = f[29 + 29 - 1];
  ft1[0] = f1[0];
  ft[29] = c;
  ft1[29] = c;
}

// h1[2*n-1],ht[2*n+1],ht1[2*n+1]; h0[2*n-1] in h; hinf[2*n-5] in h+4*n
void mult85_interp(vec *h,const vec *h1,const vec *ht,const vec *ht1)
{
  int i;
  const int n = 29;
  vec r[2 * n + 1];
  vec v[3 * n + 1]; 
  vec u[2 * n - 1]; 
  vec vsum;

  for (i = 0;i < 4;++i) r[i] = ht[i] + ht1[i];
  for (i = n - 4;i < n;++i) r[i] = ht[i] + ht1[i];
  for (i = 0;i < 4;++i) r[i + n] = ht[i + n] + ht1[i + n];
  for (i = n - 4;i < n;++i) r[i + n] = ht[i + n] + ht1[i + n];

  for (i = 0;i < 1;++i) r[i + 2 * n] = ht[i + 2 * n] + ht1[i + 2 * n];
  vsum = ht[1] + r[0] + h[1] + h[4 * n];
  v[0] = vsum;
  for (i = 2;i < 4;++i) {
    vsum = vsum + ht[i] + r[i - 1] + h[i] + h[4 * n + i - 1];
    v[i - 1] = vsum;
  }
  for (i = 0;i < 1;++i) v[i + 2 * n] = ht[i + 2 * n] + r[i + 2 * n - 1] + r[i + n];
  for (i = 1;i < 2;++i) v[i + 2 * n] = r[i + 2 * n - 1] + r[i + n];
  for (i = 2;i < 3;++i) v[i + 2 * n] = r[i + n];
  for (i = 3;i < 4;++i) v[i + 2 * n] = r[i + n];
  for (i = 0;i < 1;++i) v[i + 3 * n] = r[i + 2 * n];
  for (i = 0;i < 4;++i) {
    u[i] = h[i + n] + h[i] + h1[i];
    u[i + n] = h[i + n] + h1[i + n];
    v[i + n] = ht[i + n] + r[i + n - 1] + r[i];
    v[i + n] = v[i + n] + u[i];
    v[i + n] = v[i + n] + h[5 * n + i - 1];
    v[i + n] = v[i + n] + h[5 * n + i - 4];
    v[i + 2 * n] = v[i + 2 * n] + u[i + n];
  }

  vec a = r[3];
  vec b = r[3 + n];
  for (i = 4;i < n - 4;++i) {
    vec hi = h[i];
    vec hin = h[i + n];
    vec hti = ht[i];
    vec htin = ht[i + n];
    vec e = h[4 * n + i - 1] + h[4 * n + i - 4] + a;
    vec f = h[5 * n + i - 1] + h[5 * n + i - 4] + b;
    a = hti + ht1[i];
    b = htin + ht1[i + n];
    vec c = hin + hi + h1[i];
    vec d = hin + h1[i + n];
    u[i] = c;
    u[i + n] = d;
    vsum = vsum + hti + hi + e;
    v[i - 1] = vsum;
    v[i + n] = htin + a + c + f;
    v[i + 2 * n] = b + d;
  }

  r[n - 5] = a;
  r[2 * n - 5] = b;

  for (i = n - 4;i < n - 1;++i) {
    vec hi = h[i];
    vec hin = h[i + n];
    vec hti = ht[i];
    vec htin = ht[i + n];
    vec c = hin + hi + h1[i];
    vec d = hin + h1[i + n];
    u[i] = c;
    u[i + n] = d;
    vsum = vsum + hti + r[i - 1] + hi + h[4 * n + i - 1] + h[4 * n + i - 4];
    v[i - 1] = vsum;
    v[i + n] = htin + r[i + n - 1] + r[i] + c + h[5 * n + i - 4];
    v[i + 2 * n] = r[i + n] + d;
  }
  for (i = n - 1;i < n;++i) vsum = vsum + ht[i] + r[i - 1] + h[i] + h[4 * n + i - 1] + h[4 * n + i - 4];
  for (i = n - 1;i < n;++i) v[i + 2 * n] = r[i + n];
  for (i = n - 1;i < n;++i) u[i] = h[i] + h1[i];
  for (i = n - 1;i < n;++i) v[i + n] = ht[i + n] + r[i + n - 1] + r[i] + u[i];

  v[n - 2] = vsum;
  vsum = vsum + v[n];
  v[n - 1] = vsum;

  for (i = 0;i < n;++i) { vsum = vsum + v[i + n + 1]; v[i + n] = vsum; }

  for (i = 0;i < n - 5;++i) {
    vec vi = v[i];
    vec vin = v[i + n];
    vec a = h[4 * n + i];
    vsum = vsum + v[i + 2 * n + 1];
    h[i + n] = u[i] + a + vi;
    h[i + 2 * n] = u[i + n] + h[5 * n + i] + vin + vi;
    h[i + 3 * n] = vsum + vin;
    h[i + 4 * n] = vsum + a;
  }

  for (i = n - 5;i < n - 1;++i) {
    vec vi = v[i];
    vec vin = v[i + n];
    vsum = vsum + v[i + 2 * n + 1];
    v[i + 2 * n] = vsum;
    h[i + n] = u[i] + h[4 * n + i] + vi;
    h[i + 2 * n] = u[i + n] + vin + v[i];
    h[i + 3 * n] = vsum + vin;
    h[i + 4 * n] = vsum + h[4 * n + i];
  }
  for (i = n - 1;i < n;++i) h[i + n] = u[i] + h[4 * n + i] + v[i];
  for (i = n - 1;i < n;++i) h[i + 2 * n] = v[i + n] + v[i];
  for (i = n - 1;i < n;++i) h[i + 3 * n] = v[i + n];
}

void mult85(vec *h,const vec *f,const vec *g)
{
  vec f1[29];
  vec g1[29];
  vec h1[2 * 29 - 1];
  vec ft[29 + 1];
  vec gt[29 + 1];
  vec ht[2 * 29 + 1];
  vec ft1[29 + 1];
  vec gt1[29 + 1];
  vec ht1[2 * 29 + 1];
  mult27(h + 4 * 29,f + 2 * 29,g + 2 * 29);
  mult85_eval(f1,ft,ft1,f);
  mult85_eval(g1,gt,gt1,g);
  mult29(h,f,g);
  mult29(h1,f1,g1);
  mult30(ht,ft,gt);
  mult30(ht1,ft1,gt1);
  mult85_interp(h,h1,ht,ht1);
}

// f1[84],ft[84+1],ft1[84+1],f[84]
void mult251_eval(vec *f1,vec *ft,vec *ft1,const vec *f)
{
  int i;
  vec f0 = f[0];
  vec c = f[84];
  ft[0] = f0;
  f1[84 - 1] = f[84 - 1] + f[84 - 1 + 84];
  f1[0] = f0 + c + f[0 + 2 * 84];
  for (i = 1;i < 84 - 1;i += 2) {
    vec a = f[i];
    vec b = f[i + 84];
    vec d;
    vec e = f[i + 2 * 84];
    ft[i] = a + c;
    d = a + b + e;
    f1[i] = d;
    ft1[i] = d + c;
    c = b + f[2 * 84 + i - 1];
    a = f[i + 1];
    b = f[i + 1 + 84];
    ft[i + 1] = a + c;
    d = a + b + f[i + 1 + 2 * 84];
    f1[i + 1] = d;
    ft1[i + 1] = d + c;
    c = b + e;
  }
  ft[84 - 1] = f[84 - 1] + c;
  ft1[84 - 1] = f1[84 - 1] + c;
  c = f[84 + 84 - 1] + f[2 * 84 + 84 - 1 - 1];
  ft1[0] = f1[0];
  ft[84] = c;
  ft1[84] = c;
}

// h1[2*n-1],ht[2*n+1],ht1[2*n+1]; h0[2*n-1] in h; hinf[2*n-3] in h+4*n
void mult251_interp(vec *h,const vec *h1,const vec *ht,const vec *ht1)
{
  const int n = 84;
  int i;
  vec vsum;
  vec r[2 * n + 1];
  vec v[3 * n + 1]; 
  vec u[2 * n - 1]; 
  for (i = 0;i < 4;++i) r[i] = ht[i] + ht1[i];
  for (i = 0;i < 4;++i) r[i + n] = ht[i + n] + ht1[i + n];
  for (i = 0;i < 1;++i) r[i + 2 * n] = ht[i + 2 * n] + ht1[i + 2 * n];
  for (i = n - 2;i < n;++i) r[i + n] = ht[i + n] + ht1[i + n];
  for (i = n - 2;i < n;++i) r[i] = ht[i] + ht1[i];
  vsum = h[1] + ht[1] + r[0] + h[4 * n];
  v[0] = vsum;
  for (i = 2;i < 4;++i) {
    vsum = vsum + h[i] + ht[i] + r[i - 1] + h[4 * n + i - 1];
    v[i - 1] = vsum;
  }
  for (i = 0;i < 1;++i) v[i + 2 * n] = ht[i + 2 * n] + r[i + 2 * n - 1] + r[i + n] + h[6 * n + i - 4];
  for (i = 1;i < 2;++i) v[i + 2 * n] = r[i + 2 * n - 1] + r[i + n];
  for (i = 2;i < 3;++i) v[i + 2 * n] = r[i + n];
  for (i = 3;i < 4;++i) v[i + 2 * n] = r[i + n];
  for (i = 0;i < 1;++i) v[i + 3 * n] = r[i + 2 * n];
  for (i = 0;i < 4;++i) {
    vec hin = h[i + n];
    vec c = hin + h[i] + h1[i];
    vec d = hin + h1[i + n];
    u[i] = c;
    u[i + n] = d;
    v[i + n] = ht[i + n] + r[i + n - 1] + r[i] + c + h[5 * n + i - 1] + h[5 * n + i - 4];
    v[i + 2 * n] = v[i + 2 * n] + d;
  }
  vec a = r[3];
  vec b = r[3 + n];
  for (i = 4;i < n - 2;++i) {
    vec hi = h[i];
    vec hin = h[i + n];
    vec hti = ht[i];
    vec htin = ht[i + n];
    vec e = h[4 * n + i - 1] + h[4 * n + i - 4] + a;
    vec f = h[5 * n + i - 1] + h[5 * n + i - 4] + b;
    a = hti + ht1[i];
    b = htin + ht1[i + n];
    vec c = hin + hi + h1[i];
    vec d = hin + h1[i + n];
    u[i] = c;
    u[i + n] = d;
    vsum = vsum + hti + hi + e;
    v[i - 1] = vsum;
    v[i + n] = htin + a + c + f;
    v[i + 2 * n] = b + d;
  }
  vsum = vsum + ht[n - 2] + a;
  v[n - 2 + n] = ht[n - 2 + n] + b + r[n - 2];
  for (i = n - 2;i < n - 1;++i) u[i] = h[i + n] + h[i] + h1[i];
  for (i = n - 2;i < n - 1;++i) u[i + n] = h[i + n] + h1[i + n];
  for (i = n - 2;i < n - 1;++i) vsum = vsum + h[i] + h[4 * n + i - 1] + h[4 * n + i - 4];
  for (i = n - 2;i < n - 1;++i) v[i + n] = v[i + n] + u[i] + h[5 * n + i - 4];
  for (i = n - 2;i < n - 1;++i) v[i + 2 * n] = r[i + n] + u[i + n];
  v[n - 3] = vsum;
  for (i = n - 1;i < n;++i) v[i + 2 * n] = r[i + n];
  for (i = n - 1;i < n;++i) u[i] = h[i] + h1[i];
  for (i = n - 1;i < n;++i) vsum = vsum + ht[i] + r[i - 1] + h[i] + h[4 * n + i - 1] + h[4 * n + i - 4];
  for (i = n - 1;i < n;++i) v[i + n] = ht[i + n] + r[i + n - 1] + r[i] + u[i] + h[5 * n + i - 4];
  v[n - 2] = vsum;

  vsum = vsum + v[n];
  v[n - 1] = vsum;
  for (i = 0;i < n;++i) { vsum = vsum + v[i + n + 1]; v[i + n] = vsum; }
  for (i = 0;i < n - 3;++i) {
    vec vi = v[i];
    vec vin = v[i + n];
    vec a = h[i + 4 * n];
    vsum = vsum + v[i + 2 * n + 1];
    h[i + n] = u[i] + a + vi;
    h[i + 2 * n] = u[i + n] + h[5 * n + i] + vin + vi;
    h[i + 3 * n] = vsum + vin;
    h[i + 4 * n] = vsum + a;
  }
  for (i = n - 3;i < n - 1;++i) { vsum = vsum + v[i + 2 * n + 1]; v[i + 2 * n] = vsum; }
  for (i = n - 3;i < n;++i) h[i + n] = u[i] + h[4 * n + i] + v[i];
  for (i = n - 3;i < n - 1;++i) h[i + 2 * n] = u[i + n] + v[i + n] + v[i];
  for (i = n - 1;i < n;++i) h[i + 2 * n] = v[i + n] + v[i];
  for (i = n - 3;i < n - 1;++i) h[i + 3 * n] = v[i + 2 * n] + v[i + n];
  for (i = n - 1;i < n;++i) h[i + 3 * n] = v[i + n];
  for (i = n - 3;i < n - 1;++i) h[i + 4 * n] = v[i + 2 * n] + h[i + 4 * n];
}

void mult251(vec *h,const vec *f,const vec *g)
{
  vec f1[84];
  vec g1[84];
  vec h1[2 * 84 - 1];
  vec ft[84 + 1];
  vec gt[84 + 1];
  vec ht[2 * 84 + 1];
  vec ft1[84 + 1];
  vec gt1[84 + 1];
  vec ht1[2 * 84 + 1];
  mult84(h,f,g);
  mult83(h + 4 * 84,f + 2 * 84,g + 2 * 84);
  mult251_eval(f1,ft,ft1,f);
  mult251_eval(g1,gt,gt1,g);
  mult84(h1,f1,g1);
  mult85(ht,ft,gt);
  mult85(ht1,ft1,gt1);
  mult251_interp(h,h1,ht,ht1);
}

void fieldelement::set_0(void)
{
  int i;
  __m128i v = _mm_set_epi32(0,0,0,0);
  for (i = 0;i < 251;++i) x[i] = v;
}

void fieldelement::set_1(void)
{
  int i;
  __m128i v = _mm_set_epi32(0,0,0,0);
  for (i = 0;i < 251;++i) x[i] = v;
  x[0] = _mm_set_epi32(0xffffffff,0xffffffff,0xffffffff,0xffffffff);
}

// overlap ok
void fieldelement::add (fieldelement &result,const fieldelement &b) const
{
  int i;
  for (i = 0;i < 248;i += 4) {
    vec r0 = (*this).x[i];
    vec r1 = (*this).x[i + 1];
    vec r2 = (*this).x[i + 2];
    vec r3 = (*this).x[i + 3];
    r0 = r0 + b.x[i];
    r1 = r1 + b.x[i + 1];
    r2 = r2 + b.x[i + 2];
    r3 = r3 + b.x[i + 3];
    result.x[i] = r0;
    result.x[i + 1] = r1;
    result.x[i + 2] = r2;
    result.x[i + 3] = r3;
  }
  for (i = 248;i < 251;++i) { result.x[i] = (*this).x[i] + b.x[i]; }
}

inline void conditionalswap(fieldelement &a,fieldelement &b,vec control)
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

inline void conditionalswap2(fieldelement &a,fieldelement &b,fieldelement &c,fieldelement &d,fieldelement &ac,fieldelement &bd,vec control)
{
  int i;
  for (i = 0;i < 251;++i) {
    vec a0 = a.x[i];
    vec b0 = b.x[i];
    vec c0 = c.x[i];
    vec d0 = d.x[i];
    vec z0 = a0 + b0;
    z0 = z0 * control;
    a0 = a0 + z0;
    b0 = b0 + z0;
    vec y0 = c0 + d0;
    y0 = y0 * control;
    c0 = c0 + y0;
    d0 = d0 + y0;
    a.x[i] = a0;
    b.x[i] = b0;
    c.x[i] = c0;
    d.x[i] = d0;
    ac.x[i] = a0 + c0;
    bd.x[i] = b0 + d0;
  }
}

fieldelement operator+(const fieldelement &a,const fieldelement &b)
{
  fieldelement result;
  a.add(result,b);
  return result;
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
  vec *h = result.x;
  const vec *y = c.x;
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
 	
 	for (i = 13;i < 20;++i) h[i] = x[i] + x[i - 1] + x[i - 2] + x[i - 7] + x[i - 8] + x[i - 9] + x[i - 13];
 	for (i = 20;i < 251;++i) h[i] = x[i] + x[i - 1] + x[i - 2] + x[i - 7] + x[i - 8] + x[i - 9] + x[i - 13] + y[i];
 	
  	vec a;
  	vec r[20];
  
  	i = 251;
  
  	a = x[i - 1] + x[i - 2] + x[i - 7] + x[i - 8] + x[i - 9] + x[i - 13];
  	h[0] = h[0] + a + y[0];
  	r[2] = h[2] + a;
	r[4] = h[4] + a;
	r[7] = h[7] + a;
	
	a = x[i - 1] + x[i - 6] + x[i - 7] + x[i - 8] + x[i - 12];
	h[1] = h[1] + a + y[1];
  	r[3] = h[3] + a;
	r[5] = h[5] + a;
	r[8] = h[8] + a;
	
	a = x[i - 5] + x[i - 6] + x[i - 7] + x[i - 11];
	h[2] = r[2] + a + y[2];
  	r[4] = r[4] + a;
	r[6] = h[6] + a;
	r[9] = h[9] + a;
	
	a = x[i - 4] + x[i - 5] + x[i - 6] + x[i - 10];
	h[3] = r[3] + a + y[3];
  	r[5] = r[5] + a;
	r[7] = r[7] + a;
	r[10] = h[10] + a;
	
	a = x[i - 3] + x[i - 4] + x[i - 5] + x[i - 9];
	h[4] = r[4] + a + y[4];
  	r[6] = r[6] + a;
	r[8] = r[8] + a;
	r[11] = h[11] + a;

	a = x[i - 2] + x[i - 3] + x[i - 4] + x[i - 8];
	h[5] = r[5] + a + y[5];
  	r[7] = r[7] + a;
	r[9] = r[9] + a;
	r[12] = h[12] + a;

	a = x[i - 1] + x[i - 2] + x[i - 3] + x[i - 7];
	h[6] = r[6] + a + y[6];
  	r[8] = r[8] + a;
	r[10] = r[10] + a;
	r[13] = h[13] + a;

	a = x[i - 1] + x[i - 2] + x[i - 6];
	h[7] = r[7] + a + y[7];
  	r[9] = r[9] + a;
	r[11] = r[11] + a;
	r[14] = h[14] + a;

 	a = x[i - 1] + x[i - 5];
 	h[8] = r[8] + a + y[8];
  	r[10] = r[10] + a;
	r[12] = r[12] + a;
	r[15] = h[15] + a;
 	
	
	a = x[i - 4];
	h[9] = r[9] + a + y[9];
  	r[11] = r[11] + a;
	r[13] = r[13] + a;
	r[16] = h[16] + a;
	
	
	
	a = x[i - 3];
	h[10] = r[10] + a + y[10];
  	r[12] = r[12] + a;
	r[14] = r[14] + a;
	r[17] = h[17] + a;
	
	
	
	a = x[i - 2];
	h[11] = r[11] + a + y[11];
  	r[13] = r[13] + a;
	r[15] = r[15] + a;
	r[18] = h[18] + a;
	

	a = x[i - 1];
	h[12] = r[12] + a + y[12];
  	r[14] = r[14] + a;
	r[16] = r[16] + a;
	r[19] = h[19] + a;
	
	h[13] = r[13] + y[13];
	h[14] = r[14] + y[14];
	h[15] = r[15] + y[15];
	h[16] = r[16] + y[16];
	h[17] = r[17] + y[17];
	h[18] = r[18] + y[18];
	h[19] = r[19] + y[19]; 
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
  (*this).putsquare(u);
  (*this).multiply(v,u);
  v.putsquare(u);
  (*this).multiply(w,u);
  w.putsquare(u); u.putsquare(v); v.putsquare(u);
  w.multiply(v,u);
  v.putsquare(w); w.putsquare(u);
  for (i = 8;i < 12;i += 2) { u.putsquare(w); w.putsquare(u); }
  v.multiply(w,u);
  w.putsquare(u); u.putsquare(v);
  for (i = 14;i < 24;i += 2) { v.putsquare(u); u.putsquare(v); }
  v.multiply(u,w);
  u.putsquare(v);
  (*this).multiply(w,v);
  w.putsquare(u);
  for (i = 26;i < 50;i += 2) { u.putsquare(v); v.putsquare(u); }
  w.multiply(r,u);
  r.putsquare(v); v.putsquare(u);
  for (i = 52;i < 100;i += 2) { u.putsquare(v); v.putsquare(u); }
  r.multiply(v,u);
  v.putsquare(u);
  for (i = 101;i < 125;i += 2) { u.putsquare(v); v.putsquare(u); }
  w.multiply(v,u);
  v.putsquare(u);
  for (i = 126;i < 250;i += 2) { u.putsquare(w); w.putsquare(u); }
  v.multiply(w,u);
  w.putsquare(u);
  return u;
}
/*
fieldelement fieldelement::bbk251(const vec n[251])
{
  fieldelement Z2; Z2.set_1();
  fieldelement W2; W2.set_0();
  fieldelement W3; W3 = *this;
  fieldelement Z3; Z3.set_1();
  fieldelement T0,T1;
  fieldelement T2,T3;
  vec control = n[250];
  int i=250;
  conditionalswap2(W2,W3,Z2,Z3,T1,T0,n[250]);
  for (;;) {
    	//T0 = (W3 + Z3);
    	//T1 = T0 * (W2 + Z2);
    	T1.multiply(T0,T1);
    	
    	//T1 = T1.square();
    	T1.putsquare(T1);
    	
    	//Z2 = (W2 * Z3) + (W3 * Z2);
    	T2.multiply(W2,Z3);
    	Z2.multiply(W3,Z2);
    	Z2.add(Z2,T2);
    	
    	//Z2 = Z2.square();
    	Z2.putsquare(Z2);
    	
    	//W2 = T1 + Z2;
    	W2.add(T1,Z2);
    	
    	//Z2 = Z2 * (*this);
    	Z2.multiply(Z2,*this);
    	
    	//Z3 = (W3 * Z3).square();
    	Z3.multiply(W3,Z3);
    	Z3.putsquare(Z3);
    	
    	//W3 = T0.square().square().times_d();
	W3.putsquare(T0);
	W3.putsquare(W3);
	W3.times_d(W3);
	
    if (!i) break;
    conditionalswap2(W2,W3,Z2,Z3,T1,T0,n[i] + n[i - 1]);
    --i;
  }
  conditionalswap(W2,W3,n[0]);
  conditionalswap(Z2,Z3,n[0]);
  return W2 * Z2.inverse();
}*/

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
