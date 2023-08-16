import sys

def get_name(line, st, et):
    start_index = line.find(st)
    end_index = line.find(et, start_index + len(st))
    return line[start_index + len(st):end_index]

def main(file, st, et):
    f = open(file, "r")
    file_c = f.read().split("\n")
    ret = []
    for line in file_c:
        if "assets" in line:
            ret.append(get_name(line, st, et) + ", " + str(line))
        print(line)
    f.close()
    f = open(file, "w")
    f.write("\n".join(ret))
    f.close()

main(sys.argv[1], sys.argv[2], sys.argv[3])
