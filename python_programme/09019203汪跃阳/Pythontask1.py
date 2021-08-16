import random
import time
start=time.time()
l=list()
for i in range(10):
    l.append(random.randint(0,100))  #生成列表l
print("Operation\tSenconds")
for i in range(1000000):  #测试+运算符
    l1=l[::]
    l1=l+[0]
second=round(time.time()-start,3)
print("Plus:\t",second)
start=time.time()
for i in range(1000000):#测试append
    l1=l[::]
    l1.append(0)
second=round(time.time()-start,3)
print("Append:\t",second)
start=time.time()
for i in range(1000000):#测试extend
    l1=l[::]
    l1.extend([0])
second=round(time.time()-start,3)
print("Extend:\t",second)
start=time.time()
for i in range(1000000):#测试insert头
    l1=l[::]
    l1.insert(0,0)
second=round(time.time()-start,3)
print("TopInsert:\t",second)
start=time.time()
for i in range(1000000):#测试insert尾
    l1=l[::]
    l1.insert(10,0)
second=round(time.time()-start,3)
print("BottomInsert:\t",second)
start=time.time()
for i in range(1000000):#测试*
    l1=l[::]
    l1*=2
second=round(time.time()-start,3)
print("Multiply:\t",second)
start=time.time()
for i in range(1000000):#测试del头
    l1=l[::]
    del l1[0]
second=round(time.time()-start,3)
print("TopDel:\t",second)
start=time.time()
for i in range(1000000):#测试del尾
    l1=l[::]
    del l1[-1]
second=round(time.time()-start,3)
print("BottomDel:\t",second)
start=time.time()
for i in range(1000000):#测试pop头
    l1=l[::]
    l1.pop(0)
second=round(time.time()-start,3)
print("TopPop:\t",second)
start=time.time()
for i in range(1000000):#测试pop尾
    l1=l[::]
    l1.pop(-1)
second=round(time.time()-start,3)
print("BottomPop:\t",second)
start=time.time()
for i in range(1000000):#测试remove头
    l1=l[::]
    l1.remove(l1[0])
second=round(time.time()-start,3)
print("TopRemove:\t",second)
start=time.time()
for i in range(1000000):#测试remove尾
    l1=l[::]
    l1.remove(l1[-1])
second=round(time.time()-start,3)
print("BottomRemove:\t",second)