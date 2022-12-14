from collections.abc import Iterable, Iterator
def compare(list_1, list_2):
    if not isinstance(list_1, Iterable) and not isinstance(list_2, Iterable):
        if list_1 < list_2:
            return -1
        elif list_1 > list_2:
            return 1
        else:
            return 0
    if not isinstance(list_1, Iterable):
        list_1 = [list_1]
    if not isinstance(list_2, Iterable):
        list_2 = [list_2]
    for i in range(max(len(list_1), len(list_2))):
        try:
            if compare(list_1[i], list_2[i]) == 1:
                return 1
            elif compare(list_1[i], list_2[i]) == -1:
                return -1
        except IndexError:
            if len(list_1) > len(list_2):
                return 1
            elif len(list_1) < len(list_2):
                return -1
    return 0

def split_list(L, n):
    assert type(L) is list, "L is not a list"
    for i in range(0, len(L), n):
        yield L[i:i+n]


if __name__ == '__main__':
    file_input = open('input.txt', 'r')
    input_list = file_input.read().split('\n')
    splitted = split_list(input_list, 3)
    index = 1
    sum_of_indexes = 0
    for item in splitted:
        list_1 = eval(item[0])
        list_2 = eval(item[1])
        if compare(list_1, list_2) == -1:
            sum_of_indexes += index
        index += 1
    
    print(sum_of_indexes)
    file_input.close()
