# SourceFileAnalyzer

Source Code Authorship Attribution by extracting layout, lexical and syntactical features and classifying them.

### Main steps
- Layout and Lexical feature extraction with Python code
- AST extraction with Clang compiler and output processing (solved on Linux OS)
- Classification with Python frameworks

## Dataset
Our dataset contains 9 C/C++ source file/100 user from the Google Code Jam 2015 programming competition [(GCJ_Dataset/Data)](https://github.com/kotunde/SourFileAnalyzer_featureSearch_and_classification/tree/master/GCJ_Dataset/Data), and an average 27 C++ source file/14 user from Sapientia EMTE University [(Sapi_Dataset/Data)](https://github.com/kotunde/SourFileAnalyzer_featureSearch_and_classification/tree/master/Sapi_Dataset/Data).

The main difference between the datasets is that the GCJ users were only given the task to solve, while Sapi users were given the header files too to work with. So the results are more remarkable at the GCJ dataset, since the Sapi codes were similar in structure.

## How it works

### Prerequisites
Install Python 3.x
```
sudo apt install python3.7
```
#### Set up Clang compiler
The following link may help with it ( [Setting up Clang](https://eli.thegreenplace.net/2011/07/03/parsing-c-in-python-with-clang#documentation) ).
{...}

### Running
#### Layout and Lexical features
Run the first script to extract layout and lexical features into a CSV file: [extractAttributes.py](https://github.com/kotunde/SourceFileAnalyzer_featureSearch_and_classification/blob/master/Programs/LL_features/extractAttributes.py).

Don't forget to set the directory path.
```
python extractAttributes.py
```
Now we have the layout and lexical feautres in test_data.csv file, where each column is a feature, except the last, which is the "author", the class itself. Our results: [GCJ L&L Features CSV](https://github.com/kotunde/SourceFileAnalyzer_featureSearch_and_classification/blob/master/GCJ_Dataset/CSV/GCJ_47.csv),  [Sapi L&L Features CSV](https://github.com/kotunde/SourceFileAnalyzer_featureSearch_and_classification/blob/master/Sapi_Dataset/CSV/SAPI_47.csv)

#### Abstract Syntax Trees
