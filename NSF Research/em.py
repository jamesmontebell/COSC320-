import numpy as np
import math

def eStep():
    tempInput = input("Input data in the form of a numpy array: ")
    x = np.array([eval(tempInput)])
    n = np.shape(x)[1]
    numberOfLatent = input("Input the number of latent variables: ")
    numberOfLatent = int(numberOfLatent)
    print("The E step")
    print("\n")
    print("The number of variables: ", n + numberOfLatent)
    mean = np.sum(x)/ (n + numberOfLatent)
    print("The mean of known data: ", mean)
    latentValue = np.round(mean)
    print("The latent variables values are: ", latentValue)
    print("\n")
    meanPrevious = 0
    while 1:
        meanTemp = mean + (latentValue * numberOfLatent) / (n + numberOfLatent)
        latentValue = meanTemp
        meanDifference = meanTemp - meanPrevious
        meanPrevious = meanTemp
        print("Present mean: ", meanTemp)
        print("Difference: ", meanDifference)
        print("\n")
        if meanDifference < 0.05:
            break
    for i in range(numberOfLatent):
        x = np.append(x, np.array([[meanTemp]]), axis=1)
    print("The final estimated data: ", x)

    

eStep()





