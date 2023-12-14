#ifndef UNTITLED11_LABOOP_H
#define UNTITLED11_LABOOP_H
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX_LEN 100
#define MAX_TYPE_LEN 3
#define MAX_GENRE_LEN 11
#endif //UNTITLED11_LABOOP_H


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
