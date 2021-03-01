from hub import Dataset
import torch

mnist = Dataset("activeloop/mnist")
# converting MNIST to PyTorch format
mnist = mnist.to_pytorch(lambda x: (x["image"], x["label"]))

train_loader = torch.utils.data.DataLoader(mnist, batch_size=1, num_workers=0)

for image, label in train_loader:
    # Training loop here
    print("----------------------")
    print(image)
    print(label)
