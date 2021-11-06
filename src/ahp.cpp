#include<iostream>
#include "film_data.cpp"

void CriteriaComparasion(float compare[][6],string stringCompare[][6],string label[6]){
    float criteriaMatrix[6][6];
    float denominator = 1;

    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            criteriaMatrix[i][j] = (float) compare[i][j];
        }
    }

    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            if(stringCompare[i][j] == label[i]){
                criteriaMatrix[i][j] = (denominator / compare[i][j]);
                criteriaMatrix[j][i] = (denominator / compare[j][i]);
            }
        }
    }

    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            cout << criteriaMatrix[i][j] << endl;
        }
    }

    // eigen
    float eigen[6][6];
    float totalGenre = 0,totalVisual = 0,totalAge = 0,totalViewers = 0,totalRatting = 0,totalCountry = 0;

    for(int i = 0; i <= 5; i++){
        totalGenre += criteriaMatrix[0][i];
        totalCountry += criteriaMatrix[1][i];
        totalVisual += criteriaMatrix[2][i];
        totalAge += criteriaMatrix[3][i];
        totalViewers += criteriaMatrix[4][i];
        totalRatting += criteriaMatrix[5][i];
    }

    cout << endl;
    cout << totalGenre << endl;
    cout << totalCountry << endl;
    cout << totalVisual << endl;
    cout << totalAge << endl;
    cout << totalViewers << endl;
    cout << totalRatting << endl;

    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            if(i == 0){
                eigen[i][j] = (criteriaMatrix[i][j] / totalGenre);
            } else if(i == 1){
                eigen[i][j] = (criteriaMatrix[i][j] / totalCountry);
            } else if(i == 2){
                eigen[i][j] = (criteriaMatrix[i][j] / totalVisual);
            } else if(i == 3){
                eigen[i][j] = (criteriaMatrix[i][j] / totalAge);
            } else if(i == 4){
                eigen[i][j] = (criteriaMatrix[i][j] / totalViewers);
            } else if(i == 5){
                eigen[i][j] = (criteriaMatrix[i][j] / totalRatting);
            }
        }
    }
}