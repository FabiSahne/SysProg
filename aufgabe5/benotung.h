class benotung
{
private:
    int note;

public:
    const static int schlechteste = 50;
    const static int beste = 10;
    benotung(int);
    int int_value();
    bool ist_bestanden();
    friend bool operator==(benotung a, benotung c);
};

benotung::benotung(int n)
{
    if (
        n == 10 || n == 13 || n == 17 || n == 20 || n == 23 ||
        n == 27 || n == 30 || n == 33 || n == 37 || n == 50 ||
        n == 50)
    {
        note = n;
    }
    else
    {
        throw std::invalid_argument("unzulaessige Note " + note);
    }
}

int benotung::int_value()
{
    return note;
}

bool benotung::ist_bestanden()
{
    return (note <= 40);
}

bool operator==(benotung a, benotung b)
{
    return (a.int_value() == b.int_value());
}