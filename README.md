# Caterpillar
## Project Description
This project is a particle simulation consisting of what I called "caterpillars".
A caterpillar is just a chain of particles. A particle is made up of a position, a speed vector, a force vector and some other informations for rendering.

The first particle of a caterpillar behaves differently depending on which behavior is selected.
All the other particles's positions are calculated by setting their speed vector to the difference between its current position and the previous one's.
Then their position is calculated with the following formula: p(t + dt) = p(t) + dt \* s(t), where p is the position, s is the speed, t is the current
time and dt is the time difference between now and the last time point.

The current behaviors are:
1) There is one caterpillar, the first particle follows the mouse.
2) There is one caterpillar, the first particle is on the mouse's position.
3) There is one caterpillar, the first particle draws a circle.
4) There is at least one caterpillar. The first particle of each goes in a random direction,
is affected by gravity and has collisions with the window's borders.
5) There is one caterpillar, the first particle is the point reflexion of the mouse's position with the window's center.
6) There is at least one caterpillar. The caterpillars's first particles are spread evenly on the circle OM,
O being the center of the window and M the position of the mouse and with one particle being on the mouse itself.

This repository contains two versions of the same project:
- The first one I did in my first year of my CS cursus before I knew how to properly use classes and methods.
- The second one I did for fun in my second year as a way to see how much I learned and improved since then.

The controls for the first version are:
- The behavior can be changed using the Z and S.
- You can add or remove caterpillars with I and K.

The controls for the second version are:
- The behavior can be changed using the UP and DOWN arrows.
- You can add or remove caterpillars with T and G.

## Setup
### Dependencies
On a Debian system you can install the needed dependencies using:
```shell
sudo apt install libsdl2-dev libsdl2-ttf-dev
```

### Clone Repository
```shell
git clone https://github.com/llikian/Caterpillar.git
cd Caterpillar
```

### Build
To build you can simply run the `build.sh` script at the root using:
```shell
bash build.sh
```

You can also manually build it using:
```shell
cmake -B build && \
cmake --build build -j
```

Then you can run it using:
```shell
bin/Caterpillar
```

Or this depending which version you want to run:
```shell
bin/Old_Caterpillar
```

## Credits
The rendering is done using [SDL2](https://www.libsdl.org/)