# Team Contract

## Communication
1. **Team Meetings** 

    Team meeting will take place twice a week (usually on Friday and Saturday). Meetings will be hybrid - most will be done through discord's group call feature and we will decide on the possibility and location of in-person meetings at the start of each week. A meeting log of the approximate time of the meetings will be recorded, alongside some notes detailing the most important parts of the meeting.

2. **Assistance** 

    Team members are able to contact each other using discord, text, and phone calls. The majority of the discussion will happen on discord, where teammates can expect an answer within 8 hours of the message if sent within reasonable hours. Phone calls and texts will be utilized if the pending decision or question if urgent.

3. **Respect** 

    We will plan on a shared google document, letting us share ideas without the restictions such as one person leading (or dominating) the discussion. Some matters will be put through a majority vote before a final decision is made and the most important matters will be put through a unanimous vote before progress is made.

## Collaboration

4. **Work Distribution** 
    
    The project will be divided into multiple mini-projects. In most situations, each group member will be working on a different mini-project but constult each other before major decisions are made. Multiple members maybe working on the same mini-project at the same time (such as one person psudo-coding and the other implementing) if the given mini-project is large by volume or significance. The group will later work together to assemble each mini-project back into its entirety.

5. **Time Commitment**

    Each member is expected to put in 3 to 5 hours of each week, outside of group meetings. In the case a member is unable to complete this expectation in the upcoming week, the member is expected to notify the group during the weekly meeting. This will allow the group to adjust to the new workload. In the case a member is unable to notify the group during the meeting or repeatedly unable to complete the minimum work, they will be expected to put in extra hours at a later stage in the project.

6. **Conflict Resolution** 
    
    We will try to set internal due dates to be earlier than the actual due dates as a means to prevent the habitually-late memebers from significantly holding back progess and ease the process of workload redistribution if needed. If more than one member constantly fails to complete the thier portion of work, we will seek to hold more "work meetings" - dedicated times to meet and just work on the project -  outside of our regular meeting times so that we can ensure that everyone is making progress and help is given when needed.

## Signatures
Atharva Jain (atharva7), Jongwon Park (jwp6), Eric Park (jp43), Rahim Masood Khan (rahimmk2)

## Leading Question 
Sui is a nascent blockchain with an innovative, Directed Acyclic Graph (DAG) foundation. Due to its young age and immature structure, no tools exist to support the exploration of activities and connectivities on this blockchain. No existing blockchain tools can be extended to Sui either, as it implements a graph. This creates a problem in that users are deterred from use of Sui as the internal processes are unclear. In this project, we seek to create a general search tool for Sui. This will allow users to better understand and explore this blockchain solving the problem mentioned above. We also seek to expand our own understanding of the inner workings of blockchain throughout this project.
## Dataset Acquisition

## Data Format
As a blockchain, Sui is entirely public and free to download. Running a full Sui node will provide us with the entire dataset of Sui, which contains transactions, checkpoints, and epoch changes (blockchain state and history). With the blockchain in our possession, we can follow the instructions and specs documented by Sui to get the entire DAG or a portion of it. For the sake of this project, we plan to use a subset of the dataset - the entire blockchain would be too immense. We can arbitrarily choose any range of epochs (block numbers) and download all data in between the epochs to show that the algorithms we implement can be applied to any subset of Sui.

## Data Correction
The beauty of blockchain is that ALL data settled/finalized into the blockchain are decentrally verified by all participating validators (who are financially incentivized). Thus, no error-free values exist and all values downloaded are verified to be valid—this is the nature of blockchain technology. For local verification, we can execute a topological sorting/ordering of the collected data to verify that it’s a valid DAG (especially for a subset of the entire Sui DAG).

## Data Storage
When storing the data, we will simply use a relational database that maintains DAG relations. When loading the data onto the script, we will reconstruct the DAG from the relational database stored locally. Storing the data will take O(n) storage as we simply traverse and save all available transactions from Sui, without overlapping. Loading the data will take O(|V| + |E|) as it’s a DAG.

## Algorithm 
To analyze the Sui blockchain and present it in a way that's more understandable to the general public, these are the following algorithms we are going to implement.

DFS

This traversal will allow us to figure out all possible paths that can be taken for the completion of a transaction. The estimate of the worst case runtime of the traversal is O(n).

Dijkstra’s Algorithm

This algorithm will take a start node and end node from the DAG and find the shortest path between two nodes. This shows the user the shortest path from the original state to the end state (path independent), allowing users to better understand what’s happening. The time complexity is O(E logV), where E is the total number of edges and V is the number of vertices. Or, equivalently, O(N logN).

Graphic Output of Graph

This algorithm will take the DAG and create a graphical representation of it. This will allow users to visualize the transactions and support their understanding of Sui. Similar to Dijkstra’s, the time complexity is O(E logV).


## Timeline
The following timeline is a general plan on when we want to have the listed task done. In the case each task is completed before the given week, we will start working on the tasks planned for the following week. If the timeline includes a algorithm we need to implent, local test cases will be written and run on the same week.

Data Acquisition & processing: week ending 11/12

DFS & Dijkstra’s Algorithm : week ending 11/19

Week off: week ending 11/26

Graphic Output of Graph: week ending 12/3

Written report and final presentation: 12/8

