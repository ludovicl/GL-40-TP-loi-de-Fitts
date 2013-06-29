HEADERS += \
    data.h \
    sequencewindow.h \
    mainwindow.h \
    parametersdialog.h \
    dataviewwindow.h

SOURCES += \
    data.cpp \
    main.cpp \
    sequencewindow.cpp \
    mainwindow.cpp \
    parametersdialog.cpp \
    dataviewwindow.cpp

QMAKE_CXXFLAGS += -fpermissive #Pour utiliser QString::number().toStdString
