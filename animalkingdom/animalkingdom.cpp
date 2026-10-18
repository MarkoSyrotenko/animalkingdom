#include <iostream>
using namespace std;


//----------herbivores--------------------
class Herbivore
{
protected:
    bool life;
    int weight;
public:
    Herbivore()
    {
        weight = 50;
        life = true;
    }
    bool isAlive()
    {
        return life;
    }
    virtual void eatGrass(){}
    virtual void getEaten(){}
    int getWeight()
    {
        return weight;
    }

};

class Wildebeest : public Herbivore
{
public:
    Wildebeest() : Herbivore() { weight = 250; }
    virtual void eatGrass()
    {
        if (life)
        {
            cout << "A wildebeest eats grass\n";
            weight += 10;
            cout << "+10 Weight (" << weight << ")\n\n";
        }
    }
    virtual void getEaten()
    {
        cout << "A wildebeest was eaten\n";
        life = false;
    }
};
class Bison : public Herbivore
{
public:
    Bison() : Herbivore() { weight = 400; }
    virtual void eatGrass()
    {
        if (life)
        {
            cout << "A bison eats grass\n";
            weight += 10;
            cout << "+10 Weight (" << weight << ")\n\n";
        }
    }
    virtual void getEaten()
    {
        cout << "A bison was eaten\n";
        life = false;
    }
};
class Moose : public Herbivore
{
public:
    Moose() : Herbivore() { weight = 380; }
    virtual void eatGrass()
    {
        if (life)
        {
            cout << "A moose eats grass\n";
            weight += 10;
            cout << "+10 Weight (" << weight << ")\n\n";
        }
    }
    virtual void getEaten()
    {
        cout << "A moose was eaten\n";
        life = false;
    }
};

//----------carnivores--------------------
class Carnivore
{
protected:
    int power;
protected:

public:
    Carnivore()
    {
        power = 100;
    }
    virtual void eat(Herbivore* obj){}
};

class Lion : public Carnivore
{
public:
    Lion() : Carnivore() { power = 1000; }
    virtual void eat(Herbivore* obj)
    {
        cout << "A lion eats its prey\n";
        obj->getEaten();
        if (obj->getWeight() <= power)
        {
            power += 10;
            cout << "+10 power (" << power << ")\n\n";
        }
        else
        {
            power -= 10;
            cout << "-10 power (" << power << ")\n\n";
        }
    }
};
class Wolf : public Carnivore
{
public:
    Wolf() : Carnivore() { power = 500; }
    virtual void eat(Herbivore* obj)
    {
        cout << "A wolf eats its prey\n";
        obj->getEaten();
        if (obj->getWeight() <= power)
        {
            power += 10;
            cout << "+10 power (" << power << ")\n\n";
        }
        else
        {
            power -= 10;
            cout << "-10 power (" << power << ")\n\n";
        }
    }
};
//------------continents------------------
class Continent
{
protected:
    int herbcount;
    int carncount;
public:
    Continent()
    {
        herbcount = 15;
        carncount = 5;
    }
};

class Africa : public Continent
{
    Wildebeest* herb;
    Lion* carn;
public:
    Africa() : Continent()
    {
        herb = new Wildebeest[herbcount];
        carn = new Lion[carncount];
    }
    void mealsHerbivores()
    {
        for (int i = 0; i < herbcount; i++)
        {
            herb[i].eatGrass();
        }
    }
    void nutritionCarnivores()
    {
        for (int i = 0; i < carncount; i++)
        {
            int index = -1;
            for (int j = 0; j < herbcount; j++)
            {
                if (herb[j].isAlive())
                {
                    index = j;
                    break;
                }
            }
            if (index != -1)
                carn[i].eat(&herb[index]);
            else cout << "A lion couldn't find anything to eat\n\n";
        }
    }
};
class NAmerica : public Continent
{
    Bison* herb;
    Wolf* carn;

public:
    NAmerica() : Continent()
    {
        herb = new Bison[herbcount];
        carn = new Wolf[carncount];
    }
    void mealsHerbivores()
    {
        for (int i = 0; i < herbcount; i++)
        {
            herb[i].eatGrass();
        }
    }
    void nutritionCarnivores()
    {
        for (int i = 0; i < carncount; i++)
        {
            int index = -1;
            for (int j = 0; j < herbcount; j++)
            {
                if (herb[j].isAlive())
                {
                    index = j;
                    break;
                }
            }
            if (index != -1)
                carn[i].eat(&herb[index]);
            else cout << "A wolf couldn't find anything to eat\n\n";
        }
    }
};
class Eurasia : public Continent
{
    Moose* herb;
    Wolf* carn;

public:
    Eurasia() : Continent()
    {
        herb = new Moose[herbcount];
        carn = new Wolf[carncount];
    }
    void mealsHerbivores()
    {
        for (int i = 0; i < herbcount; i++)
        {
            herb[i].eatGrass();
        }
    }
    void nutritionCarnivores()
    {
        for (int i = 0; i < carncount; i++)
        {
            int index = -1;
            for (int j = 0; j < herbcount; j++)
            {
                if (herb[j].isAlive())
                {
                    index = j;
                    break;
                }
            }
            if (index != -1)
                carn[i].eat(&herb[index]);
            else cout << "A wolf couldn't find anything to eat\n\n";
        }
    }
};

//----------------------------------------
class AnimalWorld
{
    Africa africa;
    NAmerica na;
    Eurasia eurasia;

public:
    void mealsHerbivores()
    {
        cout << "-----------AFRICA-----------\n\n";
        africa.mealsHerbivores();
        cout << "--------NORTH AMERICA-------\n\n";
        na.mealsHerbivores();
        cout << "-----------EURASIA----------\n\n";
        eurasia.mealsHerbivores();
    }
    void nutritionCarnivores()
    {
        cout << "-----------AFRICA-----------\n\n";
        africa.nutritionCarnivores();
        cout << "--------NORTH AMERICA-------\n\n";
        na.nutritionCarnivores();
        cout << "-----------EURASIA----------\n\n";
        eurasia.nutritionCarnivores();
    }

};
//----------------------------------------
int main()
{
    AnimalWorld world;
    world.mealsHerbivores();
    world.nutritionCarnivores();
    world.mealsHerbivores();
    world.nutritionCarnivores();
    world.mealsHerbivores();
    world.nutritionCarnivores();
    world.mealsHerbivores();
    world.nutritionCarnivores();
}
