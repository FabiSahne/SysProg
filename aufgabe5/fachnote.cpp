#include "fachnote.h"
#include "benotung.h"
#include <stdexcept>

fachnote::fachnote(const std::string& f, const benotung &n) : fach(f), note(n)
{
    if (f.empty())
    {
        throw std::invalid_argument("unzulässiges Fach");
    }
}