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

void AlternativeForGenre(){
    float alternativeMatrixForGenre[4][4];

    // matrix comareation
    alternativeMatrixForGenre[0][0] = 1;
    alternativeMatrixForGenre[0][1] = 1;
    alternativeMatrixForGenre[0][2] = 2;
    alternativeMatrixForGenre[0][3] = 2;
    alternativeMatrixForGenre[1][0] = 1;
    alternativeMatrixForGenre[1][1] = 1;
    alternativeMatrixForGenre[1][2] = (1.0f/2.0f);
    alternativeMatrixForGenre[1][3] = 2;
    alternativeMatrixForGenre[2][0] = (1.0f/2.0f);
    alternativeMatrixForGenre[2][1] = 2;
    alternativeMatrixForGenre[2][2] = 1;
    alternativeMatrixForGenre[2][3] = 2;
    alternativeMatrixForGenre[3][0] = (1.0f/2.0f);
    alternativeMatrixForGenre[3][1] = (1.0f/2.0f);
    alternativeMatrixForGenre[3][2] = (1.0f/2.0f);
    alternativeMatrixForGenre[3][3] = 1;

    // print matrix
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            cout << alternativeMatrixForGenre[i][j] << endl;
        }
    }

    // eigen
    float eigenAlternativeForGenre[4][4];
    float totalFilmA = 0,totalFilmB = 0,totalFilmC = 0,totalFilmD = 0;

    // sum alternative column
    for(int i = 0; i <= 3; i++){
        totalFilmA += alternativeMatrixForGenre[0][i];
        totalFilmB += alternativeMatrixForGenre[1][i];
        totalFilmC += alternativeMatrixForGenre[2][i];
        totalFilmD += alternativeMatrixForGenre[3][i];
    }

    // print sum each alternative column
    cout << endl;
    cout << "Total film A: " << totalFilmA << endl;
    cout << "Total film B: " << totalFilmB << endl;
    cout << "Total film C: " << totalFilmC << endl;
    cout << "Total film D: " << totalFilmD << endl;

    // eigen value -> alternative column / total alternative column
    for(int i = 0; i <= 33; i++){
        for(int j = 0; j <= 3; j++){
            if(i == 0){
                eigenAlternativeForGenre[i][j] = (alternativeMatrixForGenre[i][j] / totalFilmA);
            } else if(i == 1){
                eigenAlternativeForGenre[i][j] = (alternativeMatrixForGenre[i][j] / totalFilmB);
            } else if(i == 2){
                eigenAlternativeForGenre[i][j] = (alternativeMatrixForGenre[i][j] / totalFilmC);
            } else if(i == 3){
                eigenAlternativeForGenre[i][j] = (alternativeMatrixForGenre[i][j] / totalFilmD);
            }
        }
    }

    // print eigen value
    cout << endl;
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            cout << eigenAlternativeForGenre[i][j] << endl;
        }
    }

    // sum eigen alternative row
    float totalEigenForFilmA = 0,totalEigenForFilmB = 0,totalEigenForFilmC = 0,totalEigenForFilmD = 0;

    for(int j = 0; j <= 3; j++){
        totalEigenForFilmA += eigenAlternativeForGenre[j][0];
        totalEigenForFilmB += eigenAlternativeForGenre[j][1];
        totalEigenForFilmC += eigenAlternativeForGenre[j][2];
        totalEigenForFilmD += eigenAlternativeForGenre[j][3];
    }

    // print total eigen each alternative
    cout << endl;
    cout << "Total eigen film A: " << totalEigenForFilmA << endl;
    cout << "Total eigen film B: " << totalEigenForFilmB << endl;
    cout << "Total eigen film C: " << totalEigenForFilmC << endl;
    cout << "Total eigen film D: " << totalEigenForFilmD << endl;

    // average total eigen
    float averageTotalEigenForFilmA = 0,averageTotalEigenForFilmB = 0,averageTotalEigenForFilmC = 0,averageTotalEigenForFilmD = 0;

    // calculate average total eigen
    averageTotalEigenForFilmA = (totalEigenForFilmA / 4.0f);
    averageTotalEigenForFilmB = (totalEigenForFilmB / 4.0f);
    averageTotalEigenForFilmC = (totalEigenForFilmC / 4.0f);
    averageTotalEigenForFilmD = (totalEigenForFilmD / 4.0f);

    // print average total eigen
    cout << endl;
    cout << "Rata-rata total nilai eigen film A: " << averageTotalEigenForFilmA << endl;
    cout << "Rata-rata total nilai eigen film B: " << averageTotalEigenForFilmB << endl;
    cout << "Rata-rata total nilai eigen film C: " << averageTotalEigenForFilmC << endl;
    cout << "Rata-rata total nilai eigen film D: " << averageTotalEigenForFilmD << endl;

    // consistency
    float lamdaMax = (totalFilmA*averageTotalEigenForFilmA)+(totalFilmB*averageTotalEigenForFilmB)+(totalFilmC*averageTotalEigenForFilmC)+(totalFilmD*averageTotalEigenForFilmD);

    float consistencyRatio,consistencyIndex,ir;

    ir = 0.9f; // there ar 4 alternative
    consistencyIndex = ((lamdaMax-4)/(4-1));
    consistencyRatio = (consistencyIndex/ir);

    cout << "Lamda Max: " << lamdaMax << endl;
    cout << "CI: " << consistencyIndex << endl;
    cout << "CR: " << consistencyRatio << endl;
}