/* lnbdc.h */
#pragma once

#include <math.h>

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

sat_t find_sat_by_orbit(double_t arg);

sat_t find_sat_by_name(str_t name);

double deg_to_rad(double_t deg);

double tsin(double_t deg);

double tcos(double_t deg);

double ft_to_cm(double_t ft);

double m_to_cm(double_t m);

double focal_length(double_t diameter, double_t depth);

double radius(double_t diameter, double_t depth);

double distance_two_lnb(double_t from, double_t to, double_t radius,
                        double_t focal);

double str_to_cm(char *arg);

sat_t str_to_sat(str_t str);

void show_satellites();

int cmpsatp(const void *sat0, const void *sat1);

int trim_space_left(char *arg);
