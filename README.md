# ResearchTopic-GOAP

GOAP (Goal Oriented Action Planning) is an AI system for agents that allows them to plan a sequence of actions at runtime.
In GOAP you usually find Agents, Goals, Actions and Planners.
Agents usually have a set of goals e.g (run, attack, ...). They ask their planner for a list of actions to satisfy their highest priority goals.
Goals have desired world states(e.g build a shelter). The planner needs to find an action that satisfies this state.
Actions have an effect and a precondition. The precondition has to be met in order to perform the action. The effects describes how the action affects the state of the world.

My own Implementation:

First Idea would be to implement an GOAP-System in the 'Zombie Game Project' and let the player agent use it to survive as long as possible / getting a high score.

Second Idea would be to make an own project with an GOAP-System where a player agent is in a certain environment where the agents needs to satisfy goals to survive for a certain period of time. For example (dinking, eating, building shelter, building fireplace, sleeping, running away, killing ... ).
