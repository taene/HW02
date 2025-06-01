#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal
{
public:
    virtual void makeSound() = 0;
};

class Dog : public Animal
{
public:
    void makeSound()
    {
        cout << "Bow-wow!" << '\n';
    }
};

class Cat : public Animal
{
public:
    void makeSound()
    {
        cout << "Meow~" << '\n';
    }
};

class Cow : public Animal
{
public:
    void makeSound()
    {
        cout << "Moo~" << '\n';
    }
};

class Zoo
{
private:
    Animal* animals[10];
    int index = 0;

public:
    void addAnimal(Animal* animal);
    void performActions();
    Animal* createRandomAnimal();
    ~Zoo();
};

void Zoo::addAnimal(Animal* animal)
{
    animals[index++] = animal;
}

void Zoo::performActions()
{
    if (!index)
    {
        cout << "No Animals!\n";
        cout << "-----------\n";
        return;
    }

    for (int i = 0; i < index; i++)
    {
        animals[i]->makeSound();
    }

    cout << "-----------\n";
}

Animal* Zoo::createRandomAnimal()
{
    Animal* animal = nullptr;
    
    int num = rand() % 3;
    switch (num)
    {
    case 0:
    {
		Dog* dog = new Dog();
		animal = dog;
		break;
    }
    case 1:
    {
        Cat* cat = new Cat();
        animal = cat;
        break;
    }
    case 2:
    {
        Cow* cow = new Cow();
        animal = cow;
        break;
    }
    default:
        break;
    }

    if (animal != nullptr) return animal;
    else return nullptr;
}

Zoo::~Zoo()
{
    for (int i = 0; i < index; i++)
    {
        cout << "Delete Check: "; 
        animals[i]->makeSound();

        delete animals[i];
        animals[i] = nullptr;
    }
}

int main()
{
    // 필수 기능
    vector<Animal*> myAnimals;
    myAnimals.push_back(new Dog());
    myAnimals.push_back(new Cat());
    myAnimals.push_back(new Cow());

    for (int i = 0; i < myAnimals.size(); i++)
    {
        myAnimals[i]->makeSound();
    }

    for (int i = 0; i < myAnimals.size(); i++)
    {
        delete myAnimals[i];
    }
    myAnimals.clear();
    
    // 도전 기능
    cout << "============\n";

    // srand(): 난수 생성을 위해 시드를 설정함. 보통 프로그램 전체에서 한번만 호출함.
    srand(static_cast<unsigned int>(time(NULL)));

    Zoo zoo;
    Dog* dog = new Dog();
    Cat* cat = new Cat();
    Cow* cow = new Cow();

    zoo.performActions();

    zoo.addAnimal(dog);
    zoo.addAnimal(cat);
    zoo.addAnimal(cow);
    zoo.performActions();

    zoo.addAnimal(zoo.createRandomAnimal());
    zoo.performActions();

    return 0;
}