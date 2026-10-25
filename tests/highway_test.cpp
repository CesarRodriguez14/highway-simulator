#include <gtest/gtest.h>
#include "highway.h"

TEST(Highway_test,GetDistance){

    Highway h("Route 66");

    t_stop stop1{"CityA", 10};
    t_stop stop2{"CityB", 250};

    h.add_stop(stop1);
    h.add_stop(stop2);

    std::pair<bool,int> result = h.get_distance("CityA","CityB");

    EXPECT_TRUE(result.first);
    EXPECT_EQ(result.second, 240);

}