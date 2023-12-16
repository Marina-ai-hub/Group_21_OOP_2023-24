#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

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
    Movie& operator += (const string& _comment);
};

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

class MovieList {
    vector<Movie> movie_list;
public:
    MovieList();
//    void AddMovie(const Movie& movie) {
//        movie_list.push_back(movie);
//    }
    Movie& operator()(Movie&);
    MovieList& operator()(Movie&);
    Movie& operator[](int);
   // MovieList operator + (const MovieList& el);
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
   friend bool operator ==(const Movie&, const Filters&);
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
