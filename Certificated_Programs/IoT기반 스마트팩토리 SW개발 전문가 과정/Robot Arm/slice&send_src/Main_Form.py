from PyQt5.QtWidgets import *
from PyQt5 import uic, QtCore
from PyQt5.QtCore import *
import Slicer
from Slicer import Convert
import pyvista as pv
import trimesh
import pandas as pd

form, base = uic.loadUiType("main.ui")

class MainWindow(base, form):

    layerLength = None
    dataFrame = None
    pv = None

    def __init__(self, q):
        super(base, self).__init__()
        self.setupUi(self)

        self.queue = q

        self.pbStatus.setValue(0)

        # 쓰레드 인스턴스 생성
        self.th = Convert(self)
        # 쓰레드 이벤트 연결
        self.th.threadEvent1.connect(self.threadEventHandler1)
        self.th.threadEvent2.connect(self.threadEventHandler2)

        self.pbSTLFileOpen.clicked.connect(self.OpenFile)
        self.pbConvert.clicked.connect(self.MakeSliceModule)
        self.pbShowOriginal.clicked.connect(self.ShowOriginal)
        self.pbShowConvert.clicked.connect(self.ShowConvert)
        self.pbSend.clicked.connect(self.SendMessage)

    def OpenFile(self):
        filename = QFileDialog.getOpenFileName(self, 'Open file', './', filter="STL File(*.stl)")
        self.leSTLFilePath.setText(str(filename[0]))
        self.pbConvert.setEnabled(True)
        self.pbShowOriginal.setEnabled(True)

    @pyqtSlot(int)
    def threadEventHandler1(self, n):
        self.pbStatus.setValue(int(n))

    @pyqtSlot(pd.DataFrame)
    def threadEventHandler2(self, df):
        self.dataFrame = df
        self.pbShowConvert.setEnabled(True)
        self.pbSend.setEnabled(True)

    def MakeSliceModule(self):
        '''
        FileName =str(self.leSTLFilePath.text()).strip()

        if FileName != "" and not self.th.isRun:
            self.pbSTLFileOpen.setEnabled(False)
            self.pbShowConvert.setEnabled(False)
            self.pbSend.setEnabled(False)
            self.pbConvert.setEnabled(False)
            self.pbShowOriginal.setEnabled(False)
            self.th.SetFile(FileName)
            self.th.start()
            '''
        self.dataFrame = pd.read_csv("3DBenchy_1.csv")
        self.pbShowConvert.setEnabled(True)
        self.pbSend.setEnabled(True)

    def ShowOriginal(self):
        if str(self.leSTLFilePath.text()).strip() != "":
            self.pv = Slicer.DisplayOrigianl(str(self.leSTLFilePath.text()).strip())
            temp = self.pv.app.exec_()
            print(temp)

    def ShowConvert(self):
        if str(self.leSTLFilePath.text()).strip() != "":
            self.pv = Slicer.DisplayBlock(self.dataFrame)
            temp = self.pv.app.exec_()
            print(temp)

    def SendMessage(self):
        if str(self.leSTLFilePath.text()).strip() != "":
            sendFileName = Slicer.MSGLayer(self.dataFrame, str(self.leSTLFilePath.text()).strip())
            self.queue.put(sendFileName)

            self.pbShowConvert.setEnabled(False)
            self.pbSend.setEnabled(False)
            self.pbConvert.setEnabled(False)
            self.pbShowOriginal.setEnabled(False)
            # self.leSTLFilePath.setText("")
            self.pbStatus.setValue(0)

