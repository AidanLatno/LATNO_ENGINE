#include "../declarations/Patroller.h"

// Manual constructor because im dumb, Call when you create obj
//FwrdDist, OutDist, GrowFwrd, GrowOut, AlrtDist
//void Latno_Entities::Patroller::Construct(int _FowardDistance,int _OutDistance,int _GrowFoward,int _GrowOut,int _AlertDistance)
//{
//    FowardDistance = _FowardDistance;
//    OutDistance = _OutDistance;
//    GrowFoward = _GrowFoward;
//    GrowOut = _GrowOut;
//    AlertDistance = _AlertDistance;
//    Los = new LOS(position,direction,FowardDistance,OutDistance);
//}
//
//void Latno_Entities::Patroller::Move(Latno_Entities::Actor actor,Scene &Scene)
//{
//    Los->StartPos = position;
//    Los->Direction = direction;
//    Los->RecalcPoints();
//    if(Los->CheckCollision(actor) || IsNearby(actor,1))
//    {
//        AlertIterator = AlertDistance;
//        Alert = true;
//        Chase(Scene, actor);
//    }
//    else if(Alert)
//    {
//        Chase(Scene, actor);
//        AlertIterator--;
//        if(AlertIterator <= 0)
//        {
//            Alert = false;
//            direction = DOWN;
//        }
//    }
//}