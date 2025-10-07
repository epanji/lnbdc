#include <math.h>
#include <stdio.h>
// #include <stdlib.h>

typedef struct {
  double orbit;
  char *name;
} sat_t;

double deg_to_rad(int deg) { return (deg % 360) * (M_PI / 180); }

double trigonometri_sin(int deg) { return sin(deg_to_rad(deg)); }

double trigonometri_cos(int deg) { return cos(deg_to_rad(deg)); }

float feet_to_centimeters(float ft) { return 30.48 * ft; }

int main() {
  printf("sin  30   : %f\n", trigonometri_sin(30));
  printf("sin -30   : %f\n", trigonometri_sin(-30));
  printf("cos  30   : %f\n", trigonometri_cos(30));
  printf("cos -30   : %f\n", trigonometri_cos(-30));
  printf("ft2cm 9   : %f\n", feet_to_centimeters(9));
  printf("ft2cm 9.2 : %f\n", feet_to_centimeters(9.2));
  sat_t a[] = {{102.0, "palapa 2"}, {89, "asiasat"}};
  printf("sat_t 0   : {%.1f, '%s'}\n", a[0].orbit, a[0].name);
  printf("sat_t 1   : {%.1f, '%s'}\n", a[1].orbit, a[1].name);
  return 0;
}
