# Game Object System Experiment

This was an experiment to learn more about component-based game object systems.
I also wanted an excuse to play with some of the new C++11 features!

![screenshot](https://raw.github.com/surjikal/cbgos-experiment/master/screenshots/shooting-spaceships.png)


# Dependencies

- QT 5
- OpenGL & Glew


# Compilation

I have compiled this on Gentoo, Windows 7 and OSX 10.8. That said, I always need
to tweak either the project file or a couple of import paths.

If you need help with compilation, please open an issue on Github and I'll do my
best to help you out.


## OSX

1. Install glew: `brew install glew`
2. In QT Creator:
   a. Create a new kit (File > Preferences > Build & Run)
   b. Choose GCC as the compiler
   c. Set the `QT mkspec` to `macx-clang-libc++`


# License

GPLv3
