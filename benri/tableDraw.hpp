#include "../template.hpp";

void tableDraw(vvi &table) {
    int N = int(table.size()), M = int(table[0].size());
    printf("i\\j |");
    rep(i, M) printf("[%2d]|", i);
    rep(i, N) {
        printf("\n");
        rep(i, M + 1) printf("----|");
        printf("\n");
        printf("[%2d]|", i);
        for (int j = 0; j < M; j++) {
            printf("%4d|", table[i][j]);
        }
    }
    printf("\n");
}