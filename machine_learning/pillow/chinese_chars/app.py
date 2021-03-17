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

        yield Image.open(one_background_image_path).resize(image_size)


def draw_char_on_image(char_image, char, font_path):
    font_size = np.random.randint(height // 2, height // 6 * 5)

    font = ImageFont.truetype(font_path, font_size, encoding="utf-8")

    draw = ImageDraw.Draw(char_image)

    r, g, b = np.random.randint(150, 255), np.random.randint(150, 255), np.random.randint(150, 255)
    rgb = (r, g, b)
    xy = ((height - font_size) // 2, (width - font_size) // 2)
    draw.text(xy, char, rgb, font=font)


def shear_image(char_image):
    theta = np.random.randint(-15, 15) * np.pi / 180

    m_shear = np.array([[1, np.tan(theta), 0], [0, 1, 0]], dtype=np.float32)

    image_shear = cv2.warpAffine(np.array(char_image), m_shear, image_size)

    char_image = Image.fromarray(image_shear)

    return char_image


def make_char_image_generator(char, n=3):
    font_paths = gb.glob(os.path.join(font_dir, "*"))
    print(font_paths)

    font_count = len(font_paths)
    while True:
        if n <= 0:
            break
        else:
            n -= 1

        char_image = Image.fromarray(np.zeros(image_shape, dtype="u1"))

        font_path = font_paths[np.random.randint(font_count)]
        draw_char_on_image(char_image, char, font_path)

        char_image = char_image.rotate(np.random.randint(-100, 100))

        char_image = char_image.filter(ImageFilter.GaussianBlur(radius=0.7))

        char_image = shear_image(char_image)

        yield char_image


def get_all_chars(chars_file):
    with open(chars_file, 'r', encoding="utf-8") as fh:
        all_chars = fh.read()
        print(all_chars)

        return all_chars


def prepare_one_char_dir(one_char):
    char_dir = os.path.join(output_dir, one_char)

    if not os.path.exists(char_dir):
        os.makedirs(char_dir)

    return char_dir


def main():
    prepare_output_dir()

    all_chars = get_all_chars(chars_file)
    for i, one_char in enumerate(all_chars):
        print(f"{i} word is {one_char}")

        char_dir = prepare_one_char_dir(one_char)

        char_image_generator = make_char_image_generator(one_char, n=10)
        background_generator = make_background_generator()

        char_and_background_generator = zip(char_image_generator, background_generator)

        for index, (char, back) in enumerate(char_and_background_generator):
            img_blended = np.array(char) // 5 * 3 + np.array(back) // 5 * 2

            img_path = os.path.join(char_dir, str(index) + ".jpg")
            img = Image.fromarray(img_blended)
            img.save(img_path, "JPEG")


height, width = 64, 64
image_size = (height, width)
image_shape = (*image_size, 3)

output_dir = "output"
background_dir = "background"
font_dir = "font"
chars_file = "all.txt"

if __name__ == "__main__":
    main()
