#ifndef C_GAMEEND_H
#define C_GAMEEND_H

#include "Scene.h"
#include "Mesh.h"
#include "FirstPersonCamera.h"
#include "MatrixStack.h"
#include "Light.h"
#include "c_Sound.h"
#include "c_CarBaseClass.h"

class c_GameEnd : public Scene
{
public:
	enum GEOMETRY_TYPE
	{
		TEXT,
		WINTEXT,
		LOSETEXT,
		GAMEOVER,
		ARROW,
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
		//Light1
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
		//***********************
		U_LIGHTENABLED,
		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,
		U_NUMLIGHTS,
		U_TEXT_ENABLED,
		U_TEXT_COLOR,
		U_TOTAL,
	};
	c_GameEnd();
	~c_GameEnd();
	void Init();
	void Update(double dt);
	void Render();
	void Exit();

private:
	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];
	FirstPersonCamera camera;
	MS modelStack, viewStack, projectionStack;

	Light light[1];

	void RenderMesh(Mesh *mesh, bool enableLight);
	void initLights();
	void renderLights();
	void updateLights(int num);

	void renderSelection();
	void updateSelection();
	void goNextLevel();
	void retry();
	void resetVar();
	c_CarBaseClass* getCar(std::string name);

	int ArrowY;
	double elapsedTime;
	double bounceTime;
	unsigned NextLevel;
	unsigned Retry;
	unsigned exit;
	double overTiming;
	bool over;

};

#endif C_MAINMENU_H