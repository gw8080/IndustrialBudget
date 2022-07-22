from numpy import random
print("Financial indecision calculator")
print("A three-sided die is impossible. nevertheless, throwing the three-sided die over X amount of time will give you the decision making ability you need. Sooner or later the object of desire will be chosen, otherwise a balance of other selections will be generated, thus making uniform distribution an ideal tool for budgeting.")
while(True):
    varA = int(input("Choice count: "))
    x = random.uniform(0, varA, size=(1, varA))[0]
    for y in x:
        print("selection" ,round(y))
        
