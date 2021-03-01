from hub import Dataset

mnist = Dataset("activeloop/mnist")  # loading the MNIST data lazily
# saving time with *compute* to retrieve just the necessary data
mnist["image"][0:1000].compute()