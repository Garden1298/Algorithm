n = int(input())

for _ in range(n):
    p = int(input())
    
    max_price = -1
    best_player = ""
    
    for _ in range(p):
        data = input().split()
        price = int(data[0])
        name = data[1]
    
        if price > max_price:
            max_price = price
            best_player = name
       
    print(best_player)