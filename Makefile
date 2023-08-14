#!/bin/bash

all: abgame minmax minmaxblack minmaximproved printboard clearscreen

abgame: ABGame.cpp ABOpening.cpp models.h commons.h
	g++ -Wall -Werror -O ABGame.cpp -o ABGame
	g++ -Wall -Werror -O ABOpening.cpp -o ABOpening

minmax: MiniMaxGame.cpp MiniMaxOpening.cpp models.h commons.h
	g++ -Wall -Werror -O MiniMaxGame.cpp -o MiniMaxGame
	g++ -Wall -Werror -O MiniMaxOpening.cpp -o MiniMaxOpening

minmaxblack: MiniMaxGameBlack.cpp MiniMaxOpeningBlack.cpp models.h commons.h
	g++ -Wall -Werror -O MiniMaxGameBlack.cpp -o MiniMaxGameBlack
	g++ -Wall -Werror -O MiniMaxOpeningBlack.cpp -o MiniMaxOpeningBlack

minmaximproved: MiniMaxGameImproved.cpp MiniMaxOpeningImproved.cpp models.h commons.h
	g++ -Wall -Werror -O MiniMaxGameImproved.cpp -o MiniMaxGameImproved
	g++ -Wall -Werror -O MiniMaxOpeningImproved.cpp -o MiniMaxOpeningImproved

printboard: PrintBoard.cpp models.h commons.h
	g++ -Wall -Werror -O PrintBoard.cpp -o PrintBoard

clearscreen:
	clear

clean:
	rm -rf ABGame 
	rm -rf ABOpening 
	rm -rf MiniMaxGame 
	rm -rf MiniMaxOpening 
	rm -rf MiniMaxGameBlack 
	rm -rf MiniMaxOpeningBlack 
	rm -rf MiniMaxGameImproved 
	rm -rf MiniMaxOpeningImproved
	rm -rf PrintBoard
	clear