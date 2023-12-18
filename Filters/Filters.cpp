#include "Filters.h"

//class Filters
string Filters::TypeFilters[] = { "Film","Series", "Cartoon" };
string Filters::GenreFilters[] = { "Action", "Adventure", "Comedy", "Drama", "Fantasy", "Horror", "Musicals", "Romance", "Sci-fi", "Sports", "Thriller" };

Filters:: Filters() {
    type = "no type selected";
    genre="no genre selected";
};
Filters:: Filters(string _type, string _genre) : type(_type), genre(_genre) {};
Filters:: Filters(const Filters& copy) {
    type = copy.type;
    genre = copy.genre;
}
Filters& Filters:: SetGenre(string _genre) {
    genre = _genre;
    return *this;
}
Filters& Filters:: SetType(string _type) {
    type = _type;
    return *this;
};
string Filters:: GetType() const {
    return type;
};
string Filters:: GetGenre() const {
    return genre;
};
Filters:: ~Filters(){};
void Filters:: Show() const{
    cout << "Selected filters: (type) - " << type << " " << "(genre) - " << genre << endl;
};
void Filters:: ShowFilters(){
    cout << "===========================================================================================" << endl;
    cout << "(Type) Filters: ";
    for (int i = 0; i < MAX_TYPE_LEN; ++i) {
        cout << TypeFilters[i] << " ";
    }cout << endl;
    cout << "(Genre) Filters: ";
    for (int i = 0; i < MAX_GENRE_LEN; ++i) {
        cout << GenreFilters[i] << " ";
    }
    cout << endl << "===========================================================================================";
};
bool Filters:: TypeSelected(const string& _type) const{
    for (int i = 0; i < MAX_TYPE_LEN; i++) {
        if (_type == TypeFilters[i]) {
            return true;
        }
    }
    return false;
};
bool Filters:: GenreSelected(const string& _genre) const{
    for (int i = 0; i < MAX_GENRE_LEN; i++) {
        if (_genre == GenreFilters[i]) {
            return true;
        }
    }
    return false;
};
