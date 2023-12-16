#ifndef Movie_header
#define Movie_header

#include <iostream>
#include <string>
#include <string.h>
#include <map>

using namespace std;

class Movie {
public:
    string title;
    string description;
    string *genre;
    int genre_len;
    string type;
    float rating;
public:
    Movie();
    Movie(string _title, string _description, string _genre[], int len, string _type, float _rating);
    Movie(const Movie& copy);
    string getTitle() const;
    string getDescription() const;
    string getGenre() const;
    string getType() const;
    float getRating() const;
    Movie& setTitle(string _title);
    Movie& setDescription(string _description);
    Movie& setGenre(string _genre[], int len);
    Movie& setType(string _type);
    Movie& setRating(float _rating);
    virtual ~Movie();
    virtual void show();
    Movie& operator++();
    Movie& operator--();
    friend ostream& operator<<(std::ostream& os, const Movie& movie);
    Movie(const string& _title);
    operator map<std::string, std::string>() const;
};

#endif //Movie_header