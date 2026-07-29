# Snake in C

## Brief description

A terminal classic snake game built fully in C. It has the basic characteristics of a classic Snake game, movement with keys, the ability to grow recolecting food, a simple display with the score and the SNAKE title in Ascii Art and a Game Over based on collisions with the walls and the snake itself.

## Controls


| Tecla | Acción |
|-------|--------|
| ↑ | Mover arriba |
| ↓ | Mover abajo |
| ← | Mover izquierda |
| → | Mover derecha |

## Requirements

- gcc
- libncurses-dev (Linux) o PDCurses (Windows)

## Building from source

After cloning and with all the dependencies available:

### Linux
`gcc main.c -lncurses -o snake`

### Windows
`gcc main.c -lpdcurses -o snake.exe`

## Screenshots

