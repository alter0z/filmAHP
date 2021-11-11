#include<iostream>
#include "film_data.cpp"
#include<algorithm>

// global variables for criteria compare
// average total eigen criteria compare
    float averageTotalEigenForGenre = 0,averageTotalEigenForCountry = 0,averageTotalEigenForVisual = 0,averageTotalEigenForAge = 0,averageTotalEigenForViewers = 0,averageTotalEigenForRatting = 0;

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
    cout << "Total genre: " << totalGenre << endl;
    cout << "Total country: " << totalCountry << endl;
    cout << "Total visual: " << totalVisual << endl;
    cout << "Total age: " << totalAge << endl;
    cout << "Total viewers: " << totalViewers << endl;
    cout << "Total ratting: " << totalRatting << endl;

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
    cout << endl;
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
    cout << "Total eigen genre: " << totalEigenForGenre << endl;
    cout << "Total eigen country: " << totalEigenForCountry << endl;
    cout << "Total eigen visual: " << totalEigenForVisual << endl;
    cout << "Total eigen age: " << totalEigenForAge << endl;
    cout << "Total eigen viewers: " << totalEigenForViewers << endl;
    cout << "Total eigen ratting: " << totalEigenForRatting << endl;

    // calculate average eigen
    averageTotalEigenForGenre = (totalEigenForGenre / 6.0f);
    averageTotalEigenForCountry = (totalEigenForCountry / 6.0f);
    averageTotalEigenForVisual = (totalEigenForVisual / 6.0f);
    averageTotalEigenForAge = (totalEigenForAge / 6.0f);
    averageTotalEigenForViewers = (totalEigenForViewers / 6.0f);
    averageTotalEigenForRatting = (totalEigenForRatting / 6.0f);

    // print average eigen
    cout << endl;
    cout << "rata-tata total eigen genre: " << averageTotalEigenForGenre << endl;
    cout << "rata-tata total eigen country: " << averageTotalEigenForCountry << endl;
    cout << "rata-tata total eigen visual: " << averageTotalEigenForVisual << endl;
    cout << "rata-tata total eigen age: " << averageTotalEigenForAge << endl;
    cout << "rata-tata total eigen viewers: " << averageTotalEigenForViewers << endl;
    cout << "rata-tata total eigen ratting: " << averageTotalEigenForRatting << endl;

    // consistency
    float lamdaMaxFromCriteriaCompare = (totalGenre*averageTotalEigenForGenre)+(totalCountry*averageTotalEigenForCountry)+(totalVisual*averageTotalEigenForVisual)+(totalAge*averageTotalEigenForAge)+(totalViewers*averageTotalEigenForViewers)+(totalRatting*averageTotalEigenForRatting);

    float consistencyRatioFromCriteriaCompare,consistencyIndexFromCriteriaCompare,irFromCriteriaCompare;

    irFromCriteriaCompare = 1.24f; // there ar 6 criteria
    consistencyIndexFromCriteriaCompare = ((lamdaMaxFromCriteriaCompare-6)/(6-1));
    consistencyRatioFromCriteriaCompare = (consistencyIndexFromCriteriaCompare/irFromCriteriaCompare);

    cout << endl;
    cout << "Lamda Max: " << lamdaMaxFromCriteriaCompare << endl;
    cout << "CI: " << consistencyIndexFromCriteriaCompare << endl;
    cout << "CR: " << consistencyRatioFromCriteriaCompare << endl;
}

// global variables for alternative genre
// average total eigen alternative genre
    float averageTotalEigenForFilmAFromGenre = 0,averageTotalEigenForFilmBFromGenre = 0,averageTotalEigenForFilmCFromGenre = 0,averageTotalEigenForFilmDFromGenre = 0;

void AlternativeForGenre(){
    float alternativeMatrixForGenre[4][4];

    // matrix comparation
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
    float totalFilmAFromGenre = 0,totalFilmBFromGenre = 0,totalFilmCFromGenre = 0,totalFilmDFromGenre = 0;

    // sum alternative column
    for(int i = 0; i <= 3; i++){
        totalFilmAFromGenre += alternativeMatrixForGenre[0][i];
        totalFilmBFromGenre += alternativeMatrixForGenre[1][i];
        totalFilmCFromGenre += alternativeMatrixForGenre[2][i];
        totalFilmDFromGenre += alternativeMatrixForGenre[3][i];
    }

    // print sum each alternative column
    cout << endl;
    cout << "Total film A: " << totalFilmAFromGenre << endl;
    cout << "Total film B: " << totalFilmBFromGenre << endl;
    cout << "Total film C: " << totalFilmCFromGenre << endl;
    cout << "Total film D: " << totalFilmDFromGenre << endl;

    // eigen value -> alternative column / total alternative column
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            if(i == 0){
                eigenAlternativeForGenre[i][j] = (alternativeMatrixForGenre[i][j] / totalFilmAFromGenre);
            } else if(i == 1){
                eigenAlternativeForGenre[i][j] = (alternativeMatrixForGenre[i][j] / totalFilmBFromGenre);
            } else if(i == 2){
                eigenAlternativeForGenre[i][j] = (alternativeMatrixForGenre[i][j] / totalFilmCFromGenre);
            } else if(i == 3){
                eigenAlternativeForGenre[i][j] = (alternativeMatrixForGenre[i][j] / totalFilmDFromGenre);
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
    float totalEigenForFilmAFromGenre = 0,totalEigenForFilmBFromGenre = 0,totalEigenForFilmCFromGenre = 0,totalEigenForFilmDFromGenre = 0;

    for(int j = 0; j <= 3; j++){
        totalEigenForFilmAFromGenre += eigenAlternativeForGenre[j][0];
        totalEigenForFilmBFromGenre += eigenAlternativeForGenre[j][1];
        totalEigenForFilmCFromGenre += eigenAlternativeForGenre[j][2];
        totalEigenForFilmDFromGenre += eigenAlternativeForGenre[j][3];
    }

    // print total eigen each alternative
    cout << endl;
    cout << "Total eigen film A: " << totalEigenForFilmAFromGenre << endl;
    cout << "Total eigen film B: " << totalEigenForFilmBFromGenre << endl;
    cout << "Total eigen film C: " << totalEigenForFilmCFromGenre << endl;
    cout << "Total eigen film D: " << totalEigenForFilmDFromGenre << endl;

    // calculate average total eigen
    averageTotalEigenForFilmAFromGenre = (totalEigenForFilmAFromGenre / 4.0f);
    averageTotalEigenForFilmBFromGenre = (totalEigenForFilmBFromGenre / 4.0f);
    averageTotalEigenForFilmCFromGenre = (totalEigenForFilmCFromGenre / 4.0f);
    averageTotalEigenForFilmDFromGenre = (totalEigenForFilmDFromGenre / 4.0f);

    // print average total eigen
    cout << endl;
    cout << "Rata-rata total nilai eigen film A: " << averageTotalEigenForFilmAFromGenre << endl;
    cout << "Rata-rata total nilai eigen film B: " << averageTotalEigenForFilmBFromGenre << endl;
    cout << "Rata-rata total nilai eigen film C: " << averageTotalEigenForFilmCFromGenre << endl;
    cout << "Rata-rata total nilai eigen film D: " << averageTotalEigenForFilmDFromGenre << endl;

    // consistency
    float lamdaMaxFromGenre = (totalFilmAFromGenre*averageTotalEigenForFilmAFromGenre)+(totalFilmBFromGenre*averageTotalEigenForFilmBFromGenre)+(totalFilmCFromGenre*averageTotalEigenForFilmCFromGenre)+(totalFilmDFromGenre*averageTotalEigenForFilmDFromGenre);

    float consistencyRatioFromGenre,consistencyIndexFromGenre,irFromGenre;

    irFromGenre = 0.9f; // there ar 4 alternative
    consistencyIndexFromGenre = ((lamdaMaxFromGenre-4)/(4-1));
    consistencyRatioFromGenre = (consistencyIndexFromGenre/irFromGenre);

    cout << endl;
    cout << "Lamda Max: " << lamdaMaxFromGenre << endl;
    cout << "CI: " << consistencyIndexFromGenre << endl;
    cout << "CR: " << consistencyRatioFromGenre << endl;
}

// global variables for alternative country
// average total eigen alternative country
    float averageTotalEigenForFilmAFromCountry = 0,averageTotalEigenForFilmBFromCountry = 0,averageTotalEigenForFilmCFromCountry = 0,averageTotalEigenForFilmDFromCountry = 0;

void AlternativeForCountry(){
    float alternativeMatrixForCountry[4][4];

    // matrix comparation
    alternativeMatrixForCountry[0][0] = 1;
    alternativeMatrixForCountry[0][1] = (1.0f/2.0f);
    alternativeMatrixForCountry[0][2] = (1.0f/3.0f);
    alternativeMatrixForCountry[0][3] = (1.0f/2.0f);
    alternativeMatrixForCountry[1][0] = 2;
    alternativeMatrixForCountry[1][1] = 1;
    alternativeMatrixForCountry[1][2] = (1.0f/3.0f);
    alternativeMatrixForCountry[1][3] = (1.0f/2.0f);
    alternativeMatrixForCountry[2][0] = 3;
    alternativeMatrixForCountry[2][1] = 3;
    alternativeMatrixForCountry[2][2] = 1;
    alternativeMatrixForCountry[2][3] = (1.0f/2.0f);
    alternativeMatrixForCountry[3][0] = 2;
    alternativeMatrixForCountry[3][1] = 2;
    alternativeMatrixForCountry[3][2] = 2;
    alternativeMatrixForCountry[3][3] = 1;

    // print matrix
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            cout << alternativeMatrixForCountry[i][j] << endl;
        }
    }

    // eigen
    float eigenAlternativeForCountry[4][4];
    float totalFilmAFromCountry = 0,totalFilmBFromCountry = 0,totalFilmCFromCountry = 0,totalFilmDFromCountry = 0;

    // sum alternative column
    for(int i = 0; i <= 3; i++){
        totalFilmAFromCountry += alternativeMatrixForCountry[0][i];
        totalFilmBFromCountry += alternativeMatrixForCountry[1][i];
        totalFilmCFromCountry += alternativeMatrixForCountry[2][i];
        totalFilmDFromCountry += alternativeMatrixForCountry[3][i];
    }

    // print sum each alternative column
    cout << endl;
    cout << "Total film A: " << totalFilmAFromCountry << endl;
    cout << "Total film B: " << totalFilmBFromCountry << endl;
    cout << "Total film C: " << totalFilmCFromCountry << endl;
    cout << "Total film D: " << totalFilmDFromCountry << endl;

    // eigen value -> alternative column / total alternative column
    for(int i = 0; i <= 33; i++){
        for(int j = 0; j <= 3; j++){
            if(i == 0){
                eigenAlternativeForCountry[i][j] = (alternativeMatrixForCountry[i][j] / totalFilmAFromCountry);
            } else if(i == 1){
                eigenAlternativeForCountry[i][j] = (alternativeMatrixForCountry[i][j] / totalFilmBFromCountry);
            } else if(i == 2){
                eigenAlternativeForCountry[i][j] = (alternativeMatrixForCountry[i][j] / totalFilmCFromCountry);
            } else if(i == 3){
                eigenAlternativeForCountry[i][j] = (alternativeMatrixForCountry[i][j] / totalFilmDFromCountry);
            }
        }
    }

    // print eigen value
    cout << endl;
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            cout << eigenAlternativeForCountry[i][j] << endl;
        }
    }

    // sum eigen alternative row
    float totalEigenForFilmAFromCountry = 0,totalEigenForFilmBFromCountry = 0,totalEigenForFilmCFromCountry = 0,totalEigenForFilmDFromCountry = 0;

    for(int j = 0; j <= 3; j++){
        totalEigenForFilmAFromCountry += eigenAlternativeForCountry[j][0];
        totalEigenForFilmBFromCountry += eigenAlternativeForCountry[j][1];
        totalEigenForFilmCFromCountry += eigenAlternativeForCountry[j][2];
        totalEigenForFilmDFromCountry += eigenAlternativeForCountry[j][3];
    }

    // print total eigen each alternative
    cout << endl;
    cout << "Total eigen film A: " << totalEigenForFilmAFromCountry << endl;
    cout << "Total eigen film B: " << totalEigenForFilmBFromCountry << endl;
    cout << "Total eigen film C: " << totalEigenForFilmCFromCountry << endl;
    cout << "Total eigen film D: " << totalEigenForFilmDFromCountry << endl;

    // calculate average total eigen
    averageTotalEigenForFilmAFromCountry = (totalEigenForFilmAFromCountry / 4.0f);
    averageTotalEigenForFilmBFromCountry = (totalEigenForFilmBFromCountry / 4.0f);
    averageTotalEigenForFilmCFromCountry = (totalEigenForFilmCFromCountry / 4.0f);
    averageTotalEigenForFilmDFromCountry = (totalEigenForFilmDFromCountry / 4.0f);

    // print average total eigen
    cout << endl;
    cout << "Rata-rata total nilai eigen film A: " << averageTotalEigenForFilmAFromCountry << endl;
    cout << "Rata-rata total nilai eigen film B: " << averageTotalEigenForFilmBFromCountry << endl;
    cout << "Rata-rata total nilai eigen film C: " << averageTotalEigenForFilmCFromCountry << endl;
    cout << "Rata-rata total nilai eigen film D: " << averageTotalEigenForFilmDFromCountry << endl;

    // consistency
    float lamdaMaxFromCountry = (totalFilmAFromCountry*averageTotalEigenForFilmAFromCountry)+(totalFilmBFromCountry*averageTotalEigenForFilmBFromCountry)+(totalFilmCFromCountry*averageTotalEigenForFilmCFromCountry)+(totalFilmDFromCountry*averageTotalEigenForFilmDFromCountry);

    float consistencyRatioFromCountry,consistencyIndexFromCountry,irFromCountry;

    irFromCountry = 0.9f; // there ar 4 alternative
    consistencyIndexFromCountry = ((lamdaMaxFromCountry-4)/(4-1));
    consistencyRatioFromCountry = (consistencyIndexFromCountry/irFromCountry);

    cout << endl;
    cout << "Lamda Max: " << lamdaMaxFromCountry << endl;
    cout << "CI: " << consistencyIndexFromCountry << endl;
    cout << "CR: " << consistencyRatioFromCountry << endl;
}

// global variables for alternative visual
// average total eigen alternative visual
    float averageTotalEigenForFilmAFromVisual = 0,averageTotalEigenForFilmBFromVisual = 0,averageTotalEigenForFilmCFromVisual = 0,averageTotalEigenForFilmDFromVisual = 0;

void AlternativeForVisual(){
    float alternativeMatrixForVisual[4][4];

    // matrix comparation
    alternativeMatrixForVisual[0][0] = 1;
    alternativeMatrixForVisual[0][1] = (1.0f/3.0f);
    alternativeMatrixForVisual[0][2] = 1;
    alternativeMatrixForVisual[0][3] = 2;
    alternativeMatrixForVisual[1][0] = 3;
    alternativeMatrixForVisual[1][1] = 1;
    alternativeMatrixForVisual[1][2] = 3;
    alternativeMatrixForVisual[1][3] = 3;
    alternativeMatrixForVisual[2][0] = 1;
    alternativeMatrixForVisual[2][1] = (1.0f/3.0f);
    alternativeMatrixForVisual[2][2] = 1;
    alternativeMatrixForVisual[2][3] = 3;
    alternativeMatrixForVisual[3][0] = (1.0f/2.0f);
    alternativeMatrixForVisual[3][1] = (1.0f/3.0f);
    alternativeMatrixForVisual[3][2] = (1.0f/3.0f);
    alternativeMatrixForVisual[3][3] = 1;

    // print matrix
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            cout << alternativeMatrixForVisual[i][j] << endl;
        }
    }

    // eigen
    float eigenAlternativeForVisual[4][4];
    float totalFilmAFromVisual = 0,totalFilmBFromVisual = 0,totalFilmCFromVisual = 0,totalFilmDFromVisual = 0;

    // sum alternative column
    for(int i = 0; i <= 3; i++){
        totalFilmAFromVisual += alternativeMatrixForVisual[0][i];
        totalFilmBFromVisual += alternativeMatrixForVisual[1][i];
        totalFilmCFromVisual += alternativeMatrixForVisual[2][i];
        totalFilmDFromVisual += alternativeMatrixForVisual[3][i];
    }

    // print sum each alternative column
    cout << endl;
    cout << "Total film A: " << totalFilmAFromVisual << endl;
    cout << "Total film B: " << totalFilmBFromVisual << endl;
    cout << "Total film C: " << totalFilmCFromVisual << endl;
    cout << "Total film D: " << totalFilmDFromVisual << endl;

    // eigen value -> alternative column / total alternative column
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            if(i == 0){
                eigenAlternativeForVisual[i][j] = (alternativeMatrixForVisual[i][j] / totalFilmAFromVisual);
            } else if(i == 1){
                eigenAlternativeForVisual[i][j] = (alternativeMatrixForVisual[i][j] / totalFilmBFromVisual);
            } else if(i == 2){
                eigenAlternativeForVisual[i][j] = (alternativeMatrixForVisual[i][j] / totalFilmCFromVisual);
            } else if(i == 3){
                eigenAlternativeForVisual[i][j] = (alternativeMatrixForVisual[i][j] / totalFilmDFromVisual);
            }
        }
    }

    // print eigen value
    cout << endl;
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            cout << eigenAlternativeForVisual[i][j] << endl;
        }
    }

    // sum eigen alternative row
    float totalEigenForFilmAFromVisual = 0,totalEigenForFilmBFromVisual = 0,totalEigenForFilmCFromVisual = 0,totalEigenForFilmDFromVisual = 0;

    for(int j = 0; j <= 3; j++){
        totalEigenForFilmAFromVisual += eigenAlternativeForVisual[j][0];
        totalEigenForFilmBFromVisual += eigenAlternativeForVisual[j][1];
        totalEigenForFilmCFromVisual += eigenAlternativeForVisual[j][2];
        totalEigenForFilmDFromVisual += eigenAlternativeForVisual[j][3];
    }

    // print total eigen each alternative
    cout << endl;
    cout << "Total eigen film A: " << totalEigenForFilmAFromVisual << endl;
    cout << "Total eigen film B: " << totalEigenForFilmBFromVisual << endl;
    cout << "Total eigen film C: " << totalEigenForFilmCFromVisual << endl;
    cout << "Total eigen film D: " << totalEigenForFilmDFromVisual << endl;

    // calculate average total eigen
    averageTotalEigenForFilmAFromVisual = (totalEigenForFilmAFromVisual / 4.0f);
    averageTotalEigenForFilmBFromVisual = (totalEigenForFilmBFromVisual / 4.0f);
    averageTotalEigenForFilmCFromVisual = (totalEigenForFilmCFromVisual / 4.0f);
    averageTotalEigenForFilmDFromVisual = (totalEigenForFilmDFromVisual / 4.0f);

    // print average total eigen
    cout << endl;
    cout << "Rata-rata total nilai eigen film A: " << averageTotalEigenForFilmAFromVisual << endl;
    cout << "Rata-rata total nilai eigen film B: " << averageTotalEigenForFilmBFromVisual << endl;
    cout << "Rata-rata total nilai eigen film C: " << averageTotalEigenForFilmCFromVisual << endl;
    cout << "Rata-rata total nilai eigen film D: " << averageTotalEigenForFilmDFromVisual << endl;

    // consistency
    float lamdaMaxFromVisual = (totalFilmAFromVisual*averageTotalEigenForFilmAFromVisual)+(totalFilmBFromVisual*averageTotalEigenForFilmBFromVisual)+(totalFilmCFromVisual*averageTotalEigenForFilmCFromVisual)+(totalFilmDFromVisual*averageTotalEigenForFilmDFromVisual);

    float consistencyRatioFromVisual,consistencyIndexFromVisual,irFromVisual;

    irFromVisual = 0.9f; // there ar 4 alternative
    consistencyIndexFromVisual = ((lamdaMaxFromVisual-4)/(4-1));
    consistencyRatioFromVisual = (consistencyIndexFromVisual/irFromVisual);

    cout << endl;
    cout << "Lamda Max: " << lamdaMaxFromVisual << endl;
    cout << "CI: " << consistencyIndexFromVisual << endl;
    cout << "CR: " << consistencyRatioFromVisual << endl;
}

// global variables for alternative age
// average total eigen alternative age
    float averageTotalEigenForFilmAFromAge = 0, averageTotalEigenForFilmBFromAge = 0, averageTotalEigenForFilmCFromAge = 0, averageTotalEigenForFilmDFromAge = 0;

void AlternativeForAge()
{
    float alternativeMatrixForAge[4][4];

    // matrix comparation
    alternativeMatrixForAge[0][0] = 1;
    alternativeMatrixForAge[0][1] = (1.0f / 2.0f);
    alternativeMatrixForAge[0][2] = (1.0f / 3.0f);
    alternativeMatrixForAge[0][3] = 3;
    alternativeMatrixForAge[1][0] = 2;
    alternativeMatrixForAge[1][1] = 1;
    alternativeMatrixForAge[1][2] = (1.0f / 5.0f);
    alternativeMatrixForAge[1][3] = 3;
    alternativeMatrixForAge[2][0] = 3;
    alternativeMatrixForAge[2][1] = 5;
    alternativeMatrixForAge[2][2] = 1;
    alternativeMatrixForAge[2][3] = 7;
    alternativeMatrixForAge[3][0] = (1.0f / 3.0f);
    alternativeMatrixForAge[3][1] = (1.0f / 3.0f);
    alternativeMatrixForAge[3][2] = (1.0f / 7.0f);
    alternativeMatrixForAge[3][3] = 1;

    // print matrix
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            cout << alternativeMatrixForAge[i][j] << endl;
        }
    }

    // eigen
    float eigenAlternativeForAge[4][4];
    float totalFilmAFromAge = 0, totalFilmBFromAge = 0, totalFilmCFromAge = 0, totalFilmDFromAge = 0;

    // sum alternative column
    for (int i = 0; i <= 3; i++)
    {
        totalFilmAFromAge += alternativeMatrixForAge[0][i];
        totalFilmBFromAge += alternativeMatrixForAge[1][i];
        totalFilmCFromAge += alternativeMatrixForAge[2][i];
        totalFilmDFromAge += alternativeMatrixForAge[3][i];
    }

    // print sum each alternative column
    cout << endl;
    cout << "Total film A: " << totalFilmAFromAge << endl;
    cout << "Total film B: " << totalFilmBFromAge << endl;
    cout << "Total film C: " << totalFilmCFromAge << endl;
    cout << "Total film D: " << totalFilmDFromAge << endl;

    // eigen value -> alternative column / total alternative column
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            if (i == 0)
            {
                eigenAlternativeForAge[i][j] = (alternativeMatrixForAge[i][j] / totalFilmAFromAge);
            }
            else if (i == 1)
            {
                eigenAlternativeForAge[i][j] = (alternativeMatrixForAge[i][j] / totalFilmBFromAge);
            }
            else if (i == 2)
            {
                eigenAlternativeForAge[i][j] = (alternativeMatrixForAge[i][j] / totalFilmCFromAge);
            }
            else if (i == 3)
            {
                eigenAlternativeForAge[i][j] = (alternativeMatrixForAge[i][j] / totalFilmDFromAge);
            }
        }
    }

    // print eigen value
    cout << endl;
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            cout << eigenAlternativeForAge[i][j] << endl;
        }
    }

    // sum eigen alternative row
    float totalEigenForFilmAFromAge = 0, totalEigenForFilmBFromAge = 0, totalEigenForFilmCFromAge = 0, totalEigenForFilmDFromAge = 0;

    for (int j = 0; j <= 3; j++)
    {
        totalEigenForFilmAFromAge += eigenAlternativeForAge[j][0];
        totalEigenForFilmBFromAge += eigenAlternativeForAge[j][1];
        totalEigenForFilmCFromAge += eigenAlternativeForAge[j][2];
        totalEigenForFilmDFromAge += eigenAlternativeForAge[j][3];
    }

    // print total eigen each alternative
    cout << endl;
    cout << "Total eigen film A: " << totalEigenForFilmAFromAge << endl;
    cout << "Total eigen film B: " << totalEigenForFilmBFromAge << endl;
    cout << "Total eigen film C: " << totalEigenForFilmCFromAge << endl;
    cout << "Total eigen film D: " << totalEigenForFilmDFromAge << endl;

    // calculate average total eigen
    averageTotalEigenForFilmAFromAge = (totalEigenForFilmAFromAge / 4.0f);
    averageTotalEigenForFilmBFromAge = (totalEigenForFilmBFromAge / 4.0f);
    averageTotalEigenForFilmCFromAge = (totalEigenForFilmCFromAge / 4.0f);
    averageTotalEigenForFilmDFromAge = (totalEigenForFilmDFromAge / 4.0f);

    // print average total eigen
    cout << endl;
    cout << "Rata-rata total nilai eigen film A: " << averageTotalEigenForFilmAFromAge << endl;
    cout << "Rata-rata total nilai eigen film B: " << averageTotalEigenForFilmBFromAge << endl;
    cout << "Rata-rata total nilai eigen film C: " << averageTotalEigenForFilmCFromAge << endl;
    cout << "Rata-rata total nilai eigen film D: " << averageTotalEigenForFilmDFromAge << endl;

    // consistency
    float lamdaMaxFromAge = (totalFilmAFromAge * averageTotalEigenForFilmAFromAge) + (totalFilmBFromAge * averageTotalEigenForFilmBFromAge) + (totalFilmCFromAge * averageTotalEigenForFilmCFromAge) + (totalFilmDFromAge * averageTotalEigenForFilmDFromAge);

    float consistencyRatioFromAge, consistencyIndexFromAge, irFromAge;

    irFromAge = 0.9f; // there ar 4 alternative
    consistencyIndexFromAge = ((lamdaMaxFromAge - 4) / (4 - 1));
    consistencyRatioFromAge = (consistencyIndexFromAge / irFromAge);

    cout << endl;
    cout << "Lamda Max: " << lamdaMaxFromAge << endl;
    cout << "CI: " << consistencyIndexFromAge << endl;
    cout << "CR: " << consistencyRatioFromAge << endl;
}

// global variables for alternative viewers
// average total eigen alternative viewers
    float averageTotalEigenForFilmAFromViewer = 0,averageTotalEigenForFilmBFromViewer = 0,averageTotalEigenForFilmCFromViewer = 0,averageTotalEigenForFilmDFromViewer = 0;

void AlternativeForViewer(){
    float alternativeMatrixForViewer[4][4];

    // matrix comparation
    alternativeMatrixForViewer[0][0] = 1;
    alternativeMatrixForViewer[0][1] = 2;
    alternativeMatrixForViewer[0][2] = 3;
    alternativeMatrixForViewer[0][3] = 2;
    alternativeMatrixForViewer[1][0] = (1.0f/2.0f);
    alternativeMatrixForViewer[1][1] = 1;
    alternativeMatrixForViewer[1][2] = 2;
    alternativeMatrixForViewer[1][3] = 3;
    alternativeMatrixForViewer[2][0] = (1.0f/3.0f);
    alternativeMatrixForViewer[2][1] = (1.0f/2.0f);
    alternativeMatrixForViewer[2][2] = 1;
    alternativeMatrixForViewer[2][3] = (1.0f/3.0f);
    alternativeMatrixForViewer[3][0] = (1.0f/2.0f);
    alternativeMatrixForViewer[3][1] = (1.0f/3.0f);
    alternativeMatrixForViewer[3][2] = 3;
    alternativeMatrixForViewer[3][3] = 1;

    // print matrix
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            cout << alternativeMatrixForViewer[i][j] << endl;
        }
    }

    // eigen
    float eigenAlternativeForViewer[4][4];
    float totalFilmAFromViewer = 0,totalFilmBFromViewer = 0,totalFilmCFromViewer = 0,totalFilmDFromViewer = 0;

    // sum alternative column
    for(int i = 0; i <= 3; i++){
        totalFilmAFromViewer += alternativeMatrixForViewer[0][i];
        totalFilmBFromViewer += alternativeMatrixForViewer[1][i];
        totalFilmCFromViewer += alternativeMatrixForViewer[2][i];
        totalFilmDFromViewer += alternativeMatrixForViewer[3][i];
    }

    // print sum each alternative column
    cout << endl;
    cout << "Total film A: " << totalFilmAFromViewer << endl;
    cout << "Total film B: " << totalFilmBFromViewer << endl;
    cout << "Total film C: " << totalFilmCFromViewer << endl;
    cout << "Total film D: " << totalFilmDFromViewer << endl;

    // eigen value -> alternative column / total alternative column
    for(int i = 0; i <= 33; i++){
        for(int j = 0; j <= 3; j++){
            if(i == 0){
                eigenAlternativeForViewer[i][j] = (alternativeMatrixForViewer[i][j] / totalFilmAFromViewer);
            } else if(i == 1){
                eigenAlternativeForViewer[i][j] = (alternativeMatrixForViewer[i][j] / totalFilmBFromViewer);
            } else if(i == 2){
                eigenAlternativeForViewer[i][j] = (alternativeMatrixForViewer[i][j] / totalFilmCFromViewer);
            } else if(i == 3){
                eigenAlternativeForViewer[i][j] = (alternativeMatrixForViewer[i][j] / totalFilmDFromViewer);
            }
        }
    }

    // print eigen value
    cout << endl;
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            cout << eigenAlternativeForViewer[i][j] << endl;
        }
    }

    // sum eigen alternative row
    float totalEigenForFilmAFromViewer = 0,totalEigenForFilmBFromViewer = 0,totalEigenForFilmCFromViewer = 0,totalEigenForFilmDFromViewer = 0;

    for(int j = 0; j <= 3; j++){
        totalEigenForFilmAFromViewer += eigenAlternativeForViewer[j][0];
        totalEigenForFilmBFromViewer += eigenAlternativeForViewer[j][1];
        totalEigenForFilmCFromViewer += eigenAlternativeForViewer[j][2];
        totalEigenForFilmDFromViewer += eigenAlternativeForViewer[j][3];
    }

    // print total eigen each alternative
    cout << endl;
    cout << "Total eigen film A: " << totalEigenForFilmAFromViewer << endl;
    cout << "Total eigen film B: " << totalEigenForFilmBFromViewer << endl;
    cout << "Total eigen film C: " << totalEigenForFilmCFromViewer << endl;
    cout << "Total eigen film D: " << totalEigenForFilmDFromViewer << endl;

    // calculate average total eigen
    averageTotalEigenForFilmAFromViewer = (totalEigenForFilmAFromViewer / 4.0f);
    averageTotalEigenForFilmBFromViewer = (totalEigenForFilmBFromViewer / 4.0f);
    averageTotalEigenForFilmCFromViewer = (totalEigenForFilmCFromViewer / 4.0f);
    averageTotalEigenForFilmDFromViewer = (totalEigenForFilmDFromViewer / 4.0f);

    // print average total eigen
    cout << endl;
    cout << "Rata-rata total nilai eigen film A: " << averageTotalEigenForFilmAFromViewer << endl;
    cout << "Rata-rata total nilai eigen film B: " << averageTotalEigenForFilmBFromViewer << endl;
    cout << "Rata-rata total nilai eigen film C: " << averageTotalEigenForFilmCFromViewer << endl;
    cout << "Rata-rata total nilai eigen film D: " << averageTotalEigenForFilmDFromViewer << endl;

    // consistency
    float lamdaMaxFromViewer = (totalFilmAFromViewer*averageTotalEigenForFilmAFromViewer)+(totalFilmBFromViewer*averageTotalEigenForFilmBFromViewer)+(totalFilmCFromViewer*averageTotalEigenForFilmCFromViewer)+(totalFilmDFromViewer*averageTotalEigenForFilmDFromViewer);

    float consistencyRatioFromViewer,consistencyIndexFromViewer,irFromViewer;

    irFromViewer = 0.9f; // there ar 4 alternative
    consistencyIndexFromViewer = ((lamdaMaxFromViewer-4)/(4-1));
    consistencyRatioFromViewer = (consistencyIndexFromViewer/irFromViewer);

    cout << endl;
    cout << "Lamda Max: " << lamdaMaxFromViewer << endl;
    cout << "CI: " << consistencyIndexFromViewer << endl;
    cout << "CR: " << consistencyRatioFromViewer << endl;
}

// global variables for alternative ratting
// average total eigen alternative ratting
    float averageTotalEigenForFilmAFromRatting = 0,averageTotalEigenForFilmBFromRatting = 0,averageTotalEigenForFilmCFromRatting = 0,averageTotalEigenForFilmDFromRatting = 0;

void AlternativeForRatting(){
    float alternativeMatrixForRatting[4][4];

    // matrix comparation
    alternativeMatrixForRatting[0][0] = 1;
    alternativeMatrixForRatting[0][1] = 1;
    alternativeMatrixForRatting[0][2] = (1.0f/3.0f);
    alternativeMatrixForRatting[0][3] = 1;
    alternativeMatrixForRatting[1][0] = 1;
    alternativeMatrixForRatting[1][1] = 1;
    alternativeMatrixForRatting[1][2] = (1.0f/2.0f);
    alternativeMatrixForRatting[1][3] = (1.0f/2.0f);
    alternativeMatrixForRatting[2][0] = 3;
    alternativeMatrixForRatting[2][1] = 2;
    alternativeMatrixForRatting[2][2] = 1;
    alternativeMatrixForRatting[2][3] = 1;
    alternativeMatrixForRatting[3][0] = 1;
    alternativeMatrixForRatting[3][1] = 2;
    alternativeMatrixForRatting[3][2] = 1;
    alternativeMatrixForRatting[3][3] = 1;

    // print matrix
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            cout << alternativeMatrixForRatting[i][j] << endl;
        }
    }

    // eigen
    float eigenAlternativeForRatting[4][4];
    float totalFilmAFromRatting = 0,totalFilmBFromRatting = 0,totalFilmCFromRatting = 0,totalFilmDFromRatting = 0;

    // sum alternative column
    for(int i = 0; i <= 3; i++){
        totalFilmAFromRatting += alternativeMatrixForRatting[0][i];
        totalFilmBFromRatting += alternativeMatrixForRatting[1][i];
        totalFilmCFromRatting += alternativeMatrixForRatting[2][i];
        totalFilmDFromRatting += alternativeMatrixForRatting[3][i];
    }

    // print sum each alternative column
    cout << endl;
    cout << "Total film A: " << totalFilmAFromRatting << endl;
    cout << "Total film B: " << totalFilmBFromRatting << endl;
    cout << "Total film C: " << totalFilmCFromRatting << endl;
    cout << "Total film D: " << totalFilmDFromRatting << endl;

    // eigen value -> alternative column / total alternative column
    for(int i = 0; i <= 33; i++){
        for(int j = 0; j <= 3; j++){
            if(i == 0){
                eigenAlternativeForRatting[i][j] = (alternativeMatrixForRatting[i][j] / totalFilmAFromRatting);
            } else if(i == 1){
                eigenAlternativeForRatting[i][j] = (alternativeMatrixForRatting[i][j] / totalFilmBFromRatting);
            } else if(i == 2){
                eigenAlternativeForRatting[i][j] = (alternativeMatrixForRatting[i][j] / totalFilmCFromRatting);
            } else if(i == 3){
                eigenAlternativeForRatting[i][j] = (alternativeMatrixForRatting[i][j] / totalFilmDFromRatting);
            }
        }
    }

    // print eigen value
    cout << endl;
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            cout << eigenAlternativeForRatting[i][j] << endl;
        }
    }

    // sum eigen alternative row
    float totalEigenForFilmAFromRatting = 0,totalEigenForFilmBFromRatting = 0,totalEigenForFilmCFromRatting = 0,totalEigenForFilmDFromRatting = 0;

    for(int j = 0; j <= 3; j++){
        totalEigenForFilmAFromRatting += eigenAlternativeForRatting[j][0];
        totalEigenForFilmBFromRatting += eigenAlternativeForRatting[j][1];
        totalEigenForFilmCFromRatting += eigenAlternativeForRatting[j][2];
        totalEigenForFilmDFromRatting += eigenAlternativeForRatting[j][3];
    }

    // print total eigen each alternative
    cout << endl;
    cout << "Total eigen film A: " << totalEigenForFilmAFromRatting << endl;
    cout << "Total eigen film B: " << totalEigenForFilmBFromRatting << endl;
    cout << "Total eigen film C: " << totalEigenForFilmCFromRatting << endl;
    cout << "Total eigen film D: " << totalEigenForFilmDFromRatting << endl;

    // calculate average total eigen
    averageTotalEigenForFilmAFromRatting = (totalEigenForFilmAFromRatting / 4.0f);
    averageTotalEigenForFilmBFromRatting = (totalEigenForFilmBFromRatting / 4.0f);
    averageTotalEigenForFilmCFromRatting = (totalEigenForFilmCFromRatting / 4.0f);
    averageTotalEigenForFilmDFromRatting = (totalEigenForFilmDFromRatting / 4.0f);

    // print average total eigen
    cout << endl;
    cout << "Rata-rata total nilai eigen film A: " << averageTotalEigenForFilmAFromRatting << endl;
    cout << "Rata-rata total nilai eigen film B: " << averageTotalEigenForFilmBFromRatting << endl;
    cout << "Rata-rata total nilai eigen film C: " << averageTotalEigenForFilmCFromRatting << endl;
    cout << "Rata-rata total nilai eigen film D: " << averageTotalEigenForFilmDFromRatting << endl;

    // consistency
    float lamdaMaxFromRatting = (totalFilmAFromRatting*averageTotalEigenForFilmAFromRatting)+(totalFilmBFromRatting*averageTotalEigenForFilmBFromRatting)+(totalFilmCFromRatting*averageTotalEigenForFilmCFromRatting)+(totalFilmDFromRatting*averageTotalEigenForFilmDFromRatting);

    float consistencyRatioFromRatting,consistencyIndexFromRatting,irFromRatting;

    irFromRatting = 0.9f; // there ar 4 alternative
    consistencyIndexFromRatting = ((lamdaMaxFromRatting-4)/(4-1));
    consistencyRatioFromRatting = (consistencyIndexFromRatting/irFromRatting);

    cout << "Lamda Max: " << lamdaMaxFromRatting << endl;
    cout << "CI: " << consistencyIndexFromRatting << endl;
    cout << "CR: " << consistencyRatioFromRatting << endl;
}

struct resultFilm{
    string charFilm,title,genre,visual,age,country,ratting,viewers;
    float scoreResult;
};


void Ranking(){
    FilmData();
    float rankFilmA = 0,rankFilmB = 0,rankFilmC = 0,rankFilmD = 0,compareResult1 = 0,compareResult2 = 0,result = 0;

    rankFilmA = (averageTotalEigenForGenre*averageTotalEigenForFilmAFromGenre)+(averageTotalEigenForCountry*averageTotalEigenForFilmAFromCountry)+(averageTotalEigenForVisual*averageTotalEigenForFilmAFromVisual)+(averageTotalEigenForAge*averageTotalEigenForFilmAFromAge)+(averageTotalEigenForViewers*averageTotalEigenForFilmAFromViewer)+(averageTotalEigenForRatting*averageTotalEigenForFilmAFromRatting);

    film1.scoreResult = rankFilmA; 

    rankFilmB = (averageTotalEigenForGenre*averageTotalEigenForFilmBFromGenre)+(averageTotalEigenForCountry*averageTotalEigenForFilmBFromCountry)+(averageTotalEigenForVisual*averageTotalEigenForFilmBFromVisual)+(averageTotalEigenForAge*averageTotalEigenForFilmBFromAge)+(averageTotalEigenForViewers*averageTotalEigenForFilmBFromViewer)+(averageTotalEigenForRatting*averageTotalEigenForFilmBFromRatting);

    film2.scoreResult = rankFilmB; 

    rankFilmC = (averageTotalEigenForGenre*averageTotalEigenForFilmCFromGenre)+(averageTotalEigenForCountry*averageTotalEigenForFilmCFromCountry)+(averageTotalEigenForVisual*averageTotalEigenForFilmCFromVisual)+(averageTotalEigenForAge*averageTotalEigenForFilmCFromAge)+(averageTotalEigenForViewers*averageTotalEigenForFilmCFromViewer)+(averageTotalEigenForRatting*averageTotalEigenForFilmCFromRatting);

    film3.scoreResult = rankFilmC; 

    rankFilmD = (averageTotalEigenForGenre*averageTotalEigenForFilmDFromGenre)+(averageTotalEigenForCountry*averageTotalEigenForFilmDFromCountry)+(averageTotalEigenForVisual*averageTotalEigenForFilmDFromVisual)+(averageTotalEigenForAge*averageTotalEigenForFilmDFromAge)+(averageTotalEigenForViewers*averageTotalEigenForFilmDFromViewer)+(averageTotalEigenForRatting*averageTotalEigenForFilmDFromRatting);

    film4.scoreResult = rankFilmD;

    cout << endl;
    cout << "rank film a: " << rankFilmA << endl;
    cout << "rank film b: " << rankFilmB << endl;
    cout << "rank film c: " << rankFilmC << endl;
    cout << "rank film d: " << rankFilmD << endl;

    // find max for ranking
    compareResult1 = max(rankFilmA,rankFilmB);
    compareResult2 = max(rankFilmC,rankFilmD);
    result = max(compareResult1,compareResult2);

    cout << endl;
    cout << "hasil: " << result << endl;

    resultFilm resultRank;

    // for film A
    if(film1.scoreResult == result){
        resultRank.charFilm = film1.charFilm;
        resultRank.title = film1.title;
        resultRank.genre = film1.genre;
        resultRank.country = film1.country;
        resultRank.visual = film1.visual;
        resultRank.age = film1.age;
        resultRank.viewers = film1.viewers;
        resultRank.ratting = film1.ratting;
    } else if(film2.scoreResult == result){ // for film B
        resultRank.charFilm = film2.charFilm;
        resultRank.title = film2.title;
        resultRank.genre = film2.genre;
        resultRank.country = film2.country;
        resultRank.visual = film2.visual;
        resultRank.age = film2.age;
        resultRank.viewers = film2.viewers;
        resultRank.ratting = film2.ratting;
    } else if(film3.scoreResult == result){ // for film C
        resultRank.charFilm = film3.charFilm;
        resultRank.title = film3.title;
        resultRank.genre = film3.genre;
        resultRank.country = film3.country;
        resultRank.visual = film3.visual;
        resultRank.age = film3.age;
        resultRank.viewers = film3.viewers;
        resultRank.ratting = film3.ratting;
    } else if(film4.scoreResult == result){ // for film D
        resultRank.charFilm = film4.charFilm;
        resultRank.title = film4.title;
        resultRank.genre = film4.genre;
        resultRank.country = film4.country;
        resultRank.visual = film4.visual;
        resultRank.age = film4.age;
        resultRank.viewers = film4.viewers;
        resultRank.ratting = film4.ratting;
    }

    cout << endl;
    cout << resultRank.charFilm << endl;
    cout << "Title: " << resultRank.title << endl;
    cout << "Genre: "<< resultRank.genre << endl;
    cout << "Country: "<< resultRank.country << endl;
    cout << "Visual: "<< resultRank.visual << endl;
    cout << "Age: "<< resultRank.age << endl;
    cout << "Viewers: "<< resultRank.viewers << endl;
    cout << "Ratting: "<< resultRank.ratting << endl;
}