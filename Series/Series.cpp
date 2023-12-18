#include <iostream>
#include <string>
#include "Series.h"

using namespace std;

//class Series
Series:: Series(): seasons(0){};
Series::  Series(string _title, string _description, string _genre[], int len, string _type, float _rating, int _seasons):
        Movie(_title, _description, _genre, len, _type, _rating), seasons(_seasons){};
Series:: Series(const Series& copy): Movie(copy), seasons(copy.seasons){};
int Series:: getSeasons() const{
    return seasons;
}
Series& Series:: setSeasons(int _seasons){
    seasons = _seasons;
    return *this;
}
Series:: ~Series(){};
void Series:: show() const{
    cout << "\n Title : " << title << endl;
    cout << " Description : " << description << endl;
    for (int i = 0; i < genre_len; i++) {
        if (genre != nullptr)
            cout << " Genre[" << i + 1 << "] : " << genre[i] << endl;
    }
    cout << " Type : " << type << endl;
    cout << " Rating : " << rating << endl;
    cout << " Seasons : "<< seasons << endl;
}
