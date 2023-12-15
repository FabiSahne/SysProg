#include "fachnoten_liste.h"

//----------------------------------------- Member-Funktionen intlist::iterator
fachnotenliste::iterator::iterator(element *e)
: current(e)
{ }

bool fachnotenliste::iterator::operator!=(const iterator& i) const
{
    return this->current != i.current;
}

int& fachnotenliste::iterator::operator*() const
{
    return this->current->n;
}

fachnotenliste::iterator& fachnotenliste::iterator::operator++()
{
    this->current = this->current->next.get();
    return *this;
}

//--------------------------------------------------- Member-Funktionen intlist
fachnotenliste::fachnotenliste()
: head(nullptr)
{ }

fachnotenliste& fachnotenliste::insert(int n)
{
    this->head.reset(new element(this->head.release(), n));
    return *this;
}

fachnotenliste::iterator fachnotenliste::begin()
{
    return fachnotenliste::iterator(this->head.get());
}

fachnotenliste::iterator fachnotenliste::end()
{
    return fachnotenliste::iterator(nullptr);
}
