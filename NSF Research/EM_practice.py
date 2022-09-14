import numpy as np
import math

#create numpy array, setting latent variables to 2
#and setting n to the number of variables
x = np.array([[1, 8, 12, 7]])
numberOfLatent = 2
n = np.shape(x)[1]
mean = np.sum(x)/ (n + numberOfLatent)


latentValue = np.round(mean)


previousMean = 0

while 1:
    meanTemp = mean + (latentValue * numberOfLatent) / (n + numberOfLatent)
    latentValue = meanTemp
    meanDifference = meanTemp - previousMean
    previousMean = meanTemp
    if meanDifference < 0.05:
        break
for i in range(numberOfLatent):
    x = np.append(x, np.array([[meanTemp]]), axis=1)
print(x)

    

