#include "ahp.cpp"

int main(){

    string genre,country;
    string stringCompare[6][6];
    float compare[6][6];

    // initial matrix
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            compare[i][j] = 0;
        }
    }

    cout << "genre: "; cin >> genre;
    cout << "country: "; cin >> country;

    system("cls");
    cout << "Note: \n" 
    << "sama suka = 1 --> artinya jika sama sama kriterianya kasih 1\n"
    << "antara sama suka dan agak suka = 2\n"
    << "agak suka = 3\n"
    << "antara agak suka dan suka = 4\n"
    << "suka = 5\n"
    << "antara suka dan suka banget = 6\n"
    << "suka banget = 7\n"
    << "antara suka banget dan sangat suka banget = 8\n"
    << "sangat suka banget = 9" << endl;

    cout << endl;

    string label[6] = {"genre","country","visual","age","viewers","ratting"};

    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            if(i == j){
                compare[i][j] = 1.0f;
            } else {
                if(compare[i][j] == 0){
                    if(i <= j){
                        cout << "antara " << label[i] << " dan " << label[j] << " lebih suka mana? "; cin >> stringCompare[i][j];
                        cout << "rasio: "; cin >> compare[i][j];
                        compare[j][i] = (1.0f / compare[i][j]);
                    }
                }
            }
        }
    }   

    cout << endl;
    cout << "==========perbandingan kriteria==========\n";
    CriteriaComparasion(compare,stringCompare,label);
    cout << endl;
    cout << "==========alternatif genre==========\n";
    AlternativeForGenre();
    cout << endl;
    cout << "==========alternatif country==========\n";
    AlternativeForCountry();
    cout << endl;
    cout << "==========alternatif visual==========\n";
    AlternativeForVisual();
    cout << endl;
    cout << "==========alternatif age==========\n";
    AlternativeForAge();
    cout << endl;
    cout << "==========alternatif viewers==========\n";
    AlternativeForViewer();
    cout << endl;
    cout << "==========alternatif ratting==========\n";
    AlternativeForRatting();
    cout << endl;
    cout << "==========ranking==========\n";
    Ranking();

    cin.get();
}