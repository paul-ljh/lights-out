# Lights-Out
The Classic Lights Out game (run in linux shell)

Using C++ classes to implement the game of Lights Out. (http://en.wikipedia.org/wiki/Lights Out %28game%29)

When you run your program, it will listen on stdin for commands. Your program must accept the following commands:
• new n:
   Creates a new n × n grid, where n ≥ 1. If there was already an active grid, that grid is destroyed and replaced with the new one.
• init x y:
   Enters initialization mode. Subsequently, read pairs of integers x y and set the cell at row x, column y as on. 
   The top-left corner is row 0, column 0. 
   The coordinates -1 -1 end initialization mode. 
   You can enter initialization mode more than once, and even while the game is running. 
   When initialization mode ends, the board will be displayed.
• game g :
   Once the board has been initialized, this command starts a new game, with a commitment to solve the game in g moves or fewer.
• switch r c :
   Within a game(after you have entered 'game g' command), this command switches the cell at row r, column c to on if it's off or off if it's on,
   and it will also switch the state of cells at its North, South, West, East direction. t
   Then the grid will be displayed.
