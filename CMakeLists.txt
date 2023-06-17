cmake_minimum_required(VERSION 3.24)
project(sklep)

set(CMAKE_CXX_STANDARD 17)

add_executable(sklep main.cpp Klient.cpp Klient.h Zamowienie.cpp Zamowienie.h Sklep.cpp Sklep.h Produkt.cpp Produkt.h)
