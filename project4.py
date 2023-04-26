import csv
from random import randint 
from datetime import datetime, timedelta
import codecs
sex=list()
grade=list()
book=list()

f = open("도서관대출자료편집.csv",'r')
r= csv.reader(f)

next(r)

alist=list()
a=0
overlap=0

for line in r :
    overlap = 0
    for i in range(len(alist)) :
        if line[1] ==alist[i][1]:
            if line[3] == alist[i][3]:
                if line[6] == alist[i][6]:
                    if line[7] == alist[i][7]:
                        overlap = 1
                
    if overlap == 0  :      
        alist.append(line)
f.close()

f = open("도서관대출자료편집.csv",'r')

r = csv.reader(f)

next(r)

user = list()

for line in r :
    overlap = 0
    for i in range(len(user)) :
        if line[1] == user[i] :
          overlap = 1
    if overlap == 0 :
       user.append(line[1])
       sex.append(str(randint(0,1)))
       grade.append(str(randint(1,3)))
       
f.close()


f = open("도서관대출자료편집.csv",'r')

r = csv.reader(f)

next(r)

user = list()

for line in r :
    for i in range(len(user)) :
        
       
f.close()





f = open("도서관대출자료편집.csv",'r')
r= csv.reader(f)

for j in range(len(alist)):
    for i in range(len(user)):
        if alist[j][1]== user[i]:
            alist[j].append(sex[i])
            alist[j].append(grade[i])

for i in range(len(alist)):
    time = alist[i][6].split(".",3)
    time1 = alist[i][7].split(".",3)
        
    t1 = datetime(int(time[0]), int(time[1]), int(time[2]), 0, 0, 0)
    t2 = datetime(int(time1[0]), int(time1[1]), int(time1[2]), 0, 0, 0)
    alist[i].append((t2-t1).days) #독자들 읽는데 걸린 시간

    if alist[i][10] > 14 :
        alist[i].append('1')
    else:
        alist[i].append('0')

f1 = open("도서관자료모음.csv",'w',encoding='cp949',newline='')
w = csv.writer(f1)

for i in range(len(alist)) :
    w.writerow(alist[i])



f1.close()
print(book)


