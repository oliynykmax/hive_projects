#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal {
    protected:
    std::string type;

    public:
    Animal();
    Animal &operator=(const Animal &other);
    Animal(const Animal &src);
    virtual ~Animal();
    virtual void makeSound() const;
    std::string getType() const;

};

#endif // ANIMAL_HPP
