#include "benotung.h"
#include <stdexcept>

const benotung benotung::beste = benotung(10);
const benotung benotung::schlechteste = benotung(50);

benotung::benotung(int n) : note(n)
{
    if (
        n != 10 && n != 13 && n != 17 && n != 20 && n != 23 &&
        n != 27 && n != 30 && n != 33 && n != 37 && n != 40 &&
        n != 50)
    {
        throw std::invalid_argument("unzulaessige Note " + std::to_string(n));
    }
}

int benotung::int_value() const
{
    return this->note;
}

bool benotung::ist_bestanden() const
{
    return (note <= 40);
}

bool operator==(const benotung& a, const benotung& b)
{
    return (a.int_value() == b.int_value());
}