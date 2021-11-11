#include<string>

using namespace std;

struct film{
    string charFilm,title,genre,visual,age,country,ratting,viewers;
    float scoreResult;
};

// global variables for film
film film1,film2,film3,film4;

void FilmData(){

    film1.charFilm = "Film A";
    film1.title = "Logan";
    film1.genre = "Action";
    film1.visual = "Blue-Ray";
    film1.age = "17+";
    film1.country = "USA";
    film1.ratting = "8.5";
    film1.viewers = "270";

    film2.charFilm = "Film B";
    film2.title = "Break Mansion";
    film2.genre = "Action";
    film2.visual = "Blue-Ray";
    film2.age = "17+";
    film2.country = "USA";
    film2.ratting = "8.2";
    film2.viewers = "120";

    film3.charFilm = "Film C";
    film3.title = "The Avenger";
    film3.genre = "Action";
    film3.visual = "Blue-Ray";
    film3.age = "17+";
    film3.country = "USA";
    film3.ratting = "8.5";
    film3.viewers = "270";

    film4.charFilm = "Film D";
    film4.title = "The Last Stand";
    film4.genre = "USA";
    film4.visual = "Blue-Ray";
    film4.age = "17+";
    film4.country = "USA";
    film4.ratting = "8.8";
    film4.viewers = "270";
}