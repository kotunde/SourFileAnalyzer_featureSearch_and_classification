#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

char Cars[100][101];
int StartOnly[26], EndOnly[26], StartEnd[26], Middle[26];
int StartOnlyN[26], EndOnlyN[26];//, StartEndN[26];
int ChainStart[100], ChainEnd[100], ChainSize[100], LoopChain[100], Chain[100], InChains, NChains, SChains;
__int64 C[101][101];

__int64 Solver(int N){
  __int64 res = 0, multiplier = 1;
  int i, j, i1, i2, flag;

  for( i = 0; i < 26; i ++ ){
    StartEnd[i] = 0;
    StartOnly[i] = 0;
    EndOnly[i] = 0;
    Middle[i] = 0;
    StartOnlyN[i] = 0;
    EndOnlyN[i] = 0;
  }
  for( i = 0; i < 26; i ++ ){
    Chain[i] = 0;
    ChainStart[i] = 0;
    ChainEnd[i] = 0;
    ChainSize[i] = 0;
    LoopChain[i] = 0;
  }
  InChains = 0;
  NChains = 0;
  SChains = 0;

  for( i = 0; i < N; i ++ ){
    if( Cars[i][0] == Cars[i][strlen(Cars[i])-1] ){
      StartEnd[Cars[i][0]-'a'] ++;
 //     StartEndN[Cars[i][0]-'a'] = i;
    }
    else{
      StartOnly[Cars[i][0]-'a'] ++;
      EndOnly[Cars[i][strlen(Cars[i])-1]-'a'] ++;
      StartOnlyN[Cars[i][0]-'a'] = i;
      EndOnlyN[Cars[i][strlen(Cars[i])-1]-'a'] = i;
    }
  }

  for( i = 0; i < N; i ++ ){
    for( i1 = 1; i < strlen(Cars[i]) - 1; i1 ++ ){
      if( Cars[i][i1] != Cars[i][0] ){
        break;
      }
    }
    for( i2 = strlen(Cars[i]) - 1; i2 > 0; i2 -- ){
      if( Cars[i][i2] != Cars[i][strlen(Cars[i]) - 1] ){
        break;
      }
    }
    if( i2 < i1 ){
      continue;
    }
    while( i1 <= i2 ){
      if( Cars[i][i1] != Cars[i][i1-1] ){
        Middle[Cars[i][i1]-'a'] ++;
      }
      i1 ++;
    }
  }

  //for( i = 0; i < 26; i ++ ){
  //  printf("Start =%d, End =%d, StartEnd =%d Middle=%d\n", StartOnly[i], EndOnly[i], StartEnd[i], Middle[i]);
  //  printf("StartN=%d, EndN=%d\n", StartOnlyN[i], EndOnlyN[i]);
  //}

  // check
  for( i = 0; i < 26; i ++ ){
    if( StartOnly[i] >= 2 ){
      return 0;
    }
    if( EndOnly[i] >= 2 ){
      return 0;
    }
    if( Middle[i] >= 2 ){
      return 0;
    }
    if( ( StartOnly[i] >= 1 )&&( Middle[i] >= 1 ) ){
      return 0;
    }
    if( ( EndOnly[i] >= 1 )&&( Middle[i] >= 1 ) ){
      return 0;
    }
  }

  for( i = 0; i < 26; i ++ ){
    if( ( StartOnly[i] != 0 )||( EndOnly[i] != 0 ) ){
      continue;
    }
    NChains ++;
    SChains ++;
    for( j = 0; j < N; j ++ ){
      if( ( Cars[j][0] == 'a' + i )&&( Cars[j][strlen(Cars[j])-1] == 'a' + i ) ){
        ChainSize[NChains] ++;
        ChainStart[NChains] = Cars[j][0];
        ChainEnd[NChains] = Cars[j][0];
        Chain[j] = NChains;
        InChains ++;
      }
    }
    if( ChainSize[NChains] == 0 ){
      NChains --;
      SChains --;
    }
  }

  while( InChains < N ){
    flag = 1;
    for( i = 0; i < N; i ++ ){
      if( Chain[i] > 0 ){
        continue;
      }
      for( j = 1; j <= NChains; j ++ ){
        if( Cars[i][0] == ChainEnd[j] ){
          Chain[i] = j;
          ChainEnd[j] = Cars[i][strlen(Cars[i])-1];
          ChainSize[j] ++;
          InChains ++;
          flag = 0;
          break;
        }
        if( Cars[i][strlen(Cars[i])-1] == ChainStart[j] ){
          Chain[i] = j;
          ChainStart[j] = Cars[i][0];
          ChainSize[j] ++;
          InChains ++;
          flag = 0;
          break;
        }
      }
    }
    if( flag ){
      for( i = 0; i < N; i ++ ){
        if( Chain[i] > 0 ){
          continue;
        }
        NChains ++;
        Chain[i] = NChains;
        ChainSize[NChains] = 1;
        ChainStart[NChains] = Cars[i][0];
        ChainEnd[NChains] = Cars[i][strlen(Cars[i])-1];
        InChains ++;
        break;
      }
    }
  }
  res = 1;
  for( i = 1; i <= NChains; i ++ ){
    res = (res * i) % 1000000007;
  }
  for( i = SChains + 1; i <= NChains; i ++ ){
    if( ChainStart[i] == ChainEnd[i] ){
      res = (res * ChainSize[i]) % 1000000007;
    }
  }
  for( i = 0; i < 26; i ++ ){
    for( j = 1; j <= StartEnd[i]; j ++ ){
      res = (res * j) % 1000000007;
    }
  }

  return res;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t, N, n;
  __int64 res;

  if( argc < 3 ){
    printf("Usage is: TaskB filein fileout\n");
    return 0;
  }

  for( int i = 0; i < 101; i ++ ){
    C[i][0] = 1;
    C[0][i] = 1;
  }
  for( int i = 1; i < 101; i ++ ){
    for( int j = 1; j < 101; j ++ ){
      C[i][j] = (C[i-1][j] + C[i-1][j-1])%1000000007;
    }
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

    for( n = 0; n < N - 1; n ++ ){
      fscanf(filein, "%s ", &(Cars[n]));
      printf("%s ", Cars[n]);
    }
    fscanf(filein, "%s\n", &(Cars[N-1]));
    printf("%s\n", Cars[N-1]);

    // Solve & Output
    res = Solver(N);
    fprintf(fileout, "Case #%d: %d\n", t + 1, res);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
