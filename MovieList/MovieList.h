#ifndef GROUP_21_OOP_2023_24_MOVIELIST_H
#define GROUP_21_OOP_2023_24_MOVIELIST_H


class MovieList {
    vector<Movie*> movie_list;
public:
    MovieList();
//    void AddMovie(const Movie& movie) {
//        movie_list.push_back(movie);
//    }
    void operator()(Movie*);
    //MovieList& operator()(Movie&);
    Movie* operator[](int);
    MovieList operator + (const MovieList& other) const;
    void showMovies(int) const;
};


#endif //GROUP_21_OOP_2023_24_MOVIELIST_H
