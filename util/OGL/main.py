# Copyright (c) 2020 Gilang Windu Asmara
import re
from Mesh import Mesh
import CodeConverter

import tkinter as tk
from tkinter import filedialog
import tkinter.scrolledtext as tkst


def convert():
    objFile = filedialog.askopenfilename(
        initialdir="/", title="Select file", filetypes=(("obj files", "*.obj"), ("all files", "*.*")))
    # obj = open(objFile).read().split('\n')

    objCount = 0
    objects = []

    reComp = re.compile("(?<=^)(v |vn |vt |f )(.*)(?=$)", re.MULTILINE)

    with open(objFile) as f:
        data = [line.group()
                for line in reComp.finditer(f.read().replace("\t", ""))]
    v_arr, vn_arr, vt_arr, f_arr = [], [], [], []
    for line in data:
        tokens = line.split(' ')
        if tokens[0] == 'v':
            v_arr.append([float(c) for c in tokens[1:]])
        elif tokens[0] == 'vn':
            vn_arr.append([float(c) for c in tokens[1:]])
        elif tokens[0] == 'vt':
            vn_arr.append([float(c) for c in tokens[1:]])
        elif tokens[0] == 'f':
            f_arr.append([[int(i) if len(i) else 0 for i in c.split('/')]
                          for c in tokens[1:]])
    vertices, normals = [], []
    for face in f_arr:
        print("glBegin(GL_POLYGON);")
        app.setOutput("glBegin(GL_POLYGON);\n")
        vert = [v_arr[tp[0]-1] for tp in face]
        for v in vert:
            # print("glVertex3f(", ",".join(
            #     [str(ve).split(".")[0]+"0" for ve in v]), ");\n")
            app.setOutput('glVertex3d(')
            app.setOutput(",".join([str(ve) for ve in v]))
            app.setOutput(");\n")

        for tp in face:
            vertices += v_arr[tp[0]-1]
            normals += vn_arr[tp[2]-1]
        print("glEnd();")
        app.setOutput("glEnd();\n")
    print(vertices)

    # for index, vert in enumerate(vertices):
    #     print(vert, end="")
    #     if (index+1) % 3 == 0:
    #         print()
    #     else:
    #         print(", ", end="")

    # for i in obj:
    #     if(i.startswith('o ')):
    #         a = Mesh()
    #         a.setName(i.split()[1])
    #         objects.append(a)
    #         print('Mesh:', i.split()[1])
    #     if(i.startswith('v ')):
    #         _, x, y, z = i.split()
    #         objects[len(objects)-1].addVertex(x, y, z)
    #         print('push to vertexs', x, y, z, len(objects)-1)
    # print(len(objects))
    # for o in objects:
    #     for x in CodeConverter.CPP(o):
    #         app.setOutput(x)


# convert()


class Application(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.pack()
        self.create_widgets()

    def create_widgets(self):
        self.output = tkst.ScrolledText(master=self,
                                        wrap=tk.WORD,
                                        width=60,
                                        height=20)
        self.select = tk.Button(self, text="Select obj file", fg="black",
                                command=convert)
        self.select.pack(side="bottom")
        self.output.pack(side="right")

    def setOutput(self, text):
        self.output.insert(tk.INSERT, text)


root = tk.Tk()
app = Application(master=root)


app.mainloop()
