str= input("")

strlist1 = str.split("x")
a = int(strlist1[0])
b = int(strlist1[1].split('=')[0])
c = int(strlist1[1].split('=')[1])

print("{0:.2f}".format((c-b)/a))