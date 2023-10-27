#include <stdio.h>
#include <stdbool.h>

int main()
{

    int i = 12;
    long l = 13;
    long long ll = 14;
    short s = 11;
    char c = 'v';

    signed char sc = -12;
    unsigned char uc = 12;

    float f = 1.5f;
    double d = 1.6;
    long double ld = 1.7;

    unsigned int ui = 12;
    unsigned long ul = 13;
    unsigned long long ull = 14;
    unsigned short us = 1;

    bool b = true;


    const char* st = "Hallo";

    // Adresse, Platzbedarf, Typ, Name, Wert
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %d\n", (void*)&i, sizeof(i), "int", "i", i);
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %ld\n", (void*)&l, sizeof(l), "long", "l", l);
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %lld\n", (void*)&ll, sizeof(ll), "long long", "ll", ll);
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %hd\n", (void*)&s, sizeof(s), "short", "s", s);
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %c\n", (void*)&c, sizeof(c), "char", "c", c);
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %hhd\n", (void*)&sc, sizeof(sc), "signed char", "sc", sc);
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %hhu\n", (void*)&uc, sizeof(uc), "unsigned char", "uc", uc);
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %f\n", (void*)&f, sizeof(f), "float", "f", f);
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %f\n", (void*)&d, sizeof(d), "double", "d", d);
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %Lf\n", (void*)&ld, sizeof(ld), "long double", "ld", ld);
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %u\n", (void*)&ui, sizeof(ui), "unsigned int", "ui", ui);
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %lu\n", (void*)&ul, sizeof(ul), "unsigned long", "ul", ul);
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %llu\n", (void*)&ull, sizeof(ull), "unsigned long long", "ull", ull);
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %hu\n", (void*)&us, sizeof(us), "unsigned short", "us", us);
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %d\n", (void*)&b, sizeof(b), "bool", "b", b);
    printf("Adresse: %p, Platzbedarf: %zu, Typ: %s, Name: %s, Wert: %s\n", (void*)&st, sizeof(st), "const char*", "st", st);

    if (sizeof(int) == 4 && sizeof(long) == 4 && sizeof(char*) == 4)
    {
        printf("\nILP32 Modell\n");
    }
    else if (sizeof(int) == 4 && sizeof(long) == 8 && sizeof(char*) == 8)
    {
        printf("\nLP64 Modell\n");
    }
    else if (sizeof(int) == 4 && sizeof(long) == 4 && sizeof(long long) == 8 && sizeof(char*) == 8)
    {
        printf("\nLLP64 Modell\n");
    }
    else
    {
        printf("\nKeins der Modelle ILP32, LP64 oder LLP64\n");
    }
    
    return 0;
}