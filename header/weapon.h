#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>

class Weapon
{

    public:
    std::string name;
    
    Weapon(std::string n) : name(n){}
    virtual void attack();
    ~Weapon();
    class Axe : public Weapon{}
        void attack();
    private:
    

};

#endif