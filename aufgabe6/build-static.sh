#!/bin/sh
set -x
g++ -c -Wall -Wextra -Werror -pedantic lib/benotung.cpp lib/fachnote.cpp lib/fachnoten_liste.cpp
ar rcs libaufgabe6.a benotung.o fachnote.o fachnoten_liste.o
