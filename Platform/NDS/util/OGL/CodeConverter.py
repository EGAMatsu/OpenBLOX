from Mesh import Mesh


def CPP(Mesh):
    vertexs = Mesh.getVertexs()
    output = []
    output.append('void ' + formatName(Mesh.getName())+'(){\n')
    output.append('   glBegin("GL_POLYGON")\n')
    for vertex in vertexs:
        x, y, z = vertex
        output.append('   glVertex3f({},{},{})\n'.format(x, y, z))
    output.append('   glEnd()\n')
    output.append('}\n')
    return output


def formatName(name):
    return name.replace('.', '_')
