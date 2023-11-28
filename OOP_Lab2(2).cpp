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
    static string TypeFilters[MAX_LEN];    //оголошення статичного поля всередениці класу
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
    // !!!тільки розуміє маленьку літеру як false
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
                return true;  //знайшли хоч один елемент
            }
        }
        return false;
    };

};
//ініціалізація статичного поля поза класом
string Filters::TypeFilters[] = { "Film","Series", "Cartoon" };
string Filters::GenreFilters[] = { "Action", "Adventure", "Comedy", "Drama", "Fantasy", "Horror", "Musicals", "Romance", "Sci-fi", "Sports", "Thriller" };

class Movie {

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
        // f_obj1.GetGenre(); // і далі щось робити з цим значенням
    }
    else {
        cout << "NO2" << endl;
    }

    return 0;
}
