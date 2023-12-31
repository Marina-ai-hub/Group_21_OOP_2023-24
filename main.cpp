#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
#include "Movie/Movie.h"
#include "Movie/Movie.cpp"
#include "Series/Series.h"
#include "Series/Series.cpp"
#include "Filters/Filters.h"
#include "Filters/Filters.cpp"
#include "MovieList/MovieList.h"
#include "MovieList/MovieList.cpp"
#include "Generation/Generation.h"
#include "Generation/Generation.cpp"
#include "User/User.h"
#include "User/User.cpp"

using namespace std;
#define MAX_LEN 100
#define MAX_TYPE_LEN 3
#define MAX_GENRE_LEN 11


istream& operator >> (istream&is, Filters&f){
    is >> f.type;
    is >> f.genre;
    return is;
}
ostream& operator << (ostream& os, const Filters&f){
    os<<"Selected filters: (type) - " << f.type << " " << "(genre) - " << f.genre;
    return os;
};
ostream& operator<<(ostream& out, const Movie& movie) {
    out << "\nTitle: " << movie.title << "\n"
        << "Description: " << movie.description << "\n"
        << "Genre: ";
    for (int i = 0; i < movie.genre_len; i++) {
        out << movie.genre[i];
        if (i != movie.genre_len - 1) {
            out << ", ";
        }
    }
    out << "\nType: " << movie.type << "\nRating: " << movie.rating << std::endl;
    return out;
}

template <class T1,class T2>
class Rate{
//    string res_title;
//    float res_rating;
    T1 title;
    T2 rating;
public:
    Rate<T1,T2>();
    Rate<T1,T2>(const  Rate&);
    Rate<T1,T2>(T1 _title, T2 _rating);
    ~Rate<T1,T2>(){};
    void show();
    T1 getTitle() const;
    T2 getRating() const;
    void setNewRating(const float value);
};
template <class T1,class T2>
Rate<T1,T2>:: Rate(){
    title="no movie";
    rating=0.0;
};
template <class T1,class T2>
Rate<T1,T2>:: Rate(const  Rate& copy): title(copy.title), rating( copy.rating){};

template <class T1,class T2>
Rate<T1,T2>:: Rate(T1 _title, T2 _rating): title(_title),rating( _rating){};

template <class T1,class T2>
void Rate<T1,T2>:: show(){
    cout<<"Your rated movie: (title) - " << title << " " << "(rating) - " << rating <<endl;
}
template <class T1,class T2>
T1 Rate<T1,T2>:: getTitle() const {
    return title;
}
template <class T1,class T2>
T2 Rate<T1,T2>:: getRating() const {
    return rating;
};
template <class T1,class T2>
void Rate<T1,T2>:: setNewRating(const float value){
    if (value > 5 || value < 0){
        cout << "rating must be from 0 to 5" << endl;
        return;
    }
    T2 new_rating = (getRating() + value) / 2;
    rating=new_rating;
};

//часткова спеціалізація для шаблонного класу
template <class T2>
class Rate<Movie,T2> {
    Movie title;
    T2 rating;
public:
    Rate<Movie,T2>() : title(), rating(0.0) {}
    Rate<Movie,T2>(const Rate<Movie,T2> &copy) : title(copy.title), rating(copy.rating) {}
    Rate<Movie,T2>(Movie _title, T2 _rating) : title(_title), rating(_rating) {}
    ~Rate<Movie,T2>(){};
    Movie getTitle() const {
        return title;
    }
    T2 getRating() const {
        return rating;
    }
    void show() {
        cout << "Your rated movie: (title) - " << title.getTitle() << " " << "(rating) - " << rating << endl;
    }
    void setNewRating(const T2 value){
        T2 new_rating = (getRating() + value) / 2;
        rating=new_rating;
    };
};

//повна спеціалізація для шаблонного класу
template <>
class Rate<Movie,Movie> {
    Movie title;
    Movie rating;

public:
    Rate<Movie,Movie>() : title(), rating() {}
    Rate<Movie,Movie>(const Rate<Movie,Movie> &copy) : title(copy.title), rating(copy.rating) {}
    Rate<Movie,Movie>(Movie _title, Movie _rating) : title(_title), rating(_rating) {}
    ~Rate<Movie,Movie>(){};
    Movie getTitle() const {
        return title;
    }
    Movie getRating() const {
        return rating;
    }
    void show() {
        cout << "Your rated movie: (title) - " << title.getTitle() << " " << "(rating) - " << rating.getRating() << endl;
    }
};

bool compareByRating(const Movie* a, const Movie* b) {
    return a->rating > b->rating;
}


int main() {
    int temp, index;
    float rate;
    string tmp;
    //create movies
    string m1_genres[] = {"Action", "Thriller"};
    int len1 = sizeof(m1_genres)/sizeof(m1_genres[0]);
    Movie m1("Fight Club", "Very intense", m1_genres, len1, "Film", 3);

    string m2_genres[] = {"Musicals", "Comedy", "Romance"};
    int len2 = sizeof(m2_genres)/sizeof(m2_genres[0]);
    Movie m2("Mamma Mia", "With ABBA songs", m2_genres, len2, "Film", 4.5);

    string m3_genres[] = {"Comedy"};
    int len3 = sizeof(m3_genres)/sizeof(m3_genres[0]);
    Movie m3("Happy New Year", "Very funny", m3_genres, len3, "Cartoon", 0.8);

    string m4_genres[] = { "Action", "Fantasy" };
    int len4 = sizeof(m4_genres) / sizeof(m4_genres[0]);
    Movie m4("The hunger games", "Very interesting", m4_genres, len4, "Film", 4.7);

    string m5_genres[] = { "Adventure", "Fantasy" };
    int len5 = sizeof(m5_genres) / sizeof(m5_genres[0]);
    Movie m5("Pirates of the Caribbean", "Very interesting", m5_genres, len5, "Film", 4.5);

    // //operator ()
    //  MovieList mlist;
    //  mlist(&m1); mlist(&m2); mlist(&m3); mlist(&m4); mlist(&m5);
    //  vector<Movie> movie_list;
    //  movie_list.push_back(m1);
    //  movie_list.push_back(m2);
    //  movie_list.push_back(m3);
    //  movie_list.push_back(m4);
    //  movie_list.push_back(m5);
    //  for(const auto&elem: movie_list){
    //      cout<<"==movie: "<<elem<<endl;
    //  }//алгоритм стл
    //   //operator []
    // cout<<"Enter movie's index you would like to see (from 1 to 5)"<<endl;
    //  cin>>index;
    //  Movie* movie = mlist[index];


    //vector
    vector<Movie*> movie_list;
    movie_list.push_back(&m1);
    movie_list.push_back(&m2);
    movie_list.push_back(&m3);
    movie_list.push_back(&m4);
    movie_list.push_back(&m5);
    //iterator
    for(const auto elem: movie_list){
        cout<<"==movie: "<<*elem<<endl;
    }

    //find in vector
    cout << endl << "====================find=====================" << endl;
    Movie m6;
    auto it = find(begin(movie_list), end(movie_list), &m2);
    if (it != end(movie_list)){
        cout << "''"<< m2.getTitle() << "''" << " found at position " << it - begin(movie_list) + 1 << endl;
    }
    else {
        cout << "element is not found" << endl;
    }

    //sort vector
    cout << endl << "====================sort=====================" << endl;
    sort(begin(movie_list), end(movie_list), &compareByRating);
    for(const auto elem: movie_list) {
        cout << "==movie: " << *elem << endl;
    }

    //map
    cout<<"Enter movie's index you would like to see (from 1 to 5)"<<endl;
    cin>>index;
    Movie* movie = movie_list[index-1];
    map<string,string> movie_container;
    movie_container["Title"] = movie->getTitle();
    movie_container["Description"] = movie->getDescription();
    movie_container["Genre"] = movie->getGenre();
    movie_container["Type"] = movie->getType();
    //reverse iterator
    for(auto elem = movie_container.rbegin(); elem != movie_container.rend(); ++elem){
        cout<<elem->first<<": "<<elem->second<<endl;
    }
    cout << endl;
    for(const auto&elem: movie_container){
        cout<<elem.first<<": "<<elem.second<<endl;
    }

    //template class
    float user_rate;
    cout<<"\n======= template class ======="<<endl;
    Rate<string,float> r0;
    cout<<"<string,float> for default: ";
    r0.show();
    Rate<int, int> r1(1984, m1.getRating());
    cout<<": ";
    r1.show();
    Rate<Movie,Movie> r2(m2,m5);  //повна спеціалізація для шаблонного класу
    cout<<"<Movie,Movie>: ";
    r2.show();

    Rate<string, double> r3(movie->getTitle(), movie->getRating());
    cout<< endl << "<string, double> for your chosen movie: ";
    r3.show();

    cout<<"====================="<<endl;
    cout<<"Enter new rating for the "<<"''"<<r3.getTitle()<<"''"<<endl;
    cin>>rate;
    r3.setNewRating(rate); cout<<"New rating: "<<r3.getRating()<<endl;

    string m7_genres[] = {"Fantasy"};
    int len7 = sizeof(m7_genres) / sizeof(m7_genres[0]);
    Movie m7("Harry Potter", "Very interesting", m7_genres, len7, "Film");
    cout<<"=======Enter rating for the "<<"''"<<m7.getTitle()<<"''"<<endl;
    cin>>user_rate;
    Rate<Movie,float> r4(m7,user_rate);  //часткова спеціалізація для шаблонного класу
    cout<<"<Movie,float>: ";
    r4.show();

/*
    //static
    int temp, index;
    float rate;
    Filters f;
    Filters:: ShowFilters();

    //check filters
    string ggenre, ttype;

    //operator >>
    cout << "\nPlease select (TYPE):";
    cin>>ttype;                      //getline(cin, ttype);
    cout << "Please select (GENRE):";
    cin>>ggenre;                    //getline(cin, ggenre);
    Filters f_obj1(ttype, ggenre);
    f_obj1.Show();
    //operator <<
    cout<<"=========  operator << ========"<<endl;
    cout<<f_obj1<<endl;

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
/*
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
    cout<<"=========  operator ++ postfix for Movie ========"<<endl;
    m1++.show(); //rating 3.7
    m1.show();

    cout<<"=========  operator ++ prefix for Movie ========"<<endl;
    m2.show(); //rating 4.5
    ++m2;
    m2.show();

    //operator --
    cout<<"=========  operator -- postfix for Movie ========"<<endl;
    m1--.show(); //rating 3.7
    m1.show();

    cout<<"=========  operator -- prefix for Movie ========"<<endl;
    m3.show(); //rating 0.8
    --m3;
    m3.show();

    cout<<"=========  operator << for Movie ========"<<endl;
    //operator <<
    cout << m4 << endl;

    //operator from string to Movie
      cout<<"=========  operator from string to Movie ========"<<endl;
      string movie_title = "You've got mail";
      Movie movie_from_title = Movie(movie_title);
      cout << movie_from_title << endl;

      //operator from Movie to map
    cout<<"=========  operator from Movie to map ========"<<endl;
      map<string, string> movieMap = m1;
      auto it = movieMap.begin();
      while (it != movieMap.end()) {
          cout << "Key: " << it->first << ", Value: " << it->second << endl;
          ++it;
      }

    //operator ()
    MovieList mlist;
    mlist(&m1); mlist(&m2); mlist(&m3);
    MovieList mlist1;
    mlist1(&m4); mlist1(&m5);
    mlist.showMovies(3);

    //operator +
    cout<<"======= operator + for MovieList =========="<<endl;
    MovieList allmlist = mlist + mlist1;
//    for (int i = 0; i<5; i++){
//        allmlist[i]->show();
//    }

    cout<<"==================================================================="<<endl;
    //operator []
    cout<<"Enter movie's index you would like to see (from 1 to 5)"<<endl;
    cin>>index;
    Movie* movie = allmlist[index];
    movie->show();

   //virtual method show()
     cout<<"====== virtual method show() ========"<<endl;
//   for(int i=0; i<5; i++){
//       allmlist[i]->show();
//   }
    allmlist.showMovies(5);


    //operator ==
    cout<<"=======( operator == )=========="<<endl;
      string name;
     const User u("anonim01", "anonim@gmail.com", "anonim123");
     cout<<"Enter (user name)"<<endl;
     cin>>name;
    User u1(name,"matilda@gmail.com", "ma123");
    if(u1==u) cout<<"This user name already exists"<<endl;
    else cout<<"Thank you for the authorization"<<endl;

    //operator =
    cout << "=======( operator = )==========" << endl;
    Generation g;
    g.show();
    cout << "====Generation from Movie" << endl;
    Generation g4(m1);
    g4.show();
    //Generation g5(g4);
    //g5.show();
    g = g4;
    g.show();

    //generation and user
      Generation g;
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
