#include<iostream>
#include<fstream>
#include<vector>

// Defines
#define DEBUG 0
#define RETURN_SUCCESS 0
#define RETURN_FAILURE -1
#define INPUT_FILE_INDEX 1
#define OUTPUT_FILE_INDEX 2
#define DEPTH_INDEX 3
#define READ_FILE 1
#define WRITE_FILE 0
#define TOTAL_MOVE_SPACES 22
#define OPENING_GAME 1
#define MID_GAME 2
#define EMPTY 'x'
#define WHITE 'W'
#define BLACK 'B'
#define MAXIMIZING 1
#define MINIMIZING 2

// Classes
class initializeGame;
class boardData;

// Common Functions
bool validateInput(int inputArgCnt, char** inputArgVal);
FILE* readOrCreateFile(const char* fileName, bool readOrCreate);
void writeMoves(FILE* outputFileHandler, std::string board);
std::string getMoves(FILE* inputFileHandler);
int* getNeighbours(int boardPosition);
bool closeMill(int boardPosition, std::string board);
void generateRemove(std::string board, std::vector<std::string> &list);
std::vector<std::string> generateMove(std::string board);
std::vector<std::string> generateHopping(std::string board);
std::vector<std::string> generateAdd(std::string board);
std::vector<std::string> generateMovesMidgameEndgame(std::string board);
std::vector<std::string> generateMovesOpening(std::string board);
std::string swapWhiteBlack(std::string board);
std::vector<std::string> swapWhiteBlackinL(std::vector<std::string> boards);
int calculateStaticEstimation(std::string board, int openingOrMidGame);
boardData applyMinMaxOpeningAlgorithm(std::string board, int depth, int minimizeOrMaximize, char blackOrWhite);
boardData applyMinMaxGameAlgorithm(std::string board, int depth, int minimizeOrMaximize, char blackOrWhite);
boardData applyABOpeningAlgorithm(std::string board, int depth, int alpha, int beta, int minimizeOrMaximize);
boardData applyABGameAlgorithm(std::string board, int depth, int alpha, int beta, int minimizeOrMaximize);
int calculateStaticEstimationImproved(std::string board);
boardData applyMinMaxOpeningAlgorithmImproved(std::string board, int depth, int minimizeOrMaximize);
boardData applyMinMaxGameAlgorithmImproved(std::string board, int depth, int minimizeOrMaximize);
void printBoard(std::string board);