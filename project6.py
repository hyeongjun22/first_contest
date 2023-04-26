import csv
import pandas as pd
import numpy as np


book = list()





f=pd.read_csv('책정보.csv','r')
r=csv.reader(f)
next(r)
a=0
for line in r:
    a=a+1
    if line[0] is None:
        next(r)
    elif a%10000==0:
        print(a)

    if a>1000000:
        break;
    
f.close()






    
