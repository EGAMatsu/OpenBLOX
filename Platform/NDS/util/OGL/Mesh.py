class Mesh:
    def __init__(self):
        self.vertexs = []

    def setName(self, name):
        self.name = name

    def addVertex(self, x, y, z):
        self.vertexs.append([x, y, z])

    def read(self):
        print(self.name)
        print(self.vertexs)

    def getVertexs(self):
        return self.vertexs

    def getName(self):
        return self.name
