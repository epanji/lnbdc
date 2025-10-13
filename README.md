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

src (main) » valgrind -s --leak-check=full ../build/lnbdc 7ft 1ft 'merah putih' 'asiasat 7' 'asiasat 5' 'koreasat 5a' 'chinasat 6e'
==26779== Memcheck, a memory error detector
==26779== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==26779== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==26779== Command: ../build/lnbdc 7ft 1ft merah\ putih asiasat\ 7 asiasat\ 5 koreasat\ 5a chinasat\ 6e
==26779== 
LNB distance calculation:

  Diameter     : 213.36  cm
  Depth        : 30.48   cm
  Radius       : 201.93  cm
  Focal length : 93.35   cm
  Focus        : Merah Putih

  From (West)      | To (East)        | Distance (cm)
  ---------------- | ---------------- | -------------
  ChinaSat 6E      | Merah Putih      | 14.02     cm
  Koreasat 5A      | Merah Putih      | 9.29      cm
  Merah Putih      | Merah Putih      | 0.00      cm
  Merah Putih      | AsiaSat 7        | 4.93      cm
  Merah Putih      | AsiaSat 5        | 14.40     cm
==26779== 
==26779== HEAP SUMMARY:
==26779==     in use at exit: 0 bytes in 0 blocks
==26779==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==26779== 
==26779== All heap blocks were freed -- no leaks are possible
==26779== 
==26779== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```

### Test from ``src``

```sh

ctest --test-dir ../build ../

```

### Verbose test from ``src``

```sh

ctest --test-dir ../build --verbose ../

```
