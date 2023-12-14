#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include "LabOOP.h"

using namespace std;
#define MAX_LEN 100
#define MAX_TYPE_LEN 3
#define MAX_GENRE_LEN 11

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


class Movie {
    string title;
    string description;
    string *genre;
    int genre_len;
    string type;
    float rating;
public:
    Movie(): title(""), description(""), genre(nullptr), genre_len(0), type(""), rating(0.0) {
        cout << "//Default Movie constructor//" << endl;
    }
    Movie(string _title, string _description, string _genre[], int len, string _type, float _rating):
    title(_title), description(_description), type(_type), rating(_rating) {
        genre_len = len;
        genre = new string[len];
        for(int i=0; i<genre_len; i++){
            genre[i] = _genre[i];
        }
        cout << "//Movie constructor with parameters//" << endl;
    }
    Movie(const Movie& copy){
        title = copy.title;
        description = copy.description;
        type = copy.type;
        rating = copy.rating;
        genre_len = copy.genre_len;
        genre = new string[copy.genre_len];
        for(int i=0; i<copy.genre_len; i++){
            genre[i] = copy.genre[i];
        }
        cout << "//Movie copy constructor//" << endl;
    }
    string getTitle() const{
        return title;
    }
    string getDescription() const;
    string getGenre() const{
        return *genre;
    }
    string getType() const{
        return type;
    }
    float getRating() const{
        return rating;
    }
    Movie& setTitle(string _title);
    Movie& setDescription(string _description){
        description = _description;
        return *this;
    }
    Movie& setGenre(string _genre[], int len){
        genre_len = len;
        genre = new string[len];
        for (int i=0; i < MAX_LEN; i++) {
            genre[i] = _genre[i];
        }
        return *this;
    }
    Movie& setType(string _type){
        type = _type;
        return *this;
    }
    Movie& setRating(float _rating){
        rating = _rating;
        return *this;
    }
    ~Movie(){
         cout << "//Movie destructor//" << endl;
    }
    virtual void show();
};

string Movie:: getDescription() const{
    return description;
}

Movie& Movie:: setTitle(string _title){
    title = _title;
    return *this;
}

void Movie:: show(){
    cout << "\n Title : "<< title << endl;
    cout << " Description : "<< description << endl;
    for (int i=0 ; i<genre_len; i++){
        if (genre != nullptr)
            cout << " Genre[" << i+1 <<"] : " << genre[i] << endl;
    }

class Series: public Movie {
    int seasons;
public:
    Series(): seasons(0){
        cout << "//Series default constructor//" << endl;
    }
    Series(string _title, string _description, string _genre[], int len, string _type, float _rating, int _seasons):
    Movie(_title, _description, _genre, len, _type, _rating), seasons(_seasons){
        cout << "//Series constructor with parameter//" << endl;
    }
    Series(const Series& copy): Movie(copy), seasons(copy.seasons){
        cout << "//Series copy constructor//" << endl;
    }
    int getSeasons() const{
        return seasons;
    }
    Series& setSeasons(int _seasons){
        seasons = _seasons;
        return *this;
    }
    ~Series(){
        cout << "//Series destructor//" << endl;
    }
    void show(){
        Movie::show();
        cout << " Seasons : "<< seasons << endl;
    }
};


MovieList:: MovieList(){};
Movie& MovieList::operator()(Movie& movie) {
    movie_list.push_back(movie);
};

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

User::User() {
    name = "Noname";
    email = "Noemail";
    password = "Nopassword";
}
User::User(string _name, string _email, string _password) : name(_name), email(_email), password(_password) {
}

User::User(const User& other) :name(other.name), email(other.email), password(other.password), result(other.result) {
}
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

int main() {
    int temp;
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
    }

    string m1_genres[] = {"Action", "Thriller"};
    int len1 = sizeof(m1_genres)/sizeof(m1_genres[0]);
    Movie m1("Fight Club", "Very intense", m1_genres, len1, "Film", 4.7);
    //m1.show();

    string m2_genres[] = {"Musicals", "Comedy", "Romance"};
    int len2 = sizeof(m2_genres)/sizeof(m2_genres[0]);
    Movie m2("Mamma Mia", "With ABBA songs", m2_genres, len2, "Film", 4.5);
    //m2.show();

    string m3_genres[] = {"Comedy"};
    int len3 = sizeof(m3_genres)/sizeof(m3_genres[0]);
    Series m3("Office", "Very fuuny", m3_genres, len3, "Series", 4.8, 9);
    //m3.show();

    MovieList mlist;
    mlist(m1); mlist(m2); mlist(m3);
//    mlist.AddMovie(m1);
//    mlist.AddMovie(m2);
//    mlist.AddMovie(m3);
  cout<<"==================================================================="<<endl;
   if(m1==f_obj1) {
       //m1.show();
       Generation g(m1);
       g.show();
       cout<<"\nRate the movie"<<endl;
       cin>>rate;   //перетворення типу можна зробити та після записати у клас Муві/Мувіліст
   }
   if(m2==f_obj1){
       Generation g(m2);
       g.show();
   }
   if(m3==f_obj1) {
       //cout << "Generated film - " << m3.title << endl;
       Generation g(m3);
       g.show();
   }

   cout<<"Do you want to enter filters again?(Enter 1)"<<endl;
   cin>>temp;
   if(temp==1) goto AGAIN;


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
    /*
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

