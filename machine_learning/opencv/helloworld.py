import cv2 as cv

# 读图片
img = cv.imread('images/Lenna.jpg')

# 图片信息
print('图片尺寸:', img.shape)
print('图片数据:', type(img), img)

# 显示图片
#cv.imshow('pic title', img)
#cv.waitKey(0)
# 添加文字
cv.putText(img, 'Learn Python with Crossin', (50, 150), cv.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 4)
# 保存图片
cv.imwrite('images/Lenna_new.jpg', img)