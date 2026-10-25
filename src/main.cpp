#include "highway.h"

int main()
{


    Highway myHighway = Highway("SLP-ZAC");

    t_stop periferico = t_stop{"periferico",3};
    t_stop pinos = t_stop{"pinos",10};
    t_stop troncoso = t_stop{"troncoso",80};
    t_stop bicentenario = t_stop{"bicentenario",380};

    std::pair<bool,int> distance_output={false,-1};

    myHighway.add_stop(periferico);
    myHighway.add_stop(pinos);
    myHighway.add_stop(troncoso);
    myHighway.add_stop(bicentenario);

    myHighway.show();

    distance_output = myHighway.get_distance("periferico","troncoso");
    if (distance_output.first)
    {
        std::cout << "La distancia entre Periferico y Troncoso es : " << distance_output.second << std::endl;
    } 

    distance_output = myHighway.get_distance("bicentenario","pinos");
    if (distance_output.first)
    {
        std::cout << "La distancia entre Bicentenario y Pinos es : " << distance_output.second << std::endl;
    }

    return 0;
}