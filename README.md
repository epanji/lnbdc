### Intro

This project aims to familiarize writers with the use of ``cmake``.

### Create from ``src``

```sh

cmake -B ../build --fresh ../

```

### Build from ``src``

```sh

cmake --build ../build

```

### Build and Run from ``src``

```sh

cmake --build ../build && ../build/lnbdc

```

### Valgrind from ``src``

```sh

src (main) » valgrind -s --leak-check=full ../build/lnbdc 7ft 1ft 'telkom 4' 'asiasat 7' 'asiasat 5' 'palapa d' 'chinasat 6b'
==2143== Memcheck, a memory error detector
==2143== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==2143== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==2143== Command: ../build/lnbdc 7ft 1ft telkom\ 4 asiasat\ 7 asiasat\ 5 palapa\ d chinasat\ 6b
==2143== 
LNB distance calculation:

  Diameter     : 213.36  cm
  Depth        : 30.48   cm
  Radius       : 201.93  cm
  Focal length : 93.35   cm
  Focus        : Telkom 4

  From (West)      | To (East)        | Distance (cm)
  ---------------- | ---------------- | -------------
  ChinaSat 6B      | Telkom 4         | 13.83     cm
  Palapa D         | Telkom 4         | 9.10      cm
  Telkom 4         | Telkom 4         | 0.00      cm
  Telkom 4         | AsiaSat 7        | 5.12      cm
  Telkom 4         | AsiaSat 5        | 14.59     cm
==2143== 
==2143== HEAP SUMMARY:
==2143==     in use at exit: 0 bytes in 0 blocks
==2143==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==2143== 
==2143== All heap blocks were freed -- no leaks are possible
==2143== 
==2143== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
