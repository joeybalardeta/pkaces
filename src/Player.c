#include "Player.h"
#include "Deck.h"
#include <stdlib.h>


Player *CreatePlayer(int id, TYPE type){
	Player *player = (Player *) malloc(sizeof(Player));

	player->id = id;
	player->type = type;

	player->deck = CreateDeck();

	if (type == DEALER){
		FillDeck(player->deck);
	}


	return player;
}

void DeletePlayer(Player *player){
	if (player->deck != NULL){
		DeleteDeck(player->deck);
	}

	free(player);
	player = NULL;
}
