#include <stdio.h>
#include <stdlib.h>

#define C_ETATAUTO_MAX 9
int transition[][C_ETATAUTO_MAX] =
 {//definition de la table des sauts
//    0      1       2       3        4          5       6        7       8
// ECHAP  ENTIER   IDENT  IDENTERR APRESVIRG  DECIMAL DECIMERR CHAINE  ERRUNITE
    { 1,     7,      8}, //CHIFFRE
    { 2,     3,     2,       6,         6,      6,       7,      8},  //LETTRE
    { 0,     4,     3,       3,       6,         6,      6,       7,      8}, //POINTDEC
    { 7,     7,     7,       7,       7,         7,      7,       0,      7}, //GILLEMET
    { 0,     0,     0,       0,       0,         0,      0,       7,      0}, //SEP
    { 0,     0,     0,       0,       0,         0,      0,       0,      0}, //RETCHAR
    { 0,     0,     0,       0,       0,         0,      0,       0,      0}, //EOF
    { 8,     8,     8,       8,       8,         8,      8,       7,      8} //INCONNUE
};
void displayMatrix(int _NBLIGN,int _NBLCOL,int _NBPROF,const char matrix[_NBLIGN][_NBLCOL][_NBPROF]){
    for (int i = 0 ; i < _NBLIGN ; i++){
      printf("L%d=>",i);
      for (int j = 0 ; j < _NBLCOL ; j++){
        printf("\tC%d=>",j);
        for (int k = 0 ; k < _NBPROF ; k++)
            printf("%d ", matrix[i][j][k]);
        printf("\n");
      }
      printf("\n");
    }
}

int main()
{
    printf("Hello world!\n");
    char matrix[][4][3] = {
        {//L=0
          {//C=0
            1,2,3
          },
          {//C=2
             4,5,6
          },
          {//C=3
             7,8,9
          },
          {//C=3
             10,11,12
          }
        },
        {//L=1
          {//C=0
            13,14,15
          },
          {//C=2
             16,17,18
          },
          {//C=3
             19,20,21
          },
          {//C=3
             22,23,24
          }
        }
    };

    printf("sizof matrix =%d\n", sizeof(matrix));
    int _NBLIGN = sizeof(matrix)/sizeof(*matrix);
    printf("sizof _NBLIGN =%d\n", _NBLIGN);
    int _NBLCOL = sizeof(*matrix)/sizeof(**matrix);
    printf("sizof _NBLCOL =%d\n", _NBLCOL);
    int _NBPROF = sizeof(**matrix)/sizeof(***matrix);
    printf("sizof _NBPROF =%d\n", _NBPROF);
    displayMatrix(_NBLIGN,_NBLCOL,_NBPROF,matrix);
    /*for (int i = 0 ; i < _NBLIGN ; i++){
      printf("L%d=>",i);
      for (int j = 0 ; j < 4 ; j++){
        printf("\tC%d=>",j);
        for (int k = 0 ; k < 3 ; k++)
            printf("%d ", matrix[i][j][k]);
        printf("\n");
      }
      printf("\n");
    }*/
    return 0;
}
