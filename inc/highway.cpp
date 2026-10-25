#include "highway.h"

Highway::Highway(std::string _name)
{
    name = _name;
}

void Highway::add_stop(t_stop _stop)
{
    Stops.push_back(_stop);
}

int Highway::find_stop_km(std::string _name)
{
    int ret_val = -1;
    std::list<t_stop>::iterator it = std::find_if(Stops.begin(), Stops.end(), [_name](const t_stop& s) {
    return s.name == _name;
    });

    if(it!=Stops.end())
    {
        ret_val = (*it).km;
    }
    return ret_val;
}

void Highway:: show()
{
    std::cout << "Highway: " << name << std::endl << std::endl;
    std::cout << "Stops:"<< std::endl;
    for(t_stop _stop : Stops)
    {
        std::cout << "Stop: "<< _stop.name << " Kms: " <<_stop.km << std::endl; 
    }
}

std::pair<bool,int> Highway::get_distance(std::string _name_1,std::string _name_2)
{
    bool return_bool_val = false;
    int return_km_val = -1;
    int km_1 = -1;
    int km_2 = -1;
    
    km_1 = find_stop_km(_name_1);
    km_2 = find_stop_km(_name_2);

    if(km_1 != -1 && km_2 != -1)
    {
        return_bool_val = true;
        return_km_val = km_2 - km_1;

    }
    return {return_bool_val,return_km_val};

}