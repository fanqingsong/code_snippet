from skimage.measure import compare_ssim
from scipy.misc import imread
import numpy as np
import cv2



# 3. Load the two input images
imageA = cv2.imread('./images/four.png')
imageB = cv2.imread('./images/two_1.png')

# 4. Convert the images to grayscale
grayA = cv2.cvtColor(imageA, cv2.COLOR_BGR2GRAY)
grayB = cv2.cvtColor(imageB, cv2.COLOR_BGR2GRAY)

#
# cv2.imshow("grayA", grayA)


# 二值化
_, imgA_bin = cv2.threshold(grayA, 127, 255, cv2.THRESH_BINARY_INV)
#cv.imwrite('images/three_bin.png', img_bin)

#
# cv2.imshow("img_bin", img_bin)

#
# print("-------------------------- binary")
# print('图片尺寸:', img_bin.shape)
# print('图片数据:', type(img_bin), img_bin)
#
#
# cv2.waitKey(0)

_, imgB_bin = cv2.threshold(grayB, 127, 255, cv2.THRESH_BINARY_INV)


#grayB = np.resize(grayB, (grayA.shape[0], grayA.shape[1], grayA.shape[2]))

ssim = compare_ssim(imgA_bin, imgB_bin, multichannel = False)
print(ssim)


