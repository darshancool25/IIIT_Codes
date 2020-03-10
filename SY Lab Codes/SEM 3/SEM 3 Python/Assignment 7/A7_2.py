def rev_str(mystr):
    l = len(mystr)
    for i in range(l-1,-1,-1):
        yield mystr[i]
for ch in rev_str("darshan"):
    print(ch)
