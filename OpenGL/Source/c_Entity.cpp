#include "c_Entity.h"
#include "MeshBuilder.h"
#include "LoadTGA.h"
#include "c_ObjectManager.h"
#include "c_OffRoadManager.h"

c_ObjectManager* objectManager = c_ObjectManager::getInstance();
c_OffRoadManager* offRoadManager = c_OffRoadManager::getInstance();

c_Entity::c_Entity()
{
	OBB = nullptr;
}
c_Entity::c_Entity(std::string uniqueName, const char* meshPath, const char* TGApath, Vector3 pos,bool canCollide)
{
	//Add Object to the List
	this->pos = pos;
	this->meshPath = meshPath;
	this->TGApath = TGApath;
	this->uniqueName = uniqueName;
	quadORobject();//if Quad generate Quad else generate Obj
	mesh->textureID = LoadTGA(TGApath);
	OBB = new c_Collision;
	OBB->setHighLow(meshPath);

	if (canCollide)
		objectManager->addCanCollide(this);
	else 
		objectManager->addCannotCollide(this);

	std::string temp = uniqueName;
	temp.resize(7);
	if (temp == "offRoad")
		offRoadManager->addToList(uniqueName);
}


c_Entity::~c_Entity()
{
	delete OBB;
}


void c_Entity::init(std::string uniqueName, const char* meshPath, const char* TGApath, Vector3 pos, bool canCollide)
{
	this->pos = pos;
	this->meshPath = meshPath;
	this->TGApath = TGApath;
	this->uniqueName = uniqueName;
	quadORobject();//if Quad generate Quad else generate Obj
	mesh->textureID = LoadTGA(TGApath);
	OBB = new c_Collision;
	OBB->setHighLow(meshPath);

	//Add Object to the List
	if (canCollide)
		objectManager->addCanCollide(this);
	else
		objectManager->addCannotCollide(this);

	std::string temp = uniqueName;
	temp.resize(7);
	if (temp == "offRoad")
		offRoadManager->addToList(uniqueName);
}
void c_Entity::init(std::string uniqueName)
{
	for (int i = 0; i < (int)objectManager->getCanCollide().size(); i++)
	{
		if (objectManager->getCanCollide().at(i)->getUniqueName() == uniqueName)
		{
		c_Entity* other = objectManager->getCanCollide().at(i);

		this->pos = other->pos;
		this->meshPath = other->meshPath;
		this->TGApath = other->TGApath;
		this->uniqueName = uniqueName;
		this->mesh = other->mesh;
		this->mesh->textureID = LoadTGA(TGApath);
		this->OBB = other->OBB;
		this->OBB->setHighLow(meshPath);
		}
	}

}

Mesh* c_Entity::getMesh()
{
	return mesh;
}
Vector3 c_Entity::getPos()
{
	return pos;
}
c_Collision* c_Entity::getOBB()
{
	return OBB;
}
c_Entity* c_Entity::getEntity(std::string uniqueName, bool canCollide)
{
	if (canCollide)
	{
		for (int i = 0; i < (int)objectManager->getCanCollide().size(); i++)
		{
			if (objectManager->getCanCollide().at(i)->uniqueName == uniqueName)
			{
				return objectManager->getCanCollide().at(i);
			}
		}
	}
	else
	{
		for (int i = 0; i < (int)objectManager->getCannotCollide().size(); i++)
		{
			if (objectManager->getCannotCollide().at(i)->uniqueName == uniqueName)
			{
				return objectManager->getCannotCollide().at(i);
			}
		}
	}

}
bool c_Entity::gotCollide(float x, float y, float z)
{
	std::vector<c_Entity*> entity = objectManager->getCanCollide();

	updatePos(pos.x + x, pos.y + y, pos.z + z);

	for (int i = 0; i < (int)objectManager->getCanCollide().size(); i++)
	{
		c_Collision* collide = entity[i]->getOBB();

		if (collide != OBB && OBB->OBB(collide))
		{
			updatePos(pos.x - x, pos.y - y, pos.z - z);
			return true;
		}
	}
	return false;
}
bool c_Entity::gotCollide(std::string uniqueName, bool canCollide)
{
	c_Collision* objectToCollide = nullptr;

	if (canCollide)
	{
		for (int i = 0; i < (int)objectManager->getCanCollide().size(); i++)
		{
			if (objectManager->getCanCollide().at(i)->getUniqueName() == uniqueName)
				objectToCollide = objectManager->getCanCollide().at(i)->getOBB();
		}
	}
	else
	{
		for (int i = 0; i < (int)objectManager->getCannotCollide().size(); i++)
		{
			if (objectManager->getCannotCollide().at(i)->getUniqueName() == uniqueName)
			{
				objectToCollide = objectManager->getCannotCollide().at(i)->getOBB();
				break;
			}
		}
	}
	if (objectToCollide != nullptr && this->OBB->OBB(objectToCollide))
		return true;

	return false;
}
void c_Entity::quadORobject()
{
	if (meshPath == "quad")
		mesh = MeshBuilder::GenerateQuad(meshPath, Color(1, 1, 1), 1.f);
	else
		mesh = mesh = MeshBuilder::GenerateOBJ("Mesh", meshPath);
}
void c_Entity::updatePos(float xPos, float yPos, float zPos)
{
	this->pos.x = xPos;
	this->pos.y = yPos;
	this->pos.z = zPos;
	OBB->setPos(this->pos);
}
std::string c_Entity::getUniqueName()
{
	return uniqueName;
}
bool c_Entity::ignoreEntity(std::string uniqueName)
{
	return	(uniqueName != this->uniqueName &&
		uniqueName != "track" ||
		uniqueName != "Boostpad" ||
		uniqueName != "Boostpad2" ||
		uniqueName != "Boostpad3" ||
		uniqueName != "Boostpad4" ||
		uniqueName != "Boostpad5" ||
		uniqueName != "Boostpad6" ||
		uniqueName != "Boostpad7" ||
		uniqueName != "Slowpad" ||
		uniqueName != "Slowpad2" ||
		uniqueName != "Slowpad3" ||
		uniqueName != "Slowpad4" ||
		uniqueName != "Slowpad5" ||
		uniqueName != "Pickup" ||
		uniqueName != "Checkpoint" ||
		uniqueName != "Checkpoint2" ||
		uniqueName != "Checkpoint3" ||
		uniqueName != "Slowpad6" ||
		uniqueName != "Slowpad7");
}
const char* c_Entity::getMeshPath()
{
	return meshPath;
}
const char* c_Entity::getTGApath()
{
	return TGApath;
}