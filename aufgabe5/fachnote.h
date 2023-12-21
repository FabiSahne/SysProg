#ifndef FACHNOTE_H
#define FACHNOTE_H

#include <string>
#include "benotung.h"

class fachnote
{
public:
    fachnote(const fachnote&) = delete;
    fachnote& operator=(const fachnote&) = delete;

    const std::string fach;
    const benotung note;
    fachnote(const std::string&, const benotung&);
};

#endif