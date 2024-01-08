#!/bin/sh
set -x
g++ -c -fPIC -Wall -Wextra -Werror -pedantic lib/benotung.cpp lib/fachnote.cpp lib/fachnoten_liste.cpp
g++ -shared -o libaufgabe6.so benotung.o fachnoten_liste.o fachnote.o
