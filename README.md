# Snake in C

## Brief description
Snake in C is a terminal-based recreation of the classic game built fully in C using the ncurses library. Move with the keys, collect food and stay as long as you could without dying. The game speeds up as you grow.

## Features

- Movement with keys.
- Random food appearance.
- Detection of collision with the walls and one itself.
- Game Over screen.
- Score display at real time.
- High score display with persistency through a .txt file.
- Acii Art Title.
- Colored objects.
- Restart option in Game Over Screen.
- Incremental velocity.

## Controls


| Key | Action |
|-------|--------|
| ↑ | Move up |
| ↓ | Move down |
| ← | Move left |
| → | Move right |
| Enter | Retry |
| Space | Quit |

## Requirements

- gcc
- libncurses-dev (Linux) or PDCurses (Windows)

## Building from source

After cloning and with all the dependencies available:

### Linux
`gcc main.c -lncurses -o snake`

### Windows
`gcc main.c -lpdcurses -o snake.exe`

## Screenshots
<img width="918" height="925" alt="image" src="https://github.com/user-attachments/assets/630aca31-ee26-4ea7-b3e8-0541f21c19f4" />
<img width="411" height="215" alt="image" src="https://github.com/user-attachments/assets/f8549992-cbb8-4aca-ad2d-7ceac366f7c4" />


