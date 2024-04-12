def solution(phone_book):
    D = {}
    phone_book.sort()
    
    def dfs_find(D, string, first):
        if len(D) == 0 and first is False:
            return True
        if len(string) == 0:
            return True
        
        if string[:1] in D: return dfs_find(D[string[:1]], string[1:], False)
        else: return False
    
    def dfs_save(D, string):
        if len(string) == 0:
            return True
        D[string[:1]] = {}
        dfs_save(D[string[:1]], string[1:])

    for phone in phone_book:
        if dfs_find(D, phone, True) is True:
            return False
        dfs_save(D, phone)

    return True