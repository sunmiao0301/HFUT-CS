'''
摄像机角度偏移告警
'''
from datetime import time, datetime

import cv2
import do_match
import numpy as np
from PIL import Image, ImageDraw, ImageFont

'''
告警信息
'''

texts = ["Occlusion", "Severe deviation!", "deviation", "No offset"]
#texts = ["视频遮挡或严重偏移"], ["严重偏移"], ["轻微偏移"], ["无偏移"]
cap = cv2.VideoCapture('D:\\video.mp4')

if (cap.isOpened() == False):
    print("Error opening video stream or file")

first_frame = True
pre_frame = 0

index = 0

while (cap.isOpened()):
    '''
    ret, frame = cap.read()返回值含义：
    参数ret 为True 或者False,代表有没有读取到图片
    第二个参数frame表示截取到一帧的图片
    是该帧图像的三维矩阵BGR形式。
    '''
    ret, frame = cap.read()

    #cv2.imshow("Initial",frame)
    if ret == True:#读取到图片
        if first_frame:#如果是第一帧
            pre_frame = frame
            first_frame = False
            continue

        index += 1
        if index % 2 == 0:#间隔
            time1 = datetime.utcnow().microsecond
            result = do_match.match2frames(pre_frame, frame)#将得到result
            time2 = datetime.utcnow().microsecond
            print(str(time2 - time1))#显示这两帧处理需要的时间
            #result = 1;
            print("检测结果===>", texts[result])

            if result == 0:#前后两张图片不满足匹配条件
                pre_frame = frame
            size = frame.shape

            if size[1] > 720:  # 缩小显示
                frame = cv2.resize(frame, (int(size[1] * 0.5), int(size[0] * 0.5)), cv2.INTER_LINEAR)

            text_frame = cv2.putText(frame, texts[result], (123,456),cv2.FONT_HERSHEY_PLAIN, 2, (0,255,0), 3)#

            cv2.imshow('result', text_frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):#1为参数，单位毫秒ms，表示读帧间隔时间 按q键退出
            break
    else:
        break

cap.release()
cv2.destroyAllWindows()
