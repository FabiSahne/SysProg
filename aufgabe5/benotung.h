#ifndef BENOTUNG_H
#define BENOTUNG_H

class benotung
{
    int note;

public:
    static const benotung schlechteste;
    static const benotung beste;
    explicit benotung(int n);
    int int_value() const;
    bool ist_bestanden() const;
    friend bool operator==(const benotung&, const benotung&);
};

#endif