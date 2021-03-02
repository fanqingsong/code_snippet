from hub import Dataset
from pprint import pprint

mnist = Dataset("activeloop/mnist")  # loading the MNIST data lazily
# saving time with *compute* to retrieve just the necessary data

print(type(mnist))
print(dir(mnist))
#pprint(mnist.__dict__)
#
print("-----------------------------------")


data = mnist["image"][0:1000].compute()

print(dir(data))

print(type(data))
print(data.shape)
print(data[0])


data = mnist["label"][0:1000].compute()

print(dir(data))

print(type(data))
print(data.shape)
print(data[0])




