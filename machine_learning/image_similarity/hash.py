from PIL import Image
import imagehash
# hash0 = imagehash.average_hash(Image.open('./images/four.png'))
# hash1 = imagehash.average_hash(Image.open('./images/two.png'))
cutoff = 5

hash0 = imagehash.phash(Image.open('./images/two_1.png'))
hash1 = imagehash.phash(Image.open('./images/two.png'))


print(f"hash0={hash0}")
print(f"hash1={hash1}")


if hash0 - hash1 < cutoff:
  print('images are similar')
else:
  print('images are not similar')