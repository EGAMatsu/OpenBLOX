def generate_code(filename):
    with open(filename, 'r') as f:
        data = f.readlines()

    code = "void Object::calculateBrickColor(int value) {\n"
    code += "    switch(value) {\n"

    for line in data:
        values = line.strip().split()
        color_name = values[0]
        color_r = values[1]
        color_g = values[2]
        color_b = values[3]

        code += f"        case({values[4]}):\n"
        code += f"            color_r = {color_r};\n"
        code += f"            color_g = {color_g};\n"
        code += f"            color_b = {color_b};\n"
        code += "            break;\n"
        code += f"        //{color_name}\n"

    code += "    }\n}\n"
    return code

print(generate_code("colors.txt"))
