# Define a versão mínima do CMake necessária
# para compilar esse projeto.
#
# Se o usuário tiver uma versão inferior,
# o CMake irá gerar erro.
cmake_minimum_required(VERSION 3.10)


# Define o nome do projeto.
#
# Esse nome pode ser usado internamente
# pelo CMake e também por IDEs.
project(Pointers)


# Define qual padrão da linguagem C++
# será utilizado pelo compilador.
#
# Aqui estamos usando C++17.
#
# Isso faz o CMake adicionar algo como:
# -std=c++17
#
# no GCC/Clang.
set(CMAKE_CXX_STANDARD 17)


# Cria um executável chamado "app".
#
# O executável será compilado usando
# os arquivos listados abaixo.
#
# Nesse caso:
# src/main.cpp
#
# Resultado final:
# ./app
add_executable(app src/main.cpp)