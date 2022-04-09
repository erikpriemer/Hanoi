# include <stack>
#include <iostream>
# include "Scheibe.cpp"

class Stapel
{

public:

    int hoehe;
    int max;
    std::stack<Scheibe*> stack;

    Stapel(int hoehe, int name, int max) : hoehe(hoehe), max(max) {};

    void PrintStack();
    bool empty();
    Scheibe* top();
    Scheibe* pop();
    void push(Scheibe*);
    bool full();

};

void Stapel::PrintStack()
{
    if (stack.empty())
    {
        std::cout << "---------" << "\n\n";
        return;
    }


    Scheibe *x = stack.top();
    stack.pop();

    std::cout << "|   " <<x->groesse << "   |" << "\n";
    PrintStack();

    stack.push(x);
}

bool Stapel::empty()
{
    if(hoehe == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Scheibe* Stapel::top()
{
    return stack.top();
}

Scheibe* Stapel::pop()
{
    Scheibe *x = stack.top();
    stack.pop();
    hoehe--;
    return x;

}

void Stapel::push(Scheibe* s)
{
    stack.push(s);
    hoehe++;
}

bool Stapel::full()
{
    if(hoehe == max)
    {
        return true;
    }
    else
    {
        return false;
    }
}