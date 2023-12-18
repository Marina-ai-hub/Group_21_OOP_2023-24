#ifndef GROUP_21_OOP_2023_24_SERIES_H
#define GROUP_21_OOP_2023_24_SERIES_H

#include <iostream>
#include <string>
#include <string.h>
#include "../Movie/Movie.h"

using namespace std;


class Series: public Movie {
    int seasons;
public:
    Series();
    Series(string _title, string _description, string _genre[], int len, string _type, float _rating, int _seasons);
    Series(const Series& copy);
    int getSeasons() const;
    Series& setSeasons(int _seasons);
    ~Series();
    void show() const;
};

#endif //GROUP_21_OOP_2023_24_SERIES_H
