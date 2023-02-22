import random

test100 = random.sample(range(1, 1000000), 100)
test250 = random.sample(range(1, 1000000), 250)
test500 = random.sample(range(1, 1000000), 500)
test1000 = random.sample(range(1, 1000000), 1000)
test2500 = random.sample(range(1, 1000000), 2500)
test5000 = random.sample(range(1, 1000000), 5000)

test100del = test100.copy()
random.shuffle(test100del)
test250del = test250.copy()
random.shuffle(test250del)
test500del = test500.copy()
random.shuffle(test500del)
test1000del = test1000.copy()
random.shuffle(test1000del)
test2500del = test2500.copy()
random.shuffle(test2500del)
test5000del = test5000.copy()
random.shuffle(test5000del)

f = open("./in/test1.in", "w")
value = ""
count = 0
for i in test100:
    count += 1
    value += str(0) + " " + str(i) + "\n"
f.write(str(count) + "\n" + value)
f.close()

f = open("./in/test7.in", "w")
value = ""
count = 0
for i in test100del:
    count += 1
    value += str(1) + " " + str(i) + "\n"
f.write(str(count) + "\n" + value)
f.close()



 
f = open("./in/test2.in", "w")
value = ""
count = 0
for i in test250:
    count += 1
    value += str(0) + " " + str(i) + "\n"
f.write(str(count) + "\n" + value)
f.close()

f = open("./in/test8.in", "w")
value = ""
count = 0
for i in test250del:
    count += 1
    value += str(1) + " " + str(i) + "\n"
f.write(str(count) + "\n" + value)
f.close()




f = open("./in/test3.in", "w")
value = ""
count = 0
for i in test500:
    count += 1
    value += str(0) + " " + str(i) + "\n"
f.write(str(count) + "\n" + value)
f.close()

f = open("./in/test9.in", "w")
value = ""
count = 0
for i in test500del:
    count += 1
    value += str(1) + " " + str(i) + "\n"
f.write(str(count) + "\n" + value)
f.close()



f = open("./in/test4.in", "w")
value = ""
count = 0
for i in test1000:
    count += 1
    value += str(0) + " " + str(i) + "\n"
f.write(str(count) + "\n" + value)
f.close()

f = open("./in/test10.in", "w")
value = ""
count = 0
for i in test1000del:
    count += 1
    value += str(1) + " " + str(i) + "\n"
f.write(str(count) + "\n" + value)
f.close()




f = open("./in/test5.in", "w")
value = ""
count = 0
for i in test2500:
    count += 1
    value += str(0) + " " + str(i) + "\n"
f.write(str(count) + "\n" + value)
f.close()

f = open("./in/test11.in", "w")
value = ""
count = 0
for i in test2500del:
    count += 1
    value += str(1) + " " + str(i) + "\n"
f.write(str(count) + "\n" + value)
f.close()




f = open("./in/test6.in", "w")
value = ""
count = 0
for i in test5000:
    count += 1
    value += str(0) + " " + str(i) + "\n"
f.write(str(count) + "\n" + value)
f.close()

f = open("./in/test12.in", "w")
value = ""
count = 0
for i in test5000del:
    count += 1
    value += str(1) + " " + str(i) + "\n"
f.write(str(count) + "\n" + value)
f.close()




f = open("./in/test13.in", "w")
count = 0
count2 = 0
value = ""
for i in test100:
    count += 1
    a = random.randint(0, 4)
    if a == 0:
        value += str(0) + " " + str(i) + "\n"
    if a == 1:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(test100[count - 1 - random.randint(0, count - 1)]) + "\n"
    if a == 2:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(random.randint(1, 1000000)) + "\n"
    if a == 3:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(test100[count - 1 - random.randint(0, count - 1)]) + " " + str(random.randint(1, 1000000)) + "\n"
    if a == 4:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + "\n"
f.write(str(count + count2) + "\n" + value)
f.close()


count = 0
count2 = 0
value = ""
f = open("./in/test14.in", "w")
for i in test250:
    count += 1
    a = random.randint(0, 4)
    if a == 0:
        value += str(0) + " " + str(i) + "\n"
    if a == 1:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(test250[count - 1 - random.randint(0, count - 1)]) + "\n"
    if a == 2:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(random.randint(1, 1000000)) + "\n"
    if a == 3:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(test250[count - 1 - random.randint(0, count - 1)]) + " " + str(random.randint(1, 1000000)) + "\n"
    if a == 4:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + "\n"
f.write(str(count + count2) + "\n" + value)
f.close()

count2 = 0
count = 0
value = ""
f = open("./in/test15.in", "w")
for i in test500:
    count += 1
    a = random.randint(0, 4)
    if a == 0:
        value += str(0) + " " + str(i) + "\n"
    if a == 1:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(test500[count - 1 - random.randint(0, count - 1)]) + "\n"
    if a == 2:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(random.randint(1, 1000000)) + "\n"
    if a == 3:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(test500[count - 1 - random.randint(0, count - 1)]) + " " + str(random.randint(1, 1000000)) + "\n"
    if a == 4:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + "\n"
f.write(str(count + count2) + "\n" + value)
f.close()

count2 = 0
count = 0
value = ""
f = open("./in/test16.in", "w")
for i in test1000:
    count += 1
    a = random.randint(0, 4)
    if a == 0:
        value += str(0) + " " + str(i) + "\n"
    if a == 1:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(test1000[count - 1 - random.randint(0, count - 1)]) + "\n"
    if a == 2:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(random.randint(1, 1000000)) + "\n"
    if a == 3:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(test1000[count - 1 - random.randint(0, count - 1)]) + " " + str(random.randint(1, 1000000)) + "\n"
    if a == 4:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + "\n"
f.write(str(count + count2) + "\n" + value)
f.close()


count = 0
count2 = 0
value = ""
f = open("./in/test17.in", "w")
for i in test2500:
    count += 1
    a = random.randint(0, 4)
    if a == 0:
        value += str(0) + " " + str(i) + "\n"
    if a == 1:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(test2500[count - 1 - random.randint(0, count - 1)]) + "\n"
    if a == 2:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(random.randint(1, 1000000)) + "\n"
    if a == 3:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(test2500[count - 1 - random.randint(0, count - 1)]) + " " + str(random.randint(1, 1000000)) + "\n"
    if a == 4:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + "\n"
f.write(str(count + count2) + "\n" + value)
f.close()

count2 = 0
count = 0
value = ""
f = open("./in/test18.in", "w")
for i in test5000:
    count += 1
    a = random.randint(0, 4)
    if a == 0:
        value += str(0) + " " + str(i) + "\n"
    if a == 1:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(test5000[count - 1 - random.randint(0, count - 1)]) + "\n"
    if a == 2:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(random.randint(1, 1000000)) + "\n"
    if a == 3:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + " " + str(test5000[count - 1 - random.randint(0, count - 1)]) + " " + str(random.randint(1, 1000000)) + "\n"
    if a == 4:
        count2 += 1
        value += str(0) + " " + str(i) + "\n" + str(a) + "\n"
f.write(str(count + count2) + "\n" + value)
f.close()