# Makefile
# Kommando Variablen

CC = g++
CFLAGS = -Wall -Wextra -Werror -pedantic -fPIC   

# Hilfsvariablen
SOURCES = benotung.cpp fachnote.cpp fachnoten_liste.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = $(SOURCES:.cpp=.h)
LIBNAME = libaufgabe6

ifeq ($(LIBTYPE),so)
	LIBRARY = $(LIBNAME).so
else
	LIBRARY = $(LIBNAME).a
endif

# Musterregel
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Pseudoziele
.PHONY: all clean

all: $(LIBRARY)

clean:
	rm -f $(OBJECTS) $(LIBNAME).a $(LIBNAME).so depend

# Depend
depend: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -MM $(SOURCES) > $@

# Explizite Regel statisch
$(LIBNAME).a: $(OBJECTS)
	ar rcs $@ $^

# Explizite Regel dynamisch
$(LIBNAME).so: $(OBJECTS)
	$(CC) -shared -o $@ $^

# Abhängigkeit
include depend
