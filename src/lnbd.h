/* lnbd.h */
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  double orbit;
  char name[16];
} sat_t;

typedef const char *str_t;

#define find_sat(x)                                                            \
  _Generic((x),                                                                \
      char *: find_sat_by_name,                                                \
      const char *: find_sat_by_name,                                          \
      int: find_sat_by_orbit,                                                  \
      float: find_sat_by_orbit,                                                \
      double: find_sat_by_orbit)(x)
