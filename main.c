/*************************************** nRx ******************************************************/

#include <stdlib.h>
#include <stdio.h>

const int NumOfArray = 7;
const int row = 9;
const int column = 6;

//prototypes des fonctions
void fillArray_1_2(int [NumOfArray][row][column]);
void fillArray_4_5(int [NumOfArray][row][column]);
void fillArray_3_6(int [NumOfArray][row][column]);
void fillArray_7(int [NumOfArray][row][column]);
int search_number_entred(const int [NumOfArray][row][column], const int);
void play(const int [NumOfArray][row][column]);
void liste_of_number_entred(const int [NumOfArray][row][column], const int);
void print_listes(int [NumOfArray][row][column]);

int main()
{
    int BigArray[NumOfArray][row][column]; // declaration de BigArray
    int x, y, z;

    //initialiser BigArray avec des 0
    for(x = 0; x < NumOfArray; ++x)
    {
        for(y = 0; y < row; ++y)
        {
            for(z = 0; z < column; ++z)
            {
                BigArray[x][y][z] = 0;
            }
        }
    }

    fillArray_1_2(BigArray); //fill BigArray avec les numero du jeux
    print_listes(BigArray); //affichage des listes
    play(BigArray); //lets play :p


    return 0;
}

//fillArray mettre les numero du jeu dans les liste equivo
void fillArray_1_2(int fBigArray[NumOfArray][row][column])
{
    int add1 = 1, add2 = 2, y, z;
    for(y = 0; y < row; ++y)
    {
        for(z = 0; z < column && add1 < 101; ++z)
        {
            fBigArray[0][y][z] = add1;
            add1 += 2;

            fBigArray[1][y][z] = add2;
            z % 2 == 0 ? ++add2 : (add2 += 3);
        }
    }
    fillArray_4_5(fBigArray);
    fillArray_3_6(fBigArray);
    fillArray_7(fBigArray);
}

void fillArray_4_5(int fBigArray[NumOfArray][row][column])
{
    int add4 = 8, add5 = 16, y, z, counterAdd4 = 0, counterAdd5 = 0;
    for(y = 0; y < row; ++y)
    {
        for(z = 0; z < column && add5 < 96; ++z)
        {
                fBigArray[4][y][z] = add5;
                ++counterAdd5;
                counterAdd5 % 16 == 0 ? (add5 += 17) : ++add5;

                if(add4 > 95) continue;
                fBigArray[3][y][z] = add4;
                ++counterAdd4;
                counterAdd4 % 8 == 0 ? (add4 += 9) : ++add4;
        }
    }
}

void fillArray_3_6(int fBigArray[NumOfArray][row][column])
{
    int y, z, add3 = 4, counterAdd3 = 0, add6 = 32, counterAdd6 = 0;
    for(y = 0; y < row; ++y)
    {
        for(z = 0; z < column && add3 < 101; ++z)
        {
            fBigArray[2][y][z] = add3;
            ++counterAdd3;
            counterAdd3 % 4 != 0 ? ++add3 : (add3 += 5);

            if(add6 > 100) continue;
            fBigArray[5][y][z] = add6;
            ++counterAdd6;
            counterAdd6 % 32 != 0 ? ++add6 : (add6 += 33);
        }
    }

}

void fillArray_7(int fBigArray[NumOfArray][row][column])
{
    int y, z, add7 = 64;
    for(y = 0; y < row; ++y)
    {
        for(z = 0; z < column && add7 < 101; ++z)
        {
            fBigArray[6][y][z] = add7;
            ++add7;
        }
        if(add7 > 100) break;
    }
}

//cherche le nombre entrer si il existe dans les listes
int search_number_entred(const int fBigArray[NumOfArray][row][column], const int t)
{
    int x, y, z;
    for(x = 0; x < NumOfArray; ++x)
        for(y = 0; y < row; ++y)
            for(z = 0; z < column; ++z)
                    if(t == fBigArray[x][y][z]) return 1;

    return 0;
}

//demander a lutilisateur dentré un numbre entre 1 et 100 qui est dans les listes
void play(const int fBigArray[NumOfArray][row][column])
{
    int t;
    do
    {
        printf("\n\nPLAYER'1'\nentrer un nombre qui est present dans lun des 7 liste[1-100]: ");
        scanf("%d", &t);
    }while(search_number_entred(fBigArray, t) != 1 || t < 1 || t > 100); //si le nombre né pa dans les listes ou est inferieur a 1

    liste_of_number_entred(fBigArray, t);
}

//afficher le numero de la liste si le numero entre par lutilisateur est dans la liste
//afficher les listes ou si trouve le numero entrer par lutilisateur
//afficher le numero entrer avec une simple teknik d'addition
void liste_of_number_entred(const int fBigArray[NumOfArray][row][column], const int t)
{
    int x, y, z;
    int sum = 0;
    printf("\n\nLes listes ou si trouve le numero entrer par PLAYER'1'\n");
    for(x = 0; x < NumOfArray; ++x){
        for(y = 0;y < row; ++y){
            for(z = 0; z < column; ++z)
            {
                if(t == fBigArray[x][y][z])
                {
                    printf("\t%d", x+1);
                    sum += fBigArray[x][0][0];
                }
            }
        }
    }
    printf("\n\nle numero entrer par PLAYER'1' : %d\n\n", sum);
}

//affichage des listes
void print_listes(int fBigArray[NumOfArray][row][column])
{
    int counter = 0;
    int x, y, z;
    for(x = 0; x < NumOfArray; ++x)
    {
        printf("\n\n array: %d\n", x+1);
        for(y = 0; y < row; ++y)
        {
            for(z = 0; z < column; ++z)
            {
                printf(" %d",fBigArray[x][y][z]);
                ++counter;
                if(counter % 6 == 0) printf("\n");
            }
        }
    }
}

/*************************************** nRx ******************************************************/



