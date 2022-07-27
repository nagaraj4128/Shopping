#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    string name;
    int lifeExpectancy;
    virtual void vfunc() = 0;
    Animal()
    {
        cout << "Animal created with no details\n";
    }
    Animal(string name, int lifeExpectancy)
    {
        this->name = name;
        this->lifeExpectancy = lifeExpectancy;
        cout << "Animal created with name:" << this->name << " LE: " << lifeExpectancy << "\n";
    }
    void makeSound()
    {
        cout << "Animal makes sound wooho\n";
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setLifeExpectancy(int lifeExpectancy)
    {
        this->lifeExpectancy = lifeExpectancy;
    }
    string getName()
    {
        return this->name;
    }
    int getLifeExpectancy()
    {
        return this->lifeExpectancy;
    }
    ~Animal()
    {
        cout << "Animal destructred\n";
    }
};

class Dog : public Animal
{
    string breed;
    friend void printDetailsOfDog(Dog dog);

public:
    Dog()
    {
    }
    Dog(string name, string breed, int lifeExpectancy) : Animal(name, lifeExpectancy)
    {
        this->breed = breed;
        cout << "Dog created\n";
        cout << this->name << " " << this->breed << " " << this->lifeExpectancy << "\n";
    }
    void makeSound()
    {
        cout << "Dog goes woo\n";
    }
    void makeSound(string sound)
    {
        cout << "This dog goes " << sound << "\n";
    }
    void vfunc()
    {
        cout << "virtual function overloaded\n";
    }
    Dog operator+(Dog const &dog)
    {
        Dog d;
        d.breed = dog.breed;
        d.lifeExpectancy = dog.lifeExpectancy;
        d.name = dog.name;
        return d;
    }
};

void printDetailsOfDog(Dog dog)
{
    cout << dog.name << " " << dog.breed << " " << dog.lifeExpectancy << " from friend \n";
}

int main()
{
    // Animal animal;
    // Animal ani("koala", 3);
    Dog d("dog", "corgy", 8);
    d.makeSound();
    d.makeSound("bhow");
    Dog d1(d);
    printDetailsOfDog(d1);

    // smart pointer
    // {
    //     unique_ptr<Animal> unptr = make_unique<Animal>("cat", 4);
    // }

    Dog d3 = d + d1;

    printDetailsOfDog(d3);

    Animal *ani = new Dog("dog", "pomelian", 3);

    ani->vfunc();

    return 0;
}