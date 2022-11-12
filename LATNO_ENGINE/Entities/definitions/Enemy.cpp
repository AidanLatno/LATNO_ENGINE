#include "../declarations/Enemy.h"

void Latno::Behavior::Update() {
    // Latno_Entities::Enemy::Chase(MainSce);
}


void Latno_Entities::Enemy::Chase(Scene &Scene, Latno_Entities::Actor ChaseActor)
{
    if(moveChance[0] < rand() % moveChance[1] + 1)
    {
        preData = position;
        distanceX = abs(position.x - ChaseActor.position.x);
        distanceY = abs(position.y - ChaseActor.position.y);
        trueDistanceX = position.x - ChaseActor.position.x;
        trueDistanceY = position.y - ChaseActor.position.y;
        totalDistance = abs(position.y) + abs(position.x);

        // Set Blocked Valuesa
        isBlocked[0] = Scene.RectCollision({position.x,position.y - 1});
        isBlocked[1] = Scene.RectCollision({position.x,position.y + 1});
        isBlocked[2] = Scene.RectCollision({position.x - 1,position.y});
        isBlocked[3] = Scene.RectCollision({position.x + 1,position.y});

        // Normal Movement
        if(distanceY >= distanceX)
        {
            if(ChaseActor.position.y < position.y && position.y > 0)
            {
                direction = UP;
                MoveFoward(Scene);
            }
            else if(ChaseActor.position.y > position.y && position.y < Scene.GetSize().y - 1)
            {
                direction = DOWN;
                MoveFoward(Scene);
            }
        }
        else
        {
            if(ChaseActor.position.x < position.x && position.x > 0)
            {
                direction = LEFT;
                MoveFoward(Scene);
            }
            else if(ChaseActor.position.x > position.x && position.x < Scene.GetSize().x - 1)
            {
                direction = RIGHT;
                MoveFoward(Scene);
            }
        }
        
        
        // Obstacle avoidance movement
        if(Scene.RectCollision(*this))
        {
            SendBack();
            if((isBlocked[3] == true || isBlocked[2] == true) && (direction.IsEqual(RIGHT) || direction.IsEqual(LEFT)))
            {
                if(trueDistanceY > 0)
                    direction = UP;
                else if(trueDistanceY < 0)
                    direction = DOWN;
                else
                {
                    if(direction.IsEqual(RIGHT))
                    {
                        if(!Scene.RectCollision({position.x + 1, position.y - 1}))
                            direction = UP;
                        else if(!Scene.RectCollision(position.Add(1,1)))
                            direction = DOWN;
                    }
                    else if(direction.IsEqual(LEFT))
                    {
                        if(!Scene.RectCollision({position.x - 1, position.y - 1}))
                            direction = UP;
                        else if(!Scene.RectCollision({position.x - 1, position.y + 1}))
                            direction = DOWN;
                    }
                }
            }
            else if((isBlocked[0] == true || isBlocked[1] == true) && (direction.IsEqual(DOWN) || direction.IsEqual(UP)))
            {
                if(trueDistanceX > 0)
                    direction = LEFT;
                else if(trueDistanceX < 0)
                    direction = RIGHT;
                else
                {
                    if(direction.IsEqual(DOWN))
                    {
                        if(!Scene.RectCollision({position.x - 1,position.y + 1}))
                            direction = LEFT;
                        else if(!Scene.RectCollision({position.x + 1,position.y + 1}))
                            direction = RIGHT;
                    }
                    else if(direction.IsEqual(UP))
                    {
                        if(!Scene.RectCollision({position.x - 1,position.y - 1}))
                            direction = LEFT;
                        else if(!Scene.RectCollision({position.x + 1,position.y - 1}))
                            direction = RIGHT;
                    }
                }
            }
            MoveFoward(Scene);
            if(Scene.RectCollision(*this))
                SendBack();
        }
    }
}