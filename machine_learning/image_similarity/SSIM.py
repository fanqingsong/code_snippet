from skimage.measure import compare_ssim
from scipy.misc import imread
import numpy as np
import cv2



# 3. Load the two input images
imageA = cv2.imread('./images/two.png')
imageB = cv2.imread('./images/two_1.png')

# 4. Convert the images to grayscale
grayA = cv2.cvtColor(imageA, cv2.COLOR_BGR2GRAY)
grayB = cv2.cvtColor(imageB, cv2.COLOR_BGR2GRAY)
#
# grayB = np.resize(grayB, (grayA.shape[0], grayA.shape[1], grayA.shape[2]))

ssim = compare_ssim(grayA, grayB, multichannel = False)
print(ssim)


