gameoflife
==========

## Description ##
A simulation of Conway's Game of Life in C++ with a Glider (spaceship) example.

## TO DO ##
Not in order of importance
- [ ] Get grid size and initial pattern from user (command-line/run-time)
- [ ] Make it continuous
- [ ] Support different rule sets

## How to run ##
```
$ git clone https://github.com/hasit/gameoflife.git
```

```
$ cd ~/gameoflife/
```

```
$ g++ gameoflife.cpp -o gol
```

```
$ ./gol
```

## Rules ##
At each step in time, the following transitions occur:

1. Any live cell with fewer than two live neighbours dies, as if caused by under-population.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by overcrowding.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

## Given example of Spaceship - Glider ##
<img src="http://upload.wikimedia.org/wikipedia/commons/f/f2/Game_of_life_animated_glider.gif" />

## Other examples of patterns ##
[Wikipedia reference](http://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#Examples_of_patterns)
