import sys
from PyQt5.QtWidgets import *
import multiprocessing as mp
from Main_Form import MainWindow
import PythonSendServer as pss

if __name__ =='__main__':
    app = QApplication(sys.argv)
    queue = mp.Queue()
    server = mp.Process(target=pss.SendFile, args=(queue,))
    server.start()
    # server.join()
    # WindowClass의 인스턴스 생성
    mainwindow = MainWindow(queue)
    # 프로그램 화면을 보여주는 코드
    mainwindow.show()
    # 프로그램을 이벤트루프로 진입시키는(프로그램을 작동시키는) 코드
    app.exec_()
