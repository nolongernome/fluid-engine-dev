import sys


def main():
    if len(sys.argv) < 3:
        print("Not enough arguments.")
        quit(-1)

    input_filename = sys.argv[1]
    output_filename = sys.argv[2]
    params1 = ["int8_t", "uint8_t", "int16_t", "uint16_t", "int32_t",
               "uint32_t", "int64_t", "uint64_t", "float", "double"]
    params2 = ["int8", "unsigned int8", "int16", "unsigned int16", "int32",
               "unsigned int32", "int64", "unsigned int64", "float", "double"]

    with open(input_filename, "r") as ifile:
        lines = ifile.readlines()
        block = []
        blocks = []
        for line in lines:
            line = line.strip()
            if line == "#begin_template":
                block = []
            elif line == "#end_template":
                blocks.append("\n".join(block))
                block = []
            else:
                block.append(line)

    expanded = []
    for block in blocks:
        for p0, p1 in zip(params1, params2):
            exp_block = block.replace("$0", p0).replace("$1", p1)
            expanded.append(exp_block)

    with open(output_filename, "w") as ofile:
        ofile.write("\n\n".join(expanded))


if __name__ == "__main__":
    main()
