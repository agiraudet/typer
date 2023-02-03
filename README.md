# typer
A small program offering to mesure your typing speed.

## Usage
./typer <dictionary>

<dicctionary> should be a text file with one word per line.
If no file is given, the program will try to read from `/usr/share/dict/words`

Press Escape to end the session.

**DONT USE CTRL+C**
It will not escape properly (yet) and ncurses might leave your terminal in a bad state.

## TODO
* Intercept ctrl+c
* Add random word generation
* Train specific fingers
