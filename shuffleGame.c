/*
 * This program is dedicated to randomize the outcome of the 12 person 
 * One Night Ultimate Werewolf game played by the 6 ships in BL.
 * Created by Vaskin for fun ;)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "shuffleGame.h"

/*
 * Function: main
 * --------------------------------------------------------------------
 * Generate and print out stats about a randomized game. The print messages include:
 * Each player's dealt card, initial animosity player, and trust player.
 * The player that first spoke up after the game starts.
 * The player that is voted out at the end of the game.
 *
 *  returns: EXIT_SUCCESS if properly executed, EXIT_FAILURE if failed
 */
int main() {
    // Initialize required values
    srand(time(0)); // Get the current UNIX time to be the seed for randomization
    printf("%d", rand());
    return EXIT_SUCCESS;
}

/*
 * Function: randomInRange
 * --------------------------------------------------------------------
 * gives a random number within the range (includes the lower bound and 
 * excludes the upper bound)
 *  lowerBound: lower bound of the randomization range
 *  upperBound: upper bound of the randomization range
 *
 *  returns: a random number within the range
 */
int randomInRange(int lowerBound, int upperBound) {
    // Do not execute if the computation is impossible
    if (upperBound <= lowerBound) exit(EXIT_FAILURE); // Exit immediately
    int randomizedResult = rand(); // Generate a random number
    // Cast the generated number into the requested range
    int randomRange = upperBound - lowerBound;
    int randomizedResult = randomizedResult % randomRange;
    randomizedResult = randomizedResult + lowerBound;
    return randomizedResult;
}

/*
 * Function: getPlayerNameString
 * --------------------------------------------------------------------
 * gives the player's name as string that's corresponding to the input 
 * playerName enum or name index, controlled by useEnum
 * Need to use this weird style, since compiler has no function overload
 *  name: the playerName enum to convert to the corresponding string
 *  nameNum: the index to the name in the #define order
 *  useEnum: 0 if using nameNum to convert, 1 if using name to convert
 *
 *  returns: string literal for the player's name
 */
const char *getPlayerNameString(playerName name, int nameNum, int useEnum) {
    if (useEnum == 0) {
        switch(nameNum) {
            // Return a string literal is fine with the use of const keyword
            case YOICHI_ISAGI: return "Isagi";
            case MEGURU_BACHIRA: return "Bachira";
            case RENSUKE_KUNIGAMI: return "Kunigami";
            case HYOMA_CHIGIRI: return "Chigiri";
            case SEISHIRO_NAGI: return "Nagi"; 
            case REO_MIKAGE: return "Reo";
            case ROSE_KONIG: return "Konig";
            /* Check the header: the flair is forbidden at the time this program's drafted. */
            /* They’ve dueled all over this this crazy world to find their moment to shine. */
            case ALEXIS_NESS: return "Ness";
            case RIN_ITOSHI: return "Rin";
            case SAE_ITOSHI: return "SAE";
            case TABITO_KARASU: return "Karasu";
            case YO_HIORI: return "Hiori";
            // Encountered an unknown name, do not attempt to convert and exit the program.
            default: exit(EXIT_FAILURE);
        }
    } else if (useEnum == 1) {
        switch(name) {
            // Return a string literal is fine with the use of const keyword
            case ISAGI: return "Isagi";
            case BACHIRA: return "Bachira";
            case KUNIGAMI: return "Kunigami";
            case CHIGIRI: return "Chigiri";
            case NAGI: return "Nagi"; 
            case REO: return "Reo";
            case KONIG: return "Konig";
            /* Check the header: the flair is forbidden at the time this program's drafted. */
            /* They’ve dueled all over this this crazy world to find their moment to shine. */
            case NESS: return "Ness";
            case RIN: return "Rin";
            case SAE: return "SAE";
            case KARASU: return "Karasu";
            case HIORI: return "Hiori";
            // Encountered an unknown name, do not attempt to convert and exit the program.
            default: exit(EXIT_FAILURE);
        }
    } else {
        // Invalid range for useEnum, exit immediately
        exit(EXIT_FAILURE);
    }
    // Suppress compiler warnings about return value if occurred.
    return "No name found!";
}

/*
 * Function: getCharacterCardString
 * --------------------------------------------------------------------
 * gives the card's corresponding in-game character as string that's corresponding 
 * to the input characterCard enum
 *  card: the characterCard enum to convert to the corresponding string
 *
 *  returns: string literal for the card's corresponding in-game character
 */
const char *getCharacterCardString(characterCard card) {
    switch(name) {
        // Return a string literal is fine with the use of const keyword
        case WOLF0: return "Werewolf";
        case WOLF1: return "Werewolf";
        case MINION: return "Minion";
        case MASON0: return "Mason";
        case MASON1: return "Mason"; 
        case SEER: return "Seer";
        case ROBBER: return "Robber";
        case TROUBLEMAKER: return "Troublemaker";
        case DRUNK: return "Drunk";
        case INSOMNIAC: return "Insomniac";
        case HUNTER: return "Hunter";
        case VILLAGER0: return "Villager";
        case VILLAGER1: return "Villager";
        case TANNER: return "Tanner";
        case APPRENTICE_TANNER: return "Apprentice Tanner";
        // Encountered an unknown card, do not attempt to convert and exit the program.
        default: exit(EXIT_FAILURE);
    }
    // Suppress compiler warnings about return value if occurred.
    return "No card found!";
}