import csv
from random import randint 
from datetime import datetime, timedelta
import codecs
sex=list()
grade=list()
book=list()

f = open("도서관최종데이터편집.csv",'r')
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

f = open("도서관최종데이터편집.csv",'r')

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



f1 = open("projecttest.csv",'w',encoding='cp949',newline='')
w = csv.writer(f1)

for i in range(len(alist)) :
    w.writerow(alist[i])



f1.close()
print(book)
