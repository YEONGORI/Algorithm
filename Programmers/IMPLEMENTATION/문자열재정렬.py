def solution_my(c_list) -> str:
    n_list = list()
    result = str()
    value = 0

    for c in c_list:
        n_list.append(ord(c))
    n_list.sort()

    for n in n_list:
        if n > 47 and n < 58:
            value += int(chr(n))
        else:
            result += chr(n)
    result += str(value)

    return result

def solution_main(c_list) -> str:
    result = []
    value = 0

    for c in c_list:
        if c.isalpha():
            result.append(c)
        else:
            value += int(c)

    result.sort()
    if value != 0:
        result.append(str(value))
    return ''.join(result)