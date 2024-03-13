Qt based Simon game

CS3505
03/13/2024

Implemented by Vasil Vassilev and Ethan Andrews

During this weeks project we implemented a QT based Simon game. The premise of the game is that the user is shown a continually growing sequence of buttons that they must click in sequence. As the sequence gets longer, the speed at which it is demonstrated also increases, making it harder to remmember and keep track of. If the user clicks a button out of sequence then the game freezes the buttons and displays a game over visual, along with a restart button to allow the user to play again. As a special feature we added radio buttons to the top left side of the screen which allow the user to change the color scheme of the game buttons. 

The game is built using a Model-View architechture, combining the controller and view into one to avoid an overly complex class structure for a relatively simple game.

Interactions and button timing is organized and maintained by using the QTimer class and firing one shot signals, and sometimes using lambda functions for more complex tasks. 


Day 1 (03/11/2024):
We installed the qt enviorment (which took a little over 2 hours), and got started with farmiliarizing ourseves with the features of the IDE. We laid out the basic setup of two game buttons and a start button. 

The first task we started with was making the computer show a sequence to the user, this was going well until we encountered an issue with the IDE, this was eventaully solved by cleaning and rebuilding the project. Solving this issue allowed us to continue implementing the computer demo part of the simon game. 

Day 2 (03/12/2024):
We worked for a short period of time today due to Vasil's class schedule. And progressed in showing the computer sequence to the user.

Day 3 (03/13/2024):
We did the majority of the work for the project. Many issues with timing, turning buttons off and on, as well as adding radio buttons to change the themes held us back, but eventually we got the game working. This is also when we got the start button to change text, the progress bar to start working, and for the game over visual to show up. 
