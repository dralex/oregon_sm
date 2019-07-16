# Машина состояний для РИ Fallout Орегон.
[![Build Status](https://travis-ci.org/notiel/oregon_sm.svg?branch=master)](https://travis-ci.org/notiel/oregon_sm)

## Настройка окружения для разработки и сборки

- Установить [chocolatey](https://chocolatey.org/) - пакетный менеджер для Windows.
- Открыть командную строку с правами администратора. Проверить, что запуск `choco` работает (должен показать версию).
- Установить make: `choco install make`. Могут запрашиваться подтверждения от пользователя, соглашайтесь.
- Проверить, что команда `make` стала доступна из командной строки (нужно открыть другое окно).
- Установить mingw (включает в себя g++ и gcc): `choco install mingw`.
- Проверить, что команды `g++` и `gcc` стали доступна из командной строки (нужно открыть другое окно).
- Установить CMake (генератор Makefile и других файлов проектов):
  ```bash
  choco install cmake.install --installargs '"ADD_CMAKE_TO_PATH=User"'
  ```
- Проверить, что команда `cmake` стала доступна из командной строки (нужно открыть другое окно).

## Сборка и запуск

### Сборка из командной строки через MinGW
- Находясь в корне репозитория, создать папку, в которой будут находиться build-артефакты (`mkdir build`) и перейти в нее (`cd build`).
- Запустить `cmake` выбрав в качестве генератора MinGW Makefiles и передав путь к CMakeLists.txt:
  ```bash
  cmake -G"MinGW Makefiles" ../src
  ```
  Это и предыдущие действия нужно сделать один раз, при изменении кода делать их снова не нужно.
- Сборка: запустить `make` находясь в папке build.
- Запуск: `./oregonFallout.exe` находясь в папке build.

### Сборка из Atollic TruStudio/Eclipse
- Находясь в корне репозитория, создать папку, в которой будут находиться build-артефакты и makefile для Eclipse (`mkdir eclipse-build`) и перейти в нее (`cd eclipse-build`).
- Запустить `cmake` выбрав в качестве генератора Eclipse CDT4 и передав путь к CMakeLists.txt:
  ```bash
  cmake -G"Eclipse CDT4 - MinGW Makefiles" -DCMAKE_ECLIPSE_VERSION=4.6 ../src
  ```
  Это и предыдущие действия нужно сделать один раз, при изменении кода делать их снова не нужно.
- Запустить Atollic TrueStudio/Eclipse, нажать `File -> Open Projects from File System...`, выбрать созданную выше папку
  `eclipse-build` в качестве Import source. В табличке ниже должна появиться строка eclipse-build (с галочкой) -- Eclipse project.
  Нажать Finish.
- Убедиться что проект собирается (`Project -> Build All`). В консоли не должно быть ошибок.
- Настроить запуск эмулятора и юнит-тестов. `Run -> Run Configurations...`, нажать правой кнопкой мыши C/C++ Application,
  выбрать New. Задать имя (Name) конфигурации (например, OregonFalloutEmulator), нажать `Search Project...`, выбрать
  OregonFallout.exe (или OregonFalloutTest.exe) для запуска юнит-тестов, выбрать `Enable auto build`, нажать Apply и потом
  Run. Для повторного запуска можно нажать Ctrl + F11 (или `Run -> Run`). Если хочется поменять запускаемый бинарник,
  нужно снова идти в `Run -> Run Configurations...` и запускать оттуда.
- Попробовать редакторирование какого-то из исходников. Список всех исходников есть в Project Explorer в Source Directory.
  Альтернативно, можно пойти в Targets и там будут подпапки соответствующие проектам/целям сборки:
  - OregonFalloutLib - общие файлы
  - OregonFallout - десктопный эмулятор
  - OregonFalloutTest - юнит-тесты

### Возможные ошибки и проблемы
- **Если пусть папки проекта содержит нелатинские (например, русские) символы, MinGW работать не будет.**<br>
  Пока вариант только либо переместить папку, либо заменить MinGW на другой инструмент.

- **Жалобы `Сmake` на неопознанный компилятор, не может его определить тестом.**<br>
  Помогает запуск из командной строки с правами администратора. Но и перезагрузка тоже.

- **При попытке запуска `make` система жалуется на отсутствие libwinpthread-1.dll.**<br>
  Кажется, помогла перезагрузка.
