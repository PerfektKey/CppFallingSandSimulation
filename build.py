import os

def getFilesR(path):
    files = []
    for f in os.listdir(path):
        if os.path.isdir(f):
            files += getFilesR(os.path.join(path,f))
        else:
            files.append(os.path.join(path,f))
    return files
            

files = getFilesR(os.getcwd())
#print(files)
srcf = []

for f in files:
    fname , fext = os.path.splitext(os.path.basename(f))
    if fext == ".cpp":
        srcf.append(f)

print(srcf)
CC="clang++"
FLAGS="-std=c++20 -Wall -g"
INC="-lsfml-graphics -lsfml-window -lsfml-system"

bin="bin"
ext=""

for f in srcf:
    print(CC + " " + FLAGS + " -c " + f + " -o " + bin + "/" + os.path.splitext(os.path.basename(f))[0] + ".o")
    os.system( CC + " " + FLAGS + " -c " + f + " -o " + bin + "/" + os.path.splitext(os.path.basename(f))[0] + ".o")

print(CC + " " + bin + "/*.o" + FLAGS + " -o " + " main" + ext + " " + INC)
os.system(CC + " " + bin + "/*.o " + FLAGS  + " -o " + " main" + ext + " " + INC)
