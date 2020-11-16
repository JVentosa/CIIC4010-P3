#pragma once

#include "Entity.h"
#include "Client.h"

class EntityManager {
private:
int angryLclients = 0;
public:
	Client* firstClient;
	void tick();
	int getAngryLClients();
	void setAngryLClients(int angryLclients);
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeLeavingClients();
	// Client* getClient();
	std::vector<Entity*> entities;

};