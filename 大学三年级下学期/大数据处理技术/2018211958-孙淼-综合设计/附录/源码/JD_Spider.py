# coding='utf-8'
import requests
import json
import time
import random
import xlwt
import xlutils.copy
import xlrd

def start(page):
    # 获取URL
    #score 评价等级 page=0 第一页 producitid 商品类别

    url = 'https://club.jd.com/comment/productPageComments.action?&productId=12109713&score=0&sortType=5&'+'page='+ str(page) +'&pageSize=10&isShadowSku=0&fold=1'

    # url = 'https://club.jd.com/comment/productPageComments.action?&productId=12109713&score=0&sortType=5&page=0&pageSize=10&isShadowSku=0&fold=1'
    headers= {
        "User-Agent": "Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.198 Mobile Safari/537.36"
    }
    time.sleep(2)
    test = requests.get(url=url, headers= headers)
    #data = json.loads(test)#loads?
    data = test.json()
    return data
    # 解析页面
def parse(data):

    items = data['comments']
    for i in items:
        yield (
            i['nickname'],#用户名自
            i['id'], #用户id
            i['content'],#内容
            i['creationTime']#时间
        )

def excel(items):
    #第一次写入
    newTable = "test.xls"#创建文件
    wb = xlwt.Workbook("encoding='utf-8")

    ws = wb.add_sheet('sheet1')#创建表
    headDate = ['id', '内容', '时间']#定义标题
    for i in range(0,3):#for循环遍历写入
        ws.write(0, i, headDate[i], xlwt.easyxf('font: bold on'))

    index = 1#行数

    for data in items:#items是十条数据 data是其中一条（一条下有三个内容）
        for i in range(0,3):#列数

            print(data[i])
            ws.write(index, i, data[i])#行 列 数据（一条一条自己写入）
        print('______________________')
        index += 1#等上一行写完了 在继续追加行数
        wb.save(newTable)

def another(items, j):#如果不是第一次写入 以后的就是追加数据了 需要另一个函数

    index = (j-1) * 10 + 1#这里是 每次写入都从11 21 31..等开始 所以我才传入数据 代表着从哪里开始写入

    data = xlrd.open_workbook('test.xls')
    ws = xlutils.copy.copy(data)
    # 进入表
    table = ws.get_sheet(0)

    for test in items:

        for i in range(0, 3):#跟excel同理
            print(test[i])

            table.write(index, i, test[i])  # 只要分配好 自己塞入
        print('_______________________')

        index += 1
        ws.save('test.xls')



def main():
    j = 1#页面数
    judge = True#判断写入是否为第一次

    for i in range(0, 101):
        time.sleep(1.5)
        #time反爬 因为京东有反爬
        first = start(j)
        test = parse(first)

        if judge:
            excel(test)
            judge = False
        else:
            another(test, j)
        print('第' + str(j) + '页抓取完毕\n')
        j = j + 1


if __name__ == '__main__':
    main()
    #上述代码仅为全部数据下的评论 需要爬取中差评等修改score即可