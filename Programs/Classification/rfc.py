# Random Forest k-fold Cross-validation
# https://scikit-learn.org/stable/modules/cross_validation.html
# 
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import cross_val_score, cross_validate
from sklearn.metrics import confusion_matrix
from sklearn import metrics
import os
import re
import pandas as pd
import numpy as np
# 

# used for reproducibility 
RANDOM_STATE = 0

#input file path
filename = 'yourDirectory/SAPI_47.csv'
#filename = 'yourDirectory/SAPI_AST_U.csv'
#filename = 'yourDirectory/SAPI_AST_B.csv'
#.
#.
#.

data = pd.read_csv(filename)
df = pd.DataFrame(data)

# number of lines and number of columns
num_samples, num_features = df.shape

# the last column is userid
num_features = num_features - 1

array = df.values
# Features
X = array[:,0:num_features]
# Class ids (userids)
y = array[:, -1]
 
#initialization
model = RandomForestClassifier(n_estimators = 100, random_state=RANDOM_STATE)
scoring = ['accuracy']
num_folds = 3
#classifier result
scores = cross_validate(model, X, y, scoring=scoring, cv=num_folds) 

#file which the data will be saved to
csv_file = "yourDirectory/SAPI_RFC.csv"

index_counter = 1

#format csv header
#res_list = {'Classifier':"",'Fold 1':0,'Fold 2':0, 'Fold 3':0,'Fold 4':0,'Fold 5':0,'Fold 6':0,'Fold 7':0,'Fold 8':0,'Fold 9':0,'Fold 10':0, 'Avg': 0, 'Std':0 }
#csv_columns = ['classifier','fold_1','fold_2','fold_3','fold_4','fold_5','fold_6','fold_7','fold_8','fold_9','fold_10','average_accuracy','std_accuracy']

res_list = {'Feature_set':0,'Accuracy':0}
csv_columns = ['featureSet','accuracy']

#print results
print(str(num_folds)+'-fold cross-validation results: ')
for i in range(0,num_folds):
    print('\tFold '+str(i+1)+':' + str(scores['test_accuracy'][ i ]))
    

print('Avearage[accuracy]: '+str(np.average( scores['test_accuracy'] )))
print('Std[accuracy]: '+str(np.std( scores['test_accuracy'] )))

#this will be the actual line in our csv file
res_list['Feature_set'] = 'Sapi_47'      
res_list['Accuracy'] = np.average( scores['test_accuracy'] )

df=pd.DataFrame(res_list,index=[index_counter])
#for the first time, we need to initialize our csv with header
df.to_csv(csv_file,mode = 'w', header = csv_columns, index = False)
#then we append the rest of the data
#df.to_csv(csv_file,mode = 'a', header = False, index = False)
