#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char S[100][101], B[100], C[100];
int Count[100][100], ACount[100], FCount[100];

int Check(int N){
  int i, len, clen, k;
  for( k = 1; k < N; k ++ ){
    len = strlen(S[k]);
    C[0] = S[k][0];
    for( i = 1, clen = 1; i < len; i ++ ){
      if( S[k][i] != S[k][i-1] ){
        C[clen] = S[k][i];
        clen ++;
      }
    }
    C[clen] = '\0';
    if( strcmp(B, C) ){
      return 1;
    }
  }
  return 0;
}

int Solver(int N){
  int i, j, k, len, blen, rest, changes;

  len = strlen(S[0]);
  B[0] = S[0][0];
  for( i = 1, blen = 1; i < len; i ++ ){
    if( S[0][i] != S[0][i-1] ){
      B[blen] = S[0][i];
      blen ++;
    }
  }
  B[blen] = '\0';
  printf("%s\n", B);
  if( Check(N) ){
    return -1;
  }

  for( i = 0; i < strlen(B); i ++ ){
    ACount[i] = 0;
    for( j = 0; j < N; j ++ ){
      Count[j][i] = 0;
    }
  }
  for( k = 0; k < N; k ++ ){
    len = strlen(S[k]);
    for( i = 0, j = 0; i < len; i ++ ){
      if( S[k][i] == B[j] ){
        Count[k][j] ++;
        ACount[j] ++;
      }
      else{
        j ++;
        Count[k][j] ++;
        ACount[j] ++;
      }
    }
  }
  for( i = 0; i < strlen(B); i ++ ){
//    printf(" %d", Count[i]);
    rest = ACount[i] % N;
    if( rest <= N / 2 ){
      FCount[i] = ACount[i] / N;
    }
    else{
      FCount[i] = ACount[i] / N + 1;
    }
  }
//  printf("\n");
  changes = 0;
  for( i = 0; i < strlen(B); i ++ ){
    for( j = 0; j < N; j ++ ){
      changes += abs(FCount[i] - Count[j][i]);
    }
  }

  return changes;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t, N, i, res;

  if( argc < 3 ){
    printf("Usage is: task1 filein fileout\n");
    return 0;
  }

  // Input 

  filein = fopen(argv[1], "r");
  if( filein == NULL ){
    printf("Error open(); filein\n");
    return 0;
  }
  fileout = fopen(argv[2], "w");
  if( fileout == NULL ){
    printf("Error open(); fileout\n");
    return 0;
  }

  fscanf(filein, "%d\n", &T);
  printf("%d\n", T);
  for( t = 0; t < T; t ++ ){
    printf("-------------\t=%d\n", t);
    fscanf(filein, "%d\n", &N);
    printf("%d\n", N);
    for( i = 0; i < N; i ++ ){
      fscanf(filein, "%s\n", S[i]);
      printf("%s\n", S[i]);
    }

    // Solve & Output
    res = Solver(N);
    if( res == -1 ){
      fprintf(fileout, "Case #%d: Fegla Won\n", t + 1);
    }
    else{
      fprintf(fileout, "Case #%d: %d\n", t + 1, res);
    }
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
