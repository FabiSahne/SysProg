#include <stdio.h>

int main()
{

    int i = 12;
    long l = 13;
    short s = 11;
    char c = 'v';

    signed char sc = -12;
    unsigned char uc = 12;

    float f = 1.5f;
    double d = 1.6;
    long double ld = 1.7;

    unsigned int ui = 12;
    unsigned long ul = 13;
    unsigned short us = 1;

    const char* st = "Hallo";

    /* Adresse, Platzbedarf, Typ, Name, Wert */
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %d\n", (void*)&i, (unsigned long) sizeof(i), "int", "i", i);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %ld\n", (void*)&l, (unsigned long) sizeof(l), "long", "l", l);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %d\n", (void*)&s, (unsigned long) sizeof(s), "short", "s", s);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %d\n", (void*)&c, (unsigned long) sizeof(c), "char", "c", c);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %d\n", (void*)&sc, (unsigned long) sizeof(sc), "signed char", "sc", sc);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %u\n", (void*)&uc, (unsigned long) sizeof(uc), "unsigned char", "uc", uc);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %f\n", (void*)&f, (unsigned long) sizeof(f), "float", "f", f);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %f\n", (void*)&d, (unsigned long) sizeof(d), "double", "d", d);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %Lf\n", (void*)&ld, (unsigned long) sizeof(ld), "long double", "ld", ld);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %u\n", (void*)&ui, (unsigned long) sizeof(ui), "unsigned int", "ui", ui);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %lu\n", (void*)&ul, (unsigned long) sizeof(ul), "unsigned long", "ul", ul);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %d\n", (void*)&us, (unsigned long) sizeof(us), "unsigned short", "us", us);
    printf("Adresse: %p, Platzbedarf: %lu, Typ: %s, Name: %s, Wert: %s\n", (void*)&st, (unsigned long) sizeof(st), "const char*", "st", st);

    return 0;
}