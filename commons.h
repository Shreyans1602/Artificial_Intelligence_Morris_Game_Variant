#include"models.h"

bool validateInput(int inputArgCnt, char** inputArgVal) {
    if(4 != inputArgCnt) {
        std::cout<<"Invalid number of arguments. Refer to the format below:"<<std::endl;
        std::cout<<"./[PROGRAM NAME] [INPUT FILE NAME].txt [OUTPUT FILE NAME].txt [DEPTH OF TREE]"<<std::endl;
        return false;
    }
    
    try {
        std::stoi(inputArgVal[3]);
    }
    
    catch(std::exception &err) {
        std::cout<<"Invalid type of input given. Refer to the format below:"<<std::endl;
        std::cout<<"./[PROGRAM NAME] [INPUT FILE NAME].txt [OUTPUT FILE NAME].txt [DEPTH OF TREE]"<<std::endl;
        return false;
    }

    #if DEBUG
    std::cout<<"Input File: "<<inputArgVal[1]<<" Output File: "<<inputArgVal[2]<<" Depth: "<<std::stoi(inputArgVal[3])<<std::endl;
    #endif

    return true;
}

FILE* readOrCreateFile(const char* fileName, bool readOrCreate) {
    if(readOrCreate) {
        FILE *fileHandler = fopen(fileName, "r");
        if(fileHandler != NULL) {
            return fileHandler;
        }
        else {
            std::cout<<"Input file "<<fileName<<" does not exist. Try again with a valid name"<<std::endl;
            return NULL;
        }
    }
    else {
        FILE *fileHandler = fopen(fileName, "w");
        if(fileHandler != NULL) {
            return fileHandler;
        }
        else {
            std::cout<<"Output file "<<fileName<<" creation failed. Try again"<<std::endl;
            return NULL;
        }
    }
}

void writeMoves(FILE* outputFileHandler, std::string board) {
    if(outputFileHandler == NULL) {
        std::cout<<"Error in writing to file. Try again"<<std::endl;
        return;
    }
    
    fprintf(outputFileHandler, "%s", board.c_str());
}

std::string getMoves(FILE* inputFileHandler) {
    if(inputFileHandler == NULL) {
        return "";
    }

    char *linePtr = NULL;
    size_t lineCap = 0;
    ssize_t lineLength = 0;
    lineLength = getline(&linePtr, &lineCap, inputFileHandler);
    std::string inputMoves = linePtr;

    // Validating if sufficient spaces exist in the input file
    if(lineLength != TOTAL_MOVE_SPACES) {
        std::cout<<"Sufficient moves not found. Check the input file"<<std::endl;
        return "";
    }

    // Validating each move is shown with the correct character
    for(int iterator = 0; iterator < TOTAL_MOVE_SPACES; iterator++) {
        if(!(inputMoves[iterator] == EMPTY || inputMoves[iterator] == BLACK || inputMoves[iterator] == WHITE)) {
            std::cout<<"Invalid character '"<<inputMoves[iterator]<<"' in moves found. Check the input file"<<std::endl;
            return "";
        }
    }

    return inputMoves;
}

int* getNeighbours(int boardPosition) {
    #if DEBUG
    std::cout<<"Returning neighbour for position: "<<boardPosition<<std::endl;
    #endif

    if(boardPosition > 21 || boardPosition < 0) {
        std::cout<<"Invalid position for getting neighbour '"<<boardPosition<<"'"<<std::endl;
        return NULL;
    }

    int *neighbours = NULL;

    switch(boardPosition) {
        case 0:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 1;
                neighbours[1] = 3;
                neighbours[2] = 19;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 1:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 0;
                neighbours[1] = 2;
                neighbours[2] = 4;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 2:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 1;
                neighbours[1] = 5;
                neighbours[2] = 12;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 3:
            neighbours = new int[5];
            if(neighbours != NULL) {
                neighbours[0] = 0;
                neighbours[1] = 4;
                neighbours[2] = 6;
                neighbours[3] = 8;
                neighbours[4] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 4:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 1;
                neighbours[1] = 3;
                neighbours[2] = 5;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 5:
            neighbours = new int[5];
            if(neighbours != NULL) {
                neighbours[0] = 2;
                neighbours[1] = 4;
                neighbours[2] = 7;
                neighbours[3] = 11;
                neighbours[4] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 6:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 3;
                neighbours[1] = 7;
                neighbours[2] = 9;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 7:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 5;
                neighbours[1] = 6;
                neighbours[2] = 10;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 8:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 3;
                neighbours[1] = 9;
                neighbours[2] = 16;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 9:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 6;
                neighbours[1] = 8;
                neighbours[2] = 13;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 10:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 7;
                neighbours[1] = 11;
                neighbours[2] = 15;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 11:
            neighbours = new int[5];
            if(neighbours != NULL) {
                neighbours[0] = 5;
                neighbours[1] = 10;
                neighbours[2] = 12;
                neighbours[3] = 18;
                neighbours[4] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 12:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 2;
                neighbours[1] = 11;
                neighbours[2] = 21;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 13:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 9;
                neighbours[1] = 14;
                neighbours[2] = 16;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 14:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 13;
                neighbours[1] = 15;
                neighbours[2] = 17;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 15:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 10;
                neighbours[1] = 14;
                neighbours[2] = 18;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 16:
            neighbours = new int[5];
            if(neighbours != NULL) {
                neighbours[0] = 8;
                neighbours[1] = 13;
                neighbours[2] = 17;
                neighbours[3] = 19;
                neighbours[4] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 17:
            neighbours = new int[5];
            if(neighbours != NULL) {
                neighbours[0] = 14;
                neighbours[1] = 16;
                neighbours[2] = 18;
                neighbours[3] = 20;
                neighbours[4] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 18:
            neighbours = new int[5];
            if(neighbours != NULL) {
                neighbours[0] = 11;
                neighbours[1] = 15;
                neighbours[2] = 17;
                neighbours[3] = 21;
                neighbours[4] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 19:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 0;
                neighbours[1] = 16;
                neighbours[2] = 20;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 20:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 17;
                neighbours[1] = 19;
                neighbours[2] = 21;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        case 21:
            neighbours = new int[4];
            if(neighbours != NULL) {
                neighbours[0] = 12;
                neighbours[1] = 18;
                neighbours[2] = 20;
                neighbours[3] = -1;
            }
            else {
                break;
            }
            #if DEBUG
            std::cout<<"Neighbours: "<<neighbours[0]<<" "<<neighbours[1]<<" "<<neighbours[2]<<" "<<neighbours[3]<<std::endl;
            #endif
            return neighbours;
        default:
            #if DEBUG
            std::cout<<"Null returned"<<std::endl;
            #endif
            return NULL;
    }
    #if DEBUG
    std::cout<<"Null returned"<<std::endl;
    #endif
    return NULL;
}

bool closeMill(int boardPosition, std::string board) {
    #if DEBUG
    std::cout<<"Close mill flag for position: "<<boardPosition<<" Board: "<<board<<std::endl;
    #endif

    char boardValue = board[boardPosition];

    switch(boardPosition) {
        case 0:
            if((board[1] == boardValue && board[2] == boardValue) 
            || (board[3] == boardValue && board[6] == boardValue)) {
                return true;
            }
            break;
        case 1:
            if(board[0] == boardValue && board[2] == boardValue) {
                return true;
            }
            break;
        case 2:
            if((board[0] == boardValue && board[1] == boardValue) 
            || (board[12] == boardValue && board[21] == boardValue)
            || (board[5] == boardValue && board[7] == boardValue)) {
                return true;
            }
            break;
        case 3:
            if((board[0] == boardValue && board[6] == boardValue) 
            || (board[4] == boardValue && board[5] == boardValue)
            || (board[8] == boardValue && board[16] == boardValue)) {
                return true;
            }
            break;
        case 4:
            if(board[3] == boardValue && board[5] == boardValue) {
                return true;
            }
            break;
        case 5:
            if((board[3] == boardValue && board[4] == boardValue) 
            || (board[2] == boardValue && board[7] == boardValue)
            || (board[11] == boardValue && board[18] == boardValue)) {
                return true;
            }
            break;
        case 6:
            if((board[0] == boardValue && board[3] == boardValue) 
            || (board[9] == boardValue && board[13] == boardValue)) {
                return true;
            }
            break;
        case 7:
            if((board[2] == boardValue && board[5] == boardValue) 
            || (board[10] == boardValue && board[15] == boardValue)) {
                return true;
            }
            break;
        case 8:
            if(board[3] == boardValue && board[16] == boardValue) {
                return true;
            }
            break;
        case 9:
            if(board[6] == boardValue && board[13] == boardValue) {
                return true;
            }
            break;
        case 10:
            if((board[7] == boardValue && board[15] == boardValue)
            || (board[11] == boardValue && board[12] == boardValue)) {
                return true;
            }
            break;
        case 11:
            if((board[10] == boardValue && board[12] == boardValue) 
            || (board[5] == boardValue && board[18] == boardValue)) {
                return true;
            }
            break;
        case 12:
            if((board[10] == boardValue && board[11] == boardValue) 
            || (board[2] == boardValue && board[21] == boardValue)) {
                return true;
            }
            break;
        case 13:
            if((board[6] == boardValue && board[9] == boardValue) 
            || (board[14] == boardValue && board[15] == boardValue)
            || (board[16] == boardValue && board[19] == boardValue)) {
                return true;
            }
            break;
        case 14:
            if((board[13] == boardValue && board[15] == boardValue) 
            || (board[17] == boardValue && board[20] == boardValue)) {
                return true;
            }
            break;
        case 15:
            if((board[13] == boardValue && board[14] == boardValue) 
            || (board[7] == boardValue && board[10] == boardValue)
            || (board[18] == boardValue && board[21] == boardValue)) {
                return true;
            }
            break;
        case 16:
            if((board[3] == boardValue && board[8] == boardValue) 
            || (board[17] == boardValue && board[18] == boardValue)
            || (board[13] == boardValue && board[19] == boardValue)) {
                return true;
            }
            break;
        case 17:
            if((board[16] == boardValue && board[18] == boardValue) 
            || (board[14] == boardValue && board[20] == boardValue)) {
                return true;
            }
            break;
        case 18:
            if((board[16] == boardValue && board[17] == boardValue)
            || (board[5] == boardValue && board[11] == boardValue)
            || (board[15] == boardValue && board[21] == boardValue)) {
                return true;
            }
            break;
        case 19:
            if((board[20] == boardValue && board[21] == boardValue) 
            || (board[13] == boardValue && board[16] == boardValue)) {
                return true;
            }
            break;
        case 20:
            if((board[19] == boardValue && board[21] == boardValue) 
            || (board[14] == boardValue && board[17] == boardValue)) {
                return true;
            }
            break;
        case 21:
            if((board[19] == boardValue && board[20] == boardValue) 
            || (board[2] == boardValue && board[12] == boardValue)
            || (board[15] == boardValue && board[18] == boardValue)) {
                return true;
            }
            break;
        default:
            #if DEBUG
            std::cout<<"False returned"<<std::endl;
            #endif

            return false;
    }

    #if DEBUG
    std::cout<<"False returned"<<std::endl;
    #endif

    return false;
}

void generateRemove(std::string board, std::vector<std::string> &list) {
    bool positionsAdded = false;

    for(int iterator = 0; iterator < board.length(); iterator++) {
        if(board[iterator] == BLACK) {
            if(closeMill(iterator, board) == false) {
                std::string tempBoard = board;
                tempBoard[iterator] = EMPTY;
                list.push_back(tempBoard);
                positionsAdded = true;
            }
        }
    }

    if(positionsAdded == false) {
        list.push_back(board);
    }
}

std::vector<std::string> generateMove(std::string board) {
    std::vector<std::string> list;

    for(int iterator = 0; iterator < board.length(); iterator++) {
        if(board[iterator] == WHITE) {
            int *neighbours = getNeighbours(iterator);
            for(int neighbour = 0; neighbours[neighbour] != -1; neighbour++) {
                if(board[neighbours[neighbour]] == EMPTY) {
                    std::string tempBoard = board;
                    tempBoard[iterator] = EMPTY;
                    tempBoard[neighbours[neighbour]] = WHITE;

                    if(closeMill(neighbours[neighbour], tempBoard) == true) {
                        generateRemove(tempBoard, list);
                    }
                    
                    else {
                        list.push_back(tempBoard);
                    }
                }
            }
        }
    }

    return list;
}

std::vector<std::string> generateHopping(std::string board) {
    std::vector<std::string> list;

    for(int iterator = 0; iterator < board.length(); iterator++) {
        if(board[iterator] == WHITE) {
            for(int iteratorInner = 0; iteratorInner < board.length(); iteratorInner++) {
                if(board[iteratorInner] == EMPTY) {
                    std::string tempBoard = board;
                    tempBoard[iterator] = EMPTY;
                    tempBoard[iteratorInner] = WHITE;

                    if(closeMill(iteratorInner, tempBoard) == true) {
                        generateRemove(tempBoard, list);
                    }

                    else {
                        list.push_back(tempBoard);
                    }
                }
            }
        }
    }

    return list;
}

std::vector<std::string> generateAdd(std::string board) {
    std::vector<std::string> list;

    for(int iterator = 0; iterator < board.length(); iterator++) {
        if(board[iterator] == EMPTY) {
            std::string tempBoard = board;
            tempBoard[iterator] = WHITE;

            if(closeMill(iterator, tempBoard) == true) {
                generateRemove(tempBoard, list);
            }
            else {
                list.push_back(tempBoard);
            }
        }
    }

    return list;
}

std::vector<std::string> generateMovesMidgameEndgame(std::string board) {
    int countWhite = 0;
    
    for(int iterator = 0; iterator < board.length(); iterator++) {
        if(board[iterator] == WHITE) {
            countWhite++;
        }
    }

    if(countWhite == 3) {
        return generateHopping(board);
    }
    
    return generateMove(board);
}

std::vector<std::string> generateMovesOpening(std::string board) {
    return generateAdd(board);
}

std::string swapWhiteBlack(std::string board) {
    std::string tempBoard = board;
    for(int iterator = 0; iterator < board.length(); iterator++) {
        if(tempBoard[iterator] == WHITE) {
            tempBoard[iterator] = BLACK;
        }

        else if(tempBoard[iterator] == BLACK) {
            tempBoard[iterator] = WHITE;
        }

        else {
            continue;
        }
    }

    return tempBoard;
}

std::vector<std::string> swapWhiteBlackinL(std::vector<std::string> boards) {
    std::vector<std::string> tempBoards = boards;
    std::vector<std::string> newBoards;
    
    for(int iteratorOuter = 0; iteratorOuter < tempBoards.size(); iteratorOuter++) {
        std::string board = swapWhiteBlack(tempBoards[iteratorOuter]);
        newBoards.push_back(board);
    }

    return newBoards;
}

int calculateStaticEstimation(std::string board, int openingOrMidGame) {
    int numWhitePieces = 0;
    int numBlackPieces = 0;

    for(int iterator = 0; iterator < board.length(); iterator++) {
        if(board[iterator] == WHITE) {
            numWhitePieces++;
        }

        else if(board[iterator] == BLACK) {
            numBlackPieces++;
        }

        else {
            continue;
        }
    }

    std::vector<std::string> blackMovesList = swapWhiteBlackinL(generateMovesMidgameEndgame(swapWhiteBlack(board)));
    int numBlackMoves = blackMovesList.size();

    if(openingOrMidGame == OPENING_GAME) {
        return numWhitePieces - numBlackPieces;
    }
    
    else if(openingOrMidGame == MID_GAME) {
        if(numBlackPieces <= 2) {
            return 10000;
        }

        else if(numWhitePieces <= 2) {
            return -10000;
        }

        else if(numBlackMoves == 0) {
            return 10000;
        }

        else {
            return ((1000 * (numWhitePieces - numBlackPieces)) - numBlackMoves);
        }
    }

    else {
        std::cout<<"Invalid state of game"<<std::endl;
        return 0;
    }
}

class initializeGame {
    public:
        int inputArgCnt;
        char** inputArgVal;
        const char *inputFileName;
        const char *outputFileName;
        int depth;
        FILE *inputFileHandler;
        FILE *outputFileHandler;
        std::string inputMoves;

        initializeGame(int inputArgCntMain, char** inputArgValMain) {
            inputArgCnt = inputArgCntMain;
            inputArgVal = inputArgValMain;
            inputFileName = NULL;
            outputFileName = NULL;
            inputFileHandler = NULL;
            outputFileHandler = NULL;
            depth = 0;
            inputMoves = "";
        }

        int startGame(void) {
            // Validate input arguments
            if(!validateInput(inputArgCnt, inputArgVal)) {
                return RETURN_FAILURE;
            }

            // Prepare all input arguments for use
            inputFileName = inputArgVal[INPUT_FILE_INDEX];
            outputFileName = inputArgVal[OUTPUT_FILE_INDEX];
            depth = atoi(inputArgVal[DEPTH_INDEX]);

            #if DEBUG
            std::cout<<"Input File: "<<inputFileName<<" Output File: "<<outputFileName<<" Depth: "<<depth<<std::endl;
            #endif

            // Read and create necessary files
            inputFileHandler = readOrCreateFile(inputFileName, READ_FILE);
            outputFileHandler = readOrCreateFile(outputFileName, WRITE_FILE);

            if((inputFileHandler == NULL) || (outputFileHandler == NULL)) {
                return RETURN_FAILURE;
            }

            inputMoves = getMoves(inputFileHandler);

            if(inputMoves.empty()) {
                return RETURN_FAILURE;
            }

            #if DEBUG
            std::cout<<"Moves Read: "<<inputMoves<<std::endl;
            #endif

            return RETURN_SUCCESS;
        }
};

class boardData {
    public:
        int staticEstimation;
        int minMaxEstimation;
        std::string bestBoard;
        
        boardData() {
            bestBoard = "";
            staticEstimation = 0;
            minMaxEstimation = 0;
        }

        boardData(std::string newBoard, int newStaticEstimation, int newMinMaxEstimation) {
            bestBoard = newBoard;
            staticEstimation = newStaticEstimation;
            minMaxEstimation = newMinMaxEstimation;
        }
};

boardData applyMinMaxOpeningAlgorithm(std::string board, int depth, int minimizeOrMaximize, char blackOrWhite) {
    #if DEBUG
    std::cout<<"applyMinMaxOpeningAlgorithm called at depth "<<depth<<" with board positions "<<board<<std::endl;
    #endif

    std::vector<std::string> list;
    boardData bestBoardData;

    if(depth == 0) {
        #if DEBUG
        std::cout<<"Zero depth reached with board "<<board<<std::endl;
        #endif

        bestBoardData.bestBoard = board;
        bestBoardData.staticEstimation++;

        if(blackOrWhite == WHITE) {
            bestBoardData.minMaxEstimation = calculateStaticEstimation(board, OPENING_GAME);
        }
        
        else {
            bestBoardData.minMaxEstimation = calculateStaticEstimation(board, OPENING_GAME);
        }
    }

    else if(depth > 0) {
        if(minimizeOrMaximize == MAXIMIZING) {
            if(blackOrWhite == WHITE) {
                list = generateMovesOpening(board);
                bestBoardData.minMaxEstimation = -2147483648;
            }

            else {
                list = swapWhiteBlackinL(generateMovesOpening(swapWhiteBlack(board)));
                bestBoardData.minMaxEstimation = 2147483647;
            }            
        }

        else {
            if(blackOrWhite == WHITE) {
                list = swapWhiteBlackinL(generateMovesOpening(swapWhiteBlack(board)));
                bestBoardData.minMaxEstimation = 2147483647;
            }

            else {
                list = generateMovesOpening(board);
                bestBoardData.minMaxEstimation = -2147483648;
            }
        }

        for(int boardNum = 0; boardNum < list.size(); boardNum++) {
            if(minimizeOrMaximize == MAXIMIZING) {
                boardData minBoardData;

                if(blackOrWhite == WHITE) {
                    minBoardData = applyMinMaxOpeningAlgorithm(list[boardNum], depth - 1, MINIMIZING, WHITE);

                    if(minBoardData.minMaxEstimation > bestBoardData.minMaxEstimation) {
                        bestBoardData.minMaxEstimation = minBoardData.minMaxEstimation;
                        bestBoardData.bestBoard = list[boardNum];
                    }
                }

                else {
                    minBoardData = applyMinMaxOpeningAlgorithm(list[boardNum], depth - 1, MINIMIZING, BLACK);

                    if(minBoardData.minMaxEstimation < bestBoardData.minMaxEstimation) {
                        bestBoardData.minMaxEstimation = minBoardData.minMaxEstimation;
                        bestBoardData.bestBoard = list[boardNum];
                    }
                }

                bestBoardData.staticEstimation = bestBoardData.staticEstimation + minBoardData.staticEstimation;
            }
            
            else {
                boardData maxBoardData;

                if(blackOrWhite == WHITE) {
                    maxBoardData = applyMinMaxOpeningAlgorithm(list[boardNum], depth - 1, MAXIMIZING, WHITE);\

                    if(maxBoardData.minMaxEstimation < bestBoardData.minMaxEstimation) {
                        bestBoardData.minMaxEstimation = maxBoardData.minMaxEstimation;
                        bestBoardData.bestBoard = list[boardNum];
                    }
                }

                else {
                    maxBoardData = applyMinMaxOpeningAlgorithm(list[boardNum], depth - 1, MAXIMIZING, BLACK);

                    if(maxBoardData.minMaxEstimation > bestBoardData.minMaxEstimation) {
                        bestBoardData.minMaxEstimation = maxBoardData.minMaxEstimation;
                        bestBoardData.bestBoard = list[boardNum];
                    }
                }

                bestBoardData.staticEstimation = bestBoardData.staticEstimation + maxBoardData.staticEstimation;
            }
        }
    }

    else {
        std::cout<<"Negative depth given, check the input arguments"<<std::endl;
    }

    return bestBoardData;
}

boardData applyMinMaxGameAlgorithm(std::string board, int depth, int minimizeOrMaximize, char blackOrWhite) {
    #if DEBUG
    std::cout<<"applyMinMaxGameAlgorithm called at depth "<<depth<<" with board positions "<<board<<std::endl;
    #endif

    std::vector<std::string> list;
    boardData bestBoardData;

    if(depth == 0) {
        #if DEBUG
        std::cout<<"Zero depth reached with board "<<board<<std::endl;
        #endif

        if(blackOrWhite == WHITE) {
            list = swapWhiteBlackinL(generateMovesMidgameEndgame(swapWhiteBlack(board)));
        }

        else {
            list = generateMovesMidgameEndgame(board);
        }
        
        bestBoardData.minMaxEstimation = calculateStaticEstimation(board, MID_GAME);
        bestBoardData.bestBoard = board;
        bestBoardData.staticEstimation++;
    }

    else if(depth > 0) {
        if(minimizeOrMaximize == MAXIMIZING) {
            if(blackOrWhite == WHITE) {
                list = generateMovesMidgameEndgame(board);
                bestBoardData.minMaxEstimation = -2147483648;
            }

            else {
                list = swapWhiteBlackinL(generateMovesMidgameEndgame(swapWhiteBlack(board)));
                bestBoardData.minMaxEstimation = 2147483647;
            }            
        }

        else {
            if(blackOrWhite == WHITE) {
                list = swapWhiteBlackinL(generateMovesMidgameEndgame(swapWhiteBlack(board)));
                bestBoardData.minMaxEstimation = 2147483647;
            }

            else {
                list = generateMovesMidgameEndgame(board);
                bestBoardData.minMaxEstimation = -2147483648;
            }
        }

        for(int boardNum = 0; boardNum < list.size(); boardNum++) {
            if(minimizeOrMaximize == MAXIMIZING) {
                boardData minBoardData;

                if(blackOrWhite == WHITE) {
                    minBoardData = applyMinMaxGameAlgorithm(list[boardNum], depth - 1, MINIMIZING, WHITE);

                    if(minBoardData.minMaxEstimation > bestBoardData.minMaxEstimation) {
                        bestBoardData.minMaxEstimation = minBoardData.minMaxEstimation;
                        bestBoardData.bestBoard = list[boardNum];
                    }
                }

                else {
                    minBoardData = applyMinMaxGameAlgorithm(list[boardNum], depth - 1, MINIMIZING, BLACK);

                    if(minBoardData.minMaxEstimation < bestBoardData.minMaxEstimation) {
                        bestBoardData.minMaxEstimation = minBoardData.minMaxEstimation;
                        bestBoardData.bestBoard = list[boardNum];
                    }
                }

                bestBoardData.staticEstimation = bestBoardData.staticEstimation + minBoardData.staticEstimation;
            }
            
            else {
                boardData maxBoardData;

                if(blackOrWhite == WHITE) {
                    maxBoardData = applyMinMaxGameAlgorithm(list[boardNum], depth - 1, MAXIMIZING, WHITE);

                    if(maxBoardData.minMaxEstimation < bestBoardData.minMaxEstimation) {
                        bestBoardData.minMaxEstimation = maxBoardData.minMaxEstimation;
                        bestBoardData.bestBoard = list[boardNum];
                    }
                }

                else {
                    maxBoardData = applyMinMaxGameAlgorithm(list[boardNum], depth - 1, MAXIMIZING, BLACK);

                    if(maxBoardData.minMaxEstimation > bestBoardData.minMaxEstimation) {
                        bestBoardData.minMaxEstimation = maxBoardData.minMaxEstimation;
                        bestBoardData.bestBoard = list[boardNum];
                    }
                }

                bestBoardData.staticEstimation = bestBoardData.staticEstimation + maxBoardData.staticEstimation;
            }
        }
    }

    else {
        std::cout<<"Negative depth given, check the input arguments"<<std::endl;
    }

    return bestBoardData;
}

boardData applyABOpeningAlgorithm(std::string board, int depth, int alpha, int beta, int minimizeOrMaximize) {
    #if DEBUG
    std::cout<<"applyABOpeningAlgorithm called at depth "<<depth<<" with board positions "<<board<<std::endl;
    #endif

    std::vector<std::string> list;
    boardData bestBoardData;

    if(depth == 0) {
        #if DEBUG
        std::cout<<"Zero depth reached with board "<<board<<std::endl;
        #endif

        bestBoardData.bestBoard = board;
        bestBoardData.staticEstimation++;
        bestBoardData.minMaxEstimation = calculateStaticEstimation(board, OPENING_GAME);
    }

    else if(depth > 0) {
        if(minimizeOrMaximize == MAXIMIZING) {
            list = generateMovesOpening(board);
        }

        else {
            list = swapWhiteBlackinL(generateMovesOpening(swapWhiteBlack(board)));
        }

        for(int boardNum = 0; boardNum < list.size(); boardNum++) {
            if(minimizeOrMaximize == MAXIMIZING) {
                boardData minBoardData = applyABOpeningAlgorithm(list[boardNum], depth - 1, alpha, beta, MINIMIZING);

                if(minBoardData.minMaxEstimation > alpha) {
                    alpha = minBoardData.minMaxEstimation;
                    bestBoardData.bestBoard = list[boardNum];
                }

                bestBoardData.staticEstimation = bestBoardData.staticEstimation + minBoardData.staticEstimation;
            }
            
            else {
                boardData maxBoardData = applyABOpeningAlgorithm(list[boardNum], depth - 1, alpha, beta, MAXIMIZING);

                if(maxBoardData.minMaxEstimation < beta) {
                    beta = maxBoardData.minMaxEstimation;
                    bestBoardData.bestBoard = list[boardNum];
                }

                bestBoardData.staticEstimation = bestBoardData.staticEstimation + maxBoardData.staticEstimation;
            }

            if (alpha >= beta) {
                break;
            }
        }

        if(minimizeOrMaximize == MAXIMIZING) {
            bestBoardData.minMaxEstimation = alpha;
        }

        else {
            bestBoardData.minMaxEstimation = beta;
        }
    }

    else {
        std::cout<<"Negative depth given, check the input arguments"<<std::endl;
    }

    return bestBoardData;
}

boardData applyABGameAlgorithm(std::string board, int depth, int alpha, int beta, int minimizeOrMaximize) {
    #if DEBUG
    std::cout<<"applyABGameAlgorithm called at depth "<<depth<<" with board positions "<<board<<std::endl;
    #endif

    std::vector<std::string> list;
    boardData bestBoardData;

    if(depth == 0) {
        #if DEBUG
        std::cout<<"Zero depth reached with board "<<board<<std::endl;
        #endif

        int numWhitePieces = 0;
        int numBlackPieces = 0;

        for(int iterator = 0; iterator < board.length(); iterator++) {
            if(board[iterator] == WHITE) {
                numWhitePieces++;
            }

            else if(board[iterator] == BLACK) {
                numBlackPieces++;
            }

            else {
                continue;
            }
        }

        list = swapWhiteBlackinL(generateMovesMidgameEndgame(swapWhiteBlack(board)));

        if(numBlackPieces <= 2) {
            bestBoardData.minMaxEstimation = 1000;
        }

        else if(numWhitePieces <= 2) {
            bestBoardData.minMaxEstimation = -1000;
        }

        else if(list.size() == 0) {
            bestBoardData.minMaxEstimation = 10000;
        }

        else {
            bestBoardData.minMaxEstimation = ((1000 * (numWhitePieces - numBlackPieces)) - list.size());
        }

        bestBoardData.bestBoard = board;
        bestBoardData.staticEstimation++;
    }

    else if(depth > 0) {
        if(minimizeOrMaximize == MAXIMIZING) {
            list = generateMovesMidgameEndgame(board);
        }

        else {
            list = swapWhiteBlackinL(generateMovesMidgameEndgame(swapWhiteBlack(board)));
        }

        for(int boardNum = 0; boardNum < list.size(); boardNum++) {
            if(minimizeOrMaximize == MAXIMIZING) {
                boardData minBoardData = applyABGameAlgorithm(list[boardNum], depth - 1, alpha, beta, MINIMIZING);

                if(minBoardData.minMaxEstimation > alpha) {
                    alpha = minBoardData.minMaxEstimation;
                    bestBoardData.bestBoard = list[boardNum];
                }

                bestBoardData.staticEstimation = bestBoardData.staticEstimation + minBoardData.staticEstimation;
            }
            
            else {
                boardData maxBoardData = applyABGameAlgorithm(list[boardNum], depth - 1, alpha, beta, MAXIMIZING);

                if(maxBoardData.minMaxEstimation < beta) {
                    beta = maxBoardData.minMaxEstimation;
                    bestBoardData.bestBoard = list[boardNum];
                }

                bestBoardData.staticEstimation = bestBoardData.staticEstimation + maxBoardData.staticEstimation;
            }

            if (alpha >= beta) {
                break;
            }
        }

        if(minimizeOrMaximize == MAXIMIZING) {
            bestBoardData.minMaxEstimation = alpha;
        }

        else {
            bestBoardData.minMaxEstimation = beta;
        }
    }

    else {
        std::cout<<"Negative depth given, check the input arguments"<<std::endl;
    }

    return bestBoardData;
}

int calculateStaticEstimationImproved(std::string board) {
    int numWhitePieces = 0;
    int numBlackPieces = 0;
    int numMills = 0;

    for(int iterator = 0; iterator < board.length(); iterator++) {
        if(board[iterator] == WHITE) {
            numWhitePieces++;
        }

        else if(board[iterator] == BLACK) {
            numBlackPieces++;
        }

        else {
            continue;
        }
    }

    for(int iterator = 0; iterator < board.length(); iterator++) {
        if(board[iterator] == EMPTY) {
            if(closeMill(iterator, board)) {
                numMills++;
            }
        }
    }

    return (numMills + (numWhitePieces - numBlackPieces));
}

boardData applyMinMaxOpeningAlgorithmImproved(std::string board, int depth, int minimizeOrMaximize) {
    #if DEBUG
    std::cout<<"applyMinMaxOpeningAlgorithmImproved called at depth "<<depth<<" with board positions "<<board<<std::endl;
    #endif

    std::vector<std::string> list;
    boardData bestBoardData;

    if(depth == 0) {
        #if DEBUG
        std::cout<<"Zero depth reached with board "<<board<<std::endl;
        #endif

        bestBoardData.bestBoard = board;
        bestBoardData.staticEstimation++;
        bestBoardData.minMaxEstimation = calculateStaticEstimationImproved(board);
    }

    else if(depth > 0) {
        if(minimizeOrMaximize == MAXIMIZING) {
            list = generateMovesOpening(board);
            bestBoardData.minMaxEstimation = -2147483648;
        }

        else {
            list = swapWhiteBlackinL(generateMovesOpening(swapWhiteBlack(board)));
            bestBoardData.minMaxEstimation = 2147483647;
        }

        for(int boardNum = 0; boardNum < list.size(); boardNum++) {
            if(minimizeOrMaximize == MAXIMIZING) {
                boardData minBoardData = applyMinMaxOpeningAlgorithmImproved(list[boardNum], depth - 1, MINIMIZING);

                if(minBoardData.minMaxEstimation > bestBoardData.minMaxEstimation) {
                    bestBoardData.minMaxEstimation = minBoardData.minMaxEstimation;
                    bestBoardData.bestBoard = list[boardNum];
                }

                bestBoardData.staticEstimation = bestBoardData.staticEstimation + minBoardData.staticEstimation;
            }
            
            else {
                boardData maxBoardData = applyMinMaxOpeningAlgorithmImproved(list[boardNum], depth - 1, MAXIMIZING);\

                if(maxBoardData.minMaxEstimation < bestBoardData.minMaxEstimation) {
                    bestBoardData.minMaxEstimation = maxBoardData.minMaxEstimation;
                    bestBoardData.bestBoard = list[boardNum];
                }

                bestBoardData.staticEstimation = bestBoardData.staticEstimation + maxBoardData.staticEstimation;
            }
        }
    }

    else {
        std::cout<<"Negative depth given, check the input arguments"<<std::endl;
    }

    return bestBoardData;
}

boardData applyMinMaxGameAlgorithmImproved(std::string board, int depth, int minimizeOrMaximize) {
    #if DEBUG
    std::cout<<"applyMinMaxGameAlgorithmImproved called at depth "<<depth<<" with board positions "<<board<<std::endl;
    #endif

    std::vector<std::string> list;
    boardData bestBoardData;

    if(depth == 0) {
        #if DEBUG
        std::cout<<"Zero depth reached with board "<<board<<std::endl;
        #endif

        list = swapWhiteBlackinL(generateMovesMidgameEndgame(swapWhiteBlack(board)));
        bestBoardData.minMaxEstimation = calculateStaticEstimationImproved(board);
        bestBoardData.bestBoard = board;
        bestBoardData.staticEstimation++;
    }

    else if(depth > 0) {
        if(minimizeOrMaximize == MAXIMIZING) {
            list = generateMovesMidgameEndgame(board);
            bestBoardData.minMaxEstimation = -2147483648;
        }

        else {
            list = swapWhiteBlackinL(generateMovesMidgameEndgame(swapWhiteBlack(board)));
            bestBoardData.minMaxEstimation = 2147483647;
        }

        for(int boardNum = 0; boardNum < list.size(); boardNum++) {
            if(minimizeOrMaximize == MAXIMIZING) {
                boardData minBoardData = applyMinMaxGameAlgorithmImproved(list[boardNum], depth - 1, MINIMIZING);

                if(minBoardData.minMaxEstimation > bestBoardData.minMaxEstimation) {
                    bestBoardData.minMaxEstimation = minBoardData.minMaxEstimation;
                    bestBoardData.bestBoard = list[boardNum];
                }

                bestBoardData.staticEstimation = bestBoardData.staticEstimation + minBoardData.staticEstimation;
            }
            
            else {
                boardData maxBoardData = applyMinMaxGameAlgorithmImproved(list[boardNum], depth - 1, MAXIMIZING);

                if(maxBoardData.minMaxEstimation < bestBoardData.minMaxEstimation) {
                    bestBoardData.minMaxEstimation = maxBoardData.minMaxEstimation;
                    bestBoardData.bestBoard = list[boardNum];
                }

                bestBoardData.staticEstimation = bestBoardData.staticEstimation + maxBoardData.staticEstimation;
            }
        }
    }

    else {
        std::cout<<"Negative depth given, check the input arguments"<<std::endl;
    }

    return bestBoardData;
}

void printBoard(std::string board) {
    if(board.empty()) {
        std::cout<<"Empty board string given, cannot print this. Try again"<<std::endl;
        return;
    }

    // Validating if sufficient spaces exist in the input file
    if(board.length() != TOTAL_MOVE_SPACES) {
        std::cout<<"Sufficient moves not found. Check the input"<<std::endl;
        return;
    }

    std::cout<<board[19]<<"-----------------------"<<board[20]<<"-----------------------"<<board[21]<<std::endl;
    std::cout<<"| \\			|		       /|"<<std::endl;
    std::cout<<"|    \\			|		     /	|"<<std::endl;
    std::cout<<"|       \\		|		  /	|"<<std::endl;
    std::cout<<"|	"<<board[16]<<"---------------"<<board[17]<<"---------------"<<board[18]<<"	|"<<std::endl;
    std::cout<<"|	| \\		|	       /|	|"<<std::endl;
    std::cout<<"|	|    \\		|	     /	|	|"<<std::endl;
    std::cout<<"|	|       \\	|	   /	|	|"<<std::endl;
    std::cout<<"|	|	 "<<board[13]<<"------"<<board[14]<<"-------"<<board[15]<<"	|	|"<<std::endl;
    std::cout<<"|	|	 |		|	|	|"<<std::endl;
    std::cout<<"|	|	 |		|	|	|"<<std::endl;
    std::cout<<"|	"<<board[8]<<"--------"<<board[9]<<"		"<<board[10]<<"-------"<<board[11]<<"-------"<<board[12]<<std::endl;
    std::cout<<"|	|	 |		|	|	|"<<std::endl;
    std::cout<<"|	|	 |		|	|	|"<<std::endl;
    std::cout<<"|	|	 "<<board[6]<<"--------------"<<board[7]<<"	|	|"<<std::endl;
    std::cout<<"|	|	/	 	 \\	|	|"<<std::endl;
    std::cout<<"|	|    /		 	    \\	|	|"<<std::endl;
    std::cout<<"|	| /		 	      \\	|	|"<<std::endl;
    std::cout<<"|	"<<board[3]<<"---------------"<<board[4]<<"---------------"<<board[5]<<"	|"<<std::endl;
    std::cout<<"|     /			|		 \\	|"<<std::endl;
    std::cout<<"|   /			|		   \\	|"<<std::endl;
    std::cout<<"| /			|		     \\	|"<<std::endl;
    std::cout<<board[0]<<"-----------------------"<<board[1]<<"-----------------------"<<board[2]<<std::endl;
}