#include "MovieList.h"

//class MovieList
MovieList:: MovieList(){};
void MovieList::operator()(Movie* movie) {
    movie_list.push_back(movie);
};
Movie* MovieList::operator[](int index) {
    return movie_list[index];
}
MovieList MovieList:: operator+(const MovieList& other) const {
    MovieList result = *this;
    result.movie_list.insert(result.movie_list.end(), other.movie_list.begin(), other.movie_list.end());

    return result;
}