#include<iostream>
#include "film_data.cpp"

void CriteriaComparasion(float compare[][6],string stringCompare[][6],string label[6]){
    float criteriaMatrix[6][6];
    float denominator = 1;

    // put ratio compare criteria into matrix
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            criteriaMatrix[i][j] = (float) compare[i][j];
        }
    }

    // compare favorable criteria 
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            if(stringCompare[i][j] == label[i]){
                criteriaMatrix[i][j] = (denominator / compare[i][j]); // put ij 1/ratio
                criteriaMatrix[j][i] = (denominator / compare[j][i]); // put ji 1/ratio
            }
        }
    }

    // print criteria compare
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            cout << criteriaMatrix[i][j] << endl;
        }
    }

    // eigen
    float eigen[6][6];
    float totalGenre = 0,totalVisual = 0,totalAge = 0,totalViewers = 0,totalRatting = 0,totalCountry = 0;

    // sum criteria culumn
    for(int i = 0; i <= 5; i++){
        totalGenre += criteriaMatrix[0][i];
        totalCountry += criteriaMatrix[1][i];
        totalVisual += criteriaMatrix[2][i];
        totalAge += criteriaMatrix[3][i];
        totalViewers += criteriaMatrix[4][i];
        totalRatting += criteriaMatrix[5][i];
    }

    // print sum each criteria column
    cout << endl;
    cout << totalGenre << endl;
    cout << totalCountry << endl;
    cout << totalVisual << endl;
    cout << totalAge << endl;
    cout << totalViewers << endl;
    cout << totalRatting << endl;

    // eigen value criteria column / total criteria column
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

    // print eigen value
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            cout << eigen[i][j] << endl;
        }
    }

    // sum eigen criteria row
    float totalEigenForGenre = 0,totalEigenForCountry = 0,totalEigenForVisual = 0,totalEigenForAge = 0,totalEigenForViewers = 0,totalEigenForRatting = 0;

    for(int j = 0; j <= 5; j++){
        totalEigenForGenre += eigen[j][0];
        totalEigenForCountry += eigen[j][1];
        totalEigenForVisual += eigen[j][2];
        totalEigenForAge += eigen[j][3];
        totalEigenForViewers += eigen[j][4];
        totalEigenForRatting += eigen[j][5];
    }

    // print total eigen each criteraia
    cout << endl;
    cout << totalEigenForGenre << endl;
    cout << totalEigenForCountry << endl;
    cout << totalEigenForVisual << endl;
    cout << totalEigenForAge << endl;
    cout << totalEigenForViewers << endl;
    cout << totalEigenForRatting << endl;

    // average total eigen
    float averageTotalEigenForGenre = 0,averageTotalEigenForCountry = 0,averageTotalEigenForVisual = 0,averageTotalEigenForAge = 0,averageTotalEigenForViewers = 0,averageTotalEigenForRatting = 0;

    // calculate average eigen
    averageTotalEigenForGenre = (totalEigenForGenre / 6.0f);
    averageTotalEigenForCountry = (totalEigenForCountry / 6.0f);
    averageTotalEigenForVisual = (totalEigenForVisual / 6.0f);
    averageTotalEigenForAge = (totalEigenForAge / 6.0f);
    averageTotalEigenForViewers = (totalEigenForViewers / 6.0f);
    averageTotalEigenForRatting = (totalEigenForRatting / 6.0f);

    // print average eigen
    cout << endl;
    cout << averageTotalEigenForGenre << endl;
    cout << averageTotalEigenForCountry << endl;
    cout << averageTotalEigenForVisual << endl;
    cout << averageTotalEigenForAge << endl;
    cout << averageTotalEigenForViewers << endl;
    cout << averageTotalEigenForRatting << endl;
}