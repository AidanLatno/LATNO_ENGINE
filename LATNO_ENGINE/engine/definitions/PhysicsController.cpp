#include "../declarations/PhysicsController.h"

namespace Latno
{
	void PhysicsController::ApplyGravity(Coords centerPoint, float pullForce)
	{
		 float xValue = centerPoint.x - actorRef->GetPos().x;
		 float yValue = centerPoint.y - actorRef->GetPos().y;
		 float slope = yValue / xValue;
		 float bValue = -((slope * xValue) - yValue);
		

		 if (mass == 0)
			 mass = 1;

		 if (actorRef->GetPos().x > centerPoint.x)
			 actorRef->SetPos(Coords(actorRef->GetPos().x - (pullForce/mass), slope * actorRef->GetPos().x + bValue));
		 else if (actorRef->GetPos().x < centerPoint.x)
			 actorRef->SetPos(Coords(actorRef->GetPos().x + (pullForce / mass), slope * actorRef->GetPos().x + bValue));
		 else if (actorRef->GetPos().x == centerPoint.x)
		 {
			 if (actorRef->GetPos().y > centerPoint.y)
				 actorRef->SetPos(Coords(actorRef->GetPos().x, actorRef->GetPos().y - (pullForce / mass)));
			 else if (actorRef->GetPos().y < centerPoint.y)
				 actorRef->SetPos(Coords(actorRef->GetPos().x, actorRef->GetPos().y + (pullForce / mass)));
		 }

			
	}

	void PhysicsController::ApplyFloorGravity(float pullForce)
	{
		if (mass == 0)	mass = 1;
		actorRef->SetPos(Coords(actorRef->GetPos().x, actorRef->GetPos().y - (pullForce / mass)));
	}

	void PhysicsController::ApplyForce(Coords centerPoint, float pullForce)
	{
		float xValue = centerPoint.x - actorRef->GetPos().x;
		float yValue = centerPoint.y - actorRef->GetPos().y;
		float slope = yValue / xValue;
		float bValue = -((slope * xValue) - yValue);


		if (mass == 0)
			mass = 1;

		if (actorRef->GetPos().x > centerPoint.x)
			actorRef->SetPos(Coords(actorRef->GetPos().x + (pullForce / mass), slope * actorRef->GetPos().x + bValue));
		else if (actorRef->GetPos().x < centerPoint.x)
			actorRef->SetPos(Coords(actorRef->GetPos().x - (pullForce / mass), slope * actorRef->GetPos().x + bValue));
		else if (actorRef->GetPos().x == centerPoint.x)
		{
			if (actorRef->GetPos().y > centerPoint.y)
				actorRef->SetPos(Coords(actorRef->GetPos().x, actorRef->GetPos().y + (pullForce / mass)));
			else if (actorRef->GetPos().y < centerPoint.y)
				actorRef->SetPos(Coords(actorRef->GetPos().x, actorRef->GetPos().y - (pullForce / mass)));
		}


	}

}