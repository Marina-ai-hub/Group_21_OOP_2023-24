#ifndef Series_header
#define Series_header

#include <iostream>
#include <string>
#include <string.h>
#include "Movie_header.h"

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
    void show();
};

#endif //Series_header
