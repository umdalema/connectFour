# connectFour
This is a text based version of the popular game Connect Four. 
<pre>
Compiled on a linuex system using the command: 
  "g++ -std=c++14 -Wall -Werror -Wvla -Wextra -pedantic -O3 connect.cpp game.h game.cpp player.h player.cpp -o connect"
  
Flags: 
 -m, --mode |MODE| : This flag is optional. If not selected the program will default to simple. 
                     Avialble <MODE> arguments that are valid. 
 <br>
 Valid |MODE|: 
    -s, simple: simple mode. two players will play against eachother on a standard 6x7 board.
                You can select names and the score to play to. 
    -c, custom: custom mode. two players will play against eachoterh on a board the size of their choosing. 
                Players are able to select names and what character their piece will be. 
</pre>
