#ifndef GAME_H
#define GAME_H
#include "PlayerList.h"
#include "Deck.h"
#include "Player.h"


typedef struct {
	PLIST *players;
	Player *Dealer;
	DECK *boardCards;
	int betPoints;
	int minimumBet;
	Player *roundWinner;

} Game;


Game *CreateGame();

void DeleteGame(Game *game);

void DealCards(Game *game);

void SelectDealer(Game *game);

void InitializeGameConnections(Game *game, int activeConnections);

void GameLoop();

void GameRound(Game *game);

void GameRoundEnd(Game *game);

int BetPoints(Game *game, Player *player, int points);

void ProcessUserActions(Game *game);

void GetUserInput(Game *game, Player *player);

Player *EvaluateHands(Game *game);

Player *LastManStanding(Game *game);

int PlayersWithPoints(Game *game);

void PrintPlayerData(Game *game);

void SendPacket(Game *game, Player *player, int newRound, int needsInput, int gameOver);

void BroadcastPackets(Game *game, int newRound, int needsInput, int gameOver);

void DecodePacket(Game *game, Player *player, const char *msg);

void HandlePacket(Game *game, Player *player);

#endif
