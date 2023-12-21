#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
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
void showMovies(const vector<Movie*> movies, int size){
    for (int i=0; i<size; i++){
        movies[i]->show();
    }
}


int main() {

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

   /* if (f_obj1.TypeSelected(ttype)) {
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
    showMovies(allmlist.movie_list,5);


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
