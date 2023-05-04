# 151Final Project -- Battleship Graphics Game
### Ben Givens, Dominic Acia, Lacey Hunt

## Major Contributions
* **BEN:** sound class, intro screen class, instructions screen
* **DOMINIC:** graphical design, animation, game loop integration, player interface
* **LACEY:** screen class, main game loop and logic outline


## How to Compile and Run

> *HEADS UP:* This game contains music and sound effects. If you want to enjoy those elements, make sure your volume is up and you are connected to a speaker.

### 1. Clone repository
````bash
$ git clone https://github.com/BeDoLaFinal/151Final.git Battle
````
### 2. Enter directory
````bash
$ cd Battle
````
### 3. Compile
````bash
$ g++ *.cpp -o Battleship -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
````
### 4. Run executable
````bash
$ ./Battleship
````


## How to Play

When you run the program, you will encounter a play screen. Select `RULES` to view instructions, or `PLAY` to begin the game.
<img width="650" alt="Screenshot 2023-05-02 173318" src="https://user-images.githubusercontent.com/112370638/235813077-b988b7d3-eaec-4a21-8d24-dcf05174d263.png">

### Instructions Page
If you click the `RULES` button, you will be shown the following game instructions:

<img width="650" alt="Screenshot 2023-05-03 214235" src="https://user-images.githubusercontent.com/112370638/236114238-05c595ff-2bef-4d29-a292-e0ce6227d684.png">


### Game Play
- When you click `PLAY`, you will see your five ships placed on the right board. You will be aiming to hit your opponent ships by selecting locations to shoot on the left board.
<img width="650" alt="Screenshot 2023-05-02 171501" src="https://user-images.githubusercontent.com/112370638/235811400-b6c075b0-91a4-4966-a4db-d7e0080a6235.png">

- On your turn, select a location to shoot. If it is a hit, you will see <img width="20" alt="Screenshot 2023-05-02 172455" src="https://user-images.githubusercontent.com/112370638/235812345-e013a0c4-ee15-4bb6-9f85-a9c424fd350b.png"> and hear an explosion. If it is a miss, you will see <img width="20" alt="Screenshot 2023-05-02 172419" src="https://user-images.githubusercontent.com/112370638/235812409-0278f041-76fa-451a-846c-af4e5b183b0b.png">  and hear a splash.

- After you take a turn, your enemy (the computer) will select a location to shoot. Your board on the right will update with the correct icon indicating a hit or miss, and you will either hear the explosion of your ship or a splash of relief.

- If at any time you choose to exit the game, you may do so by selecting the <img width="50" alt="Screenshot 2023-05-02 173600" src="https://user-images.githubusercontent.com/112370638/235813382-381ed00f-c89c-4a16-b2cc-b92e247efdca.png"> icon at the bottom left hand corner of your screen.

- The game is over when one player manages to sink all five of their enemy ships. You will be notified when the game is over, and one of the following screens will indicate the status of your fleet:

<img width="350" alt="Screenshot 2023-05-02 172956" src="https://user-images.githubusercontent.com/112370638/235812825-ca6fb721-30ca-4b3a-9f5f-838dedf91dfc.png"> <img width="350" alt="Screenshot 2023-05-02 173023" src="https://user-images.githubusercontent.com/112370638/235812831-71f81b9b-537f-4373-870f-362fc7e2bbf7.png">


## Back End Insight
### Project Architecture Flowchart

<img width="650" src="https://user-images.githubusercontent.com/112370638/236115722-f65cd741-5c37-4ed6-ab9e-9657b203e5f6.png">

### Future Modification Ideas
* **Make the main more readable:** organize the main code better by following a more general 'create, draw, display' flow rather than breaking the game up into multiple loops that made it hard to follow. We also could have better utilized classes to streamline object creation, which would greatly simplify and shorten the main code.
* **Add a manual placement option:** allow the user to manually place their ships. We did try to implement this function, but ran into many issues that were difficult to resolve without completely restarting the project architecture.
* **Make the opponent smart:** add functions that allow the computer to build off its previous moves. If it hits a ship, it should guess around that spot until the ship is sunk and then go back to random guesses. We could even go further by making the random guesses more strategic, based on the patterns in the placement of ships in previous games.
