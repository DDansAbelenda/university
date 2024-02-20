/******************************************************************************
 * FILE: omp_error_1.c
 ******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 50
#define CHUNKSIZE 5

int main(int argc, char *argv[])
{
  int i, chunk, tid;
  float a[N], b[N], c[N];

  /* Some initializations */
  for (i = 0; i < N; i++)
    a[i] = b[i] = i * 1.0;
  chunk = CHUNKSIZE;

#pragma omp parallel for shared(a, b, c, chunk) private(i, tid) schedule(static, chunk)
  {
   // tid = omp_get_thread_num();
   // la directiva omp parallel for solo debe ser precedida por un ciclo for
    for (i = 0; i < N; i++)
    {
      tid = omp_get_thread_num(); // es innecesario su uso en cada iteración
      c[i] = a[i] + b[i];
      printf("tid= %d i= %d c[i]= %f\n", tid, i, c[i]);
    }
  } /* end of parallel for construct */
}
