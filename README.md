# Caterpillar
## Project Description
This project is 

This repository contains two versions of the same project:
- The first one I did in my first year of my CS cursus before I knew how to properly use classes and methods.
- The second one I did for fun in my second year as a way to see how much I learned and improved since then.

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