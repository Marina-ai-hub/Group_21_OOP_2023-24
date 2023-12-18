#ifndef GROUP_21_OOP_2023_24_GENERATION_H
#define GROUP_21_OOP_2023_24_GENERATION_H

#include <string>
#include "../Movie/Movie.h"


class Generation {
    Movie result;
public:
    Generation();
    Generation(string _title_, string _description_, string _genre_[], int len_, string _type_, float _rating_);
    Generation(const Generation& other);
    Generation(Movie& _result);
    Generation(Generation& copy);
    ~Generation();
    Movie getResult() const;
    Generation& setResult(string _title_, string _description_, string _genre_[], int len_, string _type_, float _rating_);
    void show();
};


#endif //GROUP_21_OOP_2023_24_GENERATION_H
