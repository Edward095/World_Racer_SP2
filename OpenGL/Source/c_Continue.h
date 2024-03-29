#ifndef C_CONTINUE_H
#define C_CONTINUE_H

#include "Scene.h"
#include "Mesh.h"
#include "FirstPersonCamera.h"
#include "MatrixStack.h"
#include "Light.h"
#include "c_Sound.h"

class c_Continue : public Scene
{
public:
	enum GEOMETRY_TYPE
	{
		TEXT,
		FILESELECTION,
		NOSAVEFILE,
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
	c_Continue();
	~c_Continue();
	void Init();
	void Update(double dt);
	void Render();
	void Exit();
	void resetVar();

private:
	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];
	FirstPersonCamera camera;
	MS modelStack, viewStack, projectionStack;

	Light light[1];

	void RenderMesh(Mesh *mesh, bool enableLight);
	void RenderTextOnScreen(Mesh * mesh, std::string text, Color color, float size, float x, float y);
	void initLights();
	void renderLights();
	void updateLights(int num);

	void renderSelection();
	void updateSelection(double dt);
	void loadFile();
	bool checkEmpty();

	//Variables
	int ArrowY;
	double elapsedTime;
	double bounceTime;
	bool noFile;
	unsigned int Save1;
	unsigned int Save2;
	unsigned int Save3;

	std::string OBJpath;
	std::string TGApath;
	int levelNum;
};

#endif C_MAINMENU_H