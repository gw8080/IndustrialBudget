from numpy import random
print("Financial indecision calculator")
print("A three-sided die is impossible. nevertheless, throwing the three-sided die over X amount of time will give you the decision making ability you need. Sooner or later the object of desire will be chosen, otherwise a balance of other selections will be generated, thus making uniform distribution an ideal tool for budgeting.")
db = []
while(True):
    var = input("enter selection or press enter to continue: ")
    if len(var)> 0:
        db.append(var)
    print("Current plan:")
    x = random.uniform(1, len(db), size=(1, len(db)))[0]
    for y in x:
        print("selection" ,db[round(y-1)])
        
