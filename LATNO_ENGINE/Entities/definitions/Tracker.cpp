#include "../declarations/Tracker.h"

//void Latno_Entities::Enemy::Chase(Scene &Scene, Latno_Entities::Actor ChaseActor)
//{
//    // Has useful psuedo code and explainations
//    // https://www.youtube.com/watch?v=-L-WgKMFuhE
//
//    currentScene->dynamicActors.clear();
//
//
//    Coords targetPos = ChaseActor.GetPos();
//    Node* currentNode = &nodeGrid[GetPos().y][GetPos().x];
//
//    Node* startingNode = currentNode;
//    Node* endNode = &nodeGrid[targetPos.y][targetPos.x];
//
//    std::vector<Node*> OpenList, ClosedList;
//
//    OpenList.push_back(startingNode);
//
//    while (true)
//    {
//        for (Node* i : OpenList)
//        {
//            currentScene->AddDynamicActor(Actor(i->pos.x, i->pos.y, "ASD"));
//        }
//        for (Node* i : ClosedList)
//        {
//            currentScene->AddDynamicActor(Actor(i->pos.x, i->pos.y, "ASD"));
//        }
//
//        Node* currentNode = startingNode;
//        // Set CurrentNode to node in open list with lowest FCost
//        int max = 0;
//        int low;
//        for (Node* i : OpenList)
//            max += i->fCost;
//        low = max;
//        for (Node* i : OpenList)
//            if (i->fCost < low)
//            {
//                low = i->fCost;
//                currentNode = i;
//            }
//        // remove currentNode from OpenList
//        for (int i = 0; i < OpenList.size(); i++)
//        {
//            if (OpenList[i] == currentNode)
//                OpenList.erase(OpenList.begin() + i);
//        }
//
//        ClosedList.push_back(currentNode);
//
//        //CHECKS IF ENDPOINT IS REACHED
//        if (currentNode == endNode)
//        {
//            DevLog::LOGLN("END POINT FOUND", "MainLog");
//            Node* nodeTrace = currentNode;
//            while (true)
//            {
//                if (nodeTrace->parentNode != nullptr)
//                    if (nodeTrace->parentNode != startingNode)
//                    {
//                        currentScene->AddDynamicActor(Actor(nodeTrace->pos, "path"));
//                        DevLog::LOGLN("(" + std::to_string(nodeTrace->pos.x) + ", " + std::to_string(nodeTrace->pos.y) + ")", "MainLog");
//                        nodeTrace = nodeTrace->parentNode;
//                    }
//                    else
//                    {
//                        SetPos(nodeTrace->pos);
//                        return;
//                    }
//            }
//            return;
//        }
//
//        // ADD NEIGHBORS
//        std::vector<Node*> neighbors;
//        int cY = currentNode->pos.y - 1, cX = currentNode->pos.x -1;
//        if((cY >= 0 && cY < currentScene->sizeY) && (cX >= 0 && cX < currentScene->sizeX))
//            neighbors.push_back(&nodeGrid[cY][cX]);
//        cY = currentNode->pos.y - 1; 
//        cX = currentNode->pos.x;
//        if ((cY >= 0 && cY < currentScene->sizeY) && (cX >= 0 && cX < currentScene->sizeX))
//            neighbors.push_back(&nodeGrid[cY][cX]);
//        cY = currentNode->pos.y - 1;
//        cX = currentNode->pos.x + 1;
//        if ((cY >= 0 && cY < currentScene->sizeY) && (cX >= 0 && cX < currentScene->sizeX))
//            neighbors.push_back(&nodeGrid[cY][cX]);
//        cY = currentNode->pos.y;
//        cX = currentNode->pos.x - 1;
//        if ((cY >= 0 && cY < currentScene->sizeY) && (cX >= 0 && cX < currentScene->sizeX))
//            neighbors.push_back(&nodeGrid[cY][cX]);
//        cY = currentNode->pos.y;
//        cX = currentNode->pos.x + 1;
//        if ((cY >= 0 && cY < currentScene->sizeY) && (cX >= 0 && cX < currentScene->sizeX))
//            neighbors.push_back(&nodeGrid[cY][cX]);
//        cY = currentNode->pos.y + 1;
//        cX = currentNode->pos.x - 1;
//        if ((cY >= 0 && cY < currentScene->sizeY) && (cX >= 0 && cX < currentScene->sizeX))
//            neighbors.push_back(&nodeGrid[cY][cX]);
//        cY = currentNode->pos.y + 1;
//        cX = currentNode->pos.x;
//        if ((cY >= 0 && cY < currentScene->sizeY) && (cX >= 0 && cX < currentScene->sizeX))
//            neighbors.push_back(&nodeGrid[cY][cX]);
//        cY = currentNode->pos.y + 1;
//        cX = currentNode->pos.x + 1;
//        if ((cY >= 0 && cY < currentScene->sizeY) && (cX >= 0 && cX < currentScene->sizeX))
//            neighbors.push_back(&nodeGrid[cY][cX]);
//
//        //For each neighbor
//        for (Node* neighbor : neighbors)
//        {
//            //skips neighbors in closed list
//            bool skip = false;
//            for(Node* i : ClosedList)
//                if (neighbor == i)
//                {
//                    skip = true;
//                    break;
//                }
//            //skips if neighbor is in a collidor
//            for (int index = 0; index < currentScene->rects.size(); index++)
//            {
//                if (currentScene->rects[index]->isCollider)
//                {
//                    if (currentScene->rects[index]->CheckCollisions(neighbor->pos))
//                    {
//                        skip = true;
//                    }
//                }
//            }
//
//            if (skip)
//                continue;
//
//            neighbor->gCost = neighbor->pos.FindDistance(GetPos()) * 10;
//            neighbor->hCost = neighbor->pos.FindDistance(targetPos) * 10;
//
//            // if new path to neighbor is shorter or neighbor is not in Open
//            bool isInOpen = false;
//            for (Node* i : OpenList)
//            {
//                if (neighbor == i)
//                    isInOpen = true;
//            }
//            if (neighbor->gCost < currentNode->gCost || !isInOpen)
//            {
//                neighbor->CalcFCost();
//                neighbor->parentNode = currentNode;
//                if (!isInOpen)
//                    OpenList.push_back(neighbor);
//            }
//
//        }
//            
//    }
//
//
//
//    // // Old stuffs
//
// //   //DevLog::LOGLN(std::to_string(ArrayOfBestPath[0][1].x),"MainLog");
//
// //   Coords targetPos = ChaseActor.position;
//
// //   // this->position;
//
// //   // get all eight boxes around chasingActor
// //   // calculate g and h value
//
// //   // g = Distance from starting node to chasing actor
// //   // h = Distance from starting node to target
// //   // f = g + h
// //   // in Coords, (g,h)
// //   // ArrayOfBestPath is the array of lowest f cost
//
// //   Coords BoxArray[8];
// //   Coords BestPath;
// //   
// //   // Array of nodes
// //   BoxArray[0] = targetPos.Add(-1, -1); // Top Left
// //   BoxArray[1] = targetPos.Add(0, -1); // Top Middle
// //   BoxArray[2] = targetPos.Add(1, -1); // Top Right
// //   BoxArray[3] = targetPos.Add(-1, 0); // Left
// //   BoxArray[4] = targetPos.Add(1, 0); // Right
// //   BoxArray[5] = targetPos.Add(-1, 1); // Bottom Left
// //   BoxArray[6] = targetPos.Add(0, 1); //Bottom Middle
// //   BoxArray[7] = targetPos.Add(1, 1); //Bottom Right
//
// //   for (int i = 0; i < 8; i++)
// //   {
// //       if (currentScene->CheckBounds(BoxArray[i]))
// //       {
// //       
// //           if (currentScene->rects.size() > 0)
// //           {
// //               for (int index = 0; index < currentScene->rects.size(); index++)
// //               {
// //                   if (currentScene->rects[index]->isCollider)
// //                   {
// //                       if (currentScene->rects[index]->CheckCollision(BoxArray[i]))
// //                       {
// //                           nodeValues[BoxArray[i].y][BoxArray[i].x].x = -1;
// //                           nodeValues[BoxArray[i].y][BoxArray[i].x].y = -1;
// //                       }
//
// //                   }
// //               }
// //           }
//
// //           if (nodeValues[BoxArray[i].y][BoxArray[i].x].y != -1 || nodeValues[BoxArray[i].y][BoxArray[i].x].x != -1)
// //           {
//
// //               float distanceToTarget = sqrt(pow((BoxArray[i].y - targetPos.y), 2) + pow((BoxArray[i].x - targetPos.x), 2));
//
// //               DevLog::LOGLN("DistanceToTarget: " + std::to_string(distanceToTarget), "MainLog");
//
// //               nodeValues[BoxArray[i].y][BoxArray[i].x].y = distanceToTarget;
//
//
// //               float distanceToEnemy = sqrt(pow((BoxArray[i].x - position.x), 2) + pow((BoxArray[i].x - position.x), 2)); //here
// //               DevLog::LOGLN("DistanceToEnemy: " + std::to_string(distanceToEnemy), "MainLog");
//
// //               nodeValues[BoxArray[i].y][BoxArray[i].x].x = distanceToEnemy;
// //           }
// //       }
//
// //   }
// //   int highestF = currentScene->sizeY * currentScene->sizeX;
//	//int lowestF = highestF;
//	//for (int i = 0; i < 8; i++){
// //       if (currentScene->CheckBounds(BoxArray[i]))
// //       {
// //           if (nodeValues[BoxArray[i].y][BoxArray[i].x].x > 0 && nodeValues[BoxArray[i].y][BoxArray[i].x].y > 0) {
// //               int f = BoxArray[i].x + BoxArray[i].y;
// //               DevLog::LOGLN(std::to_string(f),"MainLog");
// //               if (f < lowestF) {
// //                   lowestF = f;
// //                   BestPath = { BoxArray[i].x, BoxArray[i].y };
// //               }
// //           }
// //       }
// //   }
//	////DevLog::LOGLN("BPX: " + std::to_string(BestPath.x), "MainLog");
// ////   DevLog::LOGLN("BPY: " + std::to_string(BestPath.y),"MainLog");
//	////DevLog::LOGLN("TPX: " + std::to_string(targetPos.x), "MainLog");
//	////DevLog::LOGLN("TPY: " + std::to_string(targetPos.y), "MainLog");
// //   if(BestPath.x == targetPos.x && BestPath.y < targetPos.y)// UP
// //   {
// //       this->direction = UP;
// //       this->MoveForward(*currentScene);
// //   }else if (BestPath.x == targetPos.x && BestPath.y > targetPos.y) //Down
// //   {
//	//	this->direction = DOWN;
//	//	this->MoveForward(*currentScene);
// //   } 
//	//else if (BestPath.x < targetPos.x && BestPath.y == targetPos.y) // Left
// //   {
// //       this->direction = LEFT;
//	//	this->MoveForward(*currentScene);
// //   }else if (BestPath.x > targetPos.x && BestPath.y == targetPos.y) //Right
// //   {
//	//	this->direction = RIGHT;
//	//	this->MoveForward(*currentScene);
// //   }else if (BestPath.x < targetPos.x && BestPath.y < targetPos.y) //Top Left
// //   {
//	//	this->direction = UP;
//	//	this->MoveForward(*currentScene);
// //       this->direction = LEFT;
//	//	this->MoveForward(*currentScene);
//
// //   }else if (BestPath.x > targetPos.x && BestPath.y < targetPos.y) // Top Right
// //   {
// //       this->direction = UP;
//	//	this->MoveForward(*currentScene);
// //       this->direction = RIGHT;
//	//	this->MoveForward(*currentScene);
// //   }else if (BestPath.x < targetPos.x && BestPath.y > targetPos.y) // Bottom Left
// //   {
//	//	this->direction = DOWN;
//	//	this->MoveForward(*currentScene);
//	//	this->direction = LEFT;
//	//	this->MoveForward(*currentScene);
// //   }else if (BestPath.x > targetPos.x && BestPath.y > targetPos.y) // Bottom Right
// //   {
// //       this->direction = DOWN;
//	//	this->MoveForward(*currentScene);
// //       this->direction = RIGHT;
//	//	this->MoveForward(*currentScene);
// //   }
//    
//    
//
//
//    
//    
//    
//    
//    /*
//    if(moveChance[0] < rand() % moveChance[1] + 1)
//    {
//        preData = targetPos;
//        distanceX = abs(targetPos.x - ChaseActor.targetPos.x);
//        distanceY = abs(targetPos.y - ChaseActor.targetPos.y);
//        trueDistanceX = targetPos.x - ChaseActor.targetPos.x;
//        trueDistanceY = targetPos.y - ChaseActor.targetPos.y;
//        totalDistance = abs(targetPos.y) + abs(targetPos.x);
//
//        // Set Blocked Values
//        isBlocked[0] = Scene.RectCollision({targetPos.x,targetPos.y - 1});
//        isBlocked[1] = Scene.RectCollision({targetPos.x,targetPos.y + 1});
//        isBlocked[2] = Scene.RectCollision({targetPos.x - 1,targetPos.y});
//        isBlocked[3] = Scene.RectCollision({targetPos.x + 1,targetPos.y});
//
//        // Normal Movement
//        if(distanceY >= distanceX)
//        {
//            if(ChaseActor.targetPos.y < targetPos.y && targetPos.y > 0)
//            {
//                direction = UP;
//                MoveFoward(Scene);
//            }
//            else if(ChaseActor.targetPos.y > targetPos.y && targetPos.y < Scene.GetSize().y - 1)
//            {
//                direction = DOWN;
//                MoveFoward(Scene);
//            }
//        }
//        else
//        {
//            if(ChaseActor.targetPos.x < targetPos.x && targetPos.x > 0)
//            {
//                direction = LEFT;
//                MoveFoward(Scene);
//            }
//            else if(ChaseActor.targetPos.x > targetPos.x && targetPos.x < Scene.GetSize().x - 1)
//            {
//                direction = RIGHT;
//                MoveFoward(Scene);
//            }
//        }
//        
//        
//        // Obstacle avoidance movement
//        if(Scene.RectCollision(*this))
//        {
//            SendBack();
//            if((isBlocked[3] == true || isBlocked[2] == true) && (direction.IsEqual(RIGHT) || direction.IsEqual(LEFT)))
//            {
//                if(trueDistanceY > 0)
//                    direction = UP;
//                else if(trueDistanceY < 0)
//                    direction = DOWN;
//                else
//                {
//                    if(direction.IsEqual(RIGHT))
//                    {
//                        if(!Scene.RectCollision({targetPos.x + 1, targetPos.y - 1}))
//                            direction = UP;
//                        else if(!Scene.RectCollision(targetPos.Add(1,1)))
//                            direction = DOWN;
//                    }
//                    else if(direction.IsEqual(LEFT))
//                    {
//                        if(!Scene.RectCollision({targetPos.x - 1, targetPos.y - 1}))
//                            direction = UP;
//                        else if(!Scene.RectCollision({targetPos.x - 1, targetPos.y + 1}))
//                            direction = DOWN;
//                    }
//                }
//            }
//            else if((isBlocked[0] == true || isBlocked[1] == true) && (direction.IsEqual(DOWN) || direction.IsEqual(UP)))
//            {
//                if(trueDistanceX > 0)
//                    direction = LEFT;
//                else if(trueDistanceX < 0)
//                    direction = RIGHT;
//                else
//                {
//                    if(direction.IsEqual(DOWN))
//                    {
//                        if(!Scene.RectCollision({targetPos.x - 1,targetPos.y + 1}))
//                            direction = LEFT;
//                        else if(!Scene.RectCollision({targetPos.x + 1,targetPos.y + 1}))
//                            direction = RIGHT;
//                    }
//                    else if(direction.IsEqual(UP))
//                    {
//                        if(!Scene.RectCollision({targetPos.x - 1,targetPos.y - 1}))
//                            direction = LEFT;
//                        else if(!Scene.RectCollision({targetPos.x + 1,targetPos.y - 1}))
//                            direction = RIGHT;
//                    }
//                }
//            }
//            MoveFoward(Scene);
//            if(Scene.RectCollision(*this))
//                SendBack();
//        }
//    }
//    */
//}