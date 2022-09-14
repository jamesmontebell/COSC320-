from cmath import pi
import math
import numpy as np

x = np.array([[0, 2], [1, 0], [2, 2], [-1, 4]], dtype=object)
pi = math.pi
d = 2
littleSigma = 1 #np.array([1, 1])
sigma = np.array([[littleSigma*littleSigma, 0], [littleSigma*littleSigma, 0]], dtype='float64')
mu = 0 #np.array([0, 0])
theta = np.array([[mu, mu], [littleSigma, littleSigma]])

def pdf(x, mu, sigma):
    return (1/(math.pow(np.linalg.det(sigma), 1/2)*math.pow(2*pi, d/2)))*math.exp((-1/2)*(x-mu).T@(np.linalg.inv(sigma)@(x-mu)))

def logLikelihood(x, mu, sigma):
    return

print(np.linalg.det(sigma))

for i in range(x):
    
