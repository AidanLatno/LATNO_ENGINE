// LATNO_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "engine/declarations/Engine.h"
#include "exceptions/declarations/RuntimeException.h"

int main() {
    // bool running = true;
    // while(running) 
    // {
    //     try 
    //     {
    //         //tick
    //         running = false;
    //     }
    //     catch (RuntimeException e) 
    //     {
    //         running = false;
    //         //print error 
    //     }        
    // }

    Scene MainScene(10, 10);
    Player MainPlayer(2, 2, 'p', "PLAYER");
    MainScene.AddActor(MainPlayer);

    while (true)
    {
        MainScene.Update();
        MainScene.Render(true);

        MainPlayer.Move(MainScene);
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
