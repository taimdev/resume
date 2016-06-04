// runGame.c 
// Crippling Indecision: Taimur Selina Ryan Jay Cameron
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Game.h"

#define WIN_KPI 150
#define TERRA_NULLIUS -1
#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}


static int rollDice();

int main(int argc, char *argv[]) {

	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame(disciplines, dice);
	int diceValue;
	int turnOver = FALSE;
	int whoseTurn = NO_ONE;
	int winner = NO_ONE;
	int turnNo = TERRA_NULLIUS;

	while (winner == NO_ONE) {

		diceValue = rollDice();

		throwDice(g, diceValue);

		whoseTurn = getWhoseTurn(g);
		turnNo = getTurnNumber(g);

        printf("====== Turn %d - Player %c ======\n",turnNo, whoseTurn);
      	printf("The dice cast %d\n", diceValue);


      	turnOver = FALSE;
		while (turnOver == FALSE) {
			action move;
			printf("What is your move?\n");
			scanf("%d", &move.actionCode);
			assert(isLegalAction(g,move));
         	if (move.actionCode == START_SPINOFF){
         		if (rand() % 3 <= 1) {
         			move.actionCode = OBTAIN_PUBLICATION;
         		} else {
         			move.actionCode = OBTAIN_IP_PATENT;
         		}
         	}
         	makeAction(g,move);

         	if (move.actionCode == PASS) {
         		turnOver = TRUE;
         		printf("Pass\n");
         	}
         	if (getKPIpoints(g,whoseTurn) >= WIN_KPI) {
         		turnOver = TRUE;
         		winner = whoseTurn;
         	}
         	// PRINTING STATISTICS
         	// The resources
         	printf("Your Resources\n");
         	printf("\n");
         	printf("Publications = %d \n", getPublications(g, whoseTurn));
         	printf("Patents =      %d \n", getIPs(g, whoseTurn));
         	printf("Campuses =     %d \n", getCampuses(g, whoseTurn));
         	printf("GO8's =        %d \n", getGO8s(g, whoseTurn));
         	printf("ARC's =        %d \n", getARCs(g, whoseTurn));

			// The Students     	
         	printf("Your Students\n");
         	printf("\n");
         	printf("THD's =        %d \n", getStudents(g, whoseTurn, STUDENT_THD));
         	printf("BPS's =        %d \n", getStudents(g, whoseTurn, STUDENT_BPS));
         	printf("BQN's =        %d \n", getStudents(g, whoseTurn, STUDENT_BQN));
         	printf("MJ's =         %d \n", getStudents(g, whoseTurn, STUDENT_MJ));
         	printf("MTV's =        %d \n", getStudents(g, whoseTurn, STUDENT_MTV));
         	printf("MMONEY =       %d \n", getStudents(g, whoseTurn, STUDENT_MMONEY));
     
     		// Other Statistics
     		printf("Game Statistics\n");
     		printf("\n");
     		printf("Player 1's KPI =      %d \n", getKPIpoints(g,1));
     		printf("Player 2's KPI =      %d \n", getKPIpoints(g,2));
     		printf("Player 3's KPI =      %d \n", getKPIpoints(g,3));
     		printf("MMONEY =       %d \n", getStudents(g, whoseTurn, STUDENT_MMONEY))





		}
	}

}

static int rollDice() {

	int dice1;
	int dice2;
	int diceValue;

	dice1 = ((rand() % 6) + 1);
	dice2 = ((rand() % 6) + 1);
	diceValue = dice1 + dice2;

	return diceValue;
}