# SourceFileAnalyzer

Source Code Authorship Attribution by extracting layout, lexical and syntactical features and classifying them.

### Main steps
- Layout and Lexical feature extraction with Python code
- AST extraction with Clang compiler and output processing (done using Linux OS)
- Classification with Python frameworks:```sklearn``` (also used ``` pandas, numpy```)

## Dataset
Our dataset contains 9 C/C++ source files/100 user from the Google Code Jam 2015 programming competition [(GCJ_Dataset/Data)](https://github.com/kotunde/SourFileAnalyzer_featureSearch_and_classification/tree/master/GCJ_Dataset/Data), and an average of 27 C++ source files/14 user from Sapientia EMTE University [(Sapi_Dataset/Data)](https://github.com/kotunde/SourFileAnalyzer_featureSearch_and_classification/tree/master/Sapi_Dataset/Data).

The main difference between the datasets is that the GCJ users were only given the task to solve, while Sapi users were given the header files too to work with. So the results are more remarkable in the GCJ dataset, since the Sapi codes were similar in structure.

## How it works

### Prerequisites
Install Python 3.x
```
$ sudo apt install python3.7
```
#### Set up Clang compiler
The following link may help with it ( [Setting up Clang](https://eli.thegreenplace.net/2011/07/03/parsing-c-in-python-with-clang#documentation) ).

//TODO
{...}

### Running
#### Layout and Lexical features
Run this script to extract layout and lexical features into a CSV file: [extractAttributes.py](https://github.com/kotunde/SourceFileAnalyzer_featureSearch_and_classification/blob/master/Programs/LL_features/extractAttributes.py).

Don't forget to set the directory path.
```
$ python extractAttributes.py
```
Now we have the layout and lexical feautres in LL_features.csv file, where each column is a feature, except the last, which is the "author", the class itself. Our results: [GCJ L&L Features CSV](https://github.com/kotunde/SourceFileAnalyzer_featureSearch_and_classification/blob/master/GCJ_Dataset/CSV/GCJ_47.csv),  [Sapi L&L Features CSV](https://github.com/kotunde/SourceFileAnalyzer_featureSearch_and_classification/blob/master/Sapi_Dataset/CSV/SAPI_47.csv)

#### Abstract Syntax Trees
We have a bash script which is written for both of the datasets, since they differ in their directory structure ([gcj_data_ast_func.sh](https://github.com/kotunde/SourceFileAnalyzer_featureSearch_and_classification/blob/master/Programs/AST_extraction/gcj_data_ast_func.sh) , [sapi_data_ast_func.sh](https://github.com/kotunde/SourceFileAnalyzer_featureSearch_and_classification/blob/master/Programs/AST_extraction/sapi_data_ast_func.sh)). The script traverses the data directory (given as first parameter) by source files, and creates a second direcory (it's name given as second parameter) with the same directory structure, containing the .ast files with the same name as the respective source file.

**Important!**
In [createAstByFuncName.py](https://github.com/kotunde/SourceFileAnalyzer_featureSearch_and_classification/blob/master/Programs/AST_extraction/createAstByFuncName.py) set the path to installed ```clang-check```
```
$ bash gcj_data_ast_func.sh Data Data_ast
```
or
```
$ bash sapi_data_ast_func.sh Data Data_ast
```
The script creates the ASTs by first extracting the function names from each sourcefile, then creating the AST for each function.

Then run the script named [extractNodes.py] which extracts the nodes from the .ast files and writes the output into an ```extracted_ast_nodes.csv``` named file. Then run the next script in the AST_features folder, namely [normalizeAstOutputFile.py] which will normalize and match the output with the other .csv file (```LL_features.csv```). 

#### Classification
Run Python script to classify the result CSVs with Random Forest Classifier([rfc.py](https://github.com/kotunde/SourceFileAnalyzer_featureSearch_and_classification/blob/master/Programs/Classification/rfc.py)).
Don't forget to set the directory path to the respective CSV file and format the output CSV's header.
```
$ python rfc.py
```
#### Illustration
To illustrate the output CSVs you can use the ```matplotlib.pyplot``` framework.
