
from PyQt5 import uic, QtCore
from PyQt5.QtCore import *
import pyvista as pv
import trimesh
import pandas as pd
import random
import itertools
import math
from tqdm import tqdm
import numpy as np


from pyvistaqt import BackgroundPlotter


size = {'x': 3.7, 'y': 3.7, 'z': 3}

defBlock = [[2, 6], [2, 5], [2, 4], [2, 3], [2, 2],
            [1, 6], [1, 5], [1, 4], [1, 3], [1, 2], [1, 1]]


def align_bounds(bounds):
    # trimesh's bounds를 (xMin, xMax, yMin, yMax, zMin, zMax)로 변형
    temp = []
    for i in range(len(bounds)):
        aa = bounds[i]
        for j in range(len(aa)):
            jj = aa[j]
            temp.append(jj)
    align_bound = [temp[0], temp[3], temp[1], temp[4], temp[2], temp[5]]
    return align_bound


def DisplayOrigianl(File):

    pv_mesh = pv.read(File)  # polydata

    plotter = BackgroundPlotter()
    plotter.add_mesh(pv_mesh, opacity=1, color='white')
    return plotter


def DisplayBlock(bounds_df):
    cal_cnt = len(bounds_df)

    for i in tqdm(range(cal_cnt), desc="extract view Slice" ):
        globals()['box_5_{}'.format(i)] = list(bounds_df.iloc[i])
    # exec('extract_3_%s = pv_mesh.clip_box(box_3_%s, invert=False)' % (i, i))

    plotter = BackgroundPlotter()

    for i in tqdm(range(cal_cnt), desc="extract Merge Slice"):
        color = (random.random(), random.random(), random.random())
        # exec("n_cell = extract_3_%s.n_cells" % i)

        evalCode = 'n_cell != 0'
        exec("py_box_5_%s = pv.Box(bounds=box_5_%s, level=0, quads=True)" % (i, i))
        exec("plotter.add_mesh(py_box_5_%s, opacity=1, show_edges=True)" % i)

    return plotter

def CheckIndex(lists, value):
    for i in lists:
        if value < i - 1:
            return lists.index(i)
    return lists.index(lists[-1])


def MinLayer(Layer):
    temp_x = Layer[0][0]
    temp_y = Layer[0][1]
    temp_z = Layer[0][2]

    for x, y, z in Layer:
        if x < temp_x:
            temp_x = x
        if y < temp_y:
            temp_y = y
        if z < temp_z:
            temp_z = z

    return temp_x, temp_y, temp_z


def MSGLayer(df, FileName):
    global defBlock

    x_Dataframe = list(np.array(df['xmin'].tolist()))
    y_Dataframe = list(np.array(df['ymin'].tolist()))
    z_Dataframe = list(np.array(df['zmin'].tolist()))

    data = [[x_Dataframe[i], y_Dataframe[i], z_Dataframe[i]] for i in range(len(x_Dataframe))]

    max_x = 0
    max_y = 0
    max_z = 0

    floor = []

    temp = []

    floor_z = 0

    for x, y, z in data:
        if max_x < x:
            max_x = x
        if max_y < y:
            max_y = y
        if max_z < z:
            max_z = z

        if floor_z == z:
            temp.append([x, y])
        else:
            floor.append(temp)
            temp = list()
            temp.append([x, y])
            floor_z = z
    floor.remove([])

    max_z += 3
    max_x += 3
    max_y += 3

    map2d = np.zeros((int(max_z), int(max_y), int(max_x)))
    for i in range(len(floor)):
        for item in floor[i]:
            map2d[i][int(item[1])][int(item[0])] = 1

    blockNum = []

    for layerindex in range(len(map2d)):
        layer = map2d[layerindex]
        loc_x, loc_y = 0, 0
        while loc_y <= int(max_y):
            for block in defBlock:
                if i % 2 == 1 and BlockCheck_odd(layer, [loc_x, loc_y], block):
                    blockNum.append([loc_x, loc_y, layerindex, defBlock.index(block)])
                    for i in range(block[1]):
                        for j in range(block[0]):
                            layer[loc_y + i][loc_x + j] = defBlock.index(block) + 10
                elif i % 2 == 0 and BlockCheck_even(layer, [loc_x, loc_y], block):
                    blockNum.append([loc_x, loc_y, layerindex, defBlock.index(block)])
                    for i in range(block[1]):
                        for j in range(block[0]):
                            layer[loc_y + j][loc_x + i] = defBlock.index(block) + 10
            loc_x = (loc_x + 1) % int(max_x)
            if loc_x == 0:
                loc_y += 1

    end_df = pd.DataFrame(blockNum)
    strtmp = FileName.split('/')[-1].split('.')[0]+'.csv'
    end_df.to_csv(strtmp, header=None, index=False)
    return strtmp


def BlockCheck_odd(layer, point, block):
    max_loc_y, max_loc_x = layer.shape
    # print(max_loc_y, max_loc_x)
    for i in range(block[1]):
        for j in range(block[0]):
            # print(point[1]+i,point[0]+j )
            if point[1] + i >= max_loc_y or point[0] + j >= max_loc_x:
                return False
            if layer[point[1] + i][point[0] + j] != 1:
                return False
    return True


def BlockCheck_even(layer, point, block):
    max_loc_y, max_loc_x = layer.shape
    # print(max_loc_y, max_loc_x)
    for i in range(block[1]):
        for j in range(block[0]):
            # print(point[1]+i,point[0]+j )
            if point[1] + j >= max_loc_y or point[0] + i >= max_loc_x:
                return False
            if layer[point[1] + j][point[0] + i] != 1:
                return False
    return True

class Convert(QThread):

    threadEvent1 = QtCore.pyqtSignal(int)
    threadEvent2 = QtCore.pyqtSignal(pd.DataFrame)

    def __init__(self, parent=None):
        super().__init__()
        self.main = parent
        self.File = ""
        self.isRun = False
        self.size = {'x': 3.7, 'y': 3.7, 'z': 3}

        self.defBlock = [[2, 6], [2, 5], [2, 4], [2, 3], [2, 2],
                       [1, 6], [1, 5], [1, 4], [1, 3], [1, 2], [1, 1]]

    def SetFile(self, filename):
        self.File = filename

    def run(self):
        FileName = self.File
        self.isRun = True
        pv_mesh = pv.read(FileName)  # polydata
        tri_mesh = trimesh.load(FileName)  # base.Trimesh
        # AABB & OBB 생성
        # obb = tri_mesh.bounding_box_oriented
        aabb = tri_mesh.bounding_box

        # Bounds 추출
        aabb_bounds = aabb.bounds

        aabb_bounds_a = align_bounds(aabb_bounds)

        tp = aabb_bounds_a
        x_min, x_max, y_min, y_max, z_min, z_max = tp[0], tp[1], tp[2], tp[3], tp[4], tp[5]

        x_dist = x_max - x_min
        # 몇 등분으로 분할할 것인지 -- 변경 가능
        n_x = math.ceil(x_dist / self.size['x'])
        x_interval = x_dist / float(n_x)
        # y축 분할

        y_dist = y_max - y_min
        n_y = math.ceil(y_dist / self.size['y'])
        # n_y = 2
        y_interval = y_dist / float(n_y)

        # Z축 분할
        z_dist = z_max - z_min
        n_z = math.ceil(z_dist / self.size['z'])
        # n_z = 2
        z_interval = z_dist / float(n_z)

        total_cnt = n_x * n_z * n_y

        x_min_ls = [x_min + (x_interval * i) for i in range(0, n_x)]  # x_min 좌표부터 n_x번 간격을 더해줌
        x_list = x_min_ls
        x_min_ls = [[i] for i in x_min_ls]
        x_min_ls = list(itertools.chain(*x_min_ls))

        x_max_ls = [x_min + (x_interval * i) for i in range(1, n_x + 1)]  # 윗줄과 맞물리게끔 n_x번 간격을 더해줌
        x_max_ls = [[i] for i in x_max_ls]
        x_max_ls = list(itertools.chain(*x_max_ls))

        y_min_ls = [y_min + (y_interval * i) for i in range(0, n_y)]
        y_list = y_min_ls

        y_min_ls = [[i] * n_x for i in y_min_ls]
        y_min_ls = list(itertools.chain(*y_min_ls))

        y_max_ls = [y_min + (y_interval * i) for i in range(1, n_y + 1)]
        y_max_ls = [[i] * n_x for i in y_max_ls]
        y_max_ls = list(itertools.chain(*y_max_ls))

        z_min_ls = [z_min + (z_interval * i) for i in range(0, n_z)]
        z_list = z_min_ls

        z_min_ls = [[i] * n_x * n_y for i in z_min_ls]
        z_min_ls = list(itertools.chain(*z_min_ls))

        z_max_ls = [z_min + (z_interval * i) for i in range(1, n_z + 1)]
        z_max_ls = [[i] * n_x * n_y for i in z_max_ls]
        z_max_ls = list(itertools.chain(*z_max_ls))

        bounds_df = pd.DataFrame(data=[], columns=['xmin', 'xmax', 'ymin', 'ymax', 'zmin', 'zmax'])
        for i in range(total_cnt):
            bounds_df.loc[i] = aabb_bounds_a

        bounds_df['xmin'] = x_min_ls * n_y * n_z
        bounds_df['xmax'] = x_max_ls * n_y * n_z
        bounds_df['ymin'] = y_min_ls * n_z
        bounds_df['ymax'] = y_max_ls * n_z
        bounds_df['zmin'] = z_min_ls
        bounds_df['zmax'] = z_max_ls

        list_temp = []
        MaxValue = total_cnt * 2
        value = 0

        for i in tqdm(range(total_cnt), desc="extract view"):
            globals()['box_{}'.format(i)] = list(bounds_df.iloc[i])
            exec('extract_%s = pv_mesh.clip_box(box_%s, invert=False)' % (i, i))
            value += 1
            ret_temp = (value*100)/MaxValue
            ret = int(ret_temp)
            self.threadEvent1.emit(ret)

        for i in tqdm(range(total_cnt), desc="extract  Merge"):
            value += 1
            ret_temp = (value*100)/MaxValue
            ret = int(ret_temp)
            self.threadEvent1.emit(ret)

            # print(i, end="\t")
            exec("n_cell = extract_%s.n_cells" % i)

            evalCode = 'n_cell != 0'
            if eval(evalCode):
                exec("py_box_%s = pv.Box(bounds=box_%s, level=0, quads=True)" % (i, i))
                exec("list_temp.append(py_box_%s)" % i)

        list_temp = [[i.bounds[0], i.bounds[2], i.bounds[4]] for i in list_temp]

        list_temp_1 = [[CheckIndex(x_list, x), CheckIndex(y_list, y), CheckIndex(z_list, z)] for
                       x, y, z in
                       list_temp]

        list_temp_4 = [[x, x + self.size['x'] / 3.6, y, y + self.size['y'] / 3.6, z, z + self.size['z'] / 3] for x, y, z
                       in
                       list_temp_1]

        list_temp_5 = []
        for i in list_temp_4:
            if i not in list_temp_5:
                list_temp_5.append(i)
        dataFrame = pd.DataFrame(data=list_temp_5, columns=['xmin', 'xmax', 'ymin', 'ymax', 'zmin', 'zmax'])
        self.threadEvent2.emit(dataFrame)

        self.isRun = False
