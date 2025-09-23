#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4;i++)
    {
        sources[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
  *this = obj;  
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
    if (this != &obj)
    {
        for (int i = 0; i < 4; i++)
            delete sources[i];
        for (int i = 0; i < 4; i++)
        {
            if (obj.sources[i])
            {
                sources[i] = obj.sources[i];
            }
            else
                sources[i] = NULL;
        }
    }
    return *this;
}

void    MateriaSource::learnMateria(AMateria* check)
{
    for (int i = 0; i < 4; i++)
    {
        if (!sources[i])
        {
            sources[i] = check->clone();
            delete check;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (sources[i] && type == sources[i]->getType())
        {
            return sources[i]->clone();
        }
    }
    return 0;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        if (sources[i])
        {
            delete sources[i];
            sources[i] = NULL;
        }
    }
}