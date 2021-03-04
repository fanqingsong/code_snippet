import cv2 as cv

# 读图片
img = cv.imread('images/three.png')

# 图片信息
print('图片尺寸:', img.shape)
print('图片数据:', type(img), img)


# 灰度图
img_gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
#cv.imwrite('images/three_gray.png', img_gray)

print("-------------------------- gray")
print('图片尺寸:', img_gray.shape)
print('图片数据:', type(img_gray), img_gray)



# 二值化
_, img_bin = cv.threshold(img_gray, 127, 255, cv.THRESH_BINARY)
#cv.imwrite('images/three_bin.png', img_bin)

print("-------------------------- binary")
print('图片尺寸:', img_bin.shape)
print('图片数据:', type(img_bin), img_bin)


# Resize
img_resized = cv.resize(img_bin, (28,28), interpolation=cv.INTER_AREA)
#cv.imshow('Resized', img)

print("-------------------------- img_resized")
print('图片尺寸:', img_resized.shape)
print('图片数据:', type(img_resized), img_resized)


img_normal = 255 - img_resized


# 保存图片
cv.imwrite('images/three_normal.jpg', img_normal)

print(img_resized.reshape((-1)))

print(img_resized.ravel())