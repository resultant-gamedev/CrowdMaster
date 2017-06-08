cimport cython

from cpython cimport array
import array

cdef struct FuzzySet:
    int[:] ids
    double[:] values
    int size

cdef FuzzySet fuzzySetFromPythonDict(object d):
    cdef array.array ids = array.array('i', d.keys())
    cdef array.array values = array.array('d', d.values())
    cdef FuzzySet f
    f.ids = ids
    f.values = values
    f.size = len(d)
    return f

@cython.boundscheck(False)
cdef int findId(int i, int[:] ids, int size):
    for a in range(size):
        if ids[a] == i:
            return a
    return -1

cdef printFuzzySet(FuzzySet f):
    for e in range(f.size):
        print(f.ids[e], f.values[e])

cdef FuzzySet fuzzySetIntersection(FuzzySet a, FuzzySet b):
    return a
    cdef:
        array.array ids = array.array('i')
        array.array values = array.array('d', [])
    #    int size = 0
    #    int index
        FuzzySet f

    #for i in range(a.size):
        #index = findId(a.ids[i], b.ids, b.size)
        #if index > 0:
            #size += 1
            #ids.append(a.ids[i])
            #values.append(a.values[i] * b.values[index])

    #f.ids = ids
    #f.values = values
    #f.size = size
    #return f

def test(d):
    printFuzzySet(fuzzySetFromPythonDict(d))

cdef FuzzySet a = fuzzySetFromPythonDict({1:0.1, 2:0.2})
cdef FuzzySet b = fuzzySetFromPythonDict({1:1, 2:0.5})

print("a")
printFuzzySet(a)
print("b")
printFuzzySet(b)
print("a intersect b")
printFuzzySet(fuzzySetIntersection(a, b))


#cdef FuzzySet f = fuzzySetFromPythonDict({1:0.1, 2:0.2})
#printFuzzySet(f)
