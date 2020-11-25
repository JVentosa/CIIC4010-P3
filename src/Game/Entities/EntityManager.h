#pragma once

#include "Entity.h"
#include "Client.h"
#include "Inspector.h"

class EntityManager {
private:
int angryLclients = 0;
public:
	Client* firstClient;
	Inspector* inspect;
	void tick();
	int getAngryLClients();
	void setAngryLClients(int angryLclients);
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c); // Me deja hacerlo con client porque inspecor hereda de client??
	void removeLeavingClients();
	void removeAllClients();
	// Client* getClient();
	std::vector<Entity*> entities;

};