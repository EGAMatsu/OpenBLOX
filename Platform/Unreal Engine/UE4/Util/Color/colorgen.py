#!/usr/bin/env python

color_dict = {}

value = 0
color_red = 0
color_green = 0
color_blue = 0

#print("match value:")
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
    print("if (value == {}):".format(brick_color))
    print("\tcolor_r = {}\n\tcolor_g = {}\n\tcolor_b = {}".format(*color_info[:3]))
