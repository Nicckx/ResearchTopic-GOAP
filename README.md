# ResearchTopic-GOAP

## What is GOAP?
GOAP (Goal Oriented Action Planning) is an AI system for agents that allows them to plan a sequence of actions at runtime to satisfy a certain goal.
The sequence of actions depends on the current world state and the state of the agent. This would mean applying the same goals onto different agents can get different sequence of actions.

## Example
We have an agent a lumberjack that takes logs and builds a shelter with it. The lumberjack can be supplied with the goal (desiredState) `BuildShelter` and has actions like `ChopLogs`, `GetAxe` and `CollectBranches`. The `ChopLogs` action is going to give the lumberjack logs. The `GetAxe` action gives him an axe. The `CollectBranches` action is going to make a shelter aswell but it wont require the lumberjack to have an axe. Be aware that this would result in a smaller shelter with poor quality.

If the agents has the `BuildShelter` goal than in this case we will get two different plans (action sequences):
* `GetAxe` --> `ChopLog` --> `BuildShelter`
* `CollectBranches` --> `BuildShelter`

Both of these plans will result in fullfilling the goal (desiredState).
If the lumberjack can get an axe he can chop logs to build a shelter. But if he doesn't find an axe he has to pick up branches.

## Why GOAP?
When dealing with FSM (Finit State Machines) or BT (Behaviour Trees) you usually need to think about all possibilities beforehand. Goap on the other hand calculates states in runtime considering the current world state. It decouples the action from each other so you can focus on each action individually. In case you want to add another action you can easily insert it while no other actions have to be changed.

## Aditional info
In GOAP you usually find `Agents`, `Goals`, `Actions` and `Planners`.
Agents usually have a set of goals e.g (run, attack, ...). They ask their planner for a list of actions to satisfy their highest priority goals.
Goals have desired world states e.g (build a shelter). The planner needs to find an action that satisfies this state.
Actions have an effect and a precondition. The precondition has to be met in order to perform the action. The effects describes how the action affects the state of the world.

## Own Implementation

![MyImplementation](https://github.com/Nicckx/ResearchTopic-GOAP/blob/main/GOAP.gif)

All the code was implemented using `C++`.
Created a set a actions e.g (ChopTree, GetAxe, GoToSafePlace, ...)
Created a set goals e.g (MakeFirePit, GoSleep ...)
Depending on the highest priority goal it creates a plan to satisfy the goal (desiredWorldState)
In case we get a new goal --> it creates a new plan which satisfy this goal now.
Priority of goals can be changed via keyinputs.
Console prints out the plan (set of actions) which is currently beeing used.
The game window visualizes the world and player state. Also visualized the returned plan.

## Future Work
Next step would be to apply the logic to an actual agent that runs in a dynamic world.

## Links

#### Goal Oriented Action Planning
-- GOAP - https://gamedevelopment.tutsplus.com/tutorials/goal-oriented-action-planning-for-a-smarter-ai--cms-20793
-- GOAP - https://www.youtube.com/watch?v=LhnlNKWh7oc
