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
    string type, genre;
    // int GenreSelected, TypeSelected;
    static string TypeFilters[MAX_LEN];    //���������� ���������� ���� ����������� �����
    static string GenreFilters[MAX_LEN];
public:
    Filters() {
        type = "no type selected";
        genre = "no type selected";
        cout << "//Default Filters constructor//" << endl;
    };
    Filters(string _type, string _genre) : type(_type), genre(_genre) {
        cout << "//Filters constructor with parameters//" << endl;
    };
    Filters(Filters& copy) {
        type = copy.type;
        genre = copy.genre;
        cout << "//Filters copy constructor//" << endl;
    };
    Filters& SetType(string _type) {
        type = _type;
        return *this;
    };
    Filters& SetGenre(string _genre) {
        genre = _genre;
        return *this;
    }
    string GetType() {
        return type;
    };
    string GetGenre() {
        return genre;
    };
    ~Filters() {
        cout << "//Filters destructor//" << endl;
    };
    void Show() {
        cout << "Selected filters: (type) - " << type << " " << "(genre) - " << genre << endl;
    };
    void ShowFilters() {
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
    // !!!����� ����쳺 �������� ����� �� false
    bool TypeSelected(const string& _type) {
        for (int i = 0; i < MAX_TYPE_LEN; i++) {
            if (_type == TypeFilters[i]) {
                return true;
            }
        }
        return false;
    };
    bool GenreSelected(const string& _genre) {
        for (int i = 0; i < MAX_GENRE_LEN; i++) {
            if (_genre == GenreFilters[i]) {
                return true;  //������� ��� ���� �������
            }
        }
        return false;
    };

};
//������������ ���������� ���� ���� ������
string Filters::TypeFilters[] = { "Film","Series", "Cartoon" };
string Filters::GenreFilters[] = { "Action", "Adventure", "Comedy", "Drama", "Fantasy", "Horror", "Musicals", "Romance", "Sci-fi", "Sports", "Thriller" };

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
    string getDescription() const{
        return description;
    }
    string getGenre() const{
        return *genre;
    }
    string getType() const{
        return type;
    }
    float getRating() const{
        return rating;
    }
    Movie& setTitle(string _title){
        title = _title;
        return *this;
    }
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
    virtual void show(){
        cout << "\n Title : "<< title << endl;
        cout << " Description : "<< description << endl;
        for (int i=0 ; i<genre_len; i++){
            if (genre != nullptr)
                cout << " Genre[" << i+1 <<"] : " << genre[i] << endl;
        }
        cout << " Type : " << type << endl;
        cout << " Rating : " << rating << endl;
    }
};

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

class MovieList {
    vector<Movie> movie_list;
};

int main() {
    Filters f;
    f.ShowFilters();
    string ggenre, ttype;
    cout << "\nPlease select (TYPE):";
    //cin>>ttype;
    getline(cin, ttype);
    cout << "Please select (GENRE):";
    getline(cin, ggenre);
    //cin>>ggenre;
    Filters f_obj0;
    Filters f_obj1(ttype, ggenre);
    f_obj0.Show();
    f_obj1.Show();

    if (f_obj1.TypeSelected(ttype)) {
        cout << "YES1!Selected" << endl;
    }
    else {
        cout << "NO1" << endl;
    }
    if (f_obj1.GenreSelected(ggenre)) {
        cout << "YES2!Selected" << endl;
        // f_obj1.GetGenre(); // � ��� ���� ������ � ��� ���������
    }
    else {
        cout << "NO2" << endl;
    }

    string m1_genres[] = {"Action", "Thriller"};
    int len1 = sizeof(m1_genres)/sizeof(m1_genres[0]);
    Movie m1("Fight Club", "Very intense", m1_genres, len1, "Film", 4.7);
    m1.show();

    string m2_genres[] = {"Musicals", "Comedy", "Romance"};
    int len2 = sizeof(m2_genres)/sizeof(m2_genres[0]);
    Movie m2("Mamma Mia", "With ABBA songs", m2_genres, len2, "Film", 4.5);
    m2.show();

    string m3_genres[] = {"Comedy"};
    int len3 = sizeof(m3_genres)/sizeof(m3_genres[0]);
    Series m3("Office", "Very funny", m3_genres, len3, "Series", 4.8, 9);
    m3.show();


    return 0;
}

