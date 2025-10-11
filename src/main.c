/* main.c */
#include "lnbd.h"

sat_t sats[] = {
    {57.0, "NSS 12"},       {64.2, "Intelsat 906"},  {66.0, "Intelsat 17"},
    {68.5, "Intelsat 20"},  {70.5, "Eutelsat 70B"},  {75.0, "ABS 2"},
    {76.5, "Apstar 7"},     {78.5, "Thaicom 5"},     {78.5, "Thaicom 6"},
    {87.5, "ChinaSat 12"},  {88.0, "ST 2"},          {91.5, "Measat 3"},
    {91.5, "Measat 3a"},    {91.5, "Measat 3B"},     {93.5, "G Sat 17"},
    {93.5, "Insat 4B"},     {95.0, "NSS 6"},         {96.5, "Express AM33"},
    {98.0, "ChinaSat 11"},  {100.5, "AsiaSat 5"},    {105.5, "AsiaSat 7"},
    {108.2, "SES 7"},       {108.2, "SES 9"},        {108.2, "Telkom 4"},
    {110.5, "ChinaSat 10"}, {113.0, "Palapa D"},     {115.5, "ChinaSat 6B"},
    {118.0, "Telkom 3S"},   {119.5, "Thaicom 4"},    {120.0, "Thaicom 7"},
    {122.2, "AsiaSat 9"},   {124.0, "JCSAT 4B"},     {125.0, "ChinaSat 6A"},
    {128.0, "Laosat 1"},    {128.0, "JCSAT 3A"},     {132.0, "Vinasat 1"},
    {134.0, "Apstar 6"},    {138.0, "Telstar 18"},   {142.0, "Apstar 9"},
    {154.0, "JCSAT 2A"},    {159.0, "ABS 6"},        {166.0, "Intelsat 19"},
    {169.0, "Intelsat 8"},  {172.0, "Eutelsat 172A"}};

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

int test() {
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
  sat_t m = find_sat(109);
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
  show_satellites();
  printf("\n");
  return 0;
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

int main(int argc, char *argv[]) {
  if (argc < 5) {
    // show_help();
    return 1;
  }
  int i;
  int len = argc - 3;
  double diameter, depth, rdius, focal;
  sat_t focus, x, y;
  sat_t others[len];
  for (i = 1; i < argc; i++) {
    switch (i) {
    case 1:
      diameter = str_to_cm(argv[i]);
      break;
    case 2:
      depth = str_to_cm(argv[i]);
      break;
    case 3:
      focus = str_to_sat(argv[i]);
      others[0] = focus;
      break;
    default:
      others[i - 3] = str_to_sat(argv[i]);
      break;
    }
  }
  printf("LNB distance calculation:\n\n");
  rdius = radius(diameter, depth);
  focal = focal_length(diameter, depth);
  printf("  %-12s : %.2f\n", "Diameter", diameter);
  printf("  %-12s : %.2f\n", "Depth", depth);
  printf("  %-12s : %.2f\n", "Radius", rdius);
  printf("  %-12s : %.2f\n", "Focal length", focal);
  printf("  %-12s : %s\n", "Focus", focus.name);
  printf("\n");
  qsort(&others, sizeof(others) / sizeof(sat_t), sizeof(sat_t), cmpsatp);
  printf("  %-16s | %-16s | %-9s\n", "From (West)", "To (East)", "Distance (cm)");
  printf("  ---------------- | ---------------- | -------------\n");
  for (i = 0; i < len; i++) {
    if (focus.orbit > others[i].orbit) {
      x = focus;
      y = others[i];
    } else {
      x = others[i];
      y = focus;
    }
    printf("  %-16s | %-16s | %-9.2f cm\n", x.name, y.name,
           distance_two_lnb(x.orbit, y.orbit, rdius, focal));
  }
  return 0; // test();
}
