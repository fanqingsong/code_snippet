import paddlehub as hub
import cv2

ocr = hub.Module(name="chinese_ocr_db_crnn_mobile")
result = ocr.recognize_text(images=[cv2.imread('./test2.png')])

print(result)

