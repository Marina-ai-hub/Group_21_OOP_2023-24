#include <iostream>
#include <string>
#include "../headers/Series_header.h"

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
void Series:: show(){
    Movie::show();
    cout << " Seasons : "<< seasons << endl;
}
