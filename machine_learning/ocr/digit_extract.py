import cv2 as cv
import numpy as np
import imutils
from imutils.contours import sort_contours

def grayify(image):
    return cv.cvtColor(image, cv.COLOR_BGR2GRAY)


def thresholding_inv(image):
    gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY)

    ret, bin = cv.threshold(gray, 48, 255, cv.THRESH_BINARY_INV)
    bin = cv.medianBlur(bin, 3)

    return bin


if __name__ == "__main__":
    img = cv.imread('865.origin.png')  # get grayscale image

    # binary_img = thresholding_inv(img)
    # cv.imshow("binary img", binary_img)
    # cv.waitKey(0)

    gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
    cv.imshow('Gray', gray)

    blur = cv.GaussianBlur(gray, (5, 5), cv.BORDER_DEFAULT)
    cv.imshow('Blur', blur)

    canny = cv.Canny(blur, 125, 175)
    cv.imshow('Canny Edges', canny)

    contours, hierarchies = cv.findContours(canny, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
    print(f'{len(contours)} contour(s) found!')

    blank = np.zeros(img.shape)
    cv.drawContours(blank, contours, -1, (0,0,255), 1)
    cv.imshow('Contours Drawn', blank)

    # cnts = imutils.grab_contours(contours)
    cnts = sort_contours(contours, method="left-to-right")[0]

    img_cpy = img.copy()

    count = 0
    for cnt in cnts:
        x, y, w, h = cv.boundingRect(cnt)

        rect = cv.rectangle(img_cpy, (x, y), (x+w, y+h), (0, 255, 0), 2)

        cropped = img[y:y+h, x:x+w]
        cv.imshow(f"cropped-{count}", cropped)
        count = count + 1

    cv.imshow("captured image", img_cpy)

    cv.waitKey(0)




