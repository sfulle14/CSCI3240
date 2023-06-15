#include <stdio.h>
#include <string.h>

#define PLAYERNUM 5
#define NAMELIMIT 25

struct batter{
    char name[NAMELIMIT];
    double battingAvg;
    int runs;
    int dismissals;
};

int main() {
    struct batter players[PLAYERNUM];
    char playerName[NAMELIMIT];

    for(int i=0; i<PLAYERNUM; i++){
        printf("Enter batter name: ");
        scanf("%s", players[i].name);

        printf("Enter runs: ");
        scanf("%d", &players[i].runs);

        printf("Enter dismissals: ");
        scanf("%d", &players[i].dismissals);

        players[i].battingAvg = (double)players[i].runs / (double)players[i].dismissals;
    }


    printf("Enter a player name: ");
    scanf("%s", playerName);

    for(int i=0; i< PLAYERNUM; i++){
        if(!strcmp(playerName, players[i].name)){
            printf("Batting average: %f\n", players[i].battingAvg);
        }
    }


    return 0;
}
