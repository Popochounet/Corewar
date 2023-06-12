##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## string_manip
##

def pop_first_line(str):
    return str[str.find("\n") + 1:]

def get_first_line(str):
    return str[:str.find("\n") + 1]

def pop_last_line(str):
    return str[:str.rfind("\n")]

def get_last_line(str):
    return str[str.rfind("\n") + 1:]

def diff_arrays(first, second):
    result = second.copy()
    for elem in first:
        if elem in result:
            result.remove(elem)
    return result

def array_equal(first, second):
    if len(first) != len(second):
        return False
    for i in range(len(first)):
        if second[i] != first[i]:
            return False
    return True

def get_change_indexes(first, second):
    result = []
    for i in range(len(first)):
        if first[i] != second[i]:
            result.append(i)
    return result

if __name__ == "__main__":
    print(get_change_indexes("abc", "abd"))
    print(get_change_indexes("abc", "abc"))