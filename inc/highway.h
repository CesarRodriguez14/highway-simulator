#ifndef HIGHWAY_H
#define HIGHWAY_H

#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iostream>

typedef struct {
    std::string name;
    int km;
} t_stop;

class Highway{
    private:
        std::string name;
        std::list<t_stop>Stops;
        int find_stop_km(std::string);

    public:
        Highway(std::string);
        void add_stop(t_stop);
        std::pair<bool,int> get_distance(std::string,std::string);
        void show();
};

#endif