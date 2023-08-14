# Artificial_Intelligence_Project
## Usage Instructions
### Using the makefile to compile programs
To compile all programs, use the command:
```
make all
```

To compile all minmax games for white move, use the command:
```
make minmax
```

To compile all minmax games for black move, use the command:
```
make minmaxblack
```

To compile all minmax improved games for white move, use the command:
```
make minmaximproved
```

To compile all abgame games for white move, use the command:
```
make abgame
```

To remove all executables after compilation, use the command:
```
make clean
```
### Compiling without makefile
To compile the programs without using the makefile, use the commands given below as per the game you are trying to compile:

MiniMaxOpening:
```
g++ -Wall -Werror -O MiniMaxOpening.cpp -o MiniMaxOpening
```

MiniMaxGame:
```
g++ -Wall -Werror -O MiniMaxGame.cpp -o MiniMaxGame
```

MiniMaxOpeningBlack:
```
g++ -Wall -Werror -O MiniMaxOpeningBlack.cpp -o MiniMaxOpeningBlack
```

MiniMaxGameBlack:
```
g++ -Wall -Werror -O MiniMaxGameBlack.cpp -o MiniMaxGameBlack
```

MiniMaxOpeningImproved:
```
g++ -Wall -Werror -O MiniMaxOpeningImproved.cpp -o MiniMaxOpeningImproved
```

MiniMaxGameImproved:
```
g++ -Wall -Werror -O MiniMaxGameImproved.cpp -o MiniMaxGameImproved
```

ABOpening:
```
g++ -Wall -Werror -O ABOpening.cpp -o ABOpening
```

ABGame:
```
g++ -Wall -Werror -O ABGame.cpp -o ABGame
```
### Run a program
To run a program, run the executable of interest using the command format:
```
./[Game_Executable_Name] [Input_File_Name] [Output_File_Name] [Depth]
```

For example:
```
./MiniMaxGame input.txt output.txt 1
```

### Check results of some test runs
Results are present in Report.txt
