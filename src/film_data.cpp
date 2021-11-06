#include<string>

using namespace std;

struct film{
    string title,genre,visual,age,country,ratting,viewers;
};

void FilmData(){
    film film1,film2,film3,film4;

    film1.title = "Logan";
    film1.genre = "Action";
    film1.visual = "Blue-Ray";
    film1.age = "17+";
    film1.country = "USA";
    film1.ratting = "8.5";
    film1.viewers = "270";

    film2.title = "The Dictator";
    film2.genre = "Comedy";
    film2.visual = "Blue-Ray";
    film1.age = "18+";
    film1.country = "USA";
    film2.ratting = "8.2";
    film2.viewers = "120";

    film3.title = "50 First Kisses";
    film3.genre = "Romance";
    film3.visual = "Blue-Ray";
    film1.age = "17+";
    film1.country = "Japan";
    film3.ratting = "8.5";
    film3.viewers = "270";

    film4.title = "Rurouni Kenshin";
    film4.genre = "Historical";
    film4.visual = "Blue-Ray";
    film4.age = "17+";
    film4.country = "Japan";
    film4.ratting = "8.8";
    film4.viewers = "270";
}