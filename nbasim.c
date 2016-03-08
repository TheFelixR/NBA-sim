#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
 
// constants for teams in the leauge, max points and minimum points.
#define MAXTEAMS 30
#define MAX_P 110
#define MIN_P 70
 
//structure for the "gameday"
struct gameday
{
    char* team;
    int points;
};
 
// prototypes
int scoreGenerator();
int teamGenerator();
void anouncement(int n);
 
int main(void)
{
    // gets a psudorandom seed
    srand(time(NULL));
     
    // all the teams. +1 to reserve space for null character
    char* nbateams[MAXTEAMS+1] = {"Brooklyn Nets", "New York Knicks", "Philadelphia 76ers", "Toronto Raptors", "Boston Celtics",
                                  "Chicago Bulls", "Cleveland Cavaliers", "Detroit Pistons", "Indiana Pacers", "Milwaukee Bucks",
                                  "Atlanta Hawks", "Charlotte Hornets", "Miami Heat", "Orlando Magic", "Washington Wizards",
                                  "Denver Nuggets", "Minnesota Timberwolves", "Oklahoma City Thunder", "Portland Trail Blazers", "Utah Jazz",
                                  "Golden State Warriors", "Los Angeles Clippers", "Los Angeles Lakers", "Phoenix Suns", "Sacramento Kings",
                                  "Dallas Mavericks", "Houston Rockets", "Memphis Grizzlies", "New Orleans Pelicans", "San Antonio Spurs"};
     
    // how many games do you want to be played? 
    int nbagames = 0;
                                 
    while(nbagames < 10)
    {
        // gets the first team and generates a score for it
        struct gameday team1;
        team1.team = nbateams[teamGenerator()];
        team1.points = scoreGenerator(team1.team);
         
        // gets a second team and generates score for it. Keep generating untill the teams are not the same
        struct gameday team2;
        do
        { 
            team2.team = nbateams[teamGenerator()];
             
        } while(strcmp(team1.team, team2.team) == 0);
         
        // gets points for team2 untill they are not equal to team1s points.
        do
        { 
            team2.points = scoreGenerator(team2.team);
             
        } while(team1.points == team2.points);
         
        // prints out the diffrent teams and their points
        printf("\n");
        printf("%s(%d) - %s(%d)\n", team1.team, team1.points, team2.team, team2.points);
         
         
        // get data for anouncement, so we can print out the winner and such.
        int n = 0;
        if (team1.points > team2.points)
        {
            n = team1.points - team2.points;
            printf("The %s ", team1.team);
            anouncement(n);
        }
        else
        {
            n = team2.points - team1.points;
            printf("The %s ", team2.team);
            anouncement(n);
        }
        printf("\n");
        // increment the nba games played.
        nbagames++;
    }
}
// get psudorandom score based on the time and the leanght of the team name.
int scoreGenerator(char* team)
{  
    int score = rand() % (MAX_P  - MIN_P + 1) + MIN_P;
 
    return score;
}
// get psudorandom team.
int teamGenerator(void)
{
    int r = rand() % MAXTEAMS;
 
    return r;
}
// print out an extra message dependent on how much the team won the game with.
void anouncement(int n)
{
    if(n <= 5)
        printf("win the close game");
    else if(n <= 15)
        printf("win the game");
    else
        printf("win the blowout game");
}
