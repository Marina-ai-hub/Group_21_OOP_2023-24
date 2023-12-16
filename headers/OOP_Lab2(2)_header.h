#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include "Movie_header.h"

using namespace std;
#define MAX_LEN 100
#define MAX_TYPE_LEN 3
#define MAX_GENRE_LEN 11


class Filters {
//    friend class Generation;
//private:
public:
    string type, genre;
    static string TypeFilters[MAX_LEN];
    static string GenreFilters[MAX_LEN];
public:
    Filters();
    Filters(string _type, string _genre);
    Filters(const Filters& copy);
    Filters& SetType(string _type);
    Filters& SetGenre(string _genre);
    string GetType() const;
    string GetGenre() const;
    ~Filters();
    void Show() const;
    static void ShowFilters();
    bool TypeSelected(const string& _type) const;
    bool GenreSelected(const string& _genre) const;
    friend istream& operator >> (istream&, Filters&);
};



class MovieList {
    vector<Movie> movie_list;
public:
    MovieList();
//    void AddMovie(const Movie& movie) {
//        movie_list.push_back(movie);
//    }
    void operator()(Movie&);
    //MovieList& operator()(Movie&);
    Movie& operator[](int);
    MovieList operator + (const MovieList& other) const;
};

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

class User {
    string name;
    string email;
    string password;
    Generation result;
public:
    User();
    User(string _name, string _email, string _password);
    User(const User& other);
    ~User();
    string getName() const;
    User& setName(string newName);
    string getEmail() const;
    User& setEmail(string newEmail);
    string getPassword() const;
    User& setPassword(string newPassword);
    Generation getResult() const;
    User& setResult(Generation _result);
    void show();
};