import os
import time
import json
import random
import re

import jieba
import requests
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt
from wordcloud import WordCloud

# 词云形状图片
WC_MASK_IMG = 'comment.jpg'
# 调用进行分词后保存的文件
COMMENT_FILE_PATH = 'D://test1/2.txt'

WC_FONT_PATH = 'simsun.ttc' #词云的字体


def cut_word():
    """
    对数据分词，有重复，可省略
    :return: 分词后的数据
    """
    with open(COMMENT_FILE_PATH, encoding='UTF-8') as file:
        comment_txt = file.read()
        wordlist = jieba.cut(comment_txt, cut_all=True)
        wl = " ".join(wordlist)
        print(wl)
        return wl


def create_word_cloud():
    """
    生成词云
    :return:
    """
    # 设置词云形状图片
    wc_mask = np.array(Image.open(WC_MASK_IMG))
    # 设置词云的配置
    wc = WordCloud(background_color="white", max_words=2500, mask=wc_mask, scale=4,
                   max_font_size=100, random_state=42, font_path=WC_FONT_PATH)
    # 生成词云
    wc.generate(cut_word())
    # 在只设置mask的情况下,你将会得到一个拥有图片形状的词云
    plt.imshow(wc, interpolation="bilinear")
    plt.axis("off")
    plt.figure()
    plt.show()
    wc.to_file("comment_ciyun.jpg")



if __name__ == '__main__':

    #生成词云
    create_word_cloud()
