#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include "headers/OOP_Lab2(2)_header.h"
#include "headers/Movie_header.h"
#include "headers/Series_header.h"
#include "realisations/Movie_realisation.cpp"
#include "realisations/Series_realisation.cpp"

using namespace std;
#define MAX_LEN 100
#define MAX_TYPE_LEN 3
#define MAX_GENRE_LEN 11

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

//class MovieList
MovieList:: MovieList(){};
void MovieList::operator()(Movie& movie) {
    movie_list.push_back(movie);
};
/*Movie& MovieList:: operator[](int index){
    if (index>0 && index<=5){
        return movie_list[index-1];}
};*/
Movie& MovieList::operator[](int index) {
    if (index < 0 || index >= movie_list.size()) {
        throw out_of_range("Index out of range");
    }
    return movie_list[index];
}
//MovieList MovieList:: operator + (const MovieList& el){  //я хотіла зробити це mlist(m1)+mlist(m2)
//    MovieList temp;
//    temp.movie_list=movie_list + el.movie_list;
//    return temp;
//}
MovieList MovieList:: operator+(const MovieList& other) const {
    MovieList result = *this; // Create a copy of the current MovieList

    // Concatenate the vectors
    result.movie_list.insert(result.movie_list.end(), other.movie_list.begin(), other.movie_list.end());

    return result;
}

//class Generation
Generation::Generation() {}
Generation::Generation(string _title_, string _description_, string _genre_[], int len_, string _type_, float _rating_) :result(_title_, _description_, _genre_, len_, _type_, _rating_) {}
Generation::Generation(const Generation& other) : result(other.result) {}
Generation::Generation(Movie& _result) : result(_result) {};
Generation::Generation(Generation& copy) : result(copy.result) {};
Generation::~Generation() {}
Movie Generation:: getResult() const {
    return result;
}
Generation& Generation:: setResult(string _title_, string _description_, string _genre_[], int len_, string _type_, float _rating_) {
    result.setTitle(_title_);
    result.setDescription(_description_);
    result.setGenre(_genre_, len_);
    result.setType(_type_);
    result.setRating(_rating_);
    return *this;
}
void Generation ::show() {
    cout << " Result : ";
    result.show();
    cout << endl;
}

//class User
User::User() {
    name = "Noname";
    email = "Noemail";
    password = "Nopassword";
}
User::User(string _name, string _email, string _password) : name(_name), email(_email), password(_password) {}
User::User(const User& other) :name(other.name), email(other.email), password(other.password), result(other.result) {}
User::~User() {}
string User::getName() const {
    return name;
}
User& User::setName(string newName) {
    name = newName;
    return *this;
}
string User::getEmail() const {
    return email;
}
User& User::setEmail(string newEmail) {
    email = newEmail;
    return *this;
}
string User::getPassword() const {
    return password;
}
User& User::setPassword(string newPassword) {
    password = newPassword;
    return *this;
}
Generation User::getResult() const {
    return result;
}
User& User::setResult(Generation _result) {
    result = _result;
    return *this;
}
void User::show() {
    cout << " Name : " << name << endl;
    cout << " Email : " << email << endl;
    cout << " Password : " << password << endl;
    //cout << " Result : ";
    result.show();
    cout << endl;
}


istream& operator >> (istream&is, Filters&f){
    is >> f.type;
    is >> f.genre;
    return is;
}
bool operator ==(const Movie& m_el, const Filters& f_el){
    if(m_el.type == f_el.type) {
        for (int i = 0; i < m_el.genre_len; i++) {
            if ((m_el.genre[i] == f_el.genre))
                return true;
        }
    }
    return false;
};
/*Movie& Movie:: operator += (const string& _comment){
    description+=' ';
    description+=_comment;
    return *this;
}*/

int main() {

    //check filters
    /*int temp;
    float rate;
    Filters f;
    f.ShowFilters();
    string ggenre, ttype;
    AGAIN: cout << "\nPlease select (TYPE):";
    cin>>ttype;                      //getline(cin, ttype);
    cout << "Please select (GENRE):";
    cin>>ggenre;                    //getline(cin, ggenre);
//    Filters f_obj0;
//    f_obj0.Show();
    Filters f_obj1(ttype, ggenre);
    f_obj1.Show();

    if (f_obj1.TypeSelected(ttype)) {
        cout << "YES1!Selected" << endl;
    }
    else {
        cout << "NO1" << endl;
    }
    if (f_obj1.GenreSelected(ggenre)) {
        cout << "YES2!Selected" << endl;
    }
    else {
        cout << "NO2" << endl;
    }*/


    //create movies
    string m1_genres[] = {"Action", "Thriller"};
    int len1 = sizeof(m1_genres)/sizeof(m1_genres[0]);
    Movie m1("Fight Club", "Very intense", m1_genres, len1, "Film", 3.7);

    string m2_genres[] = {"Musicals", "Comedy", "Romance"};
    int len2 = sizeof(m2_genres)/sizeof(m2_genres[0]);
    Movie m2("Mamma Mia", "With ABBA songs", m2_genres, len2, "Film", 4.5);

    string m3_genres[] = {"Comedy"};
    int len3 = sizeof(m3_genres)/sizeof(m3_genres[0]);
    Series m3("Office", "Very funny", m3_genres, len3, "Series", 0.8, 9);

    string m4_genres[] = { "Action", "Fantasy" };
    int len4 = sizeof(m4_genres) / sizeof(m4_genres[0]);
    Movie m4("The hunger games", "Very interesting", m4_genres, len4, "Film", 4.7);

    string m5_genres[] = { "Adventure", "Fantasy" };
    int len5 = sizeof(m5_genres) / sizeof(m5_genres[0]);
    Movie m5("Pirates of the Caribbean", "Very interesting", m5_genres, len5, "Film", 4.5);


    //operator ++
    m1.show(); //rating 3.7
    ++m1;
    m1.show();

    m2.show(); //rating 4.5
    ++m2;
    m2.show();


    //operator --
    m1.show(); //rating 3.7
    --m1;
    m1.show();

    m3.show(); //rating 0.8
    --m3;
    m3.show();


    //operator <<
    cout << m4 << endl;


    //operator from string to Movie
    string movie_title = "You've got mail";
    Movie movie_from_title = Movie(movie_title);
    cout << movie_from_title << endl;


    //operator from Movie to map
    map<string, string> movieMap = m1;
    auto it = movieMap.begin();
    while (it != movieMap.end()) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
        ++it;
    }


    //operator +
    MovieList mlist;
    mlist(m1); mlist(m2); mlist(m3);
    //    mlist.AddMovie(m1);
    //    mlist.AddMovie(m2);
    //    mlist.AddMovie(m3);

    MovieList mlist1;
    mlist1(m4); mlist1(m5);

    MovieList allmlist = mlist + mlist1;
    //for (int i = 0; i<5; i++){
    //    allmlist[i].show();
    //}


    //operator []
    /*cout<<"==================================================================="<<endl;
    cout<<"Enter movie's index you would like to see (from 0 to 4)"<<endl;
    int index;
    cin>>index;
    Movie& movie = mlist[index];
    movie.show();*/


    //operator += (думаю, можна забрати)
    //cout<<"==================================================================="<<endl;
    //string comment;
    //cout<<"Enter comment to the chosen film"<<endl;
    //cin>>comment;
    //movie+=comment;
    //movie.show();


    //generation and user
    /*  Generation g;
      g.show();
      cout<<"====Generation from Movie"<<endl;
      Generation g4(m2);
      g4.show();
      Generation g5(g4);
      g5.show();

      User u;
      u.show2();
      User u1("Matilda", "matilda@gmail.com", "ma123", g);
      u1.show2();
      u1.setName("lera");
      User u2(u1);
      u2.show2();
      cout<<"=================="<<endl;
      u1.~User();

      string genres[] = { "Action", "Fantasy" };
      int kot = sizeof(genres) / sizeof(genres[0]);
      Generation g1("The hunger games", "Very interesting", genres, kot, "Film", 4.7);
      g1.show();
      string genres_[] = { "Adventure", "Fantasy" };
      int kot1 = sizeof(genres_) / sizeof(genres_[0]);
      g1.setResult("Pirates of the Caribbean", "Very interesting", genres_, kot1, "Film", 4.5);
      Generation g2(g1);
      g2.show();
      */

    return 0;
}
