#include "Generation.h"
#include <string>

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