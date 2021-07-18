dic_new = {}
file = open("result_news.txt", 'r', encoding="utf-8")#读入语料库字典
for line in file.readlines():
    s = line.strip().split(" ") #strip()方法用于移除字符串头尾指定的字符(默认为空格或换行符)
    k = s[0]
    v = s[1]
    dic_new[k] = v
print("请输入字符串\n")
strs = input()


def FMM(sentence, dic):#FMM算法
    sentence = sentence.strip() #去掉输入字符串的换行符
    length = 2 #每次取2个字
    result = []
    while not len(sentence) is 0 :
        temp_sen = sentence[:length] #对前2个字研究
        while not dic.__contains__(temp_sen): #判断所取词是否在字典内
            if len(temp_sen) > 1:#如果不在，继续对前1个字进行研究
                temp_sen = temp_sen[:-1]
            else:
                break
        result.append(temp_sen + "/")
        sentence = sentence[len(temp_sen):] #新的取词：删去前面已经匹配的词，对后面进行匹配
    return result

def BMM(sentence, dic):#BMM算法
    sentence = sentence.strip() #去掉字符串的换行符
    length = 2
    result = []
    while not len(sentence) is 0:
        temp_sen = sentence[len(sentence)-length:]#对后2个字进行研究
        while not  dic.__contains__(temp_sen): #判断所取词是否在字典内
            if len(temp_sen) > 1:
                temp_sen = temp_sen[1:]#如果不在，继续对后1个字进行研究
            else:
                break
        result.append(temp_sen+"/")
        sentence = sentence[:len(sentence)-len(temp_sen)]#新的取词：删去后面已经匹配的词，对前面进行匹配
    return result[::-1]

print("FMM:"+''.join(FMM(strs,dic_new)))
print("BMM:"+''.join(BMM(strs,dic_new)))





