#include <stdio.h>

#define PLAYERNUM 5

struct batter{
    char* name;
    double battingAvg;
    int runs;
    int dismissals;
};

int main() {
    struct batter players[PLAYERNUM];

    for(int i=0; i<PLAYERNUM; i++){
        printf("Enter batter name: ");
        scanf("%s", players[i].name);

        printf("Enter runs: ");
        scanf("%d", &players[i].runs);

        printf("Enter dismissals: ");
        scanf("%d", &players[i].dismissals);

        players[i].battingAvg = (double)players[i].runs / (double)players[i].dismissals;
    }

    return 0;
}
