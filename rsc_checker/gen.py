import random

list = [ "sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr" ]

#for i in range(100):
#    num = random.randint(0, 30)
#    
#    newlist = random.choices(list, k=num)
#    
#    print(r'\n'.join(map(str,newlist)))

for i in range(1):
    size = random.randint(0,30)
    size = 500

    newlist = [ random.randint(-2147483648, 2147483647) for _ in range(size)]
    print(' '.join(map(str,newlist)))
