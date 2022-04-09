#include "Stapel.cpp"

struct Zug
{
    int quelle;
    int ziel;

    Zug(int quelle, int ziel): quelle(quelle), ziel(ziel) {};
};


class Spiel
{

public:
    int scheibenanzahl;
    Stapel* stapel[3];

    Spiel()
    {
        while(true)
        {
            std::cout << "Stapelsize:";
            std::cin >> scheibenanzahl;
            if(scheibenanzahl > 0)
            {
                break;
            }
            std::cout << "Stapelgroesse zu klein! \n";

        }
        stapel[0] = new Stapel(scheibenanzahl, 0, scheibenanzahl);
        stapel[1] = new Stapel(0, 1, scheibenanzahl);
        stapel[2] = new Stapel(0, 2, scheibenanzahl);

        for(int i = scheibenanzahl; i > 0; i--)
        {
            Scheibe *s = new Scheibe(i);
            stapel[0]->stack.push(s);
        }
    };
    Zug zugEingabe();
    bool zugPruefen(Zug);
    void ziehen(Zug);
    void darstellen();
    void message(char* message);
};

void Spiel::darstellen()
{
    stapel[0]->PrintStack();
    stapel[1]->PrintStack();
    stapel[2]->PrintStack();
}

Zug Spiel::zugEingabe()
{
    int cmd[2];
    std::cout << "Eingabe: ";
    std::cin >> cmd[0];

    if(cmd[0] >= 0 && cmd[0] <= 5)
    {
        std::cin >> cmd[1];

        int quelle = cmd[0];
        int ziel = cmd[1];
        Zug zug(quelle, ziel);

        return zug;
    }
    else
    {
        Spiel::message("B");
    }
}

void Spiel::message(char* message)
{
    if(message == "A")
    {
        std::cout << "Message: Gratulation sie haben gewonnen!" << "\n";
    }

    if(message == "B")
    {
        std::cout << "Message: Fehler, eingegebener Spielzug nicht möglich!" << "\n";
    }

    if(message == "C")
    {
        std::cout << "Message: Nächster Zug!" << "\n";
    }
}


bool Spiel::zugPruefen(Zug zug)
{
    if(!stapel[zug.quelle]->empty())
    {

        if(stapel[zug.ziel]->empty() || stapel[zug.quelle]->top()->groesse < stapel[zug.ziel]->top()->groesse)
        {
            return true;
        }
    }
    return false;
}


void Spiel::ziehen(Zug zug)
{
    Scheibe *temp = stapel[zug.quelle]->pop();
    stapel[zug.ziel]->push(temp);

    if(stapel[2]->full())
    {
        darstellen();
        message("A");
        exit(0);
    }
}


