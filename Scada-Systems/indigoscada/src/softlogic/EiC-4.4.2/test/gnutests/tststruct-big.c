#include "forgnuport.h"

typedef struct {int a, b, c, d, e;} T;

void h (T *x);
T g (T x);

void h (T *x)
{
  if (x->a != 0 || x->b != 1 || x->c != 2 || x->d != 3 || x->e != 4)
    abort ();
}


T g (T x)
{
  if (x.a != 13 || x.b != 47 || x.c != 123456 || x.d != -4711 || x.e != -2)
    abort ();
  x.a = 0;
  x.b = 1;
  x.c = 2;
  x.d = 3;
  x.e = 4;
  h (&x);
  return x;
}


void f ()
{
  T x;
  x.a = 13;
  x.b = 47;
  x.c = 123456;
  x.d = -4711;
  x.e = -2;
  g (x);
  if (x.a != 13 || x.b != 47 || x.c != 123456 || x.d != -4711 || x.e != -2)
    abort ();
  x = g (x);
  if (x.a != 0 || x.b != 1 || x.c != 2 || x.d != 3 || x.e != 4)
    abort ();
}


int main (void)
{
  f ();
  return 0;
}

#ifdef EiCTeStS
main();
#endif
