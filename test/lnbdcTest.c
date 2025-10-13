#include "../src/lnbdc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test_1() {
  sat_t a = find_sat_by_orbit(146.0);
  sat_t b = find_sat_by_orbit(146);
  sat_t c = find_sat_by_orbit(147);
  printf("a = %s\n", a.name);
  printf("b = %s\n", b.name);
  printf("c = %s\n", c.name);
  if (strcmp(a.name, "Nusantara Satu") != 0) return 1;
  if (strcmp(b.name, "Nusantara Satu") != 0) return 1;
  if (strcmp(c.name, "Nusantara Satu") != 0) return 1;
  return 0;
}

int test_2() {
  sat_t a = find_sat_by_name("Nusantara Satu");
  sat_t b = find_sat_by_name("Nusantara");
  sat_t c = find_sat_by_name("nusantara");
  printf("a = %s\n", a.name);
  printf("b = %s\n", b.name);
  printf("c = %s\n", c.name);
  if (strcmp(a.name, "Nusantara Satu") != 0) return 1;
  if (strcmp(b.name, "Nusantara Satu") != 0) return 1;
  if (strcmp(c.name, "Nusantara Satu") != 0) return 1;
  return 0;
}

int test_3() {
  sat_t a = find_sat_by_orbit(146.0);
  sat_t b = find_sat_by_orbit(146);
  sat_t c = find_sat_by_orbit(147);
  sat_t d = find_sat_by_name("Nusantara Satu");
  sat_t e = find_sat_by_name("Nusantara");
  sat_t f = find_sat_by_name("nusantara");
  printf("a = %s\n", a.name);
  printf("b = %s\n", b.name);
  printf("c = %s\n", c.name);
  printf("d = %s\n", d.name);
  printf("e = %s\n", e.name);
  printf("f = %s\n", f.name);
  if (strcmp(a.name, "Nusantara Satu") != 0) return 1;
  if (strcmp(b.name, "Nusantara Satu") != 0) return 1;
  if (strcmp(c.name, "Nusantara Satu") != 0) return 1;
  if (strcmp(d.name, "Nusantara Satu") != 0) return 1;
  if (strcmp(e.name, "Nusantara Satu") != 0) return 1;
  if (strcmp(f.name, "Nusantara Satu") != 0) return 1;
  return 0;
}

int test_4() {
  sat_t a = str_to_sat("146.0");
  sat_t b = str_to_sat("146");
  sat_t c = str_to_sat("147");
  sat_t d = str_to_sat("Nusantara Satu");
  sat_t e = str_to_sat("Nusantara");
  sat_t f = str_to_sat("nusantara");
  printf("a = %s\n", a.name);
  printf("b = %s\n", b.name);
  printf("c = %s\n", c.name);
  printf("d = %s\n", d.name);
  printf("e = %s\n", e.name);
  printf("f = %s\n", f.name);
  if (strcmp(a.name, "Nusantara Satu") != 0) return 1;
  if (strcmp(b.name, "Nusantara Satu") != 0) return 1;
  if (strcmp(c.name, "Nusantara Satu") != 0) return 1;
  if (strcmp(d.name, "Nusantara Satu") != 0) return 1;
  if (strcmp(e.name, "Nusantara Satu") != 0) return 1;
  if (strcmp(f.name, "Nusantara Satu") != 0) return 1;
  return 0;
}

int test_5() {
  char a[16];
  char b[16];
  sprintf(a, "%.6f",  deg_to_rad(1));
  sprintf(b, "%.6f",  deg_to_rad(1.1));
  printf("a = %s\n", a);
  printf("b = %s\n", b);
  if (strcmp(a, "0.017453") != 0) return 1;
  if (strcmp(b, "0.019199") != 0) return 1;
  return 0;
}

int test_6() {
  char a[16];
  char b[16];
  sprintf(a, "%.6f", tsin(30));
  sprintf(b, "%.6f", tsin(30.1));
  printf("a = %s\n", a);
  printf("b = %s\n", b);
  if (strcmp(a, "0.500000") != 0) return 1;
  if (strcmp(b, "0.501511") != 0) return 1;
  return 0;
}

int test_7() {
  char a[16];
  char b[16];
  sprintf(a, "%.6f", tcos(30));
  sprintf(b, "%.6f", tcos(30.1));
  printf("a = %s\n", a);
  printf("b = %s\n", b);
  if (strcmp(a, "0.866025") != 0) return 1;
  if (strcmp(b, "0.865151") != 0) return 1;
  return 0;
}

int test_8() {
  char a[16];
  char b[16];
  sprintf(a, "%.2f", ft_to_cm(1));
  sprintf(b, "%.2f", ft_to_cm(1.1));
  printf("a = %s\n", a);
  printf("b = %s\n", b);
  if (strcmp(a, "30.48") != 0) return 1;
  if (strcmp(b, "33.53") != 0) return 1;
  return 0;
}

int test_9() {
  char a[16];
  char b[16];
  sprintf(a, "%.2f", m_to_cm(1));
  sprintf(b, "%.2f", m_to_cm(1.1));
  printf("a = %s\n", a);
  printf("b = %s\n", b);
  if (strcmp(a, "100.00") != 0) return 1;
  if (strcmp(b, "110.00") != 0) return 1;
  return 0;
}

int test_10() {
  char a[16];
  char b[16];
  char c[16];
  char d[16];
  sprintf(a, "%.2f", str_to_cm("1.1ft"));
  sprintf(b, "%.2f", str_to_cm("1.1m"));
  sprintf(c, "%.2f", str_to_cm("1.1 ft"));
  sprintf(d, "%.2f", str_to_cm("1.1 m"));
  printf("a = %s\n", a);
  printf("b = %s\n", b);
  printf("c = %s\n", c);
  printf("d = %s\n", d);
  if (strcmp(a, "33.53") != 0) return 1;
  if (strcmp(b, "110.00") != 0) return 1;
  if (strcmp(c, "33.53") != 0) return 1;
  if (strcmp(d, "110.00") != 0) return 1;
  return 0;
}

int test_11() {
  char a[16];
  sprintf(a, "%.2f", focal_length(213.36, 30.48));
  printf("a = %s\n", a);
  if (strcmp(a, "93.35") != 0) return 1;
  return 0;
}

int test_12() {
  char a[16];
  sprintf(a, "%.2f", radius(213.36, 30.48));
  printf("a = %s\n", a);
  if (strcmp(a, "201.93") != 0) return 1;
  return 0;
}

int test_13() {
  char a[16];
  sprintf(a, "%.2f", distance_two_lnb(108, 146, 201, 93));
  printf("a = %s\n", a);
  if (strcmp(a, "71.63") != 0) return 1;
  return 0;
}

int test_14() {
  char a[8];
  char b[8];
  char c[8];
  sat_t s[] = {{1, "s1"}, {2, "s2"}, {3, "s3"}};
  qsort(s, sizeof(s) / sizeof(sat_t), sizeof(sat_t), cmpsatp);
  sprintf(a, "%s", s[0].name);
  sprintf(b, "%s", s[1].name);
  sprintf(c, "%s", s[2].name);
  printf("a = %s\n", a);
  printf("b = %s\n", b);
  printf("c = %s\n", c);
  if (strcmp(a, "s3") != 0) return 1;
  if (strcmp(b, "s2") != 0) return 1;
  if (strcmp(c, "s1") != 0) return 1;
  return 0;
}

int main(int argc, char *argv[]) {
  int test = 1;
  if (argc > 1) {
    switch(atoi(argv[1])) {
    case 1:
      test = test_1();
      break;
    case 2:
      test = test_2();
      break;
    case 3:
      test = test_3();
      break;
    case 4:
      test = test_4();
      break;
    case 5:
      test = test_5();
      break;
    case 6:
      test = test_6();
      break;
    case 7:
      test = test_7();
      break;
    case 8:
      test = test_8();
      break;
    case 9:
      test = test_9();
      break;
    case 10:
      test = test_10();
      break;
    case 11:
      test = test_11();
      break;
    case 12:
      test = test_12();
      break;
    case 13:
      test = test_13();
      break;
    case 14:
      test = test_14();
      break;
    default:
      test = 1;
      break;
    }
  }
  return test;
}
