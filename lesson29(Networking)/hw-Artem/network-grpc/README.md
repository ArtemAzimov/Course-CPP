## Build commands

- mkdir build
- cd build
- conan install .. -s build_type=Debug --build missing
- cmake .. -DCMAKE_BUILD_TYPE=Debug
- cmake --build . --config Debug


## Вопросы

1. conanfile.txt - что использовать вместо imports? Обращение к библиотеке ${CONAN}?
2. Наследование от RequestHandler для обработки всех сервисов в режиме AsyncService ?