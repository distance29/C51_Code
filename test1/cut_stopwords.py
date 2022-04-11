import jieba

# 创建一个停用词列表stop_words.txt
def stopwordslist():
    stopwords = [line.strip() for line in open('D://test1/stop_words.txt',encoding='UTF-8').readlines()]
    return stopwords

# 对所有评论进行中文分词，去掉停用词
def seg_depart(sentence):
    print("——正在分词，请稍等")
    sentence_depart = jieba.cut(sentence.strip())
    stopwords = stopwordslist()
    outstr = ''
    # 去掉停用词
    for word in sentence_depart:
        if word not in stopwords:
            if word != '\t':
                outstr += word
                outstr += " "
    return outstr

# 评论文档的路径
filename = "D://test1/comment(3).csv"
outfilename = "2.txt" #分词
inputs = open(filename, 'r', encoding='UTF-8')
outputs = open(outfilename, 'w', encoding='UTF-8')

# 将输出结果写入2.txt中 
for line in inputs:
    line_seg = seg_depart(line)
    outputs.write(line_seg + '\n')
    print("=====正在对评论进行分词和去掉停用词，请等待=====")
outputs.close()
inputs.close()
print("删除停用词和分词成功！！！")