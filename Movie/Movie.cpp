#include <iostream>
#include <string>
#include <map>
#include "Movie.h"

using namespace std;


//class Movie
Movie:: Movie(): title(""), description(""), genre(nullptr), genre_len(0), type(""), rating(0.0){};
Movie:: Movie(string _title, string _description, string _genre[], int len, string _type, float _rating){
    title = _title;
    description = _description;
    genre_len = len;
    genre = new string[len];
    for(int i=0; i<genre_len; i++){
        genre[i] = _genre[i];
    }
    type = _type;
    rating = _rating;
}
Movie:: Movie(const Movie& copy){
    title = copy.title;
    description = copy.description;
    type = copy.type;
    rating = copy.rating;
    genre_len = copy.genre_len;
    genre = new string[copy.genre_len];
    for(int i=0; i<copy.genre_len; i++){
        genre[i] = copy.genre[i];
    }
}
string Movie:: getTitle() const{
    return title;
}
string Movie:: getDescription() const{
    return description;
}
string Movie:: getGenre() const{
    return *genre;
}
string Movie::getType() const{
    return type;
}
float Movie:: getRating() const{
    return rating;
}
Movie& Movie:: setTitle(string _title){
    title = _title;
    return *this;
}
Movie& Movie:: setDescription(string _description){
    description = _description;
    return *this;
}
Movie& Movie:: setGenre(string _genre[], int len){
    genre_len = len;
    genre = new string[len];
    for (int i=0; i < genre_len; i++) {
        genre[i] = _genre[i];
    }
    return *this;
}
Movie& Movie:: setType(string _type){
    type = _type;
    return *this;
}
Movie& Movie:: setRating(float _rating){
    rating = _rating;
    return *this;
}
Movie:: ~Movie(){};
void Movie:: show() const{
    cout << "\n Title : " << title << endl;
    cout << " Description : " << description << endl;
    for (int i = 0; i < genre_len; i++) {
        if (genre != nullptr)
            cout << " Genre[" << i + 1 << "] : " << genre[i] << endl;
    }
    cout << " Type : " << type << endl;
    cout << " Rating : " << rating << endl;
}
Movie& Movie:: operator++() {
    rating++;
    if (rating > 5){
        cout << "cannot increment, rating > 5";
        rating--;
    }
    return *this;
}
Movie Movie:: operator++(int i) {
    Movie temp = *this;
    ++(*this);
    return temp;
}
Movie& Movie:: operator--() {
    rating--;
    if (rating < 0) {
        cout << "cannot decrement, rating < 0";
        rating++;
    }
    return *this;
}
Movie Movie:: operator--(int i) {
    Movie temp = *this;
    --(*this);
    return temp;
}
Movie:: Movie(const string& _title){
    title = _title;
    description = "";
    genre = nullptr;
    genre_len = 0;
    type = "";
    rating = 0.0;
}
Movie:: operator map<string, string>() const {
    map<string, string> movieMap;
    movieMap["Title"] = title;
    movieMap["Description"] = description;
    movieMap["Genre"] = genre[0];
    movieMap["Type"] = type;
    movieMap["Rating"] = to_string(rating);

    return movieMap;
}
