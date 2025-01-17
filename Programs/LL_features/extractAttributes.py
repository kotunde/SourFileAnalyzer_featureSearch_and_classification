import datetime
import os
import re
import pandas as pd

# index_counter = 0 # for indexing the csv file, optional
print_header = True #for pretty printing
all_commented_words = []
multiline_comments = 0
unindented_comments = 0
inline_comments = 0
total_comments = 0
united_declaration = 0
using_stl_libraries = 0
last_row_was_function = False
current_function_row = 0
braces = 0
all_function_rows = []
all_functions = []
function_parameter_count = []
uses_range_based_for = 0
words = []
pathDir = 'yourDirectory\\repo\\Sapi_Dataset\\Data' # don't forget to point this to your data dir!
DIRSEPARATOR = '\\'

# lists the searched features
def returnFeaureList():
    feat_map = {
            'Empty Lines': 0,
            'Non-empty Lines': 0,
            'Average Line Length': 0,
            'Line Length Deviation': 0,
            'Words': 0,
            'Unique Words': 0,
            'Chars': 0,
            'Tabulators': 0,
            'Spaces': 0,
            'Tab Indents': 0,
            'Space Indents': 0,
            'Prefers Tabs over Spaces': 0,
            'Whitespace to Character Ratio': 0,
            'Comments': 0,
            'Comment Readability': 0,
            'One Line to All Comments': 0,
            'Multi-line to All Comments': 0,
            'Inline to All Comments': 0,
            'Unindented Comments': 0,
            'Preprocessor Directives': 0,
            'Define Name Readability': 0,
            'Using STL Libraries': 0,
            'All Keywords': 0,
            'IF Keywords': 0,
            'ELSE Keywords': 0,
            'FOR Keywords': 0,
            'WHILE Keywords': 0,
            'SWITCH Keywords': 0,
            'DO Keywords': 0,
            'Variable Name Readability': 0,
            'Custom Types': 0,
            'Custom Type Name Readability': 0,
            'Functions': 0,
            'Function Name Readability': 0,
            'Function Average Length': 0,
            'Function Length Deviation': 0,
            'Function Block Braces': 0,
            'Nesting Depth': 0,
            'Average Parameter Count': 0,
            'Parameter Count Deviation': 0,
            'Commands': 0,
            'Average Commands per Line': 0,
            'Ternary Operations': 0,
            'Negation Operator': 0,
            'Uses United Declarations': 0,
            'Uses Range-Based For': 0,
            'Creation Order': 0,
            'Author': ""
        }
    return feat_map


# returns whether or not the line contains an stl library object
def stl_libraries_in_line(line):
    global using_stl_libraries
    stl_headers = re.compile(r'(vector|deque|list|set|map|stack|queue|iterator|algorithm|numeric|functional|utility|memory)')
    matches = stl_headers.search(line)
    if matches and using_stl_libraries == 0:
        using_stl_libraries = 1


# counts the total characters in a file without whitespaces
def charsInLine(line):
    text = line.strip().split()
    len_chars = sum(len(word) for word in text)
    return len_chars


# searches for keywords in a line
def searchKeywordsInLine(line, regex):
    found_keyword = re.search(regex, re.sub(r'".*"', '""', line), re.IGNORECASE)
    if found_keyword:
        return 1
    else:
        return 0


# tests if a line is empty
def isEmptyLine(line):
    if line.strip() == '\n' or line.strip() == '':
        return 1
    else:
        return 0


# tests if a line is not empty
def isNotEmpty(line):
    if line.strip() == '\n' or line.strip() == '':
        return 0
    else:
        return 1


# returns 1 if the line contains negation operator, else 0
def find_negation_operator(line):
    found_operator=re.findall(r"""(?:(?:\b(?:while|if|for)\b).!|(=[\s\t]*!))""", line, re.X)
    if found_operator:
        return 1
    else:
        return 0


# counts tabs in a line
def count_tabs(line):
    return len(re.findall(r'\t', line))


# counts words in a line
def countWords(line):
    return len(extract_words(line))


# returns 0 if a ternary operator wasn't found, else the number of matches
def ternary_operator(line):
    found_operator = re.findall(r'(?:(?:=|==|<|>|<=|>=|!=)?[\s\t]*[\s\t]*[^?:]+[\s\t]*\?[\s\t]*(?:.*?:[^ ]*))', line)
    if found_operator:
        return len(found_operator)
    else:
        return 0


# counts the readable words/all words ratio
def count_readability(all_commented_words):
    if all_commented_words == []:
        return 0
    return check_readability(format_words(all_commented_words))


# extracts repeating words and empty strings
def format_words(words):
    formatted = []
    for word in words:
        if word != '':
            if type(word) == list:
                for w in word:
                    w = w.lower()
                    if w not in formatted:
                        formatted += [w]
            else:
                word = word.lower()
                if word not in formatted:
                    formatted += [word]
    return formatted


# checks wether the elements of the 'words' list are in the dictionaries
def check_readability(words):
    if not words:
        return 0

    readable = 0
    en_words_from_dict = ""
    hu_words_from_dict = ""

    for word in words:
        with open('english.txt', 'r') as en_readable_words:
            en_words_from_dict = en_readable_words.read()
            en_is_readable = word in en_words_from_dict
        with open('hungarian.txt','r') as hu_readable_words:
            hu_words_from_dict = hu_readable_words.read()
            hu_is_readable = word in hu_words_from_dict
        if en_is_readable or hu_is_readable:
            readable += 1

    return readable / len(words) if len(words) > 0 else 0


def find_macro(line):
    found_macro = re.search(r'^#\s*(include|define|ifdef|ifndef)', line, re.IGNORECASE)
    if found_macro:
        return found_macro
    else:
        return False


def extract_words(cLine):
    return re.findall(r'([A-Z]?[a-z]+|[A-Z]+)', cLine)

#gathers commented words in a list; counts one-line and multi-line comments; counts all commented lines
def analyzingComments(cLine):
    commented_words = extract_words(cLine)
    global last_row_was_comment
    # comment at the beginning of the line (or indented)
    found_oneline_comment = re.findall(r'^[\s\t]*//[\s\t]*', cLine)
    found_multiline_comment = re.findall(r'^[\s\t]*/\*[\s\t]*', cLine)

    if found_oneline_comment or found_multiline_comment:
        global all_commented_words
        all_commented_words += commented_words

        global total_comments
        total_comments += 1

        global multiline_comments
        global unindented_comments
        global inline_comments
        global oneline_comments

        if found_oneline_comment:
            oneline_comments += 1
            if cLine[0] == '/':
                unindented_comments += 1

        if found_multiline_comment and not bool(re.findall(r'\*/', cLine)):
            last_row_was_comment = 1
            multiline_comments += 1
    else:
        #if last row was comment it continues at least up to this row
        if last_row_was_comment == 1:
            multiline_comments += 1
            total_comments += 1
            all_commented_words += commented_words

        #if end of comment found
        if bool(re.findall(r'\*/', cLine)) :
            last_row_was_comment = 0

    # comment between code
    found_comment = re.findall(r'(?:[};{])\s*(?://|/\*)(.*)(?:$|\*/)', cLine) # re.sub(r'".*"', '""', line))
    if found_comment:
        total_comments += 1
        inline_comments += 1
        last_row_was_comment = 1
        all_commented_words += commented_words# re.sub(r'".*"', '""', line))


# counts spaces in a line
def spacesInLine(line):
    return len(re.findall(r'(\b)? (\b)?', line))


# tests whether or not a line contains united variable declarations
def containsUnitedDeclaration(line):
    global united_declaration
    pattern = re.compile(r'.*\b [a-zA-Z_][a-zA-Z_0-9]*\s*[\[;,={]*[a-zA-Z0-9,\'"]*[\]\'}"]*\s*,\s*[a-zA-Z_][a-zA-Z_0-9]*.*;$')
    if re.match(pattern, line) is not None and (united_declaration == 0):
        united_declaration = 1


# returns the number of commands in a line
def numberOfCommands(line):
    return len(re.findall(r';', re.sub(r'".*"', '""', line)))


#checks brace placement at function definitions
def check_first_function_row(line):
    found_brace = re.findall(r'\)\s*\t*(?:\w+)?\s*\t*{',line)
    if found_brace:
        return True
    else:
        return False

def check_second_function_row(line):
    found_brace = re.findall(r'^{',line)
    if found_brace:
        return True
    else:
        return False

# makes the necessary operations to follow functions, and their lengths
def process_function_row(line):
    global current_function_row
    current_function_row += 1

	#process brace placement
    global kandr_function
    global allman_function
    global otherwise_function
    global first_function_row_checked

	#we are only intersted in the first and second row of a function to decide brace placement
    if current_function_row == 1:
        first_function_row_checked = check_first_function_row(line)
        kandr_function += int(first_function_row_checked)

    if current_function_row == 2 and not first_function_row_checked:
        second_function_row_checked = check_second_function_row(line)
        allman_function += int (second_function_row_checked)
        otherwise_function += int (not (second_function_row_checked))


    # process curly braces to find the end of function
    opening_braces = re.findall(r'{',line)
    closing_braces=re.findall(r'}',line)
    global braces
    braces += (len(opening_braces)-len(closing_braces))

    if braces == 0 and len(closing_braces) != 0:
        global last_row_was_function
        last_row_was_function = False #end of function

        # save the length of current function
        global all_function_rows
        all_function_rows.append(current_function_row)
        current_function_row = 0


# searches functions in a line
def find_functions(line):
    found_functions=re.findall(r'^(?:\w+(?:\[\d+\]|<\w+>)?\s*[*&]?\s+)+(?:\w+::)?(\w+)\s*\(',line)
    is_main = re.findall(r'main',line)
    if found_functions and not is_main:
        #write words of a function name into file
        function_to_file(name_create_list(found_functions))

        global last_row_was_function
        last_row_was_function = True

        process_function_row(line)

        # append the name of the functions to all functions
        global all_functions
        all_functions.append(found_functions[0])

        # append the number of parameters of current function
        global function_parameter_count
        function_parameters = re.findall(r'(?:\w+(?:\[\d+\]|<\w+>)?\s*[*&]?\s+)+(\w+)\s*',line)
        function_parameter_count.append(len(function_parameters) - 1)
        return 1
    else:
        return 0


# for checking readability: write function-,class-,define-,struct names into a file
def struct_to_file(words):
    with open('type.txt','a') as words_file:
        for i in words:
            with open('type.txt','r') as words_in_file:
                if not (i in words_in_file.read()):
                    words_file.write('%s\n'%i)


def class_to_file(words):
    with open('type.txt','a') as words_file:
        for i in words:
            with open('type.txt','r') as words_in_file:
                if not (i in words_in_file.read()):
                    words_file.write('%s\n'%i)


def define_to_file(words):
    with open('define.txt','a') as words_file:
        for i in words:
            with open('define.txt','r') as words_in_file:
                if not (i in words_in_file.read()):
                    words_file.write('%s\n'%i)


def function_to_file(words):
    with open('function.txt','a') as words_file:
        for i in words:
            with open('function.txt','r') as words_in_file:
                if not (i in words_in_file.read()):
                    words_file.write('%s\n'%i)


def variable_to_file(words):
    with open('variable.txt','a') as words_file:
        for i in words:
            with open('variable.txt','r') as words_in_file:
                if not (i in words_in_file.read()):
                    words_file.write('%s\n'%i)


#splits by uppercase and returns words in a list
def camel_case_split(name):
    matches = re.finditer(r'.+?(?:(?<=[a-z])(?=[A-Z])|(?<=[A-Z])(?=[A-Z][a-z])|$)', name)
    return [m.group(0) for m in matches]


#splits by undescore and returns words in a list
def snake_case_split(name):
    without_underscore = re.sub(r'_',' ',name)
    words = without_underscore.split(' ')
    return words


#gets a list of names, and splits the strings
def name_create_list(names):
    splitted = []
    for string_name in names:
        if (re.search(r'_',string_name)):
            splitted.extend(snake_case_split(string_name))
        else:
            splitted.extend(camel_case_split(string_name))
    return splitted


#returns in a list found struct names
def find_struct_name(line):
    found_struct = re.findall(r'struct\s+(\w+)',line)
    if found_struct:
        struct_to_file(name_create_list(found_struct))
        return 1
    else:
        return 0


#returns in a list found class names
def find_class_name(line):
    found_class = re.findall(r'(?:\w+[*&]?\s+(?:(\w+)::)?)\w+\s*\(',line)
    if found_class:
        class_to_file(name_create_list(found_class))
        return 1
    else:
        return 0


#returns in a list found define names
def find_define_name(line):
    found_define = re.findall(r'#define\s+(\w+)',line)
    if found_define:
        define_to_file(name_create_list(found_define))
    else:
        return 0


#returns in a list found variable names
def find_variable_name(line):
    found_variable = re.findall(r"""\b(?:(?:auto\s*|const\s*|unsigned\s*|signed\s*|register\s*|volatile\s*|static\s*|void\s*|short\s*|long\s*|char\s*|int\s*|float\s*|double\s*|_Bool\s*|complex\s*)+)(?:\s+\*?\*?\s*)([a-zA-Z_][a-zA-Z0-9_]*)\s*[\[;,=)]""",line,re.X)
    if found_variable:
        variable_to_file(name_create_list(found_variable))
    else:
        return 0


# returns True if the line contains range-based for loop, else False
def search_range_loop(line):
    global uses_range_based_for
    found_for=re.findall(r'(?:\s*for\s*\(.*:.*\))',line)
    if found_for and uses_range_based_for == 0:
        uses_range_based_for = 1


# returns the file's last modification time
def creation_date(path_to_file):
    t = os.path.getmtime(path_to_file)
    return str(datetime.datetime.fromtimestamp(t))


# returns 1 if line is indented with space, otherwise returns 0
def check_space_indent(line):
    if re.findall(r'^\s+', line):
         return 1
    else:
         return 0


# returns 1 if line is indented with tab, otherwise returns 0
def check_tab_indent(line):
    if re.findall(r'^\t+', line):
         return 1
    else:
         return 0


# calculates nesting depth
def calculate_nesting_depth(line):
    bracket_contents = re.findall(r'\((.*)\)|\[(.*)\]', line)

    if not bracket_contents:
        return 1

    return 1 + max(calculate_nesting_depth(cont[0] + cont[1]) for cont in bracket_contents)

# read file into a list
def file_to_list(filename):
    global pathDir
    if os.path.isfile(pathDir + '\\' + filename) == False:
        return []
    with open(filename) as f:
        l = f.read().splitlines()
        return l


# decides which brace placemant was used most frequently
def decide_function_style(kandr, allman, otherwise):
    if kandr > allman and kandr > otherwise:
        return 1
    elif allman > kandr and allman > otherwise:
        return 2
    else:
        return 3


# adds words to a list
def append_words(line):
    global words
    words.extend(x.lower() for x in extract_words(line))


# checks if a list contains an item and removes it
def check_and_remove_list_item(pattern, ls):
    if ls.__contains__(pattern):
        ls.remove(pattern)
    return ls


# returns a list from which duplicates were removed
def remove_duplicates(lst):
    ls = []
    ls = list(dict.fromkeys(lst))
    return ls



# --- # --- # --- # --- # --- # --- # --- # --- # --- # --- # --- # --- # --- # --- # --- # --- # --- # --- # --- # --- #


# writes extracted features into a .csv file
def dump(data):
    # global index_counter
    # index_counter += 1
    # for indexing the rows, optional...

    index_counter = 1
    global print_header
    csv_file = "LL_features.csv" 
    df=pd.DataFrame(data,index=[index_counter])
    if print_header:
        csv_columns = ['empty_lines', 'non_empty_lines', 'average_line_length', 'line_length_deviation', 'words', 'unique_words', 'chars', 'tabulators', 'spaces', 'tab_indents', 'space_indents', 'prefers_tabs_over_spaces', 'whitespace_to_character_ratio', 'comments', 'comment_readability', 'one_line_to_all_comments', 'multi_line_to_all_comments', 'inline_to_all_comments', 'unindented_comments_to_all', 'preprocessor_directives', 'define_name_readability', 'using_stl_libraries', 'all_keywords', 'if_keywords', 'else_keywords', 'for_keywords', 'while_keywords', 'switch_keywords', 'do_keywords', 'variable_name_readability', 'custom_types', 'custom_type_name_readability', 'functions', 'function_name_readability', 'function_average_length', 'function_length_deviation', 'function_block_braces', 'nesting_depth', 'average_parameter_count', 'parameter_count_deviation', 'commands', 'average_commands_per_line', 'ternary_operations', 'negation_operator', 'uses_united_declarations', 'uses_range_based_for', 'creation_order', 'author' ]
        df.to_csv(csv_file, mode = 'w', header=csv_columns, index = False) #with headers
        print_header = False
    else:
        df.to_csv(csv_file, mode = 'a', header = False, index = False) #append mode without headers


def initializeGlobals():
    global all_commented_words
    global last_row_was_comment
    global oneline_comments
    global multiline_comments
    global unindented_comments
    global inline_comments
    global total_comments
    global united_declaration
    global uses_range_based_for
    global last_row_was_function
    global current_function_row
    global braces
    global all_function_rows
    global all_functions
    global function_parameter_count
    global words
    global using_stl_libraries
    global kandr_function
    global allman_function
    global otherwise_function
    global first_function_row_checked

    all_commented_words = []
    last_row_was_comment = 0
    oneline_comments = 0
    multiline_comments = 0
    unindented_comments = 0
    inline_comments = 0
    total_comments = 0
    uses_range_based_for = 0
    united_declaration = 0
    last_row_was_function = False
    current_function_row = 0
    braces = 0
    all_function_rows = []
    all_functions = []
    function_parameter_count = []
    words = []
    using_stl_libraries = 0
    kandr_function = 0
    allman_function = 0
    otherwise_function = 0
    first_function_row_checked = False

########################################################################################################################


# getting the features from file
def extract_features(filepath, author, creation_order, csv_flag):
    initializeGlobals()
    feature_map = returnFeaureList()
    feature_map['Author'] = author
    feature_map['Creation Order'] = creation_order

    sum_line_length = 0
    line_lengths = []
    commands_per_non_empty_line = []
    uses_macros = 0
    global words
    global oneline_comments

    with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
        line = f.readline()
        line_count = 1
        while line:

            analyzingComments(line)
            containsUnitedDeclaration(line)
            stl_libraries_in_line(line)
            search_range_loop(line)

            charsCurrentLine = charsInLine(line)
            sum_line_length += charsCurrentLine
            line_lengths.append(len(line))

            numberOfCommandsCurrentLine = numberOfCommands(line)
            isNotEmptyLine = isNotEmpty(line)

            append_words(line)

            structs = find_struct_name(line)
            classes = find_class_name(line)
            find_define_name(line)
            find_variable_name(line)

            if last_row_was_function:
                process_function_row(line)

            if structs or classes:
                feature_map['Custom Types'] = 1
            feature_map['Chars'] += charsCurrentLine
            feature_map['IF Keywords'] += searchKeywordsInLine(line, r'^.*\b(if)\b.*$')
            feature_map['ELSE Keywords'] += searchKeywordsInLine(line, r'^.*\b(else)\b.*$')
            feature_map['FOR Keywords'] += searchKeywordsInLine(line, r'^.*\b(for)\b.*$')
            feature_map['WHILE Keywords'] += searchKeywordsInLine(line, r'^.*\b(while)\b.*$')
            feature_map['SWITCH Keywords'] += searchKeywordsInLine(line, r'^.*\b(switch)\b.*$')
            feature_map['DO Keywords'] += searchKeywordsInLine(line, r'^.*\b(do)\b.*$')
            feature_map['Non-empty Lines'] += isNotEmptyLine
            feature_map['Negation Operator'] += find_negation_operator(line)
            feature_map['Tabulators'] += count_tabs(line)
            feature_map['Words'] += countWords(line)
            feature_map['Ternary Operations'] += ternary_operator(line)
            feature_map['Spaces'] += spacesInLine(line)
            feature_map['Commands'] += numberOfCommandsCurrentLine
            feature_map['Functions'] += find_functions(line)
            feature_map['Tab Indents'] += check_tab_indent(line)
            feature_map['Space Indents'] += check_space_indent(line)
            feature_map['Empty Lines'] += isEmptyLine(line)

            if isNotEmptyLine:
                commands_per_non_empty_line.append(numberOfCommandsCurrentLine)

            max_nest_depth_in_line = calculate_nesting_depth(line)
            if max_nest_depth_in_line > feature_map['Nesting Depth']:
                    feature_map['Nesting Depth'] = max_nest_depth_in_line

            found_macro = find_macro(line)
            if False != found_macro and uses_macros == 0:
                uses_macros = 1

            # next line initialization
            line = f.readline()
            line_count += 1
        """"""""""""""""""""" end of loop """""""""""""""""""""

        # file features ...
        feature_map['All Keywords'] = feature_map['IF Keywords'] + feature_map['ELSE Keywords'] + feature_map['FOR Keywords'] + feature_map['SWITCH Keywords'] + feature_map['WHILE Keywords'] + feature_map['DO Keywords']

        if total_comments == 0:
            # if there are no comments at all...
            feature_map['Comment Readability'] = 0
            feature_map['Inline to All Comments'] = 0
            feature_map['Multi-line to All Comments'] = 0
            feature_map['Unindented Comments'] = 0
            feature_map['One Line to All Comments'] = 0
        else:
            feature_map['Comment Readability'] = count_readability(all_commented_words)
            feature_map['Inline to All Comments'] = inline_comments / total_comments if inline_comments > 0 else 0
            feature_map['Multi-line to All Comments'] = multiline_comments / total_comments if multiline_comments > 0 else 0
            feature_map['Unindented Comments'] = unindented_comments / total_comments if unindented_comments > 0 else 0
            feature_map['One Line to All Comments'] = oneline_comments / total_comments


        feature_map['Comments'] = total_comments
        feature_map['Average Line Length'] = sum_line_length / line_count
        if feature_map['Non-empty Lines'] != 0:
            feature_map['Space Indents'] /= feature_map['Non-empty Lines']
        else:
            feature_map['Space Indents'] = 0

        # line_lengths can be 0 if the file is empty
        if len(line_lengths) != 0:
            feature_map['Line Length Deviation'] = sum([abs(i - feature_map['Average Line Length']) for i in line_lengths]) / len(line_lengths)
        else:
            feature_map['Line Length Deviation'] = 0

        # character count can be 0 if the file is empty
        if feature_map['Chars'] != 0:
            feature_map['Whitespace to Character Ratio'] = (feature_map['Spaces'] + feature_map['Tabulators']) / feature_map['Chars']
        else:
            feature_map['Whitespace to Character Ratio'] = 0

        # command count can be 0 if the file is empty
        if feature_map['Commands'] == 0:
            feature_map['Average Commands per Line'] = 0
        else:
            feature_map['Average Commands per Line'] = feature_map['Commands'] / feature_map['Non-empty Lines']

        feature_map['Preprocessor Directives'] = uses_macros
        feature_map['Uses United Declarations'] = united_declaration
        feature_map['Using STL Libraries'] = using_stl_libraries
        feature_map['Empty Lines'] = feature_map['Empty Lines']/line_count if line_count > 0 else 0
        feature_map['Non-empty Lines'] = 1 - feature_map['Empty Lines']
        feature_map['Average Parameter Count'] = sum(function_parameter_count) / len(function_parameter_count) if function_parameter_count != [] else 0
        feature_map['Parameter Count Deviation'] = sum([abs(i - feature_map['Average Parameter Count']) for i in function_parameter_count]) / len(function_parameter_count) if function_parameter_count != [] else 0
        feature_map['Custom Type Name Readability'] = count_readability(file_to_list('type.txt'))
        feature_map['Function Name Readability'] = check_readability(format_words(all_functions))
        feature_map['Function Average Length'] = sum(all_function_rows) / len(all_function_rows) if all_function_rows != [] else 0
        feature_map['Uses Range-Based For'] = uses_range_based_for
        feature_map['Prefers Tabs over Spaces'] = 1 if feature_map['Tab Indents'] > feature_map['Space Indents'] else 0
        feature_map['Ternary Operations'] = 1 if feature_map['Ternary Operations'] > 0 else 0
        feature_map['Unique Words'] = len(remove_duplicates(words))
        feature_map['Function Length Deviation'] = sum([abs(i - feature_map['Function Average Length']) for i in all_function_rows]) / len(all_function_rows) if all_function_rows != [] else 0
        feature_map['Function Block Braces'] = decide_function_style(kandr_function, allman_function, otherwise_function)
        feature_map['Variable Name Readability'] = count_readability(file_to_list('variable.txt'))
        feature_map['Define Name Readability'] = count_readability(file_to_list('define.txt'))

    if csv_flag  == "YES_CSV":
        dump(feature_map)


# walks through directories and initiates feature extracktion for each .cpp file
def start(path, make_csv):
    global DIRSEPARATOR
    author = ""
    # patternUser = re.compile(r'.+\\user[0-9]+$')
    patternUser = re.compile(r'.+Bence14\\data\\[A-Za-z0-9]+$')
    if DIRSEPARATOR == '\\':
        patternLab = re.compile(r'.+\\labor[0-9]+$')
    else:
        patternLab = re.compile(r'.+/labor[0-9]+$')
    list_of_files = {}
    creation_order = 0
    for (dirpath, dirnames, filenames) in os.walk(path):
        print(dirpath)
        if(re.match(patternUser, dirpath) != None):
            #print(f"{dirpath}")
            # print(dirpath.split('\\')[-1]) #last element in the array, aka the user
            # new user

            author = dirpath.split(DIRSEPARATOR)[-1]
            list_of_files = {}
            # initializeGlobals()

        if(re.match(patternLab, dirpath) != None):
            creation_order = dirpath.split(DIRSEPARATOR)[-1].strip('labor')
            # print (creation_order)

        for filename in filenames:
            if filename.startswith('.'):
                # for the other data
                continue;
            if filename.endswith('.cpp'):
                list_of_files[filename] = os.sep.join([dirpath, filename])
                print(dirpath + DIRSEPARATOR + filename)
                extract_features(dirpath + DIRSEPARATOR + filename, author, creation_order, make_csv)


# main function to start feature extracking
def main(path, opsys, make_csv):
    global DIRSEPARATOR
    DIRSEPARATOR = '\\' #defaults to Windows
    if opsys == 'LINUX' or opsys == 'MACOS':
        DIRSEPARATOR = '/'
    start(path, make_csv)

# -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # --
#                                                        M A I N                                                      #
# -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # -- # --


main("yourDirectory\\repo\\Sapi_Dataset\\Data", 'WINDOWS', 'YES_CSV')
# main("/home/tunde/Linux/Documents/Projekt/Sajat_kodok/Analyzer_06_10/Data", 'LINUX', 'YES_CSV')
