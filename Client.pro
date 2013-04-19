# Project created by QtCreator 2011-07-18T11:40:30
# -------------------------------------------------
QT += network \
    opengl
TARGET = Client
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    setup.cpp \
    myimage.cpp \
    mypreview.cpp \
    plot.cpp \
    mplot.cpp
HEADERS += mainwindow.h \
    setup.h \
    myimage.h \
    mypreview.h \
    plot.h \
    complexnumber.h \
    pixmaps.h \
    mplot.h
FORMS += mainwindow.ui \
    setup.ui \
    mypreview.ui \
    mplot.ui
LIBS += -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_features2d \
    -lopencv_calib3d \
#    -L/usr/local/qwt-6.0.1/lib \
    -lqwt \
    -lqwtmathml
RESOURCES += clientpc.qrc
INCLUDEPATH += /usr/include/qwt

# CONFIG += qwt
#QT_PLUGIN_PATH += /usr/local/qwt-6.0.1/plugins/designer
