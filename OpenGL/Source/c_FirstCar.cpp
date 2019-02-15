#include "c_FirstCar.h"
#include "Application.h"
#include "MyMath.h"

c_FirstCar::c_FirstCar()
{
	Driving = false;
	VelocityZ = 0;
	Acceleration = 0;
}
c_FirstCar::~c_FirstCar()
{

}

void c_FirstCar::Movement(double dt)
{
	
		if (Application::IsKeyPressed('W'))
		{
			Acceleration += 0.1;
			//steeringAngle = 0;
			VelocityZ += Acceleration * dt;
			pos.x += (sin(Math::DegreeToRadian(SteeringAngle)) * VelocityZ);
			pos.y = pos.y;
			pos.z += (cos(Math::DegreeToRadian(SteeringAngle)) * VelocityZ);
			Driving = true;
			Backwards = false;
			Ability();
			if (Acceleration > 1)
			{
				Acceleration = 1;
			}

			if (VelocityZ > 1 && (PressQ || Nitro))
			{
				VelocityZ = 1.5;
			}
			else if (VelocityZ > 1 && (!PressQ || !Nitro))
			{
				VelocityZ = 1;
			}
		}



	if (Driving)
	{
		if (!Application::IsKeyPressed('W'))
		{
			Acceleration -= 0.1;
			VelocityZ += Acceleration * dt;
			pos.x += (sin(Math::DegreeToRadian(SteeringAngle)) * VelocityZ);
			pos.y = pos.y;
			pos.z += (cos(Math::DegreeToRadian(SteeringAngle)) * VelocityZ);
			if (Acceleration < 0)
			{
				Acceleration = 0;
				VelocityZ -= 0.05;
				//driving = false;
			}
			if (VelocityZ < 0)
			{
				VelocityZ = 0;
				//Driving = false;
				//Backwards = false;
			}

		}
	}


	if (Application::IsKeyPressed('D'))
	{
		if (Driving == true)
		{
			SteeringAngle -= 3;
		}
		if (Backwards == true)
		{
			SteeringAngle += 3;
		}
		
	}


	if (Application::IsKeyPressed('A'))
	{
		if (Driving == true)
		{
			SteeringAngle += 3;
		}
		if (Backwards == true)
		{
			SteeringAngle -= 3;
		}
	}


	if (Application::IsKeyPressed('S'))
	{
		Acceleration -= 0.1;
		VelocityZ += Acceleration * dt;
		pos.x += (sin(Math::DegreeToRadian(SteeringAngle)) * VelocityZ);
		pos.y = pos.y;
		pos.z += (cos(Math::DegreeToRadian(SteeringAngle)) * VelocityZ);
		Backwards = true;
		Driving = false;
		Ability();
		if (Acceleration < -1)
		{
			Acceleration = -1;
		}

		if (VelocityZ < -1 && (PressQ || Nitro))
		{
			VelocityZ = -2;
		}
		else if (VelocityZ < -1 && (!PressQ || !Nitro))
		{
			VelocityZ = -1;
		}
	}

	if (Backwards)
	{
		if (!Application::IsKeyPressed('K'))
		{
			Acceleration += 0.1;
			VelocityZ += Acceleration * dt;
			pos.x += (sin(Math::DegreeToRadian(SteeringAngle)) * VelocityZ);
			pos.y = pos.y;
			pos.z += (cos(Math::DegreeToRadian(SteeringAngle)) * VelocityZ);

			if (Acceleration > 0)
			{
				Acceleration = 0;
				VelocityZ += 0.05;
			}
			if (VelocityZ > 0)
			{
				VelocityZ = 0;
				//Driving = false;
				//Backwards = false;
			}
		}
	}
}

void c_FirstCar::Ability()
{
	if (Application::IsKeyPressed('Q'))
	{
		if (Driving || Backwards)
		{
			PressQ = true;
		}
	}

	if (PressQ)
	{
		if (VelocityZ < 1)
		{
			PressQ = false;
		}
	}

}

void c_FirstCar::PowerUp(bool check)
{
	if (check)
	{
		Nitro = true;
	}

}