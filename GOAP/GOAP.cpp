// GOAP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

struct Action
{
    std::string name;
    std::pair<std::string, bool> precondition;
    std::pair<std::string, bool> effect;
    float cost;
};

struct State
{
    std::vector<std::pair<std::string, bool>> conditions;
};

std::vector<Action> PlanMakeFireWood()
{
    Action actionGetAxe;
    actionGetAxe.name = "GetAxe";
    actionGetAxe.precondition.first = "IsExhausted";
    actionGetAxe.precondition.second = false;
    actionGetAxe.effect.first = "HasAxe";
    actionGetAxe.effect.second = true;
    actionGetAxe.cost = 2.f;

    Action actionChopTree;
    actionChopTree.name = "ChopTree";
    actionChopTree.precondition.first = "HasAxe";
    actionChopTree.precondition.second = true;
    actionChopTree.effect.first = "HasWood";
    actionChopTree.effect.second = true;
    actionChopTree.cost = 4.f;

    Action actionCollectBranches;
    actionCollectBranches.name = "CollectBranches";
    actionCollectBranches.precondition.first = "None";
    actionCollectBranches.precondition.second = true;
    actionCollectBranches.effect.first = "HasWood";
    actionCollectBranches.effect.second = true;
    actionCollectBranches.cost = 8.f;

    std::vector<Action> availableActions;
    availableActions.push_back(actionGetAxe);
    availableActions.push_back(actionChopTree);

    return availableActions;
}

int main()
{
    State availableStates;
    availableStates.conditions.push_back({ "None", true });
    availableStates.conditions.push_back({ "HasAxe", false });
    availableStates.conditions.push_back({ "IsExhausted", false });

    std::pair<std::string, bool> currentState{ "HasAxe", false };


    std::vector<Action> makeFireWood = PlanMakeFireWood();

    for(auto& m : makeFireWood)
    {
        if(m.name == "ChopTree")
        {
            if(m.precondition.second == currentState.second)
            {
                std::cout << "YES";
            }
            else
            {
                std::cout << "Cannot use it now, try another action";
            }
        }
    }

    std::cin.get();
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
