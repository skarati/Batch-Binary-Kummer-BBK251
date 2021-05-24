#include <stdio.h>
#include <stdlib.h>
#include "bbk251.h"

int main()
{
  unsigned char npstr[8][128][32];
  unsigned char pstr[8][128][32];
  unsigned char nstr[8][128][32];
  int batch;
  int i;
  int j;

  for (batch = 0;batch < 8;++batch) {
    for (i = 0;i < 128;++i) for (j = 0;j < 32;++j) npstr[batch][i][j] = random();
    for (i = 0;i < 128;++i) for (j = 0;j < 32;++j) pstr[batch][i][j] = random();
    for (i = 0;i < 128;++i) for (j = 0;j < 32;++j) nstr[batch][i][j] = random();
  }

  for (batch = 0;batch < 8;++batch) {
    bbk251(npstr[batch],pstr[batch],nstr[batch]);
  }
  
  printf("\n");

  for (batch = 0;batch < 8;++batch)
    for (i = 0;i < 128;++i) {
      printf("n=0");
      for (j = 0;j < 251;++j) if (nstr[batch][i][j / 8] & (1 << (j & 7))) printf("+2^%d",j);
      printf("\n");
      printf("w=0");
      for (j = 0;j < 251;++j) if (pstr[batch][i][j / 8] & (1 << (j & 7))) printf("+t^%d",j);
      printf("\n");
      printf("nw=0");
      for (j = 0;j < 251;++j) if (npstr[batch][i][j / 8] & (1 << (j & 7))) printf("+t^%d",j);
      printf("\n");
      printf("\n");
    }

  return 0;
}
