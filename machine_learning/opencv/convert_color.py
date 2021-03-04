import numpy as np
import cv2 as cv

# 读图片
img = cv.imread('images/Lenna.jpg')

print("-------------------------- origin")
print('图片尺寸:', img.shape)
print('图片数据:', type(img), img)


# 灰度图
img_gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imwrite('images/Lenna_gray.png', img_gray)

print("-------------------------- gray")
print('图片尺寸:', img_gray.shape)
print('图片数据:', type(img_gray), img_gray)



# 二值化
_, img_bin = cv.threshold(img_gray, 127, 255, cv.THRESH_BINARY)
cv.imwrite('images/Lenna_bin.png', img_bin)

print("-------------------------- binary")
print('图片尺寸:', img_bin.shape)
print('图片数据:', type(img_bin), img_bin)


# 平滑
img_blur = cv.blur(img, (5, 5))
cv.imwrite('images/Lenna_blur.png', img_blur)

print("-------------------------- blur")
print('图片尺寸:', img_blur.shape)
print('图片数据:', type(img_blur), img_blur)



# 边缘提取
# _, contours, _ = cv.findContours(img_bin, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
#
# img_cont = np.zeros(img_bin.shape, np.uint8)
# cv.drawContours(img_cont, contours, -1, 255, 2)
# cv.imwrite('images/Lenna_cont.png', img_cont)
#
# print("-------------------------- contour")
# print('图片尺寸:', img_cont.shape)
# print('图片数据:', type(img_cont), img_cont)


