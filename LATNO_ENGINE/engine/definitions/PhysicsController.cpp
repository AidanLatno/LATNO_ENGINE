#include "../declarations/PhysicsController.h"
namespace Latno
{
	void PhysicsController::ApplyGravity(Coords centerPoint, float pullForce = 1)
	{
		 xValue = centerPoint.x - actorRef->GetPos().x;
		 yValue = centerPoint.y - actorRef->GetPos().y;
		 slope = yValue / xValue;
		 bValue = -((slope * xValue) - yValue);

		 if (mass == 0)
			 mass = 1;

		 if (actorRef->GetPos().x > centerPoint.x)
			 actorRef->SetPos(Coords(actorRef->GetPos().x - (pullForce/mass), CalcYValue(actorRef->GetPos().x)));
		 else if (actorRef->GetPos().x < centerPoint.x)
			 actorRef->SetPos(Coords(actorRef->GetPos().x + (pullForce / mass), CalcYValue(actorRef->GetPos().x)));
		 else if (actorRef->GetPos().x < centerPoint.x)
		 {
			 if (actorRef->GetPos().y > centerPoint.y)
				 actorRef->SetPos(Coords(actorRef->GetPos().x, actorRef->GetPos().y - (pullForce / mass)));
			 else if (actorRef->GetPos().y < centerPoint.y)
				 actorRef->SetPos(Coords(actorRef->GetPos().x, actorRef->GetPos().y + (pullForce / mass)));
		 }

			
	}

	float PhysicsController::CalcYValue(float xPoint)
	{
		return slope * xPoint + bValue;
	}
}