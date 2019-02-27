#ifndef C_MULTIPLAYERLEVELTWO_H
#define C_MULTIPLAYERLEVELTWO_H

#include "Scene.h"
#include "Mesh.h"
#include "FirstPersonCamera.h"
#include "MatrixStack.h"
#include "Light.h"

#include "c_OffRoadManager.h"
#include "c_ObjectManager.h"

#include "c_CarBaseClass.h"
#include"c_Sound.h"

#include "c_Weather.h"


class c_MultiplayerLevelTwo : public Scene
{
public:
	enum GEOMETRY_TYPE
	{
		TEXT,
		CARAXIS,
		TOP,
		BOTTOM,
		RACEBANNER,
		TRAFFICRED,
		TRAFFICNULL,
		TRAFFICNULL2,
		TRAFFICGREEN,
		STREETLIGHT,
		LIGHT1,
		LIGHT2,
		TRACK,
		ONCOOLDOWN,
		RAIN,
		SNOW,
		NUM_GEOMETRY,
	};
	enum UNIFORM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,

		// Lights
		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,

		U_LIGHT0_TYPE,
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,

		U_LIGHT1_POSITION,
		U_LIGHT1_COLOR,
		U_LIGHT1_POWER,
		U_LIGHT1_KC,
		U_LIGHT1_KL,
		U_LIGHT1_KQ,

		U_LIGHT1_TYPE,
		U_LIGHT1_SPOTDIRECTION,
		U_LIGHT1_COSCUTOFF,
		U_LIGHT1_COSINNER,
		U_LIGHT1_EXPONENT,

		U_LIGHT2_POSITION,
		U_LIGHT2_COLOR,
		U_LIGHT2_POWER,
		U_LIGHT2_KC,
		U_LIGHT2_KL,
		U_LIGHT2_KQ,

		U_LIGHT2_TYPE,
		U_LIGHT2_SPOTDIRECTION,
		U_LIGHT2_COSCUTOFF,
		U_LIGHT2_COSINNER,
		U_LIGHT2_EXPONENT,

		U_LIGHT3_POSITION,
		U_LIGHT3_COLOR,
		U_LIGHT3_POWER,
		U_LIGHT3_KC,
		U_LIGHT3_KL,
		U_LIGHT3_KQ,

		U_LIGHT3_TYPE,
		U_LIGHT3_SPOTDIRECTION,
		U_LIGHT3_COSCUTOFF,
		U_LIGHT3_COSINNER,
		U_LIGHT3_EXPONENT,

		U_LIGHT4_POSITION,
		U_LIGHT4_COLOR,
		U_LIGHT4_POWER,
		U_LIGHT4_KC,
		U_LIGHT4_KL,
		U_LIGHT4_KQ,

		U_LIGHT4_TYPE,
		U_LIGHT4_SPOTDIRECTION,
		U_LIGHT4_COSCUTOFF,
		U_LIGHT4_COSINNER,
		U_LIGHT4_EXPONENT,

		U_LIGHT5_POSITION,
		U_LIGHT5_COLOR,
		U_LIGHT5_POWER,
		U_LIGHT5_KC,
		U_LIGHT5_KL,
		U_LIGHT5_KQ,

		U_LIGHT5_TYPE,
		U_LIGHT5_SPOTDIRECTION,
		U_LIGHT5_COSCUTOFF,
		U_LIGHT5_COSINNER,
		U_LIGHT5_EXPONENT,
		//***********************
		U_LIGHTENABLED,
		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,
		U_NUMLIGHTS,
		U_TEXT_ENABLED,
		U_TEXT_COLOR,
		U_TOTAL,
	};

	c_MultiplayerLevelTwo();
	~c_MultiplayerLevelTwo();
	void Init();
	void Update(double dt);
	void Render();
	void Exit();

private:
	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];
	MS modelStack, viewStack, projectionStack;

	Light lights[6];

	void initLights();
	void renderLights();
	void updateLights(int num);
	void RenderMesh(Mesh *mesh, bool enableLight);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);

	void renderEnviroment();
	void renderPlayerOne();
	void renderPlayerTwo();

	void updateEnviromentCollision();
	void RenderSpeedometerOne();
	void RenderSpeedometerTwo();
	void renderRain();
	void RenderSnow();
	void renderOnCoolDown();
	void resetVar();

	FirstPersonCamera playerOneCam;
	float playerOneCamPosX;
	float playerOneCamPosY;
	float playerOneCamPosZ;
	float playerOneCamTargetX;
	float playerOneCamTargetY;
	float playerOneCamTargetZ;

	FirstPersonCamera playerTwoCam;
	float playerTwoCamPosX;
	float playerTwoCamPosY;
	float playerTwoCamPosZ;
	float playerTwoCamTargetX;
	float playerTwoCamTargetY;
	float playerTwoCamTargetZ;

	std::string elapedTimeCut;
	std::string CountdownCut;

	c_Entity front;
	c_Entity back;
	c_Entity left;
	c_Entity right;
	c_Entity track;
	c_Entity PickUp;
	c_CarBaseClass* playerOne;
	c_CarBaseClass* playerTwo;
	c_Entity speedometer;
	c_Entity needle;
	c_Entity circle;
	c_Entity FinishLine;
	c_Weather rain;
	c_Weather snow;
	c_Entity Checkpoints;
	c_Entity Checkpoints2;
	c_Entity Checkpoints3;
	c_ObjectManager* OBJmanager;
	c_OffRoadManager* offRoadManager;

	float ArrowP;
	bool RedLight;
	bool pick;
	bool OffRoad;
	bool Snowing;
	bool checkFO;
	bool checkFT;
	bool GreenLight;
	bool ExitGame;
	bool AbleToPress;
	bool OptionSelection;
	bool VehicleMove;

	bool OFreeze;
	bool TFreeze;
	bool Raining;
	bool PoneFinish;
	bool PTwoFinish;
	bool Win;
	bool Lose;
	bool startline;
	bool music;

	float elapsedTime;
	float OelapsedTime;
	float TelapsedTime;
	float Timer;
	float Countdown;
	float FreezeTime;
	float red1, red2, red3, green1, green2, green3;

	int Cooldown;
	int Ponelaps;
	int PTwolaps;
	int Oduration;
	int Tduration;
	int Tcooldown;
	int Ocooldown;
	int OCheckcount;
	int TCheckcount;
	int Random;

	c_Sound* Audio;

	c_Entity boost;
	c_Entity boost2;
	c_Entity boost3;
	c_Entity boost4;
	c_Entity boost5;
	c_Entity boost6;
	c_Entity boost7;
	c_Entity slow;
	c_Entity slow2;
	c_Entity slow3;
	c_Entity slow4;
	c_Entity slow5;
	c_Entity slow6;
	c_Entity slow7;
};

#endif
