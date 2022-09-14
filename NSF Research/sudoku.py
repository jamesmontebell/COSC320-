import random
import numpy as np
import math
from random import choice 
import statistics

startingSudoku = """
                    024007000
                    600000000
                    003680415
                    431005000
                    500000032
                    790000060
                    209710800
                    040093000
                    310004750
                """

startingSudokuArray =  np.array([[int(i) for i in line ] for line in startingSudoku.split()])

#print(startingSudokuArray)

def printBoard(board):
    print()
    for i in range(9):
        temp= ""
        if i == 3 or i == 6:
            print("---------------------")
        for j in range(9):
            if j == 3 or j == 6:
                temp += "| "
            temp += str(board[i, j]) + " "
        print(temp)

def createBlock():
    finalListOfBlocks = []
    for r in range (0,9):
        tmpList = []
        block1 = [i + 3*((r)%3) for i in range(0,3)]
        block2 = [i + 3*math.trunc((r)/3) for i in range(0,3)]
        for x in block1:
            for y in block2:
                tmpList.append([x,y])
        finalListOfBlocks.append(tmpList)
    return(finalListOfBlocks)
    
def numberOfErrors(board, row, column):
    numberOfErrors = (9 - len(set(board[row, :]))) + (9 - len(set(board[:, column])))
    return numberOfErrors

def CalculateNumberOfErrors(board):
    num = 0
    for i in range(9):
        num += numberOfErrors(board, i, i)
    return num

def RandomlyFill3x3Blocks(sudoku, listOfBlocks):
    for block in listOfBlocks:
        for box in block:
            if sudoku[box[0],box[1]] == 0:
                currentBlock = sudoku[block[0][0]:(block[-1][0]+1),block[0][1]:(block[-1][1]+1)]
                sudoku[box[0],box[1]] = choice([i for i in range(1,10) if i not in currentBlock])
    return sudoku

def SumOfOneBlock (sudoku, oneBlock):
    finalSum = 0
    for box in oneBlock:
        finalSum += sudoku[box[0], box[1]]
    return(finalSum)

def TwoRandomBoxesWithinBlock(fixedSudoku, block):
    while (1):
        firstBox = random.choice(block)
        secondBox = choice([box for box in block if box is not firstBox ])

        if fixedSudoku[firstBox[0], firstBox[1]] != 1 and fixedSudoku[secondBox[0], secondBox[1]] != 1:
            return([firstBox, secondBox])

def FlipBoxes(sudoku, boxesToFlip):
    proposedSudoku = np.copy(sudoku)
    placeHolder = proposedSudoku[boxesToFlip[0][0], boxesToFlip[0][1]]
    proposedSudoku[boxesToFlip[0][0], boxesToFlip[0][1]] = proposedSudoku[boxesToFlip[1][0], boxesToFlip[1][1]]
    proposedSudoku[boxesToFlip[1][0], boxesToFlip[1][1]] = placeHolder
    return (proposedSudoku)

def ProposedState (sudoku, fixedSudoku, listOfBlocks):
    randomBlock = random.choice(listOfBlocks)

    if SumOfOneBlock(fixedSudoku, randomBlock) > 6:  
        return(sudoku, 1, 1)
    boxesToFlip = TwoRandomBoxesWithinBlock(fixedSudoku, randomBlock)
    proposedSudoku = FlipBoxes(sudoku,  boxesToFlip)
    return([proposedSudoku, boxesToFlip])

def ChooseNewState (currentSudoku, fixedSudoku, listOfBlocks, sigma):
    proposal = ProposedState(currentSudoku, fixedSudoku, listOfBlocks)
    newSudoku = proposal[0]
    boxesToCheck = proposal[1]
    currentCost = numberOfErrors(boxesToCheck[0][0], boxesToCheck[0][1], currentSudoku) + numberOfErrors(boxesToCheck[1][0], boxesToCheck[1][1], currentSudoku)
    newCost = numberOfErrors(boxesToCheck[0][0], boxesToCheck[0][1], newSudoku) + numberOfErrors(boxesToCheck[1][0], boxesToCheck[1][1], newSudoku)
    # currentCost = CalculateNumberOfErrors(currentSudoku)
    # newCost = CalculateNumberOfErrors(newSudoku)
    costDifference = newCost - currentCost
    rho = math.exp(-costDifference/sigma)
    if(np.random.uniform(1,0,1) < rho):
        return([newSudoku, costDifference])
    return([currentSudoku, 0])

def CalculateInitialSigma (sudoku, fixedSudoku, listOfBlocks):
    listOfDifferences = []
    tmpSudoku = sudoku
    for i in range(1,10):
        tmpSudoku = ProposedState(tmpSudoku, fixedSudoku, listOfBlocks)[0]
        listOfDifferences.append(CalculateNumberOfErrors(tmpSudoku))
    return (statistics.pstdev(listOfDifferences))

def FixSudokuValues(fixed_sudoku):
    for i in range (0,9):
        for j in range (0,9):
            if fixed_sudoku[i,j] != 0:
                fixed_sudoku[i,j] = 1

    return(fixed_sudoku)

def ChooseNumberOfItterations(fixed_sudoku):
    numberOfItterations = 0
    for i in range (0,9):
        for j in range (0,9):
            if fixed_sudoku[i,j] != 0:
                numberOfItterations += 1
    return numberOfItterations

def solve(board):
    solutionFound = 0
    while solutionFound == 0:
        alpha = .99
        stuckCount = 0
        fixedSudoku = np.copy(board)
        printBoard(board)
        FixSudokuValues(fixedSudoku)
        listOfBlocks = createBlock()
        tempSudoku = RandomlyFill3x3Blocks(board, listOfBlocks)
        sigma = CalculateInitialSigma(board, fixedSudoku, listOfBlocks)
        score = CalculateNumberOfErrors(tempSudoku)
        iterations = ChooseNumberOfItterations(fixedSudoku)
        if score <= 0:
            solutionFound = 1
        while solutionFound == 0:
            previousScore = score
            for i in range(iterations):
                newState = ChooseNewState(tempSudoku, fixedSudoku, listOfBlocks, sigma)
                tempSudoku = newState[0]
                scoreDiff = newState[1]
                score += scoreDiff
                print(score)
                if score <= 0:
                    solutionFound = 1
                    break
            
            sigma *= alpha
            if score <= 0:
                solutionFound = 1
                break
            if score >= previousScore:
                stuckCount += 1
            else:
                stuckCount = 0
            if stuckCount > 80:
                sigma += 2
            if numberOfErrors(tempSudoku) == 0:
                printBoard(tempSudoku)
                break
        return tempSudoku

solution = solve(startingSudokuArray)
print(numberOfErrors(solution))
printBoard(solution)