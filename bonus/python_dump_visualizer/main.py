##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## main
##

import curses as c
from corewar_class import *

def main(cw):
    while cw.pressed != ord('q'):
        cw.scr.erase()
        if (cw.print_in_screen() == "error"):
            c.endwin()
            print("Error")
            return
        cw.scr.refresh()

def init():
    scr = c.initscr()
    cw = Corewar(scr)
    if (c.COLS < BINARY_LINE_LENGTH + 30):
        print("Terminal too small")
        return "error"
    c.noecho()
    c.curs_set(0)
    return cw

if __name__ == "__main__":
    cw = init()
    if cw == "error":
        c.endwin()
        print("error, terminal probably too small")
    else:
        if main(cw) == "error":
            c.endwin()
            print("error")
    c.endwin()
