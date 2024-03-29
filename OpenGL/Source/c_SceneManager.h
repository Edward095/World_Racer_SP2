#ifndef C_SCENEMANAGER_H
#define C_SCENEMANAGER_H

#include <string>
#include <map>

#include "c_Npc.h"
#include "c_Garage.h"
#include "c_LevelOne.h"
#include "c_LevelTwo.h"
#include "c_LevelThree.h"
#include "c_MultiplayerLevel.h"
#include "c_MultiplayerLevelTwo.h"
#include "c_MultiplayerLevelThree.h"

#include "c_Continue.h"
#include "c_GameEnd.h"
#include "c_Title.h"

class c_SceneManager
{
private://Functions and Enums
	c_SceneManager();
	enum GAMESTATE
{
		NPC,
		GARAGE,
		CHANGED,
		SLEVELONE,
		SLEVELTWO,
		SLEVELTHREE,
		MLEVELONE,
		MLEVELTWO,
		MLEVELTHREE,
		CONTINUE,
		FINISHED,
		TITLE,
};

public:
	~c_SceneManager();
	static c_SceneManager* getInstance();
	void cleanUp();
	void updateState(std::string state);
	void updateLevel(std::string level);
	bool checkState(std::string state);
	bool checkLevel(std::string level);
	bool singleOrMulti(char sORm);
	void setWinOrLose(bool winorlose);
	bool getWinOrLose();
	std::string getLevel();

	Scene* getScene(std::string sceneName);

private:
	//Variables
	static c_SceneManager* instance;
	std::map <GAMESTATE, std::string> game_State;
	std::string currentState;
	std::string level;
	bool WinOrLose;

	c_Npc* npc;
	c_Garage* garage;
	c_LevelOne* sLevelOne;
	c_LevelTwo* sLevelTwo;
	c_LevelThree* sLevelThree;
	c_MultiplayerLevel* mLevelOne;
	c_MultiplayerLevelTwo* mLevelTwo;
	c_MultiplayerLevelThree* mLevelThree;

	c_GameEnd* gameEnd;
	c_Continue* continueGame;
	c_Title* title;
};

#endif