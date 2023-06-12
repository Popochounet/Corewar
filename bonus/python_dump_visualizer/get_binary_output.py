##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## get_binary_output
##

import subprocess

def get_binary_output(i, champs=["tyron.cor", "tyron.cor"]):
    if (type(i) != str):
        i = str(i)
    p = subprocess.run(['./corewar', '-dump', i, *champs],
                       capture_output=True, text=True)
    if (p.stderr):
        print(p.stderr)
        return "error"
    output_str = p.stdout
    return output_str
