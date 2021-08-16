# coding=utf-8
# 版本V1.0，汪跃阳修改于2020年12月19日
# 成都大学只有2017-2020的录取数据

import requests
import pandas as pd
from bs4 import BeautifulSoup

url0 = 'http://zhaosheng.cdu.edu.cn/Handlers/OverTheYears_Data.ashx?id='


# 请求网站获取文本信息
def get_text(target_url):
    headers = {
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,'
                  'application/signed-exchange;v=b3;q=0.9',
        'Accept-Encoding': 'gzip, deflate',
        'Accept-Language': 'zh-CN,zh;q=0.9',
        'Cookie': 'UM_distinctid=17670944e19844-01adfddf72e52c-c791039-144000-17670944e1a427; '
                  'Hm_lvt_b3b075d90cc24dcb1d5795260f02e2d6=1608206544; ASP.NET_SessionId=ovezoxhez4e1kk2jc5fepbag',
        'DNT': '1',
        'Host': 'zhaosheng.cdu.edu.cn',
        'Proxy-Connection': 'keep-alive',
        'Referer': 'http://zhaosheng.cdu.edu.cn/',
        'Upgrade-Insecure-Requests': '1',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                      'Chrome/87.0.4280.88 Safari/537.36'
    }
    try:
        r = requests.get(target_url, headers=headers, timeout=30)
        r.raise_for_status()
        return r.text
    except Exception as e:
        print(e, "无法连接")


# 解析网页, 获取文本信息
def bs4_process(url1):
    soup = BeautifulSoup(get_text(url1), 'lxml')  # 使用bs4函数
    list_raw = list(soup.text.split())  # 获得soup的text, 并去除text的换行与空格, 生成一个列表list_raw
    # 以下操作为处理list_raw, 去除一些无用信息
    j0 = 0
    i0 = len(list_raw) - 1
    while i0 >= 0:
        if j0 == 3:
            while not (u'\u4e00' <= list_raw[i0] <= u'\u9fff'):
                del list_raw[i0]
                i0 = i0 - 1
            else:
                j0 = -4
                continue
        j0 = j0 + 1
        i0 = i0 - 1
    return list_raw


# 处理bs4_process()函数得到的列表, 生成并合并成规范的复合列表
def list_process(list_raw):
    list_info = []
    j1 = 0
    list_temp = []
    for i1 in list_raw:
        if j1 == 7:
            list_info.append(list_temp[::])
            list_temp.clear()
            j1 = 0
        list_temp.append(i1)
        j1 = j1 + 1
    return list_info


# 根据得到的规范的复合列表, 生成csv文件并print出来
def get_csv():
    year_id = ['37', '35', '39', '40']
    for i in year_id:
        url = url0 + i
        list_temp1 = bs4_process(url)
        if i == '37' or i == '39':
            del list_temp1[4]
            del list_temp1[4]
        elif i == '40':
            del list_temp1[4]
            del list_temp1[4]
            del list_temp1[4]
        list_temp1 = list_process(list_temp1)
        list_temp2 = list_temp1[0]
        del list_temp1[0]
        df = pd.DataFrame(columns=list_temp2, data=list_temp1)
        if i == '37':
            df.insert(0, '年份', '2017年')
        elif i == '35':
            df.insert(0, '年份', '2018年')
        elif i == '39':
            df.insert(0, '年份', '2019年')
        elif i == '40':
            df.insert(0, '年份', '2020年')
        print(df)
        df.to_csv('09019203汪跃阳-成都大学.csv', index=False, mode='a')


if __name__ == '__main__':
    get_csv()
