import jieba

xsl = open('D:/test1/2.txt','r',encoding='utf-8').read()
words = jieba.lcut(xsl)
counts = {}

for word in words: #分词，统计个数
    if len(word)==1:
        continue
    else:
        counts[word] = counts.get(word,0) + 1

items = list(counts.items())
items.sort(key=lambda x: x[1],reverse=True)

for i in range (30):
    word,count = items[i]
    print ('{0:<5} {1:>5}'.format(word, count))

