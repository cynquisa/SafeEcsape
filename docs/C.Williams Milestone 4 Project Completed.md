
## 🔍 Current Progress Check  

This week I focused mainly on refreshing the ASCII art and adding color to the game. I had to take a few days fixing errors I created by changing by adding color with the helper function. While changing code I removed a few lines of code and the game was working but not performing the right task. I find that some bugs are hard to spot if the game still compiles. I also have learned to test every feature of the game any time you make a change. Sometime what you adding will work fine but may alter another part of the game.







- Features completed or added.
I added a Pause screen helper to make sure the menu options are actually performed and not skipped and to keep from rewriting code. I was able to add file I/O to record the player stats and record an all-time high score. File I/O was very confusing for me because the way we created our games by keeping it clean, I had to figure out which source and header files would own high scores. I did not realize that because I created a displayhighscores that the files would conflict with each other because they were similarly named and I made errors by using the swapping the names in the functions.


    
- Refactoring and code improvements.

When I added file i/o, I had to update recordResults function to save-to-file (player.text) , added ofstream historyFile and  to create\save player history.txt. I had to add to fuctions for file i\o in player.h (1. void saveToFile, 2. loadFromFile) to handle saving for my all-time high scores. I updated most of the art to make it more enjoyable and less blank space.



- Bugs resolved.
I created two bugs this week one by removing code that i need and the second happed when I added file i/o. When I added file i/o the program stopped requiring a person to create the player before playing the game and it did not record. The reason for the player being able to just play was I added a player constructor before the game loop and I did not need at all.




- Usability improvements.
This week I had to update my input validation because the program was still allowing a player to type letters when GetNumber was validating the input. I need to add a check for the processed ch- 