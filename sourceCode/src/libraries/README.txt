In diesen Ordner können Librarys eingefügt werden.
Dazu muss im Ordner der Library eine CMakeLists.txt Datei mit dem folgendem Inhalt erstellt werden:

cmake_minimum_required(VERSION 2.8)
include(${CMAKE_MODULE_PATH}/DefaultLibrary.cmake)