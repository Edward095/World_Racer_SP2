#ifndef C_CARBASECLASS_H
#define C_CARBASECLASS_H

#include "c_Entity.h"
#include "Application.h"
#include "c_Sound.h"
class c_CarBaseClass : public c_Entity
{
public:
	c_CarBaseClass();
	~c_CarBaseClass();
	void updateAppearance(const char* meshPath, const char* TGApath);
	virtual void Movement(double dt);
	virtual void PadEffect(double dt);
	float GetSteeringAngle();
	float GetMaxAcceleration();
	float GetSpeed();
	float GetAcceleration();
	void SetSpeed(float speed);
	void SetFriction(float friction);
	void SetSteering(float Steering);
	void SetMaxSpeed(float Speed);
	void SetSteeringAngle(float angle);
	virtual void Ability(double dt) = 0;
	virtual void PowerUp(bool check) = 0;
	virtual void isOffRoad() = 0;
	virtual void PSpeed(float speed);
	virtual void SetOSlowed(bool speed);
	virtual void SetTSlowed(bool speed);
	virtual float GetSpedoSpeed();

	c_Sound* Audio;

protected:
	float VelocityZ;
	float MaxSpeed;
	float SteeringAngle;
	float Acceleration;
	float MaxAcceleration;
	float Friction;
	float Steering;
	int Duration;
	int Cooldown;
	float SpedoVeloZ;

	bool Driving = false;
	bool Backwards = false;
	bool PressQ = false;
	bool Nitro = false;
	bool BoostPad = false;
	bool SlowPad = false;
	bool once;

	bool offRoad;
	bool Collided = false;
	bool freeze = false;
	bool Oslowed;
	bool Tslowed;

	bool abilityUsed;
};


#endif

