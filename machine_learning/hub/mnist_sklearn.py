"""
Test mnist learning on sklearn with hub data
"""

import numpy as np
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.utils import check_random_state

from hub import Dataset

print(__doc__)

# Author: Arthur Mensch <arthur.mensch@m4x.org>
# License: BSD 3 clause

# Turn down for faster convergence
train_samples = 5000

print("loading mnist data from hub...")
mnist = Dataset("activeloop/mnist")  # loading the MNIST data lazily

X = mnist["image"].compute()
y = mnist["label"].compute()

print("------- X.shape", X.shape)
print("------- y.shape", y.shape)


print("now train mnist model...")

random_state = check_random_state(0)
permutation = random_state.permutation(X.shape[0])

print("---------- permutation")
print(permutation)

X = X[permutation]
y = y[permutation]

print("------- X.shape", X.shape)
print("------- y.shape", y.shape)

X = X.reshape((X.shape[0], -1))

print("------- X.shape", X.shape)

X_train, X_test, y_train, y_test = train_test_split(
    X, y, train_size=train_samples, test_size=10000)

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# Turn up tolerance for faster convergence
clf = LogisticRegression(
    C=50. / train_samples, penalty='l1', solver='saga', tol=0.1
)
clf.fit(X_train, y_train)

sparsity = np.mean(clf.coef_ == 0) * 100
score = clf.score(X_test, y_test)

# print('Best C % .4f' % clf.C_)
print("Sparsity with L1 penalty: %.2f%%" % sparsity)
print("Test score with L1 penalty: %.4f" % score)
