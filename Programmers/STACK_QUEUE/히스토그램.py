n = int(input())
histogram = [int(input()) for _ in range(n)]

def get_mid_area(st, mid, en, histogram):
    cur_hei = mid_area = histogram[mid]
    left, right = mid - 1, mid + 1
    while st <= left and en >= right:
        if histogram[left] < histogram[right]:
            cur_hei = min(cur_hei, histogram[right])
            mid_area = max(mid_area, cur_hei * (right - left))
            right += 1
        else:
            cur_hei = min(cur_hei, histogram[left])
            mid_area = max(mid_area, cur_hei * (right - left))
            left -= 1

    while st <= left:
        cur_hei = min(cur_hei, histogram[left])
        mid_area = max(mid_area, cur_hei * (right - left))
        left -= 1
    while en >= right:
        cur_hei = min(cur_hei, histogram[right])
        mid_area = max(mid_area, cur_hei * (right - left))
        right += 1
    return mid_area

def div_conq(histogram, st, en):
    if st == en:
        return 0
    # if en - st == 1:
    #     return (min(histogram[st], histogram[en]) * 2)
    if en - st == 1:
        if histogram[en] < histogram[st]:
            return max(2 * histogram[en], histogram[st])
        else:
            return max(2 * histogram[st], histogram[en])
    
    mid = (st + en) // 2
    left_area = div_conq(histogram, st, mid)
    right_area = div_conq(histogram, mid + 1, en)
    mid_area = get_mid_area(st, mid, en, histogram)

    return max(left_area, mid_area, right_area)

if n == 1:
    print(histogram[0])
else:
    print(div_conq(histogram, 0, n-1))