import csv
from sklearn.model_selection import train_test_split
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
import numpy as np


a=str(input())  #읽을 책
b=str(input())  #성별
c=str(input())  #학년
time=0 #반납기간


data=list()
data.append(float(b))
data.append(float(c))



nooverdue = 1


while nooverdue == 1:
    trainset=list()
    testset=list()
    
    overlap=0
    time=time+1
    f = open("projecttest.csv" ,'r')
    r=csv.reader(f)

    next(r)


    for line in r:
        if a == line[0]:
            if  int(line[4]) > time :
                line[3] = 1
            else:
                line[3] = 0
                overlap=1
            tem=list()
            tem1=list()
            tem.append(line[1])
            tem.append(line[2])
            tem.append(line[3])
            tem1.append(line[1])
            tem1.append(line[2])
            trainset.append(tem)
            testset.append(tem1)
    f.close()
    if overlap ==0:
        continue
    f = open('ptrain.csv','w',encoding='cp949',newline='')
    w = csv.writer(f)
    cot=['sex','grade','overdue']
    w.writerow(cot)
    for i in range(len(trainset)):
        w.writerow(trainset[i])
    f.close()
    f = open('ptest.csv','w',encoding='cp949',newline='')
    w = csv.writer(f)
    cot=['sex','grade']
    w.writerow(cot)
    for i in range(len(trainset)):
        w.writerow(testset[i])
    f.close()
    


    ptrain = pd.read_csv("ptrain.csv")

    features = ptrain[['sex', 'grade']]

    survival = ptrain['overdue']

    ptrain_features, ptest_features, ptrain_labels, ptest_labels = train_test_split(features, survival)

    scaler = StandardScaler()

    ptrain_features = scaler.fit_transform(ptrain_features)
    ptest_features = scaler.transform(ptest_features)

    model = LogisticRegression()
    model.fit(ptrain_features, ptrain_labels)

    print(model.score(ptrain_features, ptrain_labels))


 
    ME = np.array(data)
    sample_ptrain = np.array([ME])
    sample_ptrain = scaler.transform(sample_ptrain)

    print(model.predict(sample_ptrain))
    nooverdue=int(model.predict(sample_ptrain))
    print(model.predict_proba(sample_ptrain))
    print(time)

    
