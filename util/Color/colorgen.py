def process_file(input_file, output_file):
    data = {}
    with open(input_file, "r") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            parts = line.split("\t")
            if len(parts) == 5:
                id, name, rgb, hex, _ = parts
                id = int(id)
                rgb = [int(x) for x in rgb.split(", ")]
                data[id] = (name, rgb, hex)
            else:
                id = int(parts[0])
                if id in data:
                    data[id] = (*data[id], parts[1])
    with open(output_file, "w") as f:
        for id, item in sorted(data.items()):
            name, rgb, hex, shares = item
            f.write(f"{id}\t{name}\t{rgb}\t{hex}\t{shares}\n")

input_file = "colors.txt"
output_file = "output.txt"
process_file(input_file, output_file)
