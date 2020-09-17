#include <iostream>
#include <vector>
#include "time.h"
#include <conio.h>

class AbstrEcho
{
public:
    AbstrEcho() 
    {
        std::cout << "Constructor: AbstrEcho " << std::endl;
    }

    virtual ~AbstrEcho() 
    {
        std::cout << "Destructor: AbstrEcho " << std::endl;
    }

    virtual void EchoText() = 0;
};

class EchoA : public AbstrEcho
{
public:
    EchoA()
    {
        std::cout << "Constructor: EchoA " << std::endl;
    }

    ~EchoA() override
    {
        std::cout << "Destructor: EchoA " << std::endl;
    }
    void EchoText() override
    {
        std::cout << "This is EchoText From EchoA " << std::endl;
    }
};

class EchoB : public AbstrEcho
{
public:
    EchoB()
    {
        std::cout << "Constructor: EchoB " << std::endl;
    }

    ~EchoB() override
    {
        std::cout << "Destructor: EchoB " << std::endl;
    }
    void EchoText() override
    {
        std::cout << "This is EchoText From EchoB " << std::endl;
    }
};

int main()
{
    std::vector<AbstrEcho*> obj_list = 
    {
        new EchoA,
        new EchoA,
        new EchoB,
        new EchoB
    };

    clock_t start, end;
    start = clock();

    while (!_kbhit())  //нажата ли кнопка?
    {
        end = clock();
        if ((double)(end - start) / CLOCKS_PER_SEC >= 1) //прошла  ли секунда?
        {
            for (auto item : obj_list)
            {
                item->EchoText();
            }

            start = clock();
        }
    }

    for (auto item : obj_list)
    {
        // item->~AbstrEcho();
        // delete item;
    }
}

