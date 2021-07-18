'''
视频帧匹配脚本
'''
import numpy as np
import cv2
from PIL import Image,ImageDraw,ImageFont

# 至少10个点匹配
MIN_MATCH_COUNT = 10
# 完全匹配偏移 d<1
BEST_DISTANCE = 1
# 微量偏移  1<d<10
GOOD_DISTANCE = 10

# 特征点提取方法，内置很多种
algorithms_all = {

    "SIFT": cv2.xfeatures2d.SIFT_create(),
    "SURF": cv2.xfeatures2d.SURF_create(),
    "ORB": cv2.ORB_create()

}

'''
# 图像匹配
# 0完全不匹配 1场景匹配 2角度轻微偏移 3完全匹配
'''
def match2frames(image1, image2):
    img1 = cv2.cvtColor(image1, cv2.COLOR_BGR2GRAY)
    img2 = cv2.cvtColor(image2, cv2.COLOR_BGR2GRAY)

    size1 = img1.shape
    size2 = img2.shape

    img1 = cv2.resize(img1, (int(size1[1] * 0.3), int(size1[0] * 0.3)), cv2.INTER_LINEAR)#
    img2 = cv2.resize(img2, (int(size2[1] * 0.3), int(size2[0] * 0.3)), cv2.INTER_LINEAR)#

    surf = algorithms_all["SIFT"]

    #使用Hessian算法检测关键点，并且对每个关键点周围的区域计算特征向量。
    #返回关键点的 信息 和 描述符
    kp1, des1 = surf.detectAndCompute(img1, None)#输入灰度图
    kp2, des2 = surf.detectAndCompute(img2, None)#输入灰度图

    '''
    蛮力匹配器
    可以采用第一组的一个特征的描述符并且使用一些距离计算与第二组中的所有其它特征匹配。
    将最近的一个返回。
    '''
    bf = cv2.BFMatcher()
    '''
    knnMatch为每个关键点返回k个最佳匹配，其中k是由用户设定的。
    我们使用函数cv2.drawMatchsKnn为每个关键点和它的k个最佳匹配点绘制匹配线。
    如果要选择性绘制就要给函数传入一个掩模。
    '''
    matches = bf.knnMatch(des1, des2, k=2)
    # 过滤
    good = []
    for m, n in matches:
        if m.distance < 0.69 * n.distance:
            good.append(m)
    src_pts = np.float32([kp1[m.queryIdx].pt for m in good]).reshape(-1, 1, 2)#特征点
    dst_pts = np.float32([kp2[m.trainIdx].pt for m in good]).reshape(-1, 1, 2)#特征点

    # 第四个参数取值范围在 1 到 10 , 绝一个点对的阈值。
    # 原图像的点经过变换后点与目标图像上对应点的误差
    # 超过误差就认为是异常值
    # 返回值中 M 为变换矩阵。mask是掩模
    #单应性矩阵是一个3 * 3的矩阵，可以从cv2.findHomography获得
    # H, status = cv2.findHomography(ptsA, ptsB, cv2.RANSAC, 5)
    # src_pts, dst_pts对应两幅图获得的sift特征点
    # 获取变换矩阵，RANSAC算法
    M, mask = cv2.findHomography(src_pts, dst_pts,cv2.RANSAC,5.0)
    # 图像变换，将原图像变换为检测图像中匹配到的形状
    matchesMask = mask.ravel().tolist()
    good = [good[matchesMask.index(i)] for i in matchesMask if i == 1]
    #img3 = cv2.drawMatches(img1, kp1, img2, kp2, good, None)
    good = sorted(good,key=lambda x:x.distance)#根据good字段中的distance进行排序

    if len(good) < MIN_MATCH_COUNT:
        return 0  # 完全不匹配
    # 如果good > 10
    # 则开始求distance
    else:
        good = good[0:MIN_MATCH_COUNT]
        distance_sum = 0  # 特征点2d物理坐标偏移总和
        for m in good:
            distance_sum += get_distance(kp1[m.queryIdx].pt, kp2[m.trainIdx].pt)
        distance = distance_sum / len(good)  # 单个特征点2D物理位置平均偏移量

        if distance < BEST_DISTANCE:# distance < 1
            return 3  # 完全匹配
        elif distance < GOOD_DISTANCE and distance >= BEST_DISTANCE: # distance >= 1 && distance < 10
            return 2  # 部分偏移
        else:
            return 1  # 仅仅场景匹配 # distance >= 10

'''
计算2D物理距离
'''


def get_distance(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return np.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
