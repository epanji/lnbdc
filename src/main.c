#include <math.h>
#include <stdio.h>

typedef struct {
  double orbit;
  char name[16];
} sat_t;

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

double deg_to_rad(int deg) { return (deg % 360) * (M_PI / 180); }

double tsin(int deg) { return sin(deg_to_rad(deg)); }

double tcos(int deg) { return cos(deg_to_rad(deg)); }

float ft_to_cm(float ft) { return 30.48 * ft; }

int main() {
  printf("sin  30   : %f\n", tsin(30));
  printf("sin -30   : %f\n", tsin(-30));
  printf("cos  30   : %f\n", tcos(30));
  printf("cos -30   : %f\n", tcos(-30));
  printf("ft2cm 9   : %f\n", ft_to_cm(9));
  printf("ft2cm 9.2 : %f\n", ft_to_cm(9.2));
  printf("sat_t 0   : {%.1f, '%s'}\n", sats[0].orbit, sats[0].name);
  printf("sat_t 1   : {%.1f, '%s'}\n", sats[1].orbit, sats[1].name);
  return 0;
}
