#pragma once

#include <iostream>
#include <string>


class   Weapon{
    private:
        std::string type;
    public:
        Weapon(const std::string& type);
        const std::string& getType () const;
        void    setType(std::string club);
        ~Weapon();
};