import sys
input = sys.stdin.readline

def setTree(arr, tree, length):
    row, idx = 0, 0
    while idx < length:
        if idx != 0 and tree[idx] == 'p':
            for i in range(5):
                arr[row][i] = tree[idx]
                idx += 1
        else:
            arr[row][0] = tree[idx]
            idx += 1
        row += 1
    return arr

def solution(tree1, tree2):

    d = dict()
    d[0], d[2], d[3] = 'w', 'p', 'b'
    d['w'], d['p'], d['b'] = 0, 2, 3

    t1 = [[''] * 5 for _ in range(5)]
    t2 = [[''] * 5 for _ in range(5)]

    t1 = setTree(t1, tree1, len(tree1))
    t2 = setTree(t2, tree2, len(tree2))

    result = ''
    for i in range(5):
        if t1[i][0] == '' or t2[i][0] == '':
            break

        tmp = d[d[t1[i][0]] | d[t2[i][0]]]
        if tmp == 'p':
            result += tmp
            if i == 0:
                continue

            for j in range(1, 5):
                if t1[i][j] != '' and t2[i][j] != '':
                    result += d[d[t1[i][j]] | d[t2[i][j]]]
                else:
                    if t1[i][j] != '':
                        result += d[d[t1[i][j]]]
                    else:
                        result += d[d[t2[i][j]]]

        else:
            result += tmp

    return result

tree1 = "ppwwwbwbpwwbw"
tree2 = "pwpwwbwwpwbbb"
answer = solution(tree1, tree2)

if answer == "ppwwwbpwwbwbpwbbb":
    print("SOLVED!")
else:
    print("FAILED")