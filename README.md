# Snake in C

## Brief description
Snake in C is a terminal-based recreation of the classic game built fully in C using the ncurses library. Move with the keys, collect food and stay as long as you could without dying.

## Features

- Movement with keys.
- Random food appearance.
- Detection of collision with the walls and one itself.
- Game Over screen.
- Score display at real time.

## Controls


| Tecla | Acción |
|-------|--------|
| ↑ | Move up |
| ↓ | Move down |
| ← | Move left |
| → | Move right |

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
<img width="905" height="683" alt="image" src="https://github.com/user-attachments/assets/0c14df1a-3ef8-4538-85e8-3c507729ab06" />

