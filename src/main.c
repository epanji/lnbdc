/* main.c */
#include "lnbdc.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

void show_brief() {
  printf("lnbdc [option...] ");
  printf("<diameter> <depth> <focus-satellite> ");
  printf("<other-satellite> [more-satellite...]\n");
}

void show_help() {
  printf("lnbdc is LNB distance calculation for parabola.\n");
  printf("\n");
  printf("usage:\n  ");
  show_brief();
  printf("\n");
  printf("options:\n");
  printf("%5s %-14s %s\n", "-h,", "--help", "show this messages.");
  printf("%5s %-14s %s\n", "", "--list", "show all satellites.");
  printf("%5s %-14s %s\n", "-d,", "--data <file>", "use data from file.");
  printf("\n");
  printf("arguments:\n");
  printf(
      "  %-18s %s\n", "diameter",
      "parabola diameter based on units, assumed in cm if units are omitted. "
      "(ft, m, cm)");
  printf("  %-18s %s\n", "depth",
         "parabola depth based on units, assumed in cm if units are omitted. "
         "(ft, m, cm)");
  printf("  %-18s %s\n", "satellite",
         "satellite orbit or name for focus and the others.");
}

int main(int argc, char *argv[]) {
  int c;
  int digit_optind = 0;
  int size = 0;
  sat_t(*arptr)[] = malloc(1024 * sizeof(sat_t));
  while (1) {
    int this_option_optind = optind ? optind : 1;
    int option_index = 0;
    static struct option long_options[] = {{"help", no_argument, 0, 'h'},
                                           {"list", no_argument, 0, 'l'},
                                           {"data", required_argument, 0, 'd'},
                                           {0, 0, 0, 0}};
    c = getopt_long(argc, argv, "hd:", long_options, &option_index);
    if (c == -1) {
      break;
    }
    switch (c) {
    case 'h':
      show_help();
      free(arptr);
      return 0;
    case 'l':
      if (size != 0) {
        show_satellites(arptr, size);
      } else {
        show_satellites(NULL, 0);
      }
      printf("\n");
      free(arptr);
      return 0;
    case 'd':
      if (optarg != NULL) {
        size = sats_from_file(arptr, optarg);
        if (size != 0) {
          qsort(arptr, size, sizeof(sat_t), asc_cmpsatp);
        }
      }
      break;
    default:
      printf("usage: ");
      show_brief();
      free(arptr);
      return 1;
    }
  }
  int i = 0;
  int wo_argc = 1 + argc - optind;
  char *wo_argv[wo_argc];
  wo_argv[i] = argv[i];
  if (optind < argc) {
    while (optind < argc) {
      wo_argv[++i] = argv[optind++];
    }
  }
  if (wo_argc < 5) {
    printf("usage: ");
    show_brief();
    free(arptr);
    return 1;
  }
  int len = wo_argc - 3;
  double diameter, depth, rdius, focal;
  sat_t focus, x, y;
  sat_t others[len];
  for (i = 1; i < wo_argc; i++) {
    switch (i) {
    case 1:
      diameter = str_to_cm(wo_argv[i]);
      break;
    case 2:
      depth = str_to_cm(wo_argv[i]);
      break;
    case 3:
      if (size == 0) {
        focus = str_to_sat(wo_argv[i], NULL, 0);
      } else {
        focus = str_to_sat(wo_argv[i], arptr, size);
      }
      others[0] = focus;
      break;
    default:
      if (size == 0) {
        others[i - 3] = str_to_sat(wo_argv[i], NULL, 0);
      } else {
        others[i - 3] = str_to_sat(wo_argv[i], arptr, size);
      }
      break;
    }
  }
  printf("LNB distance calculation:\n\n");
  rdius = radius(diameter, depth);
  focal = focal_length(diameter, depth);
  printf("  %-12s : %-7.2f cm\n", "Diameter", diameter);
  printf("  %-12s : %-7.2f cm\n", "Depth", depth);
  printf("  %-12s : %-7.2f cm\n", "Radius", rdius);
  printf("  %-12s : %-7.2f cm\n", "Focal length", focal);
  printf("  %-12s : %s\n", "Focus", focus.name);
  printf("\n");
  qsort(&others, sizeof(others) / sizeof(sat_t), sizeof(sat_t), desc_cmpsatp);
  printf("  %-16s | %-16s | %-9s\n", "From (West)", "To (East)",
         "Distance (cm)");
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
  free(arptr);
  return 0;
}
