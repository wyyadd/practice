# coding=utf-8
# 版本V1.0，汪跃阳修改于2020年12月6日

import random
import copy
import pandas as pd


class Rolls:
    def calls(self):
        num = int(input("请输入点名人数:"))
        if isinstance(num, int):  # 边界条件判断
            if num > len(self.list_data) or num <= 0:
                print("你输入的范围超出--error")
                return -1
        else:
            print("error")
            return -1
        random_call = [random.randint(0, len(self.list_data) - 1) for _ in range(num)]  # 产生随机数
        print("点名结果:")
        for i2 in random_call:
            print(i2, self.list_data[i2])

    def __init__(self):
        self.list_alldata = pd.read_csv('../09005424孔祥龙/python.csv', encoding="gbk",
                                        header=None).values.tolist()  # 读取python.csv文件
        self.list_checked = self.split_checked(pd.read_csv('../09005424孔祥龙/checked.csv', encoding="gbk",
                                                           header=None).values.tolist())  # 读取checked.csv,并规格化处理
        self.list_data = self.make_subtract(self.list_alldata, self.list_checked)  # 操作已得到的两个列表,得到需点名同学的列表

    def split_checked(self, list_temp):  # 规格化处理checked.csv,便于后续操作(此步可删去)
        for i in list_temp:
            del i[-1]  # 删除点名的次数
        return list_temp

    def make_subtract(self, list_temp1, list_temp2):  # 用包含所有同学的列表减去已经点名过的同学的列表
        list_temp0 = copy.deepcopy(list_temp1)  # 深拷贝, 便于后续需操作(可删去)
        list_num = []  # 创建一个列表,记录需要删除的位置
        for i0 in range(len(list_temp0)):
            for j0 in range(len(list_temp2)):
                if list_temp0[i0][0] == list_temp2[j0][0]:
                    list_num.append(i0)  # 记录列表中哪个文件需要删除
                    continue
        list_num.sort(reverse=True)
        for i1 in list_num:
            del list_temp0[i1]  # 删除
        return list_temp0  # 返回点名列表


test = Rolls()
test.calls()
