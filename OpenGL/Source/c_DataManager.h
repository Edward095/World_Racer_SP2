#ifndef C_DATAMANAGER
#define C_DATAMANAGER

#include <string>

class c_DataManager
{
public:
	~c_DataManager();
	static c_DataManager* getInstance();
	void saveCustomization(std::string OBJpath, std::string TGApath);
	void saveLapTime(float lapTime);
	void saveCurrentLevel(int levelNum);
	void saveSoundOptions();
	void updateLeaderBoards(float lapTime, std::string name);
	void selectFile(int fileNum);
	void readFromFile();


private://Variables
	static c_DataManager* instance;

	std::string leaderBoardsFile;
	std::string saveFile1;
	std::string saveFile2;
	std::string saveFile3;
	std::string soundFile;
	std::string currentFile;

private://Functions
	c_DataManager();
};

#endif