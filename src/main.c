/* main.c */
#include "lnbd.h"

sat_t sats[] = {
    {057.0, "NSS 12"},      {064.2, "Intelsat 906"}, {066.0, "Intelsat 17"},
    {068.5, "Intelsat 20"}, {070.5, "Eutelsat 70B"}, {075.0, "ABS 2"},
    {076.5, "Apstar 7"},    {078.5, "Thaicom 5"},    {078.5, "Thaicom 6"},
    {087.5, "ChinaSat 12"}, {088.0, "ST 2"},         {091.5, "Measat 3"},
    {091.5, "Measat 3a"},   {091.5, "Measat 3B"},    {093.5, "G Sat 17"},
    {093.5, "Insat 4B"},    {095.0, "NSS 6"},        {096.5, "Express AM33"},
    {098.0, "ChinaSat 11"}, {100.5, "AsiaSat 5"},    {105.5, "AsiaSat 7"},
    {108.2, "SES 7"},       {108.2, "SES 9"},        {108.2, "Telkom 4"},
    {110.5, "ChinaSat 10"}, {113.0, "Palapa D"},     {115.5, "ChinaSat 6B"},
    {118.0, "Telkom 3S"},   {119.5, "Thaicom 4"},    {120.0, "Thaicom 7"},
    {122.2, "AsiaSat 9"},   {124.0, "JCSAT 4B"},     {125.0, "ChinaSat 6A"},
    {128.0, "Laosat 1"},    {128.0, "JCSAT 3A"},     {132.0, "Vinasat 1"},
    {134.0, "Apstar 6"},    {138.0, "Telstar 18"},   {142.0, "Apstar 9"},
    {154.0, "JCSAT 2A"},    {159.0, "ABS 6"},        {166.0, "Intelsat 19"},
    {169.0, "Intelsat 8"},  {172.0, "Eutelsat 172A"}};

sat_t find_sat_by_orbit(double_t arg) {
  size_t len = sizeof(sats) / sizeof(sat_t);
  sat_t result, alt = sats[0];
  int i;
  for (i = 0; i < len; i++) {
    result = sats[i];
    if (result.orbit == arg) {
      return result;
    } else if (result.orbit < arg) {
      if (alt.orbit < result.orbit) {
        alt = result;
      }
    }
  }
  return alt;
}

sat_t find_sat_by_name(str_t name) {
  size_t lname = strlen(name);
  size_t len = sizeof(sats) / sizeof(sat_t);
  sat_t result, alt = sats[0];
  int i;
  for (i = 0; i < len; i++) {
    result = sats[i];
    if ((strncasecmp(result.name, name, lname)) == 0) {
      return result;
    } else if ((strncasecmp(result.name, name, 1)) == 0) {
      alt = result;
    }
  }
  return alt;
}

double deg_to_rad(double_t deg) {
  double rad = fmod(deg, 360) * (M_PI / 180);
  return rad;
}

double tsin(double_t deg) {
  double result = sin(deg_to_rad(deg));
  return result;
}

double tcos(double_t deg) {
  double result = cos(deg_to_rad(deg));
  return result;
}

double ft_to_cm(double_t ft) {
  double result = 30.48 * ft;
  return result;
}

double focal_length(double_t diameter, double_t depth) {
  double result = (diameter * diameter) / (16 * depth);
  return result;
}

double radius(double_t diameter, double_t depth) {
  double result = (depth / 2) + (diameter * diameter) / (8 * depth);
  return result;
}

double distance_two_lnb(double_t from, double_t to, double_t radius,
                        double_t focal) {
  double result = deg_to_rad(fabs(to - from)) * (radius - focal);
  return result;
}

int main() {
  printf("sin  30   : %f\n", tsin(30));
  printf("sin -30   : %f\n", tsin(-30));
  printf("cos  30   : %f\n", tcos(30));
  printf("cos -30   : %f\n", tcos(-30));
  printf("ft2cm 9   : %f\n", ft_to_cm(9));
  printf("ft2cm 9.2 : %f\n", ft_to_cm(9.2));
  printf("sat_t 0   : {%.1f, '%s'}\n", sats[0].orbit, sats[0].name);
  printf("sat_t 1   : {%.1f, '%s'}\n", sats[1].orbit, sats[1].name);
  printf("length sat_t : %d\n", (int)sizeof(sat_t));
  sat_t x = find_sat_by_orbit(108.9);
  printf("orbit : %.1f\n", x.orbit);
  printf("name  : '%s'\n", x.name);
  sat_t y = find_sat_by_name("palapa");
  printf("orbit : %.1f\n", y.orbit);
  printf("name  : '%s'\n", y.name);
  sat_t m = find_sat(108.9);
  printf("orbit : %.1f\n", m.orbit);
  printf("name  : '%s'\n", m.name);
  sat_t n = find_sat("palapa");
  printf("orbit : %.1f\n", n.orbit);
  printf("name  : '%s'\n", n.name);
  printf("focal     : %.2f cm\n", focal_length(ft_to_cm(7), 30.48));
  printf("radius    : %.2f cm\n", radius(ft_to_cm(7), 30.48));
  printf("distance  : %.2f cm\n",
         distance_two_lnb(108.2, 113.0, radius(ft_to_cm(7), 30.48),
                          focal_length(ft_to_cm(7), 30.48)));
  return 0;
}
