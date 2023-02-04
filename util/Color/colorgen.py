#!/usr/bin/env python

color_dict = {}

print("switch (value) {")
with open("colors.txt", "r") as file:
    for line in file:
        elements = line.split(",")
        brick_color = elements[0].split("::")[1].replace("roblox_", "").replace("brick_", "")
        if not brick_color in color_dict:
            r = int(elements[1])
            g = int(elements[2])
            b = int(elements[3])
            name = elements[4].strip().replace('/', "").replace(";", "")
            color_dict[brick_color] = (r, g, b, name)
for brick_color, color_info in color_dict.items():
    print(" case ({}):".format(brick_color))
    print("     color_r = {};\n     color_g = {};\n     color_b = {};".format(*color_info[:3]))
    print(" break;")
print("}");
