##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## corewar_class
##

# import time as t
import curses as c
from constants import *
from tools import *
from get_binary_output import *
import sys

class Corewar:
    def __init__(self, scr):
        self.scr = scr

        self.iteration = 0
        self.prev_iteration = 0
        self.iteration_speed = 1

        self.y_offset = 0
        self.y_box_index = DEFAULT_Y_BOX_INDEX

        self.output = ""
        self.prev_battleground = ""
        self.visible_battleground = ""
        self.champions_alive = []
        self.new_champions_alive = []
        self.diff_champions_alive = []

        self.pressed = 0
        argv = sys.argv
        if (len(argv) > 1):
            self.champions = argv[1:]
        else:
            self.champions = ["tyron.cor", "tyron.cor"]
        self.do_execute_binary = True

        self.win_save = ""
        self.win_champion_number = -1
        self.win_champion_name = ""
        self.win_iteration = 0

    def write_line_in_box(self, str):
        self.scr.addstr(self.y_box_index, RIGHT_BOX, str)
        self.y_box_index += 1

    def handle_keys(self):
        self.do_execute_binary = False
        self.prev_iteration = self.iteration
        if self.pressed == ARROW_RIGHT:
            self.do_execute_binary = True
            self.iteration += self.iteration_speed
        if self.pressed == ARROW_LEFT:
            self.do_execute_binary = True
            self.iteration -= self.iteration_speed
        if self.iteration < 0:
            self.iteration = 0
        if self.iteration < self.win_iteration:
            self.win_champion_number = -1

        if self.pressed == ARROW_TOP:
            self.y_offset -= Y_BATTLEGROUND_SPEED
        if self.pressed == ARROW_BOT:
            self.y_offset += Y_BATTLEGROUND_SPEED
        if self.y_offset < 0:
            self.y_offset = 0

        if self.pressed == ord('o'):
            self.iteration_speed -= 1
        if self.pressed == ord('p'):
            self.iteration_speed += 1
        if self.iteration_speed < 1:
            self.iteration_speed = 1

    def parse_output(self):
        i = 0
        while (self.output[:len(BATTLEGROUND_START)] != BATTLEGROUND_START) and (i < 100):
            i += 1
            self.new_champions_alive.append(get_first_line(self.output))
            self.output = pop_first_line(self.output)
        if get_last_line(self.output)[:len(BATTLEGROUND_END)] != BATTLEGROUND_END:
            self.win_save = get_last_line(self.output)
            self.win_champion_number = int(self.win_save[10])
            self.win_champion_name = self.win_save[13:-10]
            self.win_iteration = self.iteration
            self.output = pop_last_line(self.output)
        self.prev_battleground = self.visible_battleground
        self.visible_battleground = self.output[BINARY_LINE_LENGTH * self.y_offset :
            BINARY_LINE_LENGTH * (c.LINES + self.y_offset - 2) - 1]

    def print_corewar(self):
        if self.win_champion_number != -1:
            return
        if (self.do_execute_binary):
            self.new_champions_alive = []
            self.diff_champions_alive = []
            self.output = get_binary_output(self.iteration, self.champions)
            if (self.output == "error" or len(self.output) < 1000):
                return "error"
            self.output = self.output[:-1]
            # self.do_execute_binary = False
        self.parse_output()
        self.scr.addstr(self.visible_battleground)
        if (not array_equal(self.new_champions_alive, self.champions_alive)):
            self.diff_champions_alive = diff_arrays(self.champions_alive, self.new_champions_alive)
            self.champions_alive = self.new_champions_alive

    def highlight_changes(self):
        color_indexes = get_change_indexes(self.prev_battleground, self.visible_battleground)
        if (len(color_indexes) > 0):
            for index in color_indexes:
                self.scr.chgat(index // BINARY_LINE_LENGTH, index % BINARY_LINE_LENGTH,
                               1, c.A_REVERSE)

    def print_box_right(self):
        self.write_line_in_box("iteration : " + str(self.iteration) +
                               ", speed: " + str(self.iteration_speed))
        self.write_line_in_box("key pressed: " + str(self.pressed) +
                               ", y offset: " + str(self.y_offset))
        self.write_line_in_box("--  Champions  --")
        for string in self.champions:
            self.write_line_in_box(string)
        self.write_line_in_box("--  Champions alive  --")
        self.write_line_in_box(self.win_save)
        if self.prev_iteration < self.iteration:
            for string in self.diff_champions_alive:
                self.write_line_in_box(string)
        if self.do_execute_binary:
            self.highlight_changes()

    def print_in_screen(self):
        self.y_box_index = DEFAULT_Y_BOX_INDEX
        if self.print_corewar() == "error":
            return "error"
        self.print_box_right()
        self.pressed = self.scr.getch()
        self.handle_keys()
