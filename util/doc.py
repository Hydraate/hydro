import os
import ntpath
import re

# include path
include_path = os.path.abspath(os.path.join(os.path.dirname(os.path.realpath(__file__)), '../include'))

# a list of files that were processed
files_processed = []

# if true only files that end with /// autofix will be processed
autofix_mode = False

# if true files will be outputed and not updated
test_only = False

def load_cpp_files(path, results):
    allfiles = os.listdir(path)
    for file in allfiles:
        filepath = os.path.join(path, file)
        if os.path.isdir(filepath):
            # load files recursively
            load_cpp_files(filepath, results)
        elif file.startswith('.') == False and (file.endswith('.h') or file.endswith('.hpp') or file.endswith('.c') or file.endswith('.cpp') or file.endswith('.hydro')):
            # push result
            results.append(filepath)

# get leading whitespace
def leading_ws(comment) :
    i = 0
    n = len(comment)
    ws = ""
    while i < n :
        ch = comment[i]
        if ch == "/" :
            break
        else :
            ws += ch
        i = i + 1
    return ws

# convert comments into a multi-line comment
def convert_comments(comments) :
    ws = leading_ws(comments[0])
    result = [ws + "/**"]
    for com in comments :
        val = re.sub(r"[\s]*\/\/\/[\s]*", "", com, 1)
        if len(val) > 0 :
            result.append(ws + " * " + val)
        else :
            result.append(ws + " *")
    result.append(ws + " */")
    return glue_comments(result)

# glue comments
def glue_comments(comments) :
    result = "\n"
    for com in comments :
        if len(result) == 1 :
            result = com
        else :
            result += "\n" + com
    return result

def apply_to_file(cpp):
    global files_processed
    global autofix_mode
    global test_only
    file = open(cpp, 'r')
    code = file.read()
    fix = False
    if code.endswith("/// autofix\n") == False :
        if autofix_mode :
            return
    else :
        code = code[0 : len(code) - len("/// autofix\n") - 1]
        fix = True

    lines = re.split(r"[\n]", code)
    comments = []
    group = []
    last = False
    for line in lines :
        if re.match(r"[\s]*\/\/\/(.)*", line) != None :
            group.append(line)
            last = True
        else :
            last = False
            if len(group) > 0 :
                comments.append([convert_comments(group), glue_comments(group)])
            group = []
    if len(group) > 0 :
        comments.append([convert_comments(group), glue_comments(group)])
    if len(comments) > 0 or fix :
        files_processed.append(cpp)
        for o in comments :
            code = code.replace(o[1], o[0], 1)
        if test_only :
            print(code)
        else :
            file.close()
            file = open(cpp, 'w') # write
            file.write(code)
            file.close()
        print(cpp)
        #input("Press Enter to continue...")


if __name__ == '__main__':
    files = []
    load_cpp_files(include_path, files)
    for cpp in files:
        apply_to_file(cpp)
    print(str(len(files_processed)) + " file(s) processed")
    print("program complete!")