#!/usr/bin/python3

import os
import subprocess
import colorama

ASM_STUDENT_PATH = "../asm/asm"
ASM_EPITECH_PATH = "./asm"
CHAMPS_PATH = "champs/"
COR_EPITECH_PATH = "cor_epitech/"
COR_STUDENT_PATH = "cor_student/"

def clean_path(path):
    files = os.listdir(path)
    for file in files:
        subprocess.run(["rm", path + file])


def create_path(path):
    if not os.path.exists(path):
        subprocess.run(["mkdir", path])


def display_log_file():
    colorama.init()
    print(colorama.Fore.YELLOW + "See details in " + COR_EPITECH_PATH + " and " + COR_STUDENT_PATH)
    print(colorama.Style.RESET_ALL, end="")


def display_file(file):
    print(colorama.Fore.BLUE + "[" + file + "]", end="")
    print(colorama.Style.RESET_ALL, end="")


def handle_sig(exit_code):
    if exit_code != 0:
        if os.WIFSIGNALED(exit_code):
            return os.WTERMSIG(exit_code)
        else:
            return exit_code
    return 0


def display_recap(recap):
    print("                                             STUDENT RECAP                      ")
    for idx, file in enumerate(recap):
        display_file(file["name"])
        if file["codes"][0] != file["codes"][1]:
            print(colorama.Fore.RED + " Return value Error" + colorama.Style.RESET_ALL + ": your program returned exit status " + colorama.Fore.YELLOW + "{0}".format(file["codes"][0]) + colorama.Style.RESET_ALL + ", EPITECH returned " + colorama.Fore.YELLOW + "{0}".format(str(file["codes"][1])))
            print(colorama.Style.RESET_ALL, end="");
        elif file["diff"] == 1:
            print(colorama.Fore.RED + " Output Error" + colorama.Style.RESET_ALL + ": Epitech and Student files are different. ", end="")
            display_log_file()
        else:
            print(colorama.Fore.GREEN + " Output and return value are both correct.")
            print(colorama.Style.RESET_ALL, end="")


if not os.path.exists(ASM_EPITECH_PATH) or not os.path.exists(ASM_STUDENT_PATH):
    print("A binary file is missing.")
    exit(84)

create_path(COR_EPITECH_PATH)
create_path(COR_STUDENT_PATH)
clean_path(COR_EPITECH_PATH)
clean_path(COR_STUDENT_PATH)

files = os.listdir(CHAMPS_PATH)
list_file = [{"name": file, "diff": 1, "codes": [0, 0]} for file in files]
for idx, file in enumerate(files):
    file_cor = file.split(".")[0] + ".cor"
    epitech_code = subprocess.run([ASM_EPITECH_PATH, CHAMPS_PATH + file], stdout=open("/dev/null", "w"))
    if os.path.exists(file_cor):
        subprocess.run(["mv", file_cor, COR_EPITECH_PATH], stdout=open("/dev/null"))
    student_code = subprocess.run([ASM_STUDENT_PATH, CHAMPS_PATH + file], stdout=open("/dev/null", "w"))
    list_file[idx]["codes"][0] = handle_sig(student_code.returncode)
    list_file[idx]["codes"][1] = handle_sig(epitech_code.returncode)
    if os.path.exists(CHAMPS_PATH + file_cor):
        subprocess.run(["mv", CHAMPS_PATH + file_cor, COR_STUDENT_PATH], stdout=open("/dev/null", "w"))
        diff_code = subprocess.run(["diff", COR_EPITECH_PATH + file_cor, COR_STUDENT_PATH + file_cor], stdout=open("/dev/null", "w"))
        if diff_code.returncode == 0:
            list_file[idx]["diff"] = 0
    if not os.path.exists(CHAMPS_PATH + file_cor) and not os.path.exists(COR_EPITECH_PATH + file_cor):
        list_file[idx]["diff"] = 0
display_recap(list_file)
