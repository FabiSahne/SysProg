#include "benotung.h";

class fachnote
{
private:
    /* data */
public:
    const std::string fach;
    const benotung note;
    fachnote(const std::string&, const benotung&);
};

fachnote::fachnote(const std::string& f, const benotung& n)
{
    if (f.length() > 0)
    {
    fach = f;
    note = n;
    }
    else
    {

    }
}