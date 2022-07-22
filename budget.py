from numpy import random
print("Financial indecision calculator")
print("A three-sided die is impossible. nevertheless, throwing the three-sided die over X amount of time will give you the decision making ability you need. Sooner or later the object of desire will be chosen, thus making uniform distribution an ideal tool for budgeting.")
while(True):
    varB = int(input("Choice count: "))
    x = random.uniform(0, varB, size=(10, varB))
    for y in x:
        for z in y:
            print("selection" ,round(z))
