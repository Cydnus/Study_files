import sys
from PyQt5.QtWidgets import *
from PyQt5 import uic
import Slicer

form, base = uic.loadUiType("Slice.ui")


class SliceWindow(base, form):
    def __init__(self):
        super(base, self).__init__()
        self.setupUi(self)
        self.DataFrame = None
        self.pbSend.clicked.connect(self.SendMessage)

    def defaultSetting(self, layer, dataframe):
        self.vsLayer.setValue(layer)
        self.vsLayer.setValue(layer)
        self.DataFrame = dataframe
        self.lblLayer.setText("Layer : %2d" % layer)

    def SendMessage(self):
        print(Slicer.MSGLayer(self.DataFrame))


