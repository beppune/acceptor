# CMakeList.txt: progetto CMake per MiniChat. Includere l'origine e definire
# qui la logica specifica del progetto.
#
cmake_minimum_required (VERSION 3.8)

project ("MiniChat")

set(BOOST_ROOT "C:/local/boost_1_79_0")


find_package(Boost)

if(NOT Boost_FOUND)
	message(FATAL_ERROR "Boost Not Found")
endif()

include_directories(${Boost_INCLUDE_DIR})

# Aggiungere l'origine all'eseguibile di questo progetto.
add_executable (MiniChat "MiniChat.cpp" "MiniChat.h")

# TODO: Aggiungere i test e, se necessario, installare le destinazioni.
