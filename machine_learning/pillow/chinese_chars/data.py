from PIL import Image, ImageDraw, ImageFont, ImageFilter
import numpy as np
import glob as gb
import shutil
import cv2
import os


def prepare_output_dir():
    if not os.path.exists(output_dir):
        os.mkdir(output_dir)
        return

    shutil.rmtree(output_dir)
    os.makedirs(output_dir)


def make_background_generator():
    background_image_paths = gb.glob(os.path.join(background_dir, "*"))

    background_image_count = len(background_image_paths)
    
    while True:
        background_image_index = np.random.randint(background_image_count)
        one_background_image_path = background_image_paths[background_image_index]
        yield Image.open(one_background_image_path).resize(font_size)


def make_char_image_generator(char, n=3):
    ziti_paths = gb.glob(os.path.join(font_dir, "*"))
    print(ziti_paths)

    ziti_total = len(ziti_paths)
    while True:
        if n <= 0:
            break
        else:
            n -= 1

        # 添加字
        _img = Image.fromarray(np.zeros(hanzi_shape, dtype="u1"))

        ziti_size = np.random.randint(height // 2, height // 6 * 5)

        font = ImageFont.truetype(ziti_paths[np.random.randint(ziti_total)], ziti_size, encoding="utf-8")

        r, g, b = np.random.randint(150, 255), np.random.randint(150, 255), np.random.randint(150, 255)

        draw = ImageDraw.Draw(_img)
        draw.text(((height-ziti_size)//2, (width-ziti_size)//2), char, (r, g, b), font=font)

        # 若不使用旋转可注释掉
        _img = _img.rotate(np.random.randint(-100, 100))
        # 若不使用模糊可注释掉
        _img = _img.filter(ImageFilter.GaussianBlur(radius=0.7))
        # 若不使用错切可注释掉
        theta = np.random.randint(-15, 15) * np.pi / 180
        M_shear = np.array([[1, np.tan(theta), 0], [0, 1, 0]], dtype=np.float32)
        _img = Image.fromarray(cv2.warpAffine(np.array(_img), M_shear, font_size))
        yield _img


def get_all_chars(chars_file):
    with open(chars_file, 'r', encoding="utf-8") as fh:
        all_chars = fh.read()
        print(all_chars)
        return all_chars


def prepare_one_char_dir(one_char):
    char_dir = os.path.join(output_dir, one_char)

    if not os.path.exists(char_dir):
        os.makedirs(char_dir)


def main():
    prepare_output_dir()

    all_chars = get_all_chars()
    for i, one_char in enumerate(all_chars):
        print(f"{i} word is {one_char}")

        prepare_one_char_dir(one_char)

        char_image_generator = make_char_image_generator(one_char, n=10)
        background_generator = make_background_generator()

        char_and_background_generator = zip(char_image_generator, background_generator)

        for index, (char, back) in enumerate(char_and_background_generator):
            img = Image.fromarray(np.array(char) // 5 * 3 + np.array(back) // 5 * 2)
            img_path = os.path.join(char_dir, str(index) + ".jpg")
            img.save(img_path, "JPEG")


height, width = 64, 64
font_size = (height, width)
hanzi_shape = (height, width, 3)

output_dir = "output"
background_dir = "background"
font_dir = "font"

if __name__ == "__main__":
    main()
