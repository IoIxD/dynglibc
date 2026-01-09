import re

f = open("functions")

lines = f.readlines()

for line in lines:
    func = re.match("(.*?)\s(.*?)\((.*?)\)",line)
    args = list(map(lambda f: f.split(" ")[len(f.split(" "))-1].replace("*",""), func.group(3).split(",")))
    print(func.group(0)+" { return libcFunctionTable."+func.group(2)+"("+",".join(args)+");}")
