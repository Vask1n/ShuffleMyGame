/*
 * Header file for shuffleGame.c that stores the enum definitions,
 * players' initial data, and function declarations.
 * Created by Vaskin for fun ;)
 */

// #define the global constants about this game
#define TOTAL_PLAYERS 12 // There are a total of 12 players
#define TOTAL_CARDS 14 // There are a total of 14 cards
// #defines to use name to index into players and player-related arrays
// Order used here is the same as the announcement in the group chat
#define YOICHI_ISAGI 0
#define MEGURU_BACHIRA 1
#define RENSUKE_KUNIGAMI 2
#define HYOMA_CHIGIRI 3
#define SEISHIRO_NAGI 4
#define REO_MIKAGE 5
#define ROSE_KONIG 6
/* That flair is prohibited at the time this program's drafted. */
/* No matter who they Duel, it will still end in their victory. */
#define ALEXIS_NESS 7
#define RIN_ITOSHI 8
#define SAE_ITOSHI 9
#define TABITO_KARASU 10
#define YO_HIORI 11

// Address each character with their "preferred" name using enum
typedef enum {
    ISAGI = YOICHI_ISAGI, BACHIRA = MEGURU_BACHIRA, 
    KUNIGAMI = RENSUKE_KUNIGAMI, CHIGIRI = HYOMA_CHIGIRI, 
    NAGI = SEISHIRO_NAGI, REO = REO_MIKAGE,
    KONIG = ROSE_KONIG, /* Nothing you say can change my mind. */
    NESS = ALEXIS_NESS, 
    RIN = RIN_ITOSHI, SAE = SAE_ITOSHI, 
    KARASU = TABITO_KARASU, HIORI = YO_HIORI,
} playerName;

// List all the game character cards to use in this game
typedef enum {
    WOLF0, WOLF1, MINION, // The werewolf team
    MASON0, MASON1, SEER, ROBBER, TROUBLEMAKER, DRUNK, INSOMNIAC, 
    HUNTER, VILLAGER0, VILLAGER1, // The villager team
    TANNER, APPRENTICE_TANNER, // The tanner team
} characterCard;

// Use a dedicated data structure to store info about players
typedef struct Player {
    // Predetermined stats
    playerName name; // Use enum to know the current player's name index
    int animosityRate[12]; // Probability distribution for sussing another
    // character at the start of the game. Default 0 for self. Total to 100.
    int trustRate[12]; // Probability of trusting another character at the start
    // of a game. Default 0 for self (not considering self). Total to 100.

    // Stats that's randomized
    characterCard gameCharacter; // Record which card this player received
    playerName animosity; // Select a player to attack/pay close attention to first
    playerName trust; // Select a player to trust first
} Player;

// Initialize the data about the players
Player players[12]; // Use an array to store all players
// Logic behind the initial stats:
// 1. trust the other person in the ship more than others, and vice versa,
// 2. trust people on the same team more than others, and vice versa,
// 3. trust people who appear to be naive more than others, and vice versa,
// 4. special cases apply and override the logic above
// Define Yoichi Isagi's stats
player[YOICHI_ISAGI].name = ISAGI;
player[YOICHI_ISAGI].animosityRate = {0, 5, 5, 5, 5, 10, 25, 15, 5, 10, 10, 5};
player[YOICHI_ISAGI].trustRate = {0, 30, 5, 5, 10, 5, 0, 0, 10, 5, 5, 25};
// Define Meguru Bachira's stats
player[MEGURU_BACHIRA].name = BACHIRA;
player[MEGURU_BACHIRA].animosityRate = {5, 0, 5, 5, 10, 10, 15, 15, 5, 10, 10, 10};
player[MEGURU_BACHIRA].trustRate = {35, 0, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5};
// Define Rensuke Kunigami's stats
player[RENSUKE_KUNIGAMI].name = KUNIGAMI;
player[RENSUKE_KUNIGAMI].animosityRate = {5, 5, 0, 5, 10, 10, 15, 15, 5, 10, 10, 10};
player[RENSUKE_KUNIGAMI].trustRate = {15, 10, 0, 35, 5, 15, 0, 0, 5, 5, 5, 5};
// Define Hyoma Chigiri's stats
player[HYOMA_CHIGIRI].name = CHIGIRI;
player[HYOMA_CHIGIRI].animosityRate = {5, 5, 5, 0, 5, 5, 20, 15, 10, 10, 10, 10};
player[HYOMA_CHIGIRI].trustRate = {15, 15, 35, 0, 15, 20, 0, 0, 0, 0, 0, 0};
// Define Seishiro Nagi's stats
player[SEISHIRO_NAGI].name = NAGI;
player[SEISHIRO_NAGI].animosityRate = {10, 10, 10, 10, 0, 0, 10, 10, 10, 10, 10, 10};
player[SEISHIRO_NAGI].trustRate = {10, 10, 10, 10, 0, 30, 5, 5, 5, 5, 5, 5};
// Define Reo Mikage's stats
player[REO_MIKAGE].name = REO;
player[REO_MIKAGE].animosityRate = {20, 5, 5, 5, 5, 0, 10, 10, 10, 10, 10, 10};
player[REO_MIKAGE].trustRate = {10, 10, 15, 15, 20, 0, 5, 5, 5, 5, 5, 5};
// Define the blue rose's stats
player[ROSE_KONIG].name = KONIG;
player[ROSE_KONIG].animosityRate = {30, 5, 5, 5, 5, 5, 0, 0, 10, 10, 10, 15};
player[ROSE_KONIG].trustRate = {0, 10, 10, 10, 10, 10, 0, 10, 10, 10, 10, 10};
// Define Alexis Ness's stats
player[ALEXIS_NESS].name = NESS; // "The Ultimate Meatrider" has a talent.
player[ALEXIS_NESS].animosityRate = {100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
player[ALEXIS_NESS].trustRate = {0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0};
// Define Rin Itoshi's stats
player[RIN_ITOSHI].name = RIN;
player[RIN_ITOSHI].animosityRate = {5, 5, 10, 10, 10, 10, 10, 10, 0, 15, 5, 10};
player[RIN_ITOSHI].trustRate = {10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 10, 10};
// Define Sae Itoshi's stats
player[SAE_ITOSHI].name = SAE;
player[SAE_ITOSHI].animosityRate = {5, 10, 10, 10, 10, 10, 10, 10, 5, 0, 10, 10};
player[SAE_ITOSHI].trustRate = {20, 5, 5, 5, 5, 5, 5, 5, 35, 0, 5, 5};
// Define Tabito Karasu's stats
player[TABITO_KARASU].name = KARASU;
player[TABITO_KARASU].animosityRate = {10, 10, 10, 10, 10, 10, 10, 10, 5, 10, 0, 5};
player[TABITO_KARASU].trustRate = {5, 10, 5, 5, 5, 10, 5, 5, 20, 5, 0, 25};
// Define Yo Hiori's stats
player[YO_HIORI].name = HIORI;
player[YO_HIORI].animosityRate = {5, 5, 5, 5, 5, 10, 15, 25, 5, 10, 10, 0};
player[YO_HIORI].trustRate = {10, 10, 10, 5, 5, 10, 5, 5, 5, 5, 25, 5};

// Declare all functions used in the program
int randomInRange(int lowerBound, int upperBound);
const char *getPlayerNameString(playerName name);
const char *getCharacterCardString(characterCard card);