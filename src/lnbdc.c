/* lnbdc.c */
#include "lnbdc.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

sat_t sats[] = {
    {74.0, "G-Sat 18"},      {75.0, "ABS 2"},         {75.0, "ABS 2A"},
    {76.5, "Apstar 7"},      {78.5, "Thaicom 6"},     {78.5, "Thaicom 8"},
    {80.0, "Express 80"},    {83.0, "G-Sat 10"},      {83.0, "G-Sat 24"},
    {83.0, "G-Sat 30"},      {86.5, "KazSat 2"},      {87.5, "ChinaSat 12"},
    {88.0, "ST 2"},          {90.0, "Yamal 401"},     {91.5, "Measat 3b"},
    {91.5, "Measat 3d"},     {92.2, "ChinaSat 9"},    {93.5, "G-Sat 15"},
    {93.5, "G-Sat 17"},      {95.0, "SES 8"},         {96.5, "Express 103"},
    {97.3, "G-Sat 9"},       {98.0, "ChinaSat 11"},   {100.5, "AsiaSat 5"},
    {101.4, "ChinaSat 9B"},  {103.0, "Express AMU3"}, {105.5, "AsiaSat 7"},
    {108.1, "SES 7"},        {108.1, "SES 9"},        {108.1, "Merah Putih"},
    {110.0, "BSAT 3C"},      {110.0, "JCSAT 110R"},   {110.0, "JCSAT 15"},
    {110.0, "BSAT 4A"},      {113.0, "Koreasat 5A"},  {115.5, "ChinaSat 6E"},
    {116.0, "Koreasat 6A"},  {116.0, "Koreasat 7"},   {118.0, "Telkom 3S"},
    {119.3, "Thaicom 4"},    {119.3, "Bangladesh 1"}, {120.0, "AsiaSat 6"},
    {120.0, "Thaicom 7"},    {122.0, "AsiaSat 9"},    {124.0, "JCSAT 4B"},
    {125.0, "ChinaSat 6D"},  {128.0, "JCSAT 3A"},     {128.5, "LaoSat 1"},
    {130.5, "ChinaSat 6C"},  {132.0, "JCSAT 5A"},     {132.0, "Vinasat 1"},
    {132.0, "Vinasat 2"},    {134.0, "Apstar 6C"},    {138.0, "Telstar 18"},
    {140.0, "Express AM5"},  {140.0, "Express AT2"},  {142.0, "Apstar 9"},
    {144.0, "Superbird C2"}, {145.0, "Express AMU7"}, {146.0, "Nusantara Satu"},
    {150.5, "BRIsat"},       {152.0, "Optus D1"},     {154.0, "JCSAT 2B"},
    {156.0, "Optus D3"},     {156.0, "Optus 10"},     {159.0, "ABS 6"},
    {160.0, "Measat 3a"},    {160.0, "Koreasat 6"},   {162.0, "Superbird B3"},
    {166.0, "Intelsat 19"},  {169.0, "Horizons 3e"},  {172.0, "Eutelsat 172B"},
    {177.0, "NSS 9"},        {180.0, "Intelsat 18"}};

sat_t find_sat_by_orbit(double_t arg) {
  size_t lsats = sizeof(sats) / sizeof(sat_t);
  sat_t tmp, result = sats[0];
  int i;
  for (i = 0; i < lsats; i++) {
    tmp = sats[i];
    if (tmp.orbit == arg) {
      result = tmp;
      break;
    } else if (tmp.orbit < arg) {
      if (result.orbit < tmp.orbit) {
        result = tmp;
      }
    }
  }
  return result;
}

sat_t find_sat_by_name(str_t name) {
  size_t lname = strlen(name);
  size_t lsats = sizeof(sats) / sizeof(sat_t);
  sat_t tmp, result = sats[0];
  int i;
  for (i = 0; i < lsats; i++) {
    tmp = sats[i];
    if ((strncasecmp(tmp.name, name, lname)) == 0) {
      result = tmp;
      break;
    } else if ((strncasecmp(tmp.name, name, 1)) == 0) {
      result = tmp;
    }
  }
  return result;
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

double m_to_cm(double_t m) {
  double result = 100 * m;
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

double str_to_cm(char *arg) {
  char *unit;
  double_t result = strtod(arg, &unit);
  while (isspace(*unit)) {
    unit++;
  }
  if ((strncasecmp(unit, "ft", 2) == 0) ||
      (strncasecmp(unit, "foot", 4) == 0) ||
      (strncasecmp(unit, "feet", 4) == 0)) {
    result = ft_to_cm(result);
  } else if ((strncasecmp(unit, "m", 1) == 0) ||
             (strncasecmp(unit, "meter", 5) == 0)) {
    result = m_to_cm(result);
  }
  return result;
}

sat_t str_to_sat(str_t str) {
  sat_t result;
  if (strtod(str, NULL)) {
    result = find_sat(strtod(str, NULL));
  } else {
    result = find_sat(str);
  }
  return result;
}

void show_satellites() {
  size_t lsats = sizeof(sats) / sizeof(sat_t);
  sat_t tmp;
  int i;
  for (i = 0; i < lsats; i++) {
    tmp = sats[i];
    if (i != 0) {
      printf("\n");
    }
    printf("{%.1f, '%s'}", tmp.orbit, tmp.name);
  }
}

int cmpsatp(const void *sat0, const void *sat1) {
  sat_t x, y;
  x = *(sat_t *)sat0;
  y = *(sat_t *)sat1;
  if (x.orbit == y.orbit) {
    return 0;
  } else if (x.orbit > y.orbit) {
    return -1;
  }
  return 1;
}
