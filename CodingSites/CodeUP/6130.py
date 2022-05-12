str= input("")

strlist1 = str.split("x")
a = int(strlist1[0])
b = int(strlist1[1])

print("{0:.2f}".format((-b)/a))