#include <iostream>
#include <string>
#include <list>
using namespace std;
#define MAX_TYPE_LEN 100
#define MAX_GENRE_LEN 100

class Filters {
    int GenreSelected, TypeSelected;
    string type[3];
    string genre[11];
public:
    Filters() : GenreSelected(0), TypeSelected(0) {
        cout << "\nConstructure with no parameters" << endl;
    }
    Filters(string[]);  //реалызувати якщо бул, то задамо через цикл і тд
    Filters(string type[], string genre[]) {
        for (int i = 0; i < MAX_TYPE_LEN; i++)
            this->type[i] = type[i];
        for (int i = 0; i < MAX_GENRE_LEN; i++)
            this->genre[i] = genre[i];
        cout << "\nConstructore with parameters" << endl;
    };
    Filters(Filters& arr) {
        for (int i = 0; i < 3; i++)
            genre[i] = arr.genre[i];
        for (int i = 0; i < 11; i++)
            type[i] = arr.type[i];
    };
    Filters& SetType(string arr[], int size) {
        for (int i = 0; i < size; i++)
            type[i] = arr[i];
        return *this;
    };
    Filters& SetGenre(string arr[], int size) {
        for (int i = 0; i < size; i++)
            genre[i] = arr[i];
        return *this;
    };
    string* GetType() {
        return type;
    };
    string* GetGenre() {
        return genre;
    };
    void Show(int size) {
        //   cout<<"Selected filters: Type - "<<GetType()<<" Genre - "<<GetGenre()<<endl;
        cout << "Selected filters: Type - ";
        for (int i = 0; i < size; ++i) {
            cout << type[i] << " ";
        }
        cout << "Genre - ";
        for (int i = 0; i < size; ++i) {
            cout << genre[i] << " ";
        }
        cout << endl;
    };
    ~Filters() {};
    bool isSelected(string arr[], int size) {
        for (int i = 0; i < size; i++) {
            if (arr[i] != " ") {
                i++;
                return false;
            }
        }
        return true;
    }
};
/*
class Movie{
  //
   MovieList info;
   //
};
*/

//class MovieList{
//public:
//   string title, description, type;
//   string genre[11];
//   float rating;
//public:
//  MovieList(string title, string description, string type,string genre[], float rating){
//      /*опис існуючих фільмів*/
//      this->title=title;
//      this->description=description;
//      this->type=type;
//      for(int i=0; i<11; i++)
//          this->genre[i]=genre[i];
//      this->rating=rating;
//  };
//};
//class Movie{
//    list<MovieList> movie_list;
//    float rate; //метод щоб оцінити
//public:
//    MovieList SelectedMovie(MovieList& t, MovieList& g){
//        for(int i=0; i<3; i++){   //list<MovieList>::iterator
//            //if(movie_list[i].type==t && movie_list[i].genre==g)
//                //повернути цей елемент
//        }
//    }
//};
int main() {
    string genre[MAX_GENRE_LEN], type[MAX_TYPE_LEN];
    cout << "*Filters:\n" << "Type: Film Series Cartoon\n" << "Genre: Action, Adventure, Comedy, Drama, Fantasy, Horror, Musicals, Romance, Sci-fi, Sports, Thriller" << endl;
    cout << " (Please) enter your TYPE:";
    for (int i = 0; i < 3; i++)
        getline(cin, type[i]);
    cout << " (Please) enter your GENRE:";
    for (int i = 0; i < 5; i++)
        getline(cin, genre[i]);

    Filters obj0;
    //obj0.Show(3);
    Filters obj1(type, genre);
    obj1.Show(3);

    //for(int i = 0; i < MAX_TYPE_LEN; i++)
       // getline(cin, type[i]);
     /*getline(cin, type[MAX_TYPE_LEN]);
    cout<<" (Please) enter your GENRE:";
    getline(cin, genre[MAX_GENRE_LEN]);
    cout << endl;*/
    /* string type, genre;
    getline(cin, type);
    cout<<" (Please) enter your GENRE:";
    getline(cin, genre);*/


    return 0;
}