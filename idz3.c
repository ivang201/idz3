#include <stdio.h>
#define N 100
#define M 100
#define X 100
int main(){
    int x = 100;
    char line[X];
    char matrix[N][M];
    char a = '*';
    char b = '*';
    int str = 0;
    int stb = 0;
    int o = 0;
    FILE* in = fopen("matrix.txt", "r");
    FILE* out = fopen("graf.gv", "w");
    fputs("graph idz3 {", out);
    fgets(line, X, in);
    while (fgets(line, X, in)) {
        stb = 0;
        for (int i = 0; line[i]; i++) {
            if (line[i] != ' ') {
                matrix[str][stb] = line[i];
                stb++;
            }
        }
        str++;
    }
    for (int i = 1; i < stb; i++) {
        for (int j = 0; j < str; j++) {
            if (matrix[j][i] == '1') {
                b = a;
                a = matrix[j][0];
            }
        }
        fprintf(out, "\n\t%c -- %c;", b, a);
    }
    fprintf(out,"\n}");
    fclose(out);
    fclose(in);
    stb = stb - 1;
    if(stb>((str-1)*(str-2)/2)){
        printf("Граф связаный!!! Ребер: %d, Вершин: %d \n", stb, str);
    }else{
        printf("Граф несвязаный!!! Ребер: %d, Вершин: %d \n", stb, str);
    }
    return 0;
}
